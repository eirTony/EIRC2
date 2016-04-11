#ifndef BASICJOURNALITEM_H
#define BASICJOURNALITEM_H
#include "../BjutLib.h"

#include <QPair>
#include <QVariant>

#include "BjutTypes.h"

class BJUTSHARED_EXPORT JournalItem : public QPair<BjutName, QVariant>
{
public:
    JournalItem(const BjutName & name,
                     const QVariant & var);
};

#endif // BASICJOURNALITEM_H
