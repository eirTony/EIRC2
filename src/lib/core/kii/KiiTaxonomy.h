#ifndef KIITAXONOMY_H
#define KIITAXONOMY_H

class KiiManager;

class KiiTaxonomy
{
public:
    KiiTaxonomy(KiiManager * manager);

private:
    const KiiManager * cmpManager = 0;
};

#endif // KIITAXONOMY_H
