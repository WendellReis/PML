#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

double cost(const vector<pair<int, int>> &v, const vector<int> &pi) {
    double res = 0;

    for (int i = 1; i < pi.size(); i++) {
        res += (v.size()-i+1)*(sqrt(pow(v[pi[i]].F - v[pi[i - 1]].F, 2) + pow(v[pi[i]].S - v[pi[i - 1]].S, 2)));
    }

    return res + sqrt(pow(v[pi[0]].F - v[pi[pi.size() - 1]].F, 2) + pow(v[pi[0]].S - v[pi[pi.size() - 1]].S, 2));
}

int main() {
    vector<pair<int, int>> v = {
        {53, 62}, {78, 31}, {21, 5}, {41, 54}, {49, 26}, {52, 31},
        {93, 37}, {81, 77}, {99, 77}, {42, 14}, {37, 60}, {44, 7},
        {17, 15}, {1, 64}, {84, 36}, {79, 90}, {79, 77}, {33, 15},
        {69, 24}, {6, 74}, {14, 51}
    };

    vector<int> pi = {6, 14, 1, 18, 5, 4, 9, 11, 17, 2, 12, 20, 13, 19, 10, 3, 0, 16, 7, 15, 8};
    
    cout << fixed << setprecision(2) << cost(v, pi) << endl;

    return 0;
}
