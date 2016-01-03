#define RUBY_PROGRAM_VERSION_MAJOR RUBY_API_VERSION_MAJOR
#define RUBY_PROGRAM_VERSION_MINOR RUBY_API_VERSION_MINOR
#define RUBY_PROGRAM_VERSION_TEENY 0

#define RUBY_BUILD_VERSION_STR_2(v) STRINGIZE(v##_MAJOR)"."STRINGIZE(v##_MINOR)
#define RUBY_BUILD_VERSION_STR_3(v) RUBY_BUILD_VERSION_STR_2(v)"."STRINGIZE(v##_TEENY)

#define RUBY_PROGRAM_VERSION RUBY_BUILD_VERSION_STR_3(RUBY_PROGRAM_VERSION)
#define RUBY_VERSION RUBY_PROGRAM_VERSION
#define RUBY_RELEASE_DATE RUBY_RELEASE_YEAR_STR"-"RUBY_RELEASE_MONTH_STR"-"RUBY_RELEASE_DAY_STR
#define RUBY_PATCHLEVEL -1

#define RUBY_RELEASE_YEAR 2016
#define RUBY_RELEASE_MONTH 1
#define RUBY_RELEASE_DAY 3

#include "ruby/version.h"

#ifndef TOKEN_PASTE
#define TOKEN_PASTE(x,y) x##y
#endif
#define ONLY_ONE_DIGIT(x) TOKEN_PASTE(10,x) < 1000
#define ZERO_STR "0"
#define RUBY_RELEASE_YEAR_STR STRINGIZE(RUBY_RELEASE_YEAR)
#if ONLY_ONE_DIGIT(RUBY_RELEASE_MONTH)
#define RUBY_RELEASE_MONTH_STR ZERO_STR STRINGIZE(RUBY_RELEASE_MONTH)
#else
#define RUBY_RELEASE_MONTH_STR STRINGIZE(RUBY_RELEASE_MONTH)
#endif
#if ONLY_ONE_DIGIT(RUBY_RELEASE_DAY)
#define RUBY_RELEASE_DAY_STR ZERO_STR STRINGIZE(RUBY_RELEASE_DAY)
#else
#define RUBY_RELEASE_DAY_STR STRINGIZE(RUBY_RELEASE_DAY)
#endif

#define RUBY_LIB_VERSION_2 RUBY_BUILD_VERSION_STR_2(RUBY_API_VERSION)
#define RUBY_LIB_VERSION_3 RUBY_BUILD_VERSION_STR_3(RUBY_API_VERSION)
#if !defined RUBY_LIB_VERSION && defined RUBY_LIB_VERSION_STYLE
# if RUBY_LIB_VERSION_STYLE == 3
#   define RUBY_LIB_VERSION RUBY_LIB_VERSION_3
# elif RUBY_LIB_VERSION_STYLE == 2
#   define RUBY_LIB_VERSION RUBY_LIB_VERSION_2
# endif
#endif

#if RUBY_PATCHLEVEL == -1
#define RUBY_PATCHLEVEL_STR "dev"
#else
#define RUBY_PATCHLEVEL_STR "p"STRINGIZE(RUBY_PATCHLEVEL)
#endif

#ifndef RUBY_REVISION
# include "revision.h"
#endif
#ifndef RUBY_REVISION
# define RUBY_REVISION 0
#endif

#if RUBY_REVISION
# if RUBY_PATCHLEVEL == -1
#  ifndef RUBY_BRANCH_NAME
#   define RUBY_BRANCH_NAME "trunk"
#  endif
#  define RUBY_REVISION_STR " "RUBY_BRANCH_NAME" "STRINGIZE(RUBY_REVISION)
# else
#  define RUBY_REVISION_STR " revision "STRINGIZE(RUBY_REVISION)
# endif
#else
# define RUBY_REVISION_STR ""
#endif

# define RUBY_DESCRIPTION	    \
    "ruby "RUBY_VERSION		    \
    RUBY_PATCHLEVEL_STR		    \
    " ("RUBY_RELEASE_DATE	    \
    RUBY_REVISION_STR") "	    \
    "["RUBY_PLATFORM"]"
# define RUBY_COPYRIGHT		    \
    "ruby - Copyright (C) "	    \
    STRINGIZE(RUBY_BIRTH_YEAR)"-"   \
    STRINGIZE(RUBY_RELEASE_YEAR)" " \
    RUBY_AUTHOR
