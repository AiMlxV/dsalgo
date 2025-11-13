#include <vector>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    v.reserve(A.size() + B.size());

    auto in_res = [&](const T& x) {
        for (const auto& y : v) if (y == x) return true;
        return false;
    };

    for (const auto& x : A) {
        if (!in_res(x)) v.push_back(x);
    }
    for (const auto& x : B) {
        if (!in_res(x)) v.push_back(x);
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    v.reserve(A.size());

    auto in_B = [&](const T& x) {
        for (const auto& y : B) if (y == x) return true;
        return false;
    };
    auto in_res = [&](const T& x) {
        for (const auto& y : v) if (y == x) return true;
        return false;
    };

    for (const auto& x : A) {
        if (in_B(x) && !in_res(x)) v.push_back(x);
    }
    return v;
}