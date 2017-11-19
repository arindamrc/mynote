#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QDir>

namespace globals {

    const QString appName = "MyNote";
    const QString appHome = QDir::homePath() + "/." + appName;
    const QString orgName = "arclights";
    const QString appDisplayName = "MyNote";
    const QString appVersion = "0.0.1";
    const QString orgDomain = "arclights.in";
    const int defaultStretch_note = 8;
    const int defaultStretch_explorer = 1;
    const double boxHeight = 10.0;
    const double boxWidth = 20.0;
    const double boxOrientation = 0.0; // in radians


}

#endif // GLOBALS_H
