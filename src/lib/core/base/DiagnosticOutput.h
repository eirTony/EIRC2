#ifndef DIAGNOSTICOUTPUT_H
#define DIAGNOSTICOUTPUT_H

#include <QObject>
#include <QIODevice>

class DiagnosticOutput : public QIODevice
{
    Q_OBJECT
public:
    DiagnosticOutput(QObject * parent=0);
};

#endif // DIAGNOSTICOUTPUT_H
