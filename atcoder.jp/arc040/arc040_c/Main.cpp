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
    vector<string> S(N);
    rep(i, N) cin >> S.at(i);
    vector<pair<ll, ll>> nopaint(N, make_pair(-1,-1));
    rep(i, N){
        rep(j, N){
            if(S.at(i).at(j) == '.'){
                if(nopaint.at(i).first == -1){
                    nopaint.at(i).first = j;
                }
                nopaint.at(i).second = j;
            }
        }
    }
    ll ans = 0;
    rep(i, N){
        if(nopaint.at(i).first == -1){
            continue;
        }
        ans++;
        ll e = nopaint.at(i).second;
        if(i != N-1){
            nopaint.at(i+1) = make_pair(-1,-1);
            rep(j, e){
                if(S.at(i+1).at(j) == '.'){
                    if(nopaint.at(i+1).first == -1){
                        nopaint.at(i+1).first = j;
                    }
                    nopaint.at(i+1).second = j;
                }
            }
        }
    }
    cout << ans << endl;
}