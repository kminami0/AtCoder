#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+9
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
    ll N, S;
    cin >> N >> S;
    vector<ll> A(N), B(N);
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
    }
    vector<set<ll>> lb(N+1);
    lb.at(0).insert(0);
    rep(i, N){
        for(auto ms : lb.at(i)){
            if(ms + A.at(i) <= S){
                lb.at(i+1).insert(ms+A.at(i));
            }
            if(ms + B.at(i) <= S){
                lb.at(i+1).insert(ms+B.at(i));
            }
        }
    }
    string ans = "";
    if(lb.at(N).count(S)){
        ll rem = S;
        rep(i, N){
            if(lb.at(N-1-i).count(rem-A.at(N-1-i))){
                ans += "A";
                rem -= A.at(N-1-i);
            }
            else{
                ans += "B";
                rem -= B.at(N-1-i);
            }
        }
        reverse(all(ans));
        cout << ans << '\n';
    }
    else{
        cout << "Impossible" << '\n';
    }
}