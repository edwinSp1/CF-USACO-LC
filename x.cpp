#include <iostream>
#include <map>
#include <bits/stdc++.h>
#include <deque>
#define INF 10000000
using namespace std;

const bool DEBUG = 1;

int solve() {
    string s; cin >> s;
    int n = s.size();
    int ans = 0;
    for(int d = 0; d <= n/2; d++) {
        int count = 0;
        for(int i = 0; i < d; i++) {
            count += s[i] == s[i+d] or s[i] == '?' or s[i+d] == '?';
        }
        if(count == d) ans = d*2;
        for(int i = d; i < n-d; i++) {
            count += s[i] == s[i+d] or s[i] == '?' or s[i+d] == '?';
            count -= s[i-d] == s[i] or s[i] == '?' or s[i-d] == '?';
            if(count == d) ans = d*2;
        }
    }
    return ans;
};


signed main() {
    if(DEBUG) {
        freopen("OUTPUT", "w", stdout);
        freopen("INPUT", "r", stdin);
    } 
    int tcs; cin >> tcs;
    for(int i = 0; i < tcs; i++) 
    cout << solve() << '\n';
}