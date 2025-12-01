#include "bits/stdc++.h"
#include <ios>
#include <vector>

using namespace std;

using ll = long long;

vector<ll> multiply(vector<ll> &A, vector<ll> &B, int k){
    vector<ll> result(4);

    result[0] = (A[0] * B[0] + A[1] * B[2]) % k;
    result[1] = (A[0] * B[1] + A[1] * B[3]) % k;
    result[2] = (A[2] * B[0] + A[3] * B[2]) % k;
    result[3] = (A[2] * B[1] + A[3] * B[3]) % k;

    return result;
}

vector<ll> power(vector<ll> &A, ll n, int k){
    vector<ll> res = {1,0,0,1};
    //identity prop

    while (n > 0) {
        if (n%2 == 1) {
            res = multiply(res, A, k);
        }

        A = multiply(A, A, k);

        n/=2;
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    int mod;
    cin >> n >> mod;

    vector<ll> matrix(4);

    for (int i = 0; i < 4; i++) {
        cin >> matrix[i];
        matrix[i] %= mod;
    }

    vector<ll> result = power(matrix, n, mod);

    for (auto &x : result) {
        cout << x << " ";
    }
    cout << "\n";
}