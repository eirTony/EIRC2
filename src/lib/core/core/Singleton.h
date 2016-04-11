#ifndef SINGLETON_H
#define SINGLETON_H

/*! @file Singleton.h Macros for Singleton classes
  *
  * Usage:
  *
  * .h File
  *
  * @code
  * class Log
  * {
  *     DECLARE_SINGLETON(Log)
  *     // do NOT declare Log(void);
  *     ...
  * };
  * @endcode
  *
  * .cpp File
  * @code
  * DEFINE_SINGLETON(Log)
  *
  * Log::Log(void)
  * {
  *     ...
  * }
  * @endcode
  *
  */

// TODO: Non-void c'tor()

#define DECLARE_SINGLETON(CLASS) \
    protected: \
        CLASS(void); \
    public: \
        static CLASS * pointer(void); \
        static CLASS & reference(void); \
    private: \
        static CLASS * instance(void); \
        static CLASS * smpClass; \

#define DEFINE_SINGLETON(CLASS) \
    CLASS * CLASS::smpClass = 0; \
    CLASS * CLASS::instance(void) \
    { if ( ! smpClass) smpClass = new CLASS; return smpClass; } \
    CLASS * CLASS::pointer(void) { return instance(); } \
    CLASS & CLASS::reference(void) { return *instance(); } \


#endif // SINGLETON_H
