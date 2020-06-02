#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14 100兆
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
  vector<string> c(H);
  rep(i, H){
    cin >> c.at(i);
  }
  vector<string> p(W, "");
  vector<string> p2(W);
  rep(i, W){
    rep(j, H){
      p.at(i) += c.at(H-1-j).at(i);
    }
    rep(j, H){
      p.at(i) += "#";
    }
  }
  rep(i, W){
    p2.at(i) = p.at(i);
  }
  queue<pair<ll, ll>> s;
  ll ans = 0;
  rep(i, W){
    rep(m, H){
      rep(j, W){
        p.at(j) = p2.at(j);
      }
      ll chain = 0;
      ll score = 0;
      s.push(make_pair(i, m));
      while(!s.empty()){
        while(!s.empty()){
          pair<ll, ll> r = s.front();
          s.pop();
          p.at(r.first).at(r.second) = '!';
        }
        rep(j, W){
          auto it = p.at(j).begin();
          while(it != p.at(j).end()){
            if(*it == '!'){
              it = p.at(j).erase(it);
            }
            else{
              it++;
            }
          }
        }
//        cout << i << " " << score << endl;
//        rep(j, W){
//          cout << p.at(j) << endl;
//        }
        rep(j, H){
          ll rin = 1;
          rep(k, W-1){
            if(p.at(k).at(j) == p.at(k+1).at(j) && isdigit(p.at(k).at(j))){
              rin++;
            }
            else if(isdigit(p.at(k).at(j)) && rin >= K){
              score += pow(2, chain) * rin * (p.at(k).at(j) - '0');
              rep(l, rin){
                s.push(make_pair(k-l, j));
              }
              rin = 1;
            }
            else{
              rin = 1;
            }
          }
          if(isdigit(p.at(W-1).at(j)) && rin >= K){
            score += pow(2, chain) * rin * (p.at(W-1).at(j) - '0');
            rep(l, rin){
              s.push(make_pair(W-1-l, j));
            }
          }
        }
        chain++;
      }
//    cout << i  << " " << m << " " << score << endl;
      chmax(ans, score);
    }
  }
  cout << ans << endl;
}