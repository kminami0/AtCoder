#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
int main()
{
    ll N;
    cin >> N;
    vector<string> s(N, "");
    rep(i, N){
        rep(j, N){
            s.at(i) += ".";
        }
    }
    rep(i, N){
        rep(j, 3){
            s.at(i).at((3*i+j)%N) = '#';
        }
    }
    if(N % 3 != 0){
        swap(s.at(0), s.at(N/3-1));
        swap(s.at(N-N/3), s.at(N-1));
    }
    rep(i, N){
        cout << s.at(i) << '\n';
    }
}