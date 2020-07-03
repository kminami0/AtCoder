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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    if(A.at(0) != 0){
        cout << -1 << endl;
        return 0;
    }
    rep(i, N-1){
        if(A.at(i+1) - A.at(i) > 1){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<ll> goal(N);
    rep(i, N){
        goal.at(i) = i - A.at(i);
    }
    ll ans = 0;
    ll p = N-1;
    while(true){
        ans += p - goal.at(p);
        if(goal.at(p) == 0){
            break;
        }
        while(goal.at(p-1) == goal.at(p)){
            p--;
        }
        p--;
    }
    cout << ans << endl;
}