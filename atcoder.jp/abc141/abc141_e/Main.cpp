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
    string S;
    cin >> N >> S;
    ll ans = 0;
    ll p = 0;
    bool found = true;
    // 尺取り法を使う。部分文字列の左端をiに固定して、長さj+1のものが
    // 重ならずに出現するか調べる。出現しなければfoundをfalseにしループを抜け、
    // 左端を右に1つずらす。前のループで条件を満たした部分文字列の長さより長いもの
    // だけ調べればよいので、その値をpに保持する。
    rep(i, N-1){
        rep2(j, p, N/2){
            if(i+j+1 > N){
                break;
            }
            string t = S.substr(i, j+1);
            rep2(k, i+j+1, N-j){
                if(t == S.substr(k, j+1)){
                    chmax(ans, ll(sz(t)));
                    p = sz(t);
                    break;
                }
                if(k == N-j-1){
                    found = false;
                }
            }
            if(!found){
                found = true;
                break;
            }
        }
    }
    cout << ans << endl;
}