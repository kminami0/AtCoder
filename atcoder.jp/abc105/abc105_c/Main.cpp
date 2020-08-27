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

set<ll> base_minus2(ll N){
    set<ll> S;
    if(N == 0){
        return S;
    }
    if(N > 0){
        ll c = 0;
        while(pow(4, c+1) - 1 < 3 * N){
            c++;
        }
        S.insert(2*c);
        set<ll> T = base_minus2(N - pow(4, c));
        set<ll> U;
        for(auto p : S){
            U.insert(p);
        }
        for(auto p : T){
            U.insert(p);
        }
        return U;
    }
    ll c = 0;
    while(2*(pow(4, c+1) - 1) < -3 * N){
        c++;
    }
    S.insert(2*c+1);
    set<ll> T = base_minus2(N + 2 * pow(4, c));
    set<ll> U;
    for(auto p : S){
        U.insert(p);
    }
    for(auto p : T){
        U.insert(p);
    }
    return U;
}

int main()
{
    ll N;
    cin >> N;
    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    ll c = 0;
    if(N > 0){
        while(pow(4, c+1) - 1 < 3 * N){
            c++;
        }
        c = 2 * c + 1;
    }
    else{
        while(2*(pow(4, c+1) - 1) < -3 * N){
            c++;
        }
        c = 2 * c + 2;
    }
    set<ll> S = base_minus2(N);
    string ans;
    rep(i, c){
        if(S.count(c-i-1)){
            ans += "1";
        }
        else{
            ans += "0";
        }
    }
    cout << ans << endl;
}