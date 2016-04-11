/*! @file   JournalItem.cpp BjutLib JournalItem class definitions
 */
#include "JournalItem.h"

JournalItem::JournalItem(const BjutName & name,
                                   const QVariant & var)
    : QPair<BjutName, QVariant>(name, var)
{
}
