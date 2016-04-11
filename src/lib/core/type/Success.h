#ifndef SUCCESS_H
#define SUCCESS_H
#include "TypeLib.h"

class TYPESHARED_EXPORT Success
{
public:
    Success(void);
    Success(const bool yes);
    void set(const bool isTrue=true);
    bool is(void) const;
    bool yes(void);
    bool no(void);
    bool expect(const bool isTrue);
    void test(const bool isTrue);
    Success tested(void);
    operator bool (void) const;

private:
    bool mSuccess = false;
    bool mIsInitialized = false;
};

#endif // SUCCESS_H
