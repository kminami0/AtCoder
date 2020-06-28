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

ll scoring(ll D, vector<vector<ll>> s, vector<ll> t, vector<vector<ll>> last, vector<ll> c){
    ll sat = 0;
    ll cnt = 0;
    rep(i, D){
        sat += s.at(i).at(t.at(i));
        last.at(i).at(t.at(i)) = i;
        if(i != 0){
            rep(j, 26){
                if(j == t.at(i)){
                    continue;
                }
                last.at(i).at(j) = last.at(i-1).at(j);
            }
        }
        rep(j, 26){
            sat -= c.at(j) * (i - last.at(i).at(j));    
        }
    }
    return sat;
}

int main()
{
    ll D;
    cin >> D;
    vector<ll> c(26);
    rep(i, 26) cin >> c.at(i);
    vector<vector<ll>> s(D, vector<ll>(26));
    rep(i, D){
        rep(j, 26){
            cin >> s.at(i).at(j);
        }
    }
    vector<ll> t(D, 0);
    ll sat = 0;
    vector<vector<ll>> last(D, vector<ll>(26, -1));
    rep(i, D){
        ll tmp = 0;
        rep(j, 26){
            ll now = t.at(i);
            t.at(i) = j;
            if(chmax(tmp, scoring(i+1, s, t, last, c))){
                continue;
            }
            else{
                t.at(i) = now;
            }
        }
//        cout << tmp << endl;
    }
    rep(i, D){
        cout << t.at(i)+1 << endl;
    }
}