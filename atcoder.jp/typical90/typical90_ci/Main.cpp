#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
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
    ll N, P, K;
    cin >> N >> P >> K;
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> A.at(i).at(j);
        }
    }
    vector<vector<ll>> dist(N, vector<ll>(N, INF));
    rep(i, N){
        dist.at(i).at(i) = 0;
    }
    rep(i, N){
        rep(j, N){
            if(A.at(i).at(j) != -1){
                dist.at(i).at(j) = A.at(i).at(j);
            }
        }
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(dist.at(i).at(j), dist.at(i).at(k)+dist.at(k).at(j));
            }
        }
    }
    ll cnt = 0;
    rep(i, N){
        rep2(j, i+1, N){
            if(dist.at(i).at(j) <= P){
                cnt++;
            }
        }
    }
    if(cnt == K){
        cout << "Infinity" << '\n';
        return 0;
    }
    else if(cnt > K){
        cout << 0 << '\n';
        return 0;
    }
    rep(i, N){
        dist.at(i).at(i) = 0;
    }
    rep(i, N){
        rep(j, N){
            if(A.at(i).at(j) != -1){
                dist.at(i).at(j) = A.at(i).at(j);
            }
            else{
                dist.at(i).at(j) = 1;
            }
        }
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(dist.at(i).at(j), dist.at(i).at(k)+dist.at(k).at(j));
            }
        }
    }
    cnt = 0;
    bool flag = false;
    rep(i, N){
        rep2(j, i+1, N){
            if(dist.at(i).at(j) <= P){
                cnt++;
            }
        }
    }
    if(cnt < K){
        cout << 0 << '\n';
        return 0;
    }
    else if(cnt == K){
        flag = true;
    }
    ll l = 1;
    ll r = INF;
    // X=lとすると条件を満たす組がK個以上存在し、X=rとすると条件を満たす組はK個未満
    while(r-l > 1){
        ll c = (l+r) / 2;
        rep(i, N){
            dist.at(i).at(i) = 0;
        }
        rep(i, N){
            rep(j, N){
                if(A.at(i).at(j) != -1){
                    dist.at(i).at(j) = A.at(i).at(j);
                }
                else{
                    dist.at(i).at(j) = c;
                }
            }
        }
        rep(k, N){
            rep(i, N){
                rep(j, N){
                    chmin(dist.at(i).at(j), dist.at(i).at(k)+dist.at(k).at(j));
                }
            }
        }
        cnt = 0;
        rep(i, N){
            rep2(j, i+1, N){
                if(dist.at(i).at(j) <= P){
                    cnt++;
                }
            }
        }
        if(cnt >= K){
            l = c;
        }
        else{
            r = c;
        }
    }
    rep(i, N){
        dist.at(i).at(i) = 0;
    }
    rep(i, N){
        rep(j, N){
            if(A.at(i).at(j) != -1){
                dist.at(i).at(j) = A.at(i).at(j);
            }
            else{
                dist.at(i).at(j) = l;
            }
        }
    }
    rep(k, N){
        rep(i, N){
            rep(j, N){
                chmin(dist.at(i).at(j), dist.at(i).at(k)+dist.at(k).at(j));
            }
        }
    }
    cnt = 0;
    rep(i, N){
        rep2(j, i+1, N){
            if(dist.at(i).at(j) <= P){
                cnt++;
            }
        }
    }
    if(cnt > K){
        cout << 0 << '\n';
        return 0;
    }
    if(flag){
        cout << l << '\n';
        return 0;
    }
    ll m = l;
    r = l;
    l = 1;
    // X=lとすると条件を満たす組がK+1個以上存在し、X=rとすると条件を満たす組はK個
    while(r-l > 1){
        ll c = (l+r) / 2;
        rep(i, N){
            dist.at(i).at(i) = 0;
        }
        rep(i, N){
            rep(j, N){
                if(A.at(i).at(j) != -1){
                    dist.at(i).at(j) = A.at(i).at(j);
                }
                else{
                    dist.at(i).at(j) = c;
                }
            }
        }
        rep(k, N){
            rep(i, N){
                rep(j, N){
                    chmin(dist.at(i).at(j), dist.at(i).at(k)+dist.at(k).at(j));
                }
            }
        }
        cnt = 0;
        rep(i, N){
            rep2(j, i+1, N){
                if(dist.at(i).at(j) <= P){
                    cnt++;
                }
            }
        }
        if(cnt > K){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << m-r+1 << '\n';
}