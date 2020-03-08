#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

int main(){
  ll N, P;
  string S;
  cin >> N >> P >> S;
  reverse(all(S));
  vector<ll> d(sz(S));
  rep(i, sz(S)){
    d.at(i) = S.at(i) - '0';
  }
  ll ans = 0;
  if(P == 2 || P == 5){
    reverse(all(d));
    rep(i, sz(d)){
      if(d.at(i) % P == 0){
        ans += i+1;
      }
    }
    cout << ans << endl;
    return 0;
  }
  vector<ll> acc(sz(S)+1, 0);
  vector<ll> buc(P, 0);
  vector<ll> pow10(sz(S));
  ll s = 1;
  rep(i, sz(S)){
    pow10.at(i) = s;
    s *= 10;
    s %= P;
  }
  buc.at(0) = 1;
  rep(i, sz(S)){
    ll t = d.at(i) % P;
    t *= pow10.at(i);
    acc.at(i+1) = (acc.at(i) + t) % P;
    buc.at(acc.at(i+1))++;
  }
  rep(i, P){
    ans += buc.at(i) * (buc.at(i)-1) / 2;
  }
  cout << ans << endl;
}