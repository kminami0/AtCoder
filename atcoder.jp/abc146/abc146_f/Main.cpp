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
//ゴールからスタートへ貪欲に進み、その逆順が答え
int main()
{
    ll N, M;
    string S;
    cin >> N >> M >> S;
    vector<ll> ans(0);
    ll pos = N;
    while(pos != 0){
        ll m = min(M, pos);
        rep(i, m){
            if(S.at(pos-(m-i)) == '0'){
                pos-= m-i;
                ans.push_back(m-i);
                break;
            }
            if(i == m-1){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    reverse(all(ans));
    rep(i, sz(ans)){
        cout << ans.at(i) << " ";
    }
    cout << endl;
}