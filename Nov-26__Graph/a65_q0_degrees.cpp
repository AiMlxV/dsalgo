#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// --- FAST I/O BUFFER ---
// This reads a huge chunk of the input file into memory at once
// and parses integers manually. This is the fastest method in C++.
const int BUFFER_SIZE = 1 << 16;
char buffer[BUFFER_SIZE];
int buffer_pos = 0, buffer_len = 0;

inline char read_char() {
    if (buffer_pos == buffer_len) {
        buffer_pos = 0;
        buffer_len = fread(buffer, 1, BUFFER_SIZE, stdin);
        if (buffer_len == 0) return EOF;
    }
    return buffer[buffer_pos++];
}

inline int read_int() {
    int x = 0;
    char c = read_char();
    while (c <= ' ') {
        if (c == EOF) return -1;
        c = read_char();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = read_char();
    }
    return x;
}

int main() {
    int n_nodes = read_int();
    if (n_nodes == -1) return 0;
    vector<int> counts(n_nodes + 1, 0); 

    int current_degree = 0;
    
    for (int i = 0; i < n_nodes; i++) {
        current_degree = 0;
        for (int j = 0; j < n_nodes; j++) {
            int val = read_int(); 
            if (val != 0) {
                current_degree++;
            }
        }
        counts[current_degree]++;
    }

    int max_idx = n_nodes;
    while(max_idx > 0 && counts[max_idx] == 0) {
        max_idx--;
    }

    for (int i = 0; i <= max_idx; i++) {
        printf("%d ", counts[i]);
    }

    return 0;
}