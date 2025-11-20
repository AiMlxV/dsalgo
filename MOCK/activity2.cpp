#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    map<string, set<string>> events;
    map<string, string> p_state;
    
    vector<tuple<string, string, string, bool>> history;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "ADDEVENT") {
            string e;
            cin >> e;
            if (events.find(e) == events.end()){
                events[e];
            }
        }
        else if (cmd == "REGISTER") {
            string e, name;
            cin >> e >> name;
            
            if (events.find(e) == events.end()){
                events[e];
            } 

            bool is_success = false;

            if (p_state.find(name) == p_state.end()) {
                events[e].insert(name);
                p_state[name] = e;
                is_success = true;
            }
            
            history.push_back({ "REGISTER", e, name, is_success });
        }
        else if (cmd == "CANCEL") {
            string e, name;
            cin >> e >> name;

            bool is_success = false;

            if (events.find(e) != events.end() && events[e].count(name)) {
                events[e].erase(name);
                p_state.erase(name);
                is_success = true;
            }

            history.push_back({ "CANCEL", e, name, is_success });
        }
        else if (cmd == "SHOW") {
            string e;
            cin >> e;
            if (events.find(e) != events.end()) {
                for (auto &n : events[e]) {
                    cout << n << " ";
                }
            }
            cout << "\n";
        }
        else if (cmd == "UNDO") {
            if (history.empty()) {
                continue;
            }
            
            auto [last_cmd, e, name, was_success] = history.back();
            history.pop_back();

            if (!was_success) continue;

            if (last_cmd == "REGISTER") {
                events[e].erase(name);
                p_state.erase(name);
            } 
            else if (last_cmd == "CANCEL") {
                events[e].insert(name);
                p_state[name] = e;
            }
        }
    }
    return 0;
}