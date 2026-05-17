// TEST: pre_short_circuit
// CATEGORY: preprocessor
// STANDARD: C11

#if 1 ? 1 : (1/0)
int ternary_true = 1;
#endif

#if 0 ? (1/0) : 1
int ternary_false = 1;
#endif

#if 0 && (1/0)
int and_false = 0;
#endif

#if 1 || (1/0)
int or_true = 1;
#endif

#if (1 ? 1 : 1u) < -1
int unsigned_promo = 1;
#endif
