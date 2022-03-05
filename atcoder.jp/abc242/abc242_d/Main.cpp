#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
#define INF 1e18+999999
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

string S;



char answer(ll t, ll k){
    if(t == 0){
        return S.at(k);
    }
    char x = answer(t-1, k/2);
    if(x == 'A'){
        if(k % 2 == 0){
            return 'B';
        }
        else{
            return 'C';
        }
    }
    else if(x == 'B'){
        if(k % 2 == 0){
            return 'C';
        }
        else{
            return 'A';
        }
    }
    else{
        if(k % 2 == 0){
            return 'A';
        }
        else{
            return 'B';
        }
    }
}

void solve(){
    ll t, k;
    cin >> t >> k;
    k--;
    if(t <= 60){
        cout << answer(t, k) << '\n';
    }
    else{
        string tmp = S;
        char y;
        if(S.at(0) == 'A'){
            y = 'A' + t % 3;
        }
        else if(S.at(0) == 'B'){
            y = 'B' + t % 3;
            if(y == 'D'){
                y = 'A';
            }
        }
        else{
            if(t % 3 == 0){
                y = 'C';
            }
            else if(t % 3 == 1){
                y = 'A';
            }
            else{
                y = 'B';
            }
        }
        S = y;
        cout << answer(60, k) << '\n';
        S = tmp;
    }
}

int main()
{
    cin >> S;
    ll Q;
    cin >> Q;
    rep(i, Q){
        solve();
    }
}