#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e17
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
    ll N, Q;
    string s;
    cin >> N >> Q >> s;
    string t = "";
    string d = "";
    rep(i, Q){
        char x, y;
        cin >> x >> y;
        t += x;
        d += y;
    }
    ll golem = 0;
    bool drop = false;
    rep(i, Q){
        if(t.at(i) == s.at(golem)){
            if(d.at(i) == 'L'){
                golem--;
            }
            else{
                golem++;
            }
            if(golem < 0){
                drop = true;
                break;
            }
            if(golem >= N){
                break;
            }
        }
    }
    ll disapp = 0;
    if(drop){
        ll l = 0;
        ll r = N;
        //はじめlにいたゴーレムは左から落ち、rにいたゴーレムは落ちない
        while(r-l > 1){
            ll c = (l+r) / 2;
            drop = false;
            golem = c;
            rep(i, Q){
                if(t.at(i) == s.at(golem)){
                    if(d.at(i) == 'L'){
                        golem--;
                    }
                    else{
                        golem++;
                    }
                    if(golem < 0){
                        drop = true;
                        break;
                    }
                    if(golem >= N){
                        break;
                    }
                }
            }
            if(drop){
                l = c;
            }
            else{
                r = c;
            }
        }
        disapp += r;
    }
    golem = N-1;
    drop = false;
    rep(i, Q){
        if(t.at(i) == s.at(golem)){
            if(d.at(i) == 'L'){
                golem--;
            }
            else{
                golem++;
            }
            if(golem >= N){
                drop = true;
                break;
            }
            if(golem < 0){
                break;
            }
        }
    }
    if(drop){
        ll l = -1;
        ll r = N-1;
        //はじめlにいたゴーレムは落ちず、rにいたゴーレムは右から落ちる
        while(r-l > 1){
            ll c = (l+r) / 2;
            drop = false;
            golem = c;
            rep(i, Q){
                if(t.at(i) == s.at(golem)){
                    if(d.at(i) == 'L'){
                        golem--;
                    }
                    else{
                        golem++;
                    }
                    if(golem >= N){
                        drop = true;
                        break;
                    }
                    if(golem < 0){
                        break;
                    }
                }
            }
            if(drop){
                r = c;
            }
            else{
                l = c;
            }
        }
        disapp += N - r;
    }
    cout << N - disapp << '\n';
}