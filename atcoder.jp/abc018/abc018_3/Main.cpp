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
    ll R, C, K;
    cin >> R >> C >> K;
    vector<string> s(R);
    rep(i, R){
        cin >> s.at(i);
    }
    vector<vector<pair<ll, ll>>> white(R, vector<pair<ll, ll>>(C, {0, 0}));
    //white.at(i).at(j).firstはs.at(i).at(j)から上に何個oが連続しているか
    //secondは下方向
    rep(i, R){
        rep(j, C){
            rep(k, K){
                if(i-k < 0){
                    break;
                }
                if(s.at(i-k).at(j) == 'o'){
                    white.at(i).at(j).first++;
                }
                else{
                    break;
                }
            }
            rep(k, K){
                if(i+k >= R){
                    break;
                }
                if(s.at(i+k).at(j) == 'o'){
                    white.at(i).at(j).second++;
                }
                else{
                    break;
                }
            }
        }
    }
    ll ans = 0;
    rep2(i, K-1, R-K+1){
        rep2(j, K-1, C-K+1){
            rep2(k, -(K-1), K){
                // 菱形の中心からabs(k)だけ離れたところでは上方向と下方向にK-abs(k)個以上oが連続しないといけない
                if(white.at(i).at(j+k).first < K-abs(k) || white.at(i).at(j+k).second < K-abs(k)){
                    break;
                }
                if(k == K-1){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}