#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#ifndef PRESETS_H
#define PRESETS_H

#include <QList>
#include "canvassize.h"
#include "chartsize.h"

class Presets
{
public:
    Presets(const QString &filePath);
    ~Presets();

    void newPresets();
    bool loadPresets();
    bool savePresets() const;

    void read(const QJsonObject &json);
    void write(QJsonObject &json) const;

    QList<CanvasSize> &lCanvasSizes();
    QList<ChartSize> &lChartSizes();

private:
    QList<CanvasSize> _lCanvasSizes;
    QList<ChartSize> _lChartSizes;
    QString _filePath;
};

typedef QSharedPointer<Presets> SpPresets;

#endif // PRESETS_H
