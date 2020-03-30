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
  ll H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  rep(i, H){
    cin >> S.at(i);
  }
  ll ans = INF;
  bool flag = false;
  bool flag2 = false;
  for (int tmp = 0; tmp < (1 << H-1); tmp++) {
    bitset<9> s(tmp);
    ll g = 0;
    vector<ll> id(H, 0);
    rep(i, H){
      id.at(i) = g;
      if(tmp >> i & 1){
        g++;
      }
    }
    g++;
    vector<ll> now(g, 0);
    ll b = 0;
    ll cut = 0;
    rep(i, W){
      b++;
      rep(j, H){
        now.at(id.at(j)) += S.at(j).at(i) - '0';
      }
      rep(j, g){
        if(now.at(j) > K){
          if(b == 1){
            flag = true;
            break;
          }
          cut++;
          flag2 = true;
          break;
        }
      }
      if(flag){
        break;
      }
      if(flag2){
        rep(j, g){
          now.at(j) = 0;
        }
        i--;
        b = 0;
        flag2 = false;
      }
    }
    if(flag){
      flag = false;
      continue;
    }
    chmin(ans, g-1+cut);
  }
  cout << ans << endl;
}