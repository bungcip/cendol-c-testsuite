// TEST: 00116_pre_empty_elif
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.1
// STANDARD_TEXT:
// "The sequence of preprocessing tokens... is processed just as a 
// series of if directives..."
// EXPECT: run_success

#if 0
#elif 1
#endif
int main(void) { return 0; }
