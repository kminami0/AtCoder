#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
    vector<ll> color(2*N);
    rep(i, N) cin >> color.at(i);
    rep(i, N){
        color.at(i+N) = color.at(i);
    }
    ll seq = 0;
    ll tmp = 1;
    rep(i, 2*N-1){
        if(color.at(i) == color.at(i+1)){
            tmp++;
        }
        else{
            chmax(seq, tmp);
            tmp = 1;
        }
    }
    chmax(seq, tmp);
    if(seq == 2*N){
        cout << -1 << endl;
    }
    else{
        cout << (seq-1)/2 +1 << endl;
    }
}