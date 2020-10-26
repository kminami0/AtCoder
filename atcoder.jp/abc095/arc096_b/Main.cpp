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
    ll N, C;
    cin >> N >> C;
    vector<ll> x(N), v(N);
    rep(i, N){
        cin >> x.at(i) >> v.at(i);
    }
    vector<ll> y(N); // 反時計回りに進んだときの距離
    rep(i, N){
        y.at(i) = C - x.at(N-1-i);
    }
    rep(i, N-1){ //隣の寿司との距離に変更する
        x.at(N-1-i) -= x.at(N-2-i); 
        y.at(N-1-i) -= y.at(N-2-i);
    }
    vector<ll> cw_acc(N+1, 0), ccw_acc(N+1, 0), cw_rt(N+1, 0), ccw_rt(N+1, 0);
    // cw_acc.at(i)は時計回りに進んでi個寿司を食べたときの差し引き摂取カロリー
    // cw_rt.at(i)は時計回りに進んでi個寿司を食べスタートに戻ってきたときの差し引き摂取カロリー
    // ccw_acc, ccw_rtは反時計回り版
    rep(i, N){
        cw_acc.at(i+1) = cw_acc.at(i) + v.at(i) - x.at(i);
        ccw_acc.at(i+1) = ccw_acc.at(i) + v.at(N-1-i) - y.at(i);
        cw_rt.at(i+1) = cw_rt.at(i) + v.at(i) - 2 * x.at(i); 
        ccw_rt.at(i+1) = ccw_rt.at(i) + v.at(N-1-i) - 2 * y.at(i);
    }
    vector<ll> cw_max(N+1, 0);
    vector<ll> ccw_max(N+1, 0);
    // cw_max.at(i)は時計回りに進んで高々i個食べたときの最大差し引き摂取カロリー
    // ccw_maxは反時計回り版
    rep(i, N){
        cw_max.at(i+1) = max(cw_max.at(i), cw_acc.at(i+1));
        ccw_max.at(i+1) = max(ccw_max.at(i), ccw_acc.at(i+1));
    }
    ll cw_rt_max = 0;
    ll ccw_rt_max = 0;
    // cw_rt_maxはまず時計回りに進み、その後反時計回りに進んだときの最大差し引き摂取カロリー
    // ccw_rt_maxはまず反時計回りに進み、その後時計回りに進んだときの最大差し引き摂取カロリー
    rep(i, N+1){ //最初の進行方向でi個食べたとき、逆方向では高々N-i個食べる
        chmax(cw_rt_max, cw_rt.at(i)+ccw_max.at(N-i));
        chmax(ccw_rt_max, ccw_rt.at(i)+cw_max.at(N-i));
    }
    ll ans = max(cw_max.at(N), ccw_max.at(N));
    chmax(ans, cw_rt_max);
    chmax(ans, ccw_rt_max);
    //4つの戦略の最大値が答え
    cout << ans << endl;
}