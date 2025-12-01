#include <functional>
#include <queue>
#include <utility>
#include <vector>
#include <cstdio>

using namespace std;

#define INF 1e9

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


int main(){
    int n,m,k;
    n = read_int();
    m = read_int();
    k = read_int();

    vector<int> attacked_node(k);
    for (int i = 0; i < k; i++) {
        attacked_node[i] = read_int();
    }

    vector<int> hacking_time(n);
    for (int i = 0; i < n; i++) {
        hacking_time[i] = read_int();
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u,v;
        u = read_int();
        v = read_int();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n,INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto &startnode : attacked_node) {
        dist[startnode] = hacking_time[startnode];
        pq.push({hacking_time[startnode],startnode});
    }

    while (!pq.empty()) {
        int current_time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (current_time > dist[u]) {
            continue;
        }

        for (int &v: adj[u]) {
            int ntime = current_time + hacking_time[v];

            if (ntime < dist[v]) {
                dist[v] = ntime;
                pq.push({dist[v],v});
            }
        }
    }
    
    int max_time = 0;
    for (auto &x: dist) {
        if (x > max_time) {
            max_time = x;
        }
    }

    write_int(max_time);
    write_char('\n');
    flush_out();
}