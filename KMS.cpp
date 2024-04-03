/*
TASK: nuggets
ID: 4400331
LANG: C++17
*/

#include <iostream>
#include <string.h>
#include <numeric>
#include <algorithm>
using namespace std;

#define MAX 256*256 - 256-256

int main() {
  
  freopen("INPUT", "r", stdin);
  freopen("OUTPUT", "w", stdout);
  int n; cin >> n;
  int sizes[n];


  for(int i = 0; i < n; i++) {
    cin >> sizes[i];
    if(sizes[i] == 1) {
      cout << 0 << '\n';
      return 1;
    }
  }
  int cur = sizes[0];
  for(int i = 1; i < n; i++) cur = __gcd(cur, sizes[i]);
  if(cur != 1) {
    cout << 0 << '\n';
    return 1;
  }
  
  
  int canmake[MAX+1];
  memset(canmake, 0, MAX+1);
  canmake[0] = 1;

  for(int i = 0; i <= MAX; i++) 
    if(canmake[i]) 
      for(int num: sizes) 
        if(i+num <= MAX)
          canmake[i+num] = 1;

  
  for(int i = MAX; i >= 0; i--) {
    if(!canmake[i]) {
      cout << i << '\n';
      return 1;
    }
  }
  cout << 0 << '\n';
  
}
/*
2
11
011111
*/