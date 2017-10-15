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
    const int note_defaultStretch = 4;

}

#endif // GLOBALS_H
