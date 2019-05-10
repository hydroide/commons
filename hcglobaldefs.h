#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef GLOBALDEFINES
#define GLOBALDEFINES

#include <QtCore>
#include <QColor>

// Project TreeView
const int ROLE_DB_FILE{Qt::UserRole + 10};
const int ROLE_DATA{Qt::UserRole + 11};
const int ROLE_SERIES{Qt::UserRole + 12};
const int ROLE_PROCESS{Qt::UserRole + 13};
const int ROLE_RELATION{Qt::UserRole + 15};
const int ROLE_CROSS_SECTION{Qt::UserRole + 16};

const int ROLE_PROPERTY_GROUP{Qt::UserRole + 20 };

const int ROLE_TABLE_NAME{Qt::UserRole + 100};

const QString PROJECT_FILE_EXT  {"hcproj"};
const QString PROJECT_DB_EXT    {"db"};
const QString CHART_FILE_EXT    {"hcchart"};

const QString DEFAULT_DATETIME_FORMAT   {"yyyy-MM-dd hh:mm"};
const QString PROCESS_DATETIME_FORMAT   {"yyyyMMddhh.mm"};
const QString NO_YEAR_DATETIME_FORMAT   {"MMddhh.mm"};

const QString DEFAULT_NUMERIAL_FONTFAMILTY  {"Arial"};
const QString DEFAULT_HEITI_FONTFAMILTY     {"SimHei"};
const QString DEFAULT_SONGTI_FONTFAMILTY    {"SimSun"};
const QString DEFAULT_KAITI_FONTFAMILTY     {"KaiTi"};

const int METHOD_LPI = 10;
const int METHOD_PLPI_TPA = 11;
const int METHOD_PLPI_LWS = 12;
const int METHOD_PLPI_MPS = 13;
const int METHOD_PLPI_AMP = 14;
const int METHOD_BEZIER_Q = 2;
const int METHOD_BEZIER_C = 3;

const QString BRACKETS_NOT_CONFIGURED   {QObject::tr("<未配置>")};
const QString BRACKETS_ERROR            {QObject::tr("<错误>")};

const QString TYPE_HOUR     {QObject::tr("逐时")};
const QString TYPE_SQUARE   {QObject::tr("方格")};
const QString TYPE_BLANK    {QObject::tr("空白")};

const QString PERIOD_MONTH      {QObject::tr("月 - 31天图纸")};
const QString PERIOD_TENDAYS    {QObject::tr("旬月 - 11天图纸")};
const QString PERIOD_YEAR       {QObject::tr("年 - 366天图纸")};
const QString PERIOD_NONE       {QObject::tr("无周期")};

const QString TEXT_STAGE_PROCESS        {QObject::tr("水位过程")};
const QString TEXT_SEDIMENT_PROCESS     {QObject::tr("单沙过程")};
const QString TEXT_ZQS_PROCESS          {QObject::tr("水流沙过程")};
const QString TEXT_MEASURED_DISCHARGE   {QObject::tr("实测流量")};
const QString TEXT_MEASURED_SDR         {QObject::tr("实测输沙率")};

const QString TEXT_SEPERATOR    {QObject::tr("、")};

const int INT_MSECS_PER_HOURS   {3600000};

const QColor HOUR_CANVAS_DEFAULT_COLOR  {0, 174, 239};
const QColor SQUARE_CANVAS_DEFAULT_COLOR  {255, 97, 0};

const QMap<QString, QString> MAP_TABLE_DISPLAY_NAMES {
    {QLatin1String("STATION_INFO"),   QObject::tr("测站信息")},
    {QLatin1String("ZQ_PERIOD"),      QObject::tr("推流时段")},
    {QLatin1String("SQ_PERIOD"),      QObject::tr("推沙时段")},
    {QLatin1String("ZQ_CURVE_NODE"),  QObject::tr("推流节点")},
    {QLatin1String("SQ_CURVE_NODE"),  QObject::tr("推沙节点")},
    {QLatin1String("ZQ_PROCESS"),     QObject::tr("水位过程")},
    {QLatin1String("SQ_PROCESS"),     QObject::tr("单沙过程")},
    {QLatin1String("ZQ_MEASUREMENT"), QObject::tr("实测流量")},
    {QLatin1String("SQ_MEASUREMENT"), QObject::tr("实测输沙率")},
    {QLatin1String("CS_SURVEY"),      QObject::tr("实测断面")},
    {QLatin1String("CS_VERTICAL"),    QObject::tr("实测断面垂线")},
};

const QString CURVE_TYPE_ZQ = QObject::tr("ZQ");
const QString CURVE_TYPE_SS = QObject::tr("SS");
const QString CURVE_TYPE_CS = QObject::tr("CS");
const QString CURVE_TYPE_ZA = QObject::tr("ZA");
const QString CURVE_TYPE_ZV = QObject::tr("ZV");
const int VALUE_TYPE_NONE = 0;
const int VALUE_TYPE_Z = 1;
const int VALUE_TYPE_Z_M = 1;
const int VALUE_TYPE_Q = 2;
const int VALUE_TYPE_Q_M3 = 2;
const int VALUE_TYPE_S_KG_M3 = 3;
const int VALUE_TYPE_S_G_CM3 = 4;

const QMap<QString, QString> MAP_STATION_DISPLAY_NAMES {
    {QLatin1String("40105650"), QObject::tr("高村（四）")},
    {QLatin1String("40106350"), QObject::tr("孙口")},
    {QLatin1String("40107100"), QObject::tr("艾山（二）")},
    {QLatin1String("40107450"), QObject::tr("泺口（三）")},
    {QLatin1String("40108400"), QObject::tr("利津（三）")},
    {QLatin1String("41502400"), QObject::tr("陈山口（闸下二）")},
    {QLatin1String("41502420"), QObject::tr("陈山口（新闸下）")}
};


const QList<QString> SYMBOLS_AS_RECENT{"\"", "〃", "“" ,"”"};

const QStringList ALLOWED_FILE_EXTENSIONS{"hcp",
                                          "hcproj",
                                          "hcproject",
                                          "hdb"
                                          "hcc",
                                          "hcchart",
                                          "hcchartjsn",
                                          "hcchartjsnb",
                                          "hcu",
                                          "hccurve",
                                          "hco",
                                          "hccomponent",
                                          "hseries"};



struct DGSDSProecssNode
{
    QString stage;
    QString discharge;
    QString sediment;
};

struct DGCrossSectionSurveyVertical
{
    QString vertical_id;
    QString distance;
    QString elevation;
};

struct DGCrossSectionSurvey
{
    QString stcd;
    int year;
    int survey_id;
    QDate date;
    QString location;
    QString stage;
    QList<DGCrossSectionSurveyVertical> verticals;
    QColor color;
};

struct DGSDRPeriodOfCurve
{
    QString stcd;
    int year;
    int period_id;
    QDateTime startDateTime;
    QDateTime endDateTime;
    int method_id;
    int curve_id;
};

#endif // GLOBALDEFINES
