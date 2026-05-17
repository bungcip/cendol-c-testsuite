// TEST: 10035_hash_hash_stringification
// CATEGORY: preprocessor
// STANDARD: C11

#define CONCAT(a, b) a ## b
#define MAKE_STR(x) #x
#define EVAL_STR(x) MAKE_STR(x)

#define HASH_OP # ## #

// This tests that HASH_OP correctly expands to ## through token pasting
// and then is stringified by EVAL_STR.
const char *s = EVAL_STR(left HASH_OP right);

#define EMPTY
#define HASH_OP_SPACED EMPTY # ## # EMPTY
const char *s2 = EVAL_STR(foo HASH_OP_SPACED bar);
