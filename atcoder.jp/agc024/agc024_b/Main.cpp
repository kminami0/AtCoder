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
    vector<ll> P(N);
    rep(i, N) cin >> P.at(i);
    map<ll, ll> pos;
    rep(i, N){
        pos[P.at(i)] = i;
    }
    ll c = 1;
    ll d = 1;
    rep(i, N-1){
        if(pos.at(i+2) > pos.at(i+1)){
            c++;
        }
        else{
            chmax(d, c);
            c = 1;
        }
    }
    chmax(d, c);
    cout << N-d << endl;
}