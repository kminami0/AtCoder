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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    ll sum = 0;
    rep(i, N){
        cin >> A.at(i);
        sum += A.at(i);
    }
    // 消化コストの合計がK以下なら、成績を0にできる 
    if(sum <= K){
        cout << 0 << endl;
        return 0;
    }
    vector<ll> F(N);
    rep(i, N) cin >> F.at(i);
    sort(all(A));
    sort(all(F));
    reverse(all(F));
    ll l = 0;
    ll r = 2e17;
    // 成績l以下は不可能で、成績r以下は可能
    // 二分探索で境界を求める
    while(r-l > 1){
        ll c = (l+r) / 2;
        ll cnt = 0;
        rep(i, N){
            cnt += max(A.at(i) - c / F.at(i), 0LL);
        }
        if(cnt <= K){
            r = c;
        }
        else{
            l = c;
        }
    }
    cout << r << endl;
}