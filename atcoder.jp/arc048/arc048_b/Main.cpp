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
    vector<ll> R(N), H(N);
    vector<tuple<ll, ll ,ll>> P(N);
    map<pair<ll, ll>, ll> Q;
    vector<ll> a(100001, N);
    rep(i, N){
        cin >> R.at(i) >> H.at(i);
        H.at(i)--;
        P.at(i) = make_tuple(R.at(i), H.at(i), i);
        Q[make_pair(R.at(i), H.at(i))]++;
    }
    rep(i, 100000){
        a.at(i+1) = a.at(i) - (Q[make_pair(i+1, 0)] + Q[make_pair(i+1, 1)] + Q[make_pair(i+1, 2)]);
    }
    sort(all(P));
    map<ll, tuple<ll, ll, ll>> result;
    rep(i, N){
        result[i] = make_tuple(N-a.at(R.at(i)-1)+Q[make_pair(R.at(i), (H.at(i)+1)%3)], a.at(R.at(i))+Q[make_pair(R.at(i), (H.at(i)+2)%3)], Q[make_pair(R.at(i), H.at(i))]-1);
    }
    rep(i, N){
        cout << get<0>(result.at(i)) << " " << get<1>(result.at(i)) << " " << get<2>(result.at(i)) << endl;
    }
}