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
    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    map<ll, ll> cnt;
    vector<ll> A(X);
    rep(i, X){
        cin >> A.at(i);
        cnt[A.at(i)]++;
    }
    vector<ll> B(Y);
    rep(i, Y) cin >> B.at(i);
    vector<ll> C(Z);
    rep(i, Z) cin >> C.at(i);
    sort(all(A));
//    reverse(all(A));
//    sort(all(B));
//    reverse(all(B));
//    sort(all(C));
//    reverse(all(C));
    long double bound = 30000000001;
    vector<long double> cake23(Y*Z);
    rep(i, Y){
        rep(j, Z){
            cake23.at(i*Z+j) = B.at(i) + C.at(j) + 0.00000001 * (i*Z+j);
        }
    }
    cake23.push_back(0);
    cake23.push_back(INF);
    sort(all(cake23));

    set<pair<ll, ll>> bought;
    vector<ll> ans(0);
    ll i = 0;
    // キャンドル1のケーキを固定して、現在の最大値未満の最大値となる買い方を
    // 二分探索で探す
    while(sz(ans) < K){
        long double tmp = 0;
        pair<ll, ll> abc = {-1, -1};
        rep(j, X){
            long double b = bound - A.at(j);
            ll l = 0;
            ll r = Y*Z+1;
            // cake23.at(l) < b <= cake23.at(r);
            while(r-l > 1){
                ll c = (l+r) / 2;
                if(cake23.at(c) < b){
                    l = c;
                }
                else{
                    r = c;
                }
            }
            if(!bought.count({A.at(j), l})){
                if(chmax(tmp, A.at(j) + cake23.at(l))){
                    abc = {A.at(j), l};
                }
            }
        }
        while(true){
            if(abc.first == -1){
                break;
            }
            bought.insert(abc);
            bool flag = false;
            rep(j, cnt.at(abc.first)){
                ans.push_back(floor(tmp));
                if(sz(ans) >= K){
                    break;
                    flag = true;
                }
            }
            if(flag){
                break;
            }
            if(abc.second == 0){
                break;
            }
            if(cake23.at(abc.second) != cake23.at(abc.second-1)){
                break;
            }
            abc.second--;
        }
        bound = tmp;
    }
    rep(j, K){
        cout << ans.at(j) << endl;
    }
}