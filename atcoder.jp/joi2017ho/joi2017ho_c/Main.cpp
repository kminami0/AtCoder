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

vector<vector<ll>> rot(vector<vector<ll>> v){
    ll H = sz(v);
    ll W = sz(v.at(0));
    vector<vector<ll>> A(W, vector<ll>(H));
    rep(i, W){
        rep(j, H){
            A.at(i).at(j) = v.at(j).at(W-1-i);
        }
    }
    return A;
}

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    ll mini = INF;
    ll maxi = 0;
    rep(i, H){
        rep(j, W){
            cin >> A.at(i).at(j);
            chmin(mini, A.at(i).at(j));
            chmax(maxi, A.at(i).at(j));
        }
    }
    ll l = 0;
    ll r = maxi-mini;
    //答えをl以下にはできずr以下にはできる
    ll ans = INF;
    while(r-l>1){
        ll p = -1;
        ll c = (l+r)/2;
        bool flag = false;
        rep(i, H){
            rep(j, W){
                if(A.at(i).at(W-1-j) > mini+c){
                    chmax(p, W-1-j);
                    break;
                }
            }
            rep(k, p+1){
                if(A.at(i).at(p-k) < maxi-c){
                    l = c;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            continue;
        }
        r = c;
    }
    chmin(ans, r);
    vector<vector<ll>> B = rot(A);
    H = sz(B);
    W = sz(B.at(0));
    l = 0;
    r = maxi-mini;
    while(r-l>1){
        ll p = -1;
        ll c = (l+r)/2;
        bool flag = false;
        rep(i, H){
            rep(j, W){
                if(B.at(i).at(W-1-j) > mini+c){
                    chmax(p, W-1-j);
                    break;
                }
            }
            rep(k, p+1){
                if(B.at(i).at(p-k) < maxi-c){
                    l = c;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            continue;
        }
        r = c;
    }
    chmin(ans, r);
    vector<vector<ll>> C = rot(B);
    H = sz(C);
    W = sz(C.at(0));
    l = 0;
    r = maxi-mini;
    while(r-l>1){
        ll p = -1;
        ll c = (l+r)/2;
        bool flag = false;
        rep(i, H){
            rep(j, W){
                if(C.at(i).at(W-1-j) > mini+c){
                    chmax(p, W-1-j);
                    break;
                }
            }
            rep(k, p+1){
                if(C.at(i).at(p-k) < maxi-c){
                    l = c;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            continue;
        }
        r = c;
    }
    chmin(ans, r);
    vector<vector<ll>> D = rot(C);
    H = sz(D);
    W = sz(D.at(0));
    l = 0;
    r = maxi-mini;
    while(r-l>1){
        ll p = -1;
        ll c = (l+r)/2;
        bool flag = false;
        rep(i, H){
            rep(j, W){
                if(D.at(i).at(W-1-j) > mini+c){
                    chmax(p, W-1-j);
                    break;
                }
            }
            rep(k, p+1){
                if(D.at(i).at(p-k) < maxi-c){
                    l = c;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            continue;
        }
        r = c;
    }
    chmin(ans, r);
    cout << ans << '\n';
}