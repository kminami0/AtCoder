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

ll lpow(ll x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    ll a = lpow(x, y / 2);
    return a * a;
  }
  else{
    ll a = lpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T){
        ll A, S;
        cin >> A >> S;
        bitset<63> a(A);
        bitset<63> s(S);
        bool c = false;
        bool ans = false;
        rep(j, 63){
            if(a.test(j)){
                if(c){
                    if(s.test(j)){
                        c = true;
                    }
                    else{
                        cout << "No" << '\n';
                        ans = true;
                        break;
                    }
                }
                else{
                    if(s.test(j)){
                        cout << "No" << '\n';
                        ans = true;
                        break;
                    }
                    else{
                        c = true;
                    }
                }
            }
            else{
                if(c){
                    if(s.test(j)){
                        c = false;
                    }
                    else{
                        c = true;
                    }
                }
                else{
                    c = false;
                }
            }
        }
        if(!ans){
            if(c){
                cout << "No" << '\n';
            }
            else{
                cout << "Yes" << '\n';
            }
        }
    }
}