#define ll long long
ll rever(ll num) 
{ 
    ll rev_num = 0; 
    while (num > 0) { 
        rev_num = rev_num*10 + num%10; 
        num = num/10; 
    } 
    return rev_num; 
} 
ll counter(ll x, unordered_map<ll, ll>&hash) {
  queue<ll, ll> q;
  q.push({1, 1});
  int ans = INT_MAX;
  hash[1] = 0;
  while(!q.empty()) {
    pair<ll, ll>p = q.front();
    q.pop();
    int y = p.first;
    int dist = p.second;
    if(x == y )
      ans = min(ans, dist);
    if(dist > ans)
      continue;
    if(y+1 <= x && hash.find(y+1) == hash.end() ) {
      q.push({y+1, dist+1});
      hash(y+1) = 0;
    }
    while(y%10 == 0)
      y = y/10;
    ll r = rever(y);
    if(r > y && r <= x && hash.find(r) == hash.end()) {
      q.push({r, dist + 1});
      hash(r) = 0;
    }
  }
  return ans;
}
