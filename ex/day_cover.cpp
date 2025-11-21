#include <bits/stdc++.h>
using namespace std;

vector<int> v[29];
int vst[1009];
int n, m;
int ans = INT_MAX;

void solve(int now, int cnt, int cst)
{
    if (cnt == n)
    {
        ans = min(ans, cst);
        return;
    }
    if (now == m)
        return;
    if (cst >= ans)
        return;
    for (int job : v[now])
    {
        if (vst[job] == 0)
            cnt++;
        vst[job]++;
    }
    solve(now + 1, cnt, cst + 1);
    for (int job : v[now])
    {
        vst[job]--;
        if (vst[job] == 0)
            cnt--;
    }
    solve(now + 1, cnt, cst);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int k;
        cin >> k;
        while (k--)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    solve(0, 0, 0);
    cout << ans;
    return 0;
}
