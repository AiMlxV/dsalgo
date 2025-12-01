#include "bits/stdc++.h"

using namespace std;

bool check_virus(string current, int dna_size){
    if (dna_size == 2) {
        return current == "01";
    }

    string left_string = current.substr(0,dna_size/2);
    string right_string = current.substr(dna_size/2,dna_size/2);

    bool is_right_valid = check_virus(right_string, dna_size/2);
    if (!is_right_valid) return false;
    
    string r_left_string = left_string;
    reverse(r_left_string.begin(),r_left_string.end());

    return check_virus(left_string, dna_size/2) || check_virus(r_left_string, dna_size/2);
}

int main(){
    int k,n,k_of_2;
    string dna,dna_remain;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        dna.clear();
        for (int j = 0; j < 1<<k; j++) {
            cin >> dna_remain;
            dna += dna_remain;
        }
        if(check_virus(dna,dna.size())){
            cout << "yes" << "\n";
        }
        else {
            cout << "no" << "\n";
        }
    }
}