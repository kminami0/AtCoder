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
  string S;
  ll Q;
  cin >> S >> Q;
  vector<ll> T(Q, 0);
  vector<ll> F(Q, 0);
  vector<char> C(Q, 'X');
  rep(i, Q){
    cin >> T.at(i);
    if(T.at(i) == 2){
      cin >> F.at(i) >> C.at(i);
    }
  }
  bool rev = false;
  deque<char> ans;
  rep(i, sz(S)){
    ans.push_back(S.at(i));
  }
  rep(i, Q){
    if(T.at(i) == 1){
      rev = !rev;
    }
    else{
      if(!rev){
        if(F.at(i) == 1){
          ans.push_front(C.at(i));
        }
        else{
          ans.push_back(C.at(i));
        }
      }
      else{
        if(F.at(i) == 1){
          ans.push_back(C.at(i));
        }
        else{
          ans.push_front(C.at(i));
        }
      }
    }
  }
  ll s = sz(ans);
  if(!rev){
    rep(i, s){
      cout << ans.front();
      ans.pop_front();
    }
  }
  else{
    rep(i, s){
      cout << ans.back();
      ans.pop_back();
    }
  }
}