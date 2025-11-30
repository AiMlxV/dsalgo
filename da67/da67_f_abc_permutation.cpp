// #include "bits/stdc++.h"

// using namespace std;

// vector<string> result;

// void perMuABC(int n, int na, int nb ,int nc, string current, int c_a, int c_b ,int c_c){
//     if (current.length() == n) {
//         result.push_back(current);
//         return;
//     }

//     if (c_a < na) {
//         perMuABC(n, na, nb, nc, current + 'A', c_a+1, c_b, c_c);
//     }

//     if (c_b < nb) {
//         perMuABC(n, na, nb, nc, current + 'B', c_a, c_b+1, c_c);
//     }

//     if (c_c < nc) {
//         perMuABC(n, na, nb, nc, current + 'C', c_a, c_b, c_c+1);
//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n,na,nb,nc;
//     cin >> n >> na >> nb >> nc;

//     perMuABC(n,na,nb,nc,"", 0,0,0);

//     cout << result.size() << "\n";

//     for(auto &word : result){
//         cout << word << "\n";
//     }
// }


//under is experiment something
#include <cstdio>
#include <cstring>

using namespace std;

// --- FAST I/O CONFIG ---
const int BUFFER_SIZE = 1 << 16;
char buffer[BUFFER_SIZE];
int buffer_pos = 0, buffer_len = 0;
char out_buffer[BUFFER_SIZE];
int out_pos = 0;

inline void flush_out() {
    if (out_pos) {
        std::fwrite(out_buffer, 1, out_pos, stdout);
        out_pos = 0;
    }
}

inline void write_char(char c) {
    if (out_pos == BUFFER_SIZE) flush_out();
    out_buffer[out_pos++] = c;
}

inline void write_int(int x) {
    if (x == 0) {
        write_char('0');
        return;
    }
    if (x < 0) {
        write_char('-');
        x = -x;
    }
    char tmp[12];
    int len = 0;
    while (x > 0) {
        tmp[len++] = static_cast<char>('0' + (x % 10));
        x /= 10;
    }
    while (len--) write_char(tmp[len]);
}

inline char read_char() {
    if (buffer_pos == buffer_len) {
        buffer_pos = 0;
        buffer_len = std::fread(buffer, 1, BUFFER_SIZE, stdin);
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

int n, na, nb, nc;
char s[15];

int count_perm(int len, int ca, int cb, int cc) {
    if (len == n) return 1;
    int res = 0;
    if (ca < na) res += count_perm(len + 1, ca + 1, cb, cc);
    if (cb < nb) res += count_perm(len + 1, ca, cb + 1, cc);
    if (cc < nc) res += count_perm(len + 1, ca, cb, cc + 1);
    return res;
}

void solve(int len, int ca, int cb, int cc) {
    if (len == n) {
        if (out_pos + n + 1 >= BUFFER_SIZE) flush_out();
        
        for (int i = 0; i < n; i++) {
            out_buffer[out_pos++] = s[i];
        }
        out_buffer[out_pos++] = '\n';
        return;
    }

    if (ca < na) {
        s[len] = 'A';
        solve(len + 1, ca + 1, cb, cc);
    }

    if (cb < nb) {
        s[len] = 'B';
        solve(len + 1, ca, cb + 1, cc);
    }

    if (cc < nc) {
        s[len] = 'C';
        solve(len + 1, ca, cb, cc + 1);
    }
}

int main() {
    n = read_int();
    na = read_int();
    nb = read_int();
    nc = read_int();

    if (n == -1) return 0;

    int total = count_perm(0, 0, 0, 0);
    write_int(total);
    write_char('\n');

    if (total > 0) {
        solve(0, 0, 0, 0);
    }

    flush_out();

    return 0;
}