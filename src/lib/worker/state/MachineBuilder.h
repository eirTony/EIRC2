#ifndef MACHINEBUILDER_H
#define MACHINEBUILDER_H

#include <type/Boolean.h>

#include "AbstraceStateMachine.h" // for now, later:
// #include "StateKii.h"

#define DECLARE_MACHINESTATES(name, parent, flags) \
    private:  \
        QQState * mp##name; \
    signals: \
        void transition##name(Boolean running); \
        void enter##name(void); \
        void enter##name(StateKey fromKey); \
        void leave##name(void); \
        void leave##name(StateKey toKey); \
    protected: \
        virtual void do##name(void); \

#define STATTEKEYLIST_MACHINESTATES(name, parent, flags) \
    public: \
        const StateKey key##name = StateKey(name); \

#define STATEMACHINE_DECLARESTATES(def) def(DECLARE_MACHINESTATES)

#define STATEMACHINE_DECLAREKEYS(def) def(DECLARE_MACHINESTATES)

#define STATEMACHINE_DEFINEKEYS() def(STATEKEYLIST_MACHINESTATES)

#endif // MACHINEBUILDER_H
