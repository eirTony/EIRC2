#ifndef KIICUTTER_H
#define KIICUTTER_H

class KiiManager;

class KiiCutter
{
public:
    KiiCutter(KiiManager * manager);

private:
    const KiiManager * cmpManager = 0;
};

#endif // KIICUTTER_H
