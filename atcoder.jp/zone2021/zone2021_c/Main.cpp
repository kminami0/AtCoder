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
int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N), C(N), D(N), E(N);
    rep(i, N){
        cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i) >> E.at(i);
    }
    ll l = 0;
    ll r = INF;
    while(r-l > 1){
        ll c = (l+r) / 2;
        set<ll> mem;
        rep(i, N){
            ll s = 0;
            if(A.at(i) >= c){
                s = s | (1 << 0);
            }
            if(B.at(i) >= c){
                s = s | (1 << 1);
            }
            if(C.at(i) >= c){
                s = s | (1 << 2);
            }
            if(D.at(i) >= c){
                s = s | (1 << 3);
            }
            if(E.at(i) >= c){
                s = s | (1 << 4);
            }
            mem.insert(s);
        }
        vector<ll> cand(0);
        for(auto s : mem){
            cand.push_back(s);
        }
        ll t = 0;
        if(sz(cand) <= 2){
            rep(i, sz(cand)){
                t = t | cand.at(i);
            }
            bool ok = true;
            rep(i, 5){
                if(!(t & (1 << i))){
                    ok = false;
                    break;
                }
            }
            if(ok){
                l = c;
            }
            else{
                r = c;
            }
        }
        else{
            bool flag = false;
            rep(i, sz(cand)){
                rep2(j, i+1, sz(cand)){
                    rep2(k, j+1, sz(cand)){
                        t = 0;
                        t = t | cand.at(i);
                        t = t | cand.at(j);
                        t = t | cand.at(k);
                        bool ok = true;
                        rep(m, 5){
                            if(!(t & (1 << m))){
                                ok = false;
                            }
                        }
                        if(ok){
                            l = c;
                            flag = true;
                        }
                        if(flag){
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
            if(!flag){
                r = c;
            }
        }
    }
    cout << l << '\n';
}