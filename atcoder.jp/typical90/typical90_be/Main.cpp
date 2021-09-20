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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
  if ((x += a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator-=(const mint a) {
  if ((x += mod-a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
  if (!t) return 1;
  mint a = pow(t>>1);
  a *= a;
  if (t&1) a *= *this;
  return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint mpow(mint x, ll y){
  if(y == 0){
    return 1;
  }
  if(y % 2 == 0){
    mint a = mpow(x, y / 2);
    return a * a;
  }
  else{
    mint a = mpow(x, y / 2);
    return a * a * x;
  }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> sw(N, vector<ll>(M, 0));
    rep(i, N){
        ll T;
        cin >> T;
        rep(j, T){
            ll x;
            cin >> x;
            x--;
            sw.at(i).at(x) = 1;
        }
    }
    vector<ll> S(M);
    rep(i, M){
        cin >> S.at(i);
    }
    ll c = 0;
    rep(i, N){
        rep2(j, i, N){
            if(sw.at(j).at(c) == 1){
                rep2(k, j+1, N){
                    if(sw.at(k).at(c) == 1){
                        rep2(l, c, M){
                            sw.at(k).at(l) ^= sw.at(j).at(l);
                        }
                    }
                }
                if(j != i){
                    swap(sw.at(i), sw.at(j));
                }
                c++;
                break;
            }
            if(j == N-1){
                c++;
                if(c == M){
                    break;
                }
                j = i-1;
            }
        }
        if(c == M){
            break;
        }
    }
    vector<ll> t(N+1, M);
    rep(i, N){
        rep(j, M){
            if(sw.at(i).at(j) == 1){
                t.at(i) = j;
                break;
            }
        }
    }
    vector<ll> now(M, 0);
    rep(i, t.at(0)){
        if(S.at(i) != 0){
            cout << 0 << '\n';
            return 0;
        }
    }
    rep(i, N+1){
        if(t.at(i) == M){
            if(now != S){
                cout << 0 << '\n';
                return 0;
            }
            cout << mpow(2, N-i) << '\n';
            return 0;
        }
        bool ok = false;
        rep2(j, t.at(i), t.at(i+1)){
            if(now.at(j) != S.at(j)){
                break;
            }
            if(j == t.at(i+1)-1){
                ok = true;
            }
        }
        rep2(j, t.at(i), t.at(i+1)){
            if((now.at(j) ^ sw.at(i).at(j)) != S.at(j)){
                break;
            }
            if(j == t.at(i+1)-1){
                rep2(k, t.at(i), M){
                    now.at(k) ^= sw.at(i).at(k);
                }
                ok = true;
            }
        }
        if(!ok){
            cout << 0 << '\n';
            return 0;
        }
    }
}