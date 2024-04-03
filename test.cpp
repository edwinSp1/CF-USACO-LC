#include <iostream>
#include <map>
#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

const bool DEBUG = 1;

//https://codeforces.com/problemset/problem/1946/C
int solve() {
    int n; cin >> n;
    int k; cin >> k;
    set<int> periods; //automatically stored in sorted fashion
    for(int i = 0; i < n; i++) {
        int years; cin >> years;
        periods.insert(years/12);
    }
    int numPeriods = periods.size();
    vector<int> vPeriods;
    for(int period: periods) vPeriods.push_back(period);

    vector<int> diffs;
    for(int i = 0; i < vPeriods.size()-1; i++) {
        diffs.push_back(vPeriods[i+1] - vPeriods[i]-1);
    }
    diffs.push_back(vPeriods[0]);
    sort(diffs.begin(), diffs.end());
    for(int diff: diffs) cout << diff << '\n';
    int ans = 0;
    for(int i = 0; i < numPeriods-k+1; i++) ans += diffs[i]*12;
    ans += numPeriods * 12;
    return ans;
};


signed main() {
    if(DEBUG) {
        freopen("OUTPUT", "w", stdout);
        freopen("INPUT", "r", stdin);
    } 
    int n; 
    cin >> n;
    //int tcs; cin >> tcs;
    //for(int i = 0; i < tcs; i++) 
    cout << solve() << '\n';
}
