// TEST: 00082_pos_vla_multi_dim
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.2p4
// EXPECT: run_success

int main(void) {
    int n = 3;
    int m = 4;
    int vla[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vla[i][j] = i + j;
        }
    }
    
    if (vla[2][3] != 5) return 1;
    if (sizeof(vla) != n * m * sizeof(int)) return 2;
    
    return 0;
}
