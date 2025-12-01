#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

//find value that equal to from(constant) and change it into to(constant)

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // your code here
    std::stack<std::vector<std::queue<int>>> tmp;

    while (!a.empty()) {

        std::vector<std::queue<int>> b;

        b = a.top();
        a.pop();

        for (int i = 0; i < b.size(); i++) {
            
            std::queue<int> c;
            
            /*----------------------------*/
            while (!b[i].empty()) {
                if (b[i].front() == from) {
                    c.push(to);
                }
                else{
                    c.push(b[i].front());
                }
                b[i].pop();
            }
            /*----------------------------*/
            b[i] = c;
        }
        tmp.push(b);
        }
    while (!tmp.empty()) {
        a.push(tmp.top());
        tmp.pop();
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for (auto it = a.begin(); it != a.end(); it++) {

        std::priority_queue<int> b;

        while(!it->second.first.empty()){

            /*----------------------------*/
            if (it->second.first.top() == from) {
                b.push(to);
            }
            else{
                b.push(it->second.first.top());
            }
            it->second.first.pop();
            /*----------------------------*/
        }
        it->second.first = b;
        /*----------------------------*/
        if (it->second.second == from) {
            it->second.second = to;
        /*----------------------------*/
        }
    }

}

void change_3(std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> &a, int from, int to)
{
    // your code here
    std::set<std::pair<std::list<int>, std::map<int, std::pair<int, string>>>> b;

    for(auto &it : a){

        // first_in_the_pair
        std::list<int> b_first;
        for (auto &x : it.first) {
            /*----------------------------*/
            if (x == from) {
                b_first.push_back(to);
            }
            else{
                b_first.push_back(x);
            }
            /*----------------------------*/
        }

        // second_in_the_pair
        std::map<int, std::pair<int, string>> b_second;
        for (auto &sub_it : it.second) {
            int key_tmp = sub_it.first;
            int value_first_tmp = sub_it.second.first;
            string value_second_tmp = sub_it.second.second;

            /*----------------------------*/
            if (key_tmp == from) {
                key_tmp = to;
            }

            if (value_first_tmp == from) {
                value_first_tmp = to;
            }
            /*----------------------------*/

            b_second[key_tmp] = {value_first_tmp,value_second_tmp};
        }
        b.insert({b_first,b_second});
    }
    a = b;
}

#endif
