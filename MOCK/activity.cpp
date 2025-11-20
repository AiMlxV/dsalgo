#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Pool 1: เก็บรายชื่อกิจกรรมที่มีอยู่จริง
    set<string> existing_events;

    // Pool 2: เก็บคำสั่งที่ผ่านการตรวจสอบแล้ว (Command Pool)
    vector<tuple<string, string, string>> command_pool;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "ADDEVENT") {
            string e;
            cin >> e;
            existing_events.insert(e);
        } 
        else if (cmd == "REGISTER") {
            string e, name;
            cin >> e >> name;

            // กฎ 1: ถ้ากิจกรรมยังไม่มี ให้สร้างใหม่
            existing_events.insert(e);

            // กฎ 2: คนหนึ่งอยู่ได้แค่กิจกรรมเดียว -> ต้อง "Replay" ดูว่าตอนนี้คนนี้ไม่ว่างหรือเปล่า
            bool is_busy = false;
            
            map<string, string> current_person_status;
            for (const auto& t : command_pool) {
                string type = get<0>(t);
                string ev = get<1>(t);
                string p = get<2>(t);
                if (type == "REGISTER") current_person_status[p] = ev;
                else if (type == "CANCEL") current_person_status.erase(p);
            }

            if (current_person_status.find(name) != current_person_status.end()) {
                is_busy = true;
            }

            if (!is_busy) {
                command_pool.push_back(make_tuple("REGISTER", e, name));
            }
        } 
        else if (cmd == "CANCEL") {
            string e, name;
            cin >> e >> name;

            bool is_in_event = false;

            map<string, string> current_person_status;
            for (const auto& t : command_pool) {
                string type = get<0>(t);
                string ev = get<1>(t);
                string p = get<2>(t);
                if (type == "REGISTER") current_person_status[p] = ev;
                else if (type == "CANCEL") current_person_status.erase(p);
            }
            
            if (current_person_status.find(name) != current_person_status.end()) {
                if (current_person_status[name] == e) {
                    is_in_event = true;
                }
            }

            if (is_in_event) {
                command_pool.push_back(make_tuple("CANCEL", e, name));
            }
        } 
        else if (cmd == "SHOW") {
            string target_event;
            cin >> target_event;

            if (existing_events.find(target_event) == existing_events.end()) {
                cout << endl;
            } else {
                map<string, set<string>> final_events;
                for (const auto& t : command_pool) {
                    string type = get<0>(t);
                    string ev = get<1>(t);
                    string p = get<2>(t);
                    if (type == "REGISTER") final_events[ev].insert(p);
                    else if (type == "CANCEL") final_events[ev].erase(p);
                }

                for (const auto& p_name : final_events[target_event]) {
                    cout << p_name << " ";
                }
                cout << endl;
            }
        } 
        else if (cmd == "UNDO") {
            if (!command_pool.empty()) {
                command_pool.pop_back();
            }
        }
    }

    return 0;
}