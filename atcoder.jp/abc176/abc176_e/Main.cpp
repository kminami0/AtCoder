#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
    ll H, W, M;
    cin >> H >> W >> M;
    vector<ll> h(M), w(M);
    map<ll, ll> rbom;
    set<pair<ll, ll>> bomb;
    map<ll, ll> cbom;
    rep(i, M){
        cin >> h.at(i) >> w.at(i);
        h.at(i)--;
        w.at(i)--;
        rbom[h.at(i)]++;
        cbom[w.at(i)]++;
        bomb.insert({h.at(i), w.at(i)});
    }
    ll X = -1;
    set<ll> rcand;
    rep(i, H){
        if(X < rbom[i]){
            rcand.clear();
            rcand.insert(i);
            X = rbom[i];
        }
        else if(X == rbom[i]){
            rcand.insert(i);
        }
    }
    ll Y = -1;
    set<ll> ccand;
    rep(i, W){
        if(Y < cbom[i]){
            ccand.clear();
            ccand.insert(i);
            Y = cbom[i];
        }
        else if(Y == cbom[i]){
            ccand.insert(i);
        }
    }
    for(auto x : rcand){
        for(auto y : ccand){
            if(!bomb.count({x, y})){
                cout << X+Y << '\n';
                return 0;
            }
        }
    }
    cout << X+Y-1 << '\n';
}