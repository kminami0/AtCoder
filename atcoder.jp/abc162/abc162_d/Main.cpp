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

unsigned euclidean_gcd(unsigned a, unsigned b) {
  if(a < b) return euclidean_gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(){
  ll N;
  string S;
  cin >> N >> S;
  vector<ll> R(N+1, 0), G(N+1, 0), B(N+1, 0);
  rep(i, N){
    if(S.at(i) == 'R'){
      R.at(i+1) = R.at(i)+1;
      G.at(i+1) = G.at(i);
      B.at(i+1) = B.at(i);
    }
    if(S.at(i) == 'G'){
      R.at(i+1) = R.at(i);
      G.at(i+1) = G.at(i)+1;
      B.at(i+1) = B.at(i);
    }
    if(S.at(i) == 'B'){
      R.at(i+1) = R.at(i);
      G.at(i+1) = G.at(i);
      B.at(i+1) = B.at(i)+1;
    }
  }
  ll ans = 0;
  rep2(i, 1, N-1){
    if(S.at(i) == 'R'){
      ll eq = 0;
      rep2(j, 1, min(i, N-i-1)+1){
        if(S.at(i-j) == 'G' && S.at(i+j) == 'B'){
          eq++;
        }
        if(S.at(i-j) == 'B' && S.at(i+j) == 'G'){
          eq++;
        }
      }
      ans += G.at(i) * (B.at(N) - B.at(i+1)) + B.at(i) * (G.at(N) - G.at(i+1)) - eq;
    }
    if(S.at(i) == 'G'){
      ll eq = 0;
      rep2(j, 1, min(i, N-i-1)+1){
        if(S.at(i-j) == 'B' && S.at(i+j) == 'R'){
          eq++;
        }
        if(S.at(i-j) == 'R' && S.at(i+j) == 'B'){
          eq++;
        }
      }
      ans += B.at(i) * (R.at(N) - R.at(i+1)) + R.at(i) * (B.at(N) - B.at(i+1)) - eq;
    }
    if(S.at(i) == 'B'){
      ll eq = 0;
      rep2(j, 1, min(i, N-i-1)+1){
        if(S.at(i-j) == 'R' && S.at(i+j) == 'G'){
          eq++;
        }
        if(S.at(i-j) == 'G' && S.at(i+j) == 'R'){
          eq++;
        }
      }
      ans += R.at(i) * (G.at(N) - G.at(i+1)) + G.at(i) * (R.at(N) - R.at(i+1)) - eq;
    }
  }
  cout << ans << endl;
}