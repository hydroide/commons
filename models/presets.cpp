#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "presets.h"
#include "../hcglobaldefs.h"

Presets::Presets(const QString &filePath)
{
    _filePath = filePath;
    QFile file(_filePath);
    if (!file.exists())
    {
        newPresets();
        savePresets();
    }
    else
    {
        loadPresets();
    }
}

Presets::~Presets()
{

}

void
Presets::newPresets()
{
    _lCanvasSizes.append(CanvasSize("50cm × 75cm （标准）",
                                    QSizeF(750, 500)));
    _lCanvasSizes.append(CanvasSize("60cm × 90cm （小绘图仪）",
                                    QSizeF(900, 600)));
    _lCanvasSizes.append(CanvasSize("75cm × 100cm （大绘图仪）",
                                    QSizeF(1000, 750)));
    _lCanvasSizes.append(CanvasSize("15cm × 25cm （适合A4）",
                                    QSizeF(250, 150)));
    _lCanvasSizes.append(CanvasSize("25cm × 30cm （适合A3）",
                                    QSizeF(300, 250)));

    _lChartSizes.append(ChartSize(
                            TYPE_SQUARE,
                            QObject::tr("75cm × 50cm（标准）"),
                            QObject::tr("mm"),
                            750,
                            500,
                            1.f,
                            1.f,
                            20.f,
                            20.f,
                            20.f,
                            20.f
                            ));
    _lChartSizes.append(ChartSize(
                            TYPE_SQUARE,
                            QObject::tr("35cm × 25cm（适合A3纸）"),
                            QObject::tr("mm"),
                            350,
                            250,
                            1.f,
                            1.f,
                            35.f,
                            35.f,
                            23.5f,
                            23.5f
                            ));
    _lChartSizes.append(ChartSize(
                            TYPE_SQUARE,
                            QObject::tr("25cm × 15cm（适合A4纸）"),
                            QObject::tr("mm"),
                            250,
                            150,
                            1.f,
                            1.f,
                            23.5f,
                            23.5f,
                            30.f,
                            30.f
                            ));
    _lChartSizes.append(ChartSize(
                            TYPE_HOUR,
                            QObject::tr("74.4cm × 50cm（31天，水文站）"),
                            QObject::tr("mm"),
                            744,
                            500,
                            1.f,
                            1.f,
                            20.f,
                            20.f,
                            20.f,
                            20.f
                            ));
    _lChartSizes.append(ChartSize(
                            TYPE_HOUR,
                            QObject::tr("74.4cm × 25cm（31天，水位站）"),
                            QObject::tr("mm"),
                            744,
                            250,
                            1.f,
                            1.f,
                            20.f,
                            20.f,
                            20.f,
                            20.f
                            ));
    _lChartSizes.append(ChartSize(
                            TYPE_HOUR,
                            QObject::tr("26.4cm × 40cm（适合A3纸，11天，水文站）"),
                            QObject::tr("mm"),
                            264,
                            400,
                            1.f,
                            1.f,
                            15.f,
                            15.f,
                            10.f,
                            10.f
                            ));
    _lChartSizes.append(ChartSize(
                            TYPE_HOUR,
                            QObject::tr("26.4cm × 20cm（适合A4纸，11天，水位站）"),
                            QObject::tr("mm"),
                            264,
                            200,
                            1.f,
                            1.f,
                            15.f,
                            15.f,
                            5.f,
                            5.f
                            ));
    _lChartSizes.append(ChartSize(
                            TYPE_HOUR,
                            QObject::tr("38.4cm × 25cm（适合A3纸横向，16天，水位站）"),
                            QObject::tr("mm"),
                            384,
                            250,
                            1.f,
                            1.f,
                            18.f,
                            18.f,
                            23.5f,
                            23.5f
                            ));
}

bool
Presets::loadPresets()
{
    QFile loadFile(_filePath);
    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qWarning() << "Couldn't load presets file: " << _filePath;
        return false;
    }

    QByteArray loadData = loadFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(loadData));

    read(loadDoc.object());

    return true;
}

bool
Presets::savePresets()
const
{
    QFile saveFile(_filePath);
    if (!saveFile.open(QIODevice::WriteOnly))
    {
        qWarning() << "Couldn't save presets file: " << _filePath;
        return false;
    }

    QJsonObject saveObject;

    write(saveObject);

    QJsonDocument saveDoc(saveObject);

    saveFile.write(saveDoc.toJson());

    return true;
}

void
Presets::read(const QJsonObject &json)
{
    _lCanvasSizes.clear();
    auto jsonArray = json["canvasSizes"].toArray();
    for (auto ref : jsonArray)
    {
        CanvasSize canvasSize;
        canvasSize.read(ref.toObject());
        _lCanvasSizes.append(canvasSize);
    }
    _lChartSizes.clear();
    auto jaChartSizes = json["chartSizes"].toArray();
    for (auto ref : jaChartSizes)
    {
        ChartSize chartSize;
        chartSize.read(ref.toObject());
        _lChartSizes.append(chartSize);
    }
}

void
Presets::write(QJsonObject &json)
const
{
    QJsonArray jsonArray;
    for (CanvasSize canvasSize : _lCanvasSizes)
    {
        QJsonObject jsonObject;
        canvasSize.write(jsonObject);
        jsonArray.append(jsonObject);
    }
    json["canvasSizes"] = jsonArray;
    QJsonArray jaChartSizes;
    for (ChartSize chartSize : _lChartSizes)
    {
        QJsonObject jo;
        chartSize.write(jo);
        jaChartSizes.append(jo);
    }
    json["chartSizes"] = jaChartSizes;
}

QList<CanvasSize> &
Presets::lCanvasSizes()
{
    return _lCanvasSizes;
}

QList<ChartSize> &
Presets::lChartSizes()
{
    return _lChartSizes;
}

