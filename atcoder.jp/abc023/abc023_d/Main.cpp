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
//浮動小数点はなるべく使うな、powも気をつけろ
int main()
{
    ll N;
    cin >> N;
    vector<ll> H(N), S(N);
    rep(i, N){
        cin >> H.at(i) >> S.at(i);
    }
    ll high = 0;
    rep(i, N){
        chmax(high, H.at(i));
    }
    ll l = 0;
    ll r = INF;
    //得点をl点以下にはできず、r点以下にはできる
    while(r-l > 1){
        ll c = (l+r)/2;
        if(c < high){
            l = c;
            continue;
        }
        vector<ll> yuuyo(N+1);
        //yuuyo.at(i)は開始してi秒で撃てばペナルティはc以下だがi+1秒で撃てばcを超える風船の数
        //ただしyuuyo.at(N)はいつ撃っても良い風船の数
        rep(i, N){
            yuuyo.at(min((c - H.at(i)) / S.at(i), N))++;
        }
        vector<ll> acc(N+2, 0);
        //acc.at(i)はi番目までに撃たねばならない風船の数
        rep(i, N+1){
            acc.at(i+1) = acc.at(i) + yuuyo.at(i);
        }
        rep(i, N){
            if(acc.at(i+1) >= i+2){
                l = c;
                break;
            }
            if(i == N-1){
                r = c;
            }
        }
    }
    cout << r << '\n';
}