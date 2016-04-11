#ifndef BASICSINGLETON_H
#define BASICSINGLETON_H

/*! @file BasicSingleton.h Macros for Basic Singleton classes
  * @todo Non-void c'tor
  *
  * Usage:
  *
  * .h File
  *
  * @code
  * class Log
  * {
  *     DECLARE_BASICSINGLETON(Log) // ctor & more
  *     // do NOT declare Log(void);
  *     ...
  * };
  * @endcode
  *
  * .cpp File
  * @code
  * DEFINE_BASICSINGLETON(Log)
  *
  * Log::Log(void)
  * {
  *     ...
  * }
  * @endcode
  *
  */
#define DECLARE_BASICSINGLETON(CLASS) \
    protected: \
        CLASS(void); \
    public: \
        static CLASS * pointer(void); \
        static CLASS & reference(void); \
    private: \
        static CLASS * instance(void); \
        static CLASS * smpClass; \

#define DEFINE_BASICSINGLETON(CLASS) \
    CLASS * CLASS::smpClass = 0; \
    CLASS * CLASS::instance(void) \
    { if ( ! smpClass) smpClass = new CLASS; return smpClass; } \
    CLASS * CLASS::pointer(void) { return instance(); } \
    CLASS & CLASS::reference(void) { return *instance(); } \

#endif // BASICSINGLETON_H
