#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, E;
bool adj[55][55];
int degrees[55];
int nodes[55];
int color[55];
int min_colors;
bool compareNodes(int a, int b) {
    return degrees[a] > degrees[b];
}

// ฟังก์ชัน DFS Backtracking
void solve(int idx, int current_max_c) {
    if (current_max_c >= min_colors) return;
    // Base Case
    if (idx == N) {
        min_colors = min(min_colors, current_max_c);
        return;
    }

    int u = nodes[idx];
    for (int c = 1; c <= current_max_c + 1; c++) {
        bool safe = true;
        
        for (int i = 0; i < idx; i++) {
            int v = nodes[i]; 
            if (adj[u][v] && color[v] == c) {
                safe = false;
                break;
            }
        }

        if (safe) {
            color[u] = c;
            solve(idx + 1, max(current_max_c, c));
            // Backtrack: ถอยกลับมาแก้สี (Reset)
            color[u] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    if (!(cin >> N >> E)) return 0;

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
        degrees[u]++;
        degrees[v]++;
    }

    for (int i = 0; i < N; i++) {
        nodes[i] = i;
    }

    sort(nodes, nodes + N, compareNodes);

    min_colors = N;
    solve(0, 0);

    cout << min_colors << endl;

    return 0;
}