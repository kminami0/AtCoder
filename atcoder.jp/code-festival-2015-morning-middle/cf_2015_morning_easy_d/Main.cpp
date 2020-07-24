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

ll heyho(string P, string S){
    string T = P + S;
    if(sz(T)%2 == 0){
        string U = T.substr(0, sz(T)/2);
        if(T == U+U){
            return 0;
        }
    }
    if(S == ""){
        return INF;
    }
    ll a = INF;
    rep(i, sz(S)-1){
        string U = S.substr(0, i);
        chmin(a, heyho(P+U, S.substr(i+1))+1);
    }
    chmin(a, heyho(P+S.substr(0, sz(S)-1), "")+1);
    return a;
}

vector<vector<vector<ll>>> dp(101, vector<vector<ll>>(101, vector<ll>(101, 0)));
//dp.at(i).at(j).at(k)はSをi文字目までで分割し前半のj文字と後半のk文字のLCS長

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    ll x = 0;
    rep(i, N+1){
        rep(j, i){
            rep(k, N-i){
                if(S.at(j) == S.at(i+k)){
                    dp.at(i).at(j+1).at(k+1) = dp.at(i).at(j).at(k)+1;
                }
                else{
                    dp.at(i).at(j+1).at(k+1) = max(dp.at(i).at(j+1).at(k), dp.at(i).at(j).at(k+1));
                }
            }
        }
        chmax(x, dp.at(i).at(i).at(N-i));
    }
    cout << sz(S)-x*2 << endl;
}