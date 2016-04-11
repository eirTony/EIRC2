#include "EclipseWorkSupervisor.h"

#include "EclipseWorkMessageMachine.h"

EclipseWorkSupervisor::EclipseWorkSupervisor(QObject *boss)
    : QObject(boss)
{
}

void EclipseWorkSupervisor::execute(const EclipseMessage & msg)
{

}
