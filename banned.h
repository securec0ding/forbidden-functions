/**
 * This header poisons functions that often result in security vulnerabilities. This ensures that any use of
 * these dangerous functions in code appearing after this header is included will results in a compiler error.
 */

#ifndef _INC_BANNED
#define _INC_BANNED

#ifdef __GNUC__
    #pragma GCC poison strcpy wcscpy
    #pragma GCC poison strcat wcscat
    #pragma GCC poison wsprintf sprintf swprintf
    #pragma GCC poison vsprintf vswprintf
    #pragma GCC poison strncpy wcsncpy
    #pragma GCC poison strncat wcsncat
    #pragma GCC poison strtok wcstok
    #pragma GCC poison scanf wscanf sscanf swscanf
    #pragma GCC poison gets
    #pragma GCC poison strlen wcslen
    #pragma GCC poison memcpy
#endif

#endif  /* _INC_BANNED */