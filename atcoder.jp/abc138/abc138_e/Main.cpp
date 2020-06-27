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
    string s, t;
    cin >> s >> t;
    map<char, vector<ll>> pos;
    rep(i, sz(s)){
        if(!pos.count(s.at(i))){
            pos[s.at(i)].push_back(-1);
        }
    }
    rep(i, sz(s)){
        pos[s.at(i)].push_back(i);
    }
    rep(i, sz(t)){
        if(!pos.count(t.at(i))){
            cout << -1 << endl;
            return 0;
        }
    }
    ll p = -1;
    ll c = 0;
    rep(i, sz(s)){
        pos.at(s.at(i)).push_back(INF);
    }
    rep(i, sz(t)){
        ll l = 0;
        ll r = sz(pos.at(t.at(i))) - 1;
        // .at(l) <= p < .at(r)
        while(r-l > 1){
            ll c = (l+r) / 2;
            if(pos.at(t.at(i)).at(c) <= p){
                l = c;
            }
            else{
                r = c;
            }
        }
        if(pos.at(t.at(i)).at(r) == INF){
            c++;
            p = pos.at(t.at(i)).at(1);
        }
        else{
            p = pos.at(t.at(i)).at(r);
        }
//        cout << t.at(i) << " " << c*(sz(s)) + p << endl;
    }
    cout << c*sz(s) + p + 1 << endl;
}