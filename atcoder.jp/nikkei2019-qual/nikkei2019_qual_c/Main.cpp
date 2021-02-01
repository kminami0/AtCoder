#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    vector<pair<ll, ll>> happy(N);
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
        happy.at(i) = {A.at(i)+B.at(i), i};
    }
    sort(all(happy));
    reverse(all(happy));
    ll ah = 0;
    ll th = 0;
    rep(i, N){
        if(i % 2 == 0){
            th += A.at(happy.at(i).second);
        }
        else{
            ah += B.at(happy.at(i).second);
        }
    }
    cout << th-ah << '\n';
}