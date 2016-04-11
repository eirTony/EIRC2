#include "Success.h"

Success::Success(void) {;}
Success::Success(const bool yes) : mSuccess(yes) , mIsInitialized(true) {;}

void Success::set(const bool isTrue)
{
    mIsInitialized = true;
    mSuccess = isTrue;
}

bool Success::is(void) const
{
    return mIsInitialized ? mSuccess : false;
}

bool Success::yes(void)
{
    set(true);
    return is();
}

bool Success::no(void)
{
    set(false);
    return is();
}

bool Success::expect(const bool isTrue)
{
    if (mIsInitialized) mSuccess &= isTrue;
    return is();
}

void Success::test(const bool isTrue)
{
    if ( ! isTrue) mIsInitialized = true, mSuccess = false;
}

Success Success::tested(void)
{
    if ( ! mIsInitialized) mIsInitialized = mSuccess = true;
    return *this;
}

Success::operator bool (void) const
{
    return is();
}
