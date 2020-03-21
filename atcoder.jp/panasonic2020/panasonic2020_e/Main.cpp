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

bool check(string a, string b, ll x){
  if(sz(a) < x){
    return true;
  }
  long long unsigned int sb = sz(b);
  rep(i, min(sz(a)-x, sb)){
    if(b.at(i) == '?' || a.at(x+i) == '?'){
      continue;
    }
    if(b.at(i) == a.at(x+i)){
      continue;
    }
    return false;
  }
  return true;
}

int main(){
  string a, b, c;
  cin >> a >> b >> c;
  vector<bool> ab(4001, false);
  vector<bool> ac(4001, false);
  vector<bool> ba(4001, false);
  vector<bool> bc(4001, false);
  vector<bool> ca(4001, false);
  vector<bool> cb(4001, false);
  rep(i, 4001){
    if(check(a, b, i)){
      ab.at(i) = true;
    }
  }
  rep(i, 4001){
    if(check(a, c, i)){
      ac.at(i) = true;
    }
  }
  rep(i, 4001){
    if(check(b, a, i)){
      ba.at(i) = true;
    }
  }
  rep(i, 4001){
    if(check(b, c, i)){
      bc.at(i) = true;
    }
  }
  rep(i, 4001){
    if(check(c, a, i)){
      ca.at(i) = true;
    }
  }
  rep(i, 4001){
    if(check(c, b, i)){
      cb.at(i) = true;
    }
  }
  ll ans = 6000;
  ll sa = sz(a);
  ll sb = sz(b);
  ll sc = sz(c);
  //abc
  rep(i, 2001){
    rep(j, 2001){
      if(ab.at(i) && bc.at(j) && ac.at(i+j)){
        chmin(ans, max(sa, max(sb+i, sc+i+j)));
      }
    }
  }
  //acb
  rep(i, 2001){
    rep(j, 2001){
      if(ac.at(i) && cb.at(j) && ab.at(i+j)){
        chmin(ans, max(sa, max(sc+i, sb+i+j)));
      }
    }
  }
  //bac
  rep(i, 2001){
    rep(j, 2001){
      if(ba.at(i) && ac.at(j) && bc.at(i+j)){
        chmin(ans, max(sb, max(sa+i, sc+i+j)));
      }
    }
  }
  //bca
  rep(i, 2001){
    rep(j, 2001){
      if(bc.at(i) && ca.at(j) && ba.at(i+j)){
        chmin(ans, max(sb, max(sc+i, sa+i+j)));
      }
    }
  }
  //cab
  rep(i, 2001){
    rep(j, 2001){
      if(ca.at(i) && ab.at(j) && cb.at(i+j)){
        chmin(ans, max(sc, max(sa+i, sb+i+j)));
      }
    }
  }
  //cba
  rep(i, 2001){
    rep(j, 2001){
      if(cb.at(i) && ba.at(j) && ca.at(i+j)){
        chmin(ans, max(sc, max(sb+i, sa+i+j)));
      }
    }
  }
  cout << ans << endl;
}