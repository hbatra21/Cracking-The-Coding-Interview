#include<bits/stdc++.h>
using namespace std;
int warships(int input1, input2) {
  int L = input1, M = input2;
  queue<pair<int, int>> q;
  pair<int, int> p;
  int count = 0, y, i;
  q.push({2, 0});
  while(!q.empty()) {
    p = q.front();
    q.pop();
    count = (count+1)%M;
    if(p.second+1 < L) {
      y = ((p.first * p.first)+1)%M;
      for(i = 0; i < y; i++) {
        q.push({ i, p.second+1});
      }
    }
  }
    return count;
}
