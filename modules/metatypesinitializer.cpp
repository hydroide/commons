#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include "metatypesinitializer.h"

#include "registerstream.h"

#include "../settings/hourcanvassettings.h"

#include "datetimetovaluemap.h"

#include <QTextOption>

MetaTypesInitializer::MetaTypesInitializer()
{
//    qRegisterMetaType()
//    qRegisterMetaTypeStreamOperators<HourCanvasSettings>(HourCanvasSettings::staticMetaObject.className());
//    qRegisterMetaTypeStreamOperators<HourCanvasSettings>("HourCanvasSettings");

//    REGISTERSTREAM(TextOption);
    REGISTERSTREAM(HourCanvasSettings);

    qRegisterMetaType<QMap<QDateTime, QString>>("DateTime_String_Map");
    qRegisterMetaTypeStreamOperators<QMap<QDateTime, QString>>("DateTime_String_Map");

//    qRegisterMetaType<DateTimeToValueMap>("DateTimeToValueMap");
//    qRegisterMetaTypeStreamOperators<DateTimeToValueMap>("DateTimeToValueMap");
}

