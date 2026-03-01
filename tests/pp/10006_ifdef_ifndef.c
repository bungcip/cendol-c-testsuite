// TEST: 10006_ifdef_ifndef
// CATEGORY: preprocessor
// STANDARD: C11

#define MACRO
#ifdef MACRO
int x = 1;
#endif

#ifndef MACRO
int y = 1;
#else
int y = 0;
#endif

#undef MACRO
#ifdef MACRO
int z = 1;
#else
int z = 0;
#endif
