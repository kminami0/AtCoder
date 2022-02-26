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
int main()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N){
        cin >> S.at(i);
    }
    rep(i, N){
        rep(j, N-5){
            ll cnt = 0;
            rep(k, 6){
                if(S.at(i).at(j+k) == '#'){
                    cnt++;
                }
            }
            if(cnt >= 4){
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    rep(i, N-5){
        rep(j, N){
            ll cnt = 0;
            rep(k, 6){
                if(S.at(i+k).at(j) == '#'){
                    cnt++;
                }
            }
            if(cnt >= 4){
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    rep(i, N-5){
        rep(j, N-5){
            ll cnt = 0;
            rep(k, 6){
                if(S.at(i+k).at(j+k) == '#'){
                    cnt++;
                }
            }
            if(cnt >= 4){
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    rep(i, N-5){
        rep2(j, 5, N){
            ll cnt = 0;
            rep(k, 6){
                if(S.at(i+k).at(j-k) == '#'){
                    cnt++;
                }
            }
            if(cnt >= 4){
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
}