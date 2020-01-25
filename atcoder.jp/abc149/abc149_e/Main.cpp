#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N;
  ll M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N){
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  vector<ll> s(N+1, 0);
  rep(i, N){
    s.at(i+1) = s.at(i) + A.at(i);
  }
  auto calc = [&](int x){
    ll tot = 0;
    ll num = 0;
    rep(i, N){
      int j = lower_bound(A.begin(), A.end(), x-A.at(i)) - A.begin();
      tot += s.at(N) - s.at(j);
      tot += A.at(i) * (ll)(N-j);
      num += N-j;
    }
    return make_pair(tot, num);
  };
  int l = 0;
  int r = 200001;
  while(l + 1 < r){
    int c = (l + r) >> 1;
    if(calc(c).second >= M){
      l = c;
    }
    else{
      r = c;
    }
  }
  auto q = calc(l);
  ll hp = q.first;
  hp -= (q.second - M) * l;
  cout << hp << endl;
}