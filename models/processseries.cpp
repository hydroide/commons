#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "processseries.h"

#include "../helpers/roundinghelper.h"
#include "../modules/qvariantserializationdefs.h"

#include "../hcglobaldefs.h"

/*****************************************************************
 * Global
 *****************************************************************/
bool toDoubleLessThan(const QString &s1, const QString &s2)
{
    bool ok1 = false;
    bool ok2 = false;
    double d1 = s1.toDouble(&ok1);
    double d2 = s2.toDouble(&ok2);
    if (ok1 && ok2)
    {
        return d1 < d2;
    }
    return false;
}

bool toDoubleGreaterThan(const QString &s1, const QString &s2)
{
    return s1.toDouble() > s2.toDouble();
}

/*****************************************************************
 * ProcessMap
 *****************************************************************/
void ProcessMap::update()
{
    if (_data.count() > 0)
    {
        QString minStr = _data.values().first();
        QString maxStr = minStr;
        double min = minStr.toDouble();
        double max = maxStr.toDouble();
        for (const auto &str: _data.values())
        {
            double val = str.toDouble();
            if (val < min)
            {
                min = val;
                minStr = str;
            }
            if (val > max)
            {
                max = val;
                maxStr = str;
            }
        }
        _minValue = minStr;
        _maxValue = maxStr;
        _minValues.clear();
        _maxValues.clear();
        for (const auto &key: _data.keys())
        {
            const auto &value = _data.value(key);
            if (_minValue == value)
            {
                _minValues.insert(key, value);
            }
            if (_maxValue == value)
            {
                _maxValues.insert(key, value);
            }
        }
    }
}

QMap<QDateTime, QString> ProcessMap::minValues()
{
//    QMap<QDateTime, QString> map;
//    auto minValue = this->minValue();
//    for (const auto &key: _data.keys())
//    {
//        const auto &value = _data.value(key);
//        if (minValue == value)
//        {
//            map.insert(key, value);
//        }
//    }
//    return map;
    return _minValues;
}

QMap<QDateTime, QString> ProcessMap::maxValues()
{
//    QMap<QDateTime, QString> map;
//    auto maxValue = this->maxValue();
//    for (const auto &key: _data.keys())
//    {
//        const auto &value = _data.value(key);
//        if (maxValue == value)
//        {
//            map.insert(key, value);
//        }
//    }
//    return map;
    return _maxValues;
}

QString ProcessMap::minValue() const
{
//    bool ok = false;
//    _minValue.toDouble(&ok);
//    if (_minValue.isNull() || _minValue.isEmpty() || !ok)
//    {
//        if (_data.count() > 0)
//        {
//            QString minStr = _data.first();
//            double min = minStr.toDouble();
//            for (const auto &str: _data.values())
//            {
//                double val = str.toDouble();
//                if (val < min)
//                {
//                    min = val;
//                    minStr = str;
//                }
//            }
//            return minStr;
//        }
//    }
    return _minValue;
}

QString ProcessMap::maxValue() const
{
//    bool ok = false;
//    _maxValue.toDouble(&ok);
//    if (_maxValue.isNull() || _maxValue.isEmpty() || !ok)
//    {
//        if (_data.count() > 0)
//        {
//            QString maxStr = _data.first();
//            double max = maxStr.toDouble();
//            for (const auto &str: _pmCurrent->values())
//            {
//                double val = str.toDouble();
//                if (val > max)
//                {
//                    max = val;
//                    maxStr = str;
//                }
//            }
//            return maxStr;
//        }
//    }
    return _maxValue;
}

QMap<QDateTime, QString> &ProcessMap::data()
{
    return _data;
}

void ProcessMap::setData(const QMap<QDateTime, QString> &data)
{
//    if (data.count() > 0)
//    {
//        if (data.count() > 1)
//        {
//            auto minmaxpair = std::minmax_element(data.values().begin(),
//                                                  data.values().end(),
//                                                  [](const QString &s1, const QString &s2){
//                bool ok1 = false;
//                bool ok2 = false;
//                double d1 = s1.toDouble(&ok1);
//                double d2 = s2.toDouble(&ok2);
//                if (ok1 && ok2)
//                {
//                    return d1 < d2;
//                }
//                return false;
//            });
//            _minValue = *minmaxpair.first;
//            _maxValue = *minmaxpair.second;
//        }
//        else
//        {
//            _minValue = data.first();
//            _maxValue = data.first();
//        }
//    }
    _data = data;
    this->update();
}

void operator <<(QVariant &data, const ProcessMap &context)
{
    QJsonArray array;

    for (auto key : context._data.keys())
    {
        auto value = context._data[key];
        QVariantMap record;
        record["d"] << key;
        record["v"] << value;
        array.append(QJsonObject::fromVariantMap(record));
    }

    data = QJsonDocument(array).toVariant();
}

void operator >>(const QVariant &data, ProcessMap &context)
{
    context._data.clear();

    auto array = QJsonDocument::fromVariant(data).array();

    for (auto ref: array)
    {
        auto record = ref.toObject().toVariantMap();
        QDateTime key;
        QString value;
        record["d"] >> key;
        record["v"] >> value;
        context._data.insert(key, value);
    }

    context.update();
}


/*****************************************************************
 * ProcessSeries
 *****************************************************************/
ProcessSeries::ProcessSeries()
{

}

ProcessSeries::~ProcessSeries()
{

}

void ProcessSeries::genStageMap()
{
    if (_dataProvider) {
        _mStages.setData(_dataProvider->z_series(_stcd, _startDateTime, _endDateTime));
    }
}

void ProcessSeries::genDischargeMap()
{
    if (_dataProvider) {
        _mDischarges.setData(_dataProvider->q_series(_stcd, _startDateTime, _endDateTime));
    }
}

void ProcessSeries::genSedimentMap()
{
    if (_dataProvider) {
        _mSediments.setData(_dataProvider->s_series(_stcd, _startDateTime, _endDateTime));
    }
}

void ProcessSeries::genMeasuredDischargeMap()
{
    if (_dataProvider) {
        _measuredDischargeMap = _dataProvider->mq_series(_stcd, _startDateTime, _endDateTime);
    }
}

void ProcessSeries::genMeasuredSedimentDischargeMap()
{
    if (_dataProvider) {
        _measuredSedimentDischargeMap = _dataProvider->msq_series(_stcd, _startDateTime, _endDateTime);
    }
}

ProcessMap &ProcessSeries::mStages()
{
    return _mStages;
}

ProcessMap &ProcessSeries::mDischarges()
{
    return _mDischarges;
}

ProcessMap &ProcessSeries::mSediments()
{
    return _mSediments;
}

QMap<QDateTime, DGMeasuredDischarge> &ProcessSeries::measuredDischargeMap()
{
    return _measuredDischargeMap;
}

QMap<QDateTime, DGMeasuredSedimentDischarge> &ProcessSeries::measuredSedimentDischargeMap()
{
    return _measuredSedimentDischargeMap;
}

QColor ProcessSeries::lineColor() const
{
    return _lineColor;
}

void ProcessSeries::setLineColor(const QColor &lineColor)
{
    _lineColor = lineColor;
}

void ProcessSeries::setDataProvider(const SpDataProviderInterface &dataProvider)
{
    _dataProvider = dataProvider;
}

QDateTime ProcessSeries::startDateTime() const
{
    return _startDateTime;
}

void ProcessSeries::setStartDateTime(const QDateTime &startDateTime)
{
    _startDateTime = startDateTime;
}

QDateTime ProcessSeries::endDateTime() const
{
    return _endDateTime;
}

void ProcessSeries::setEndDateTime(const QDateTime &endDateTime)
{
    _endDateTime = endDateTime;
}

double ProcessSeries::hoursRange() const
{
    return (double)(_endDateTime.toMSecsSinceEpoch() -
                    _startDateTime.toMSecsSinceEpoch())
            /INT_MSECS_PER_HOURS;
}

QString ProcessSeries::stationName() const
{
    return _stationName;
}

void ProcessSeries::setStationName(const QString &stationName)
{
    _stationName = stationName;
}

QString ProcessSeries::stcd() const
{
    return _stcd;
}

void ProcessSeries::setSTCD(const QString &stcd)
{
    _stcd = stcd;
}

void operator <<(QVariant &data, const ProcessSeries &context)
{
    QVariantMap map;
    map["stages"] << context._mStages;
    map["discharges"] << context._mDischarges;
    map["sediments"] << context._mSediments;
    map["startDateTime"] << context._startDateTime;
    map["endDateTime"] << context._endDateTime;
    map["stcd"] << context._stcd;
    map["stationName"] << context._stationName;
    data = map;
}

void operator >>(const QVariant &data, ProcessSeries &context)
{
    auto map = QJsonDocument::fromVariant(data).object().toVariantMap();

    map["stages"] >> context._mStages;
    map["discharges"] >> context._mDischarges;
    map["sediments"] >> context._mSediments;
    map["startDateTime"] >> context._startDateTime;
    map["endDateTime"] >> context._endDateTime;
    map["stcd"] >> context._stcd;
    map["stationName"] >> context._stationName;
}
