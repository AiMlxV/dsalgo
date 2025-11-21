#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, start;
    if (!(cin >> n >> m >> start)) return 0;

    vector<pair<int, int>> changes(n);
    int max_change_day = 0;
    for (auto &ch : changes) {
        cin >> ch.first >> ch.second;
        max_change_day = max(max_change_day, ch.first);
    }
    sort(changes.begin(), changes.end());

    vector<pair<long long, int>> queries(m);
    int max_query_day = 0;
    for (auto &q : queries) {
        cin >> q.first >> q.second;
        max_query_day = max(max_query_day, q.second);
    }

    int limit = max({100000, max_change_day, max_query_day});
    vector<int> daily(limit + 1);
    int idx = 0, rate = start;
    for (int day = 0; day <= limit; ++day) {
        while (idx < n && changes[idx].first == day) {
            rate = changes[idx].second;
            ++idx;
        }
        daily[day] = rate;
    }

    vector<long long> prefix(limit + 2, 0);
    for (int day = 0; day <= limit; ++day) {
        prefix[day + 1] = prefix[day] + daily[day];
    }

    vector<int> answers(m);
    for (int i = 0; i < m; ++i) {
        long long price = queries[i].first;
        int scam_day = min(queries[i].second, limit);

        auto it = lower_bound(prefix.begin() + 1, prefix.end(), price);
        int day = int(it - prefix.begin()) - 1;
        if (it != prefix.end() && day <= scam_day) {
            answers[i] = day;
            continue;
        }

        long long target = prefix[scam_day + 1] + price;
        it = lower_bound(prefix.begin() + scam_day + 2, prefix.end(), target);
        answers[i] = int(it - prefix.begin()) - 1;
    }

    for (int i = 0; i < m; ++i) {
        if (i) cout << ' ';
        cout << answers[i];
    }
    cout << '\n';
    return 0;
}