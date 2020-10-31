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


vector<mint> fac(2000003, 1);
void calc(int n){
  rep(i, n){
    fac.at(i+1) = fac.at(i) * (i+1);
  }
  return;
}

vector<ll> par(1000000);
vector<ll> rnk(1000000);

void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 1;
  }
}

ll root(ll x){
  if(par.at(x) == x){
    return x;
  }
  else{
    par.at(x) = root(par.at(x));
    return par.at(x);
  }
}

bool same(ll x, ll y){
  if(root(x) == root(y)){
    return true;
  }
  else{
    return false;
  }
}

void unite(ll x, ll y){
  x = root(x);
  y = root(y);
  if(x == y){
    return;
  }
  if(rnk.at(x) < rnk.at(y)){
    par.at(x) = y;
    rnk.at(y) += rnk.at(x);
  }
  else{
    par.at(y) = x;
    rnk.at(x) += rnk.at(y);
  }
}

int main()
{
    ll N, K;
    cin >> N >> K;
    calc(2000000);
    init(N);
    vector<vector<ll>> a(N, vector<ll>(N));
    rep(i, N){
        rep(j, N){
            cin >> a.at(i).at(j);
        }
    }
    rep(i, N){
        set<ll> ok;
        rep2(j, i+1, N){
            ok.insert(j);
        }
        rep(j, N){
            set<ll> ng;
            for(auto k : ok){
                if(a.at(j).at(i) + a.at(j).at(k) > K){
                    ng.insert(k);
                }
            }
            for(auto k : ng){
                ok.erase(k);
            }
        }
        for(auto j: ok){
            unite(i, j);
        }
    }
    mint ans = 1;
    set<ll> cc;
    rep(i, N){
        cc.insert(root(i));
    }
    for(auto i : cc){
        ans *= fac.at(rnk.at(i));
    }
    init(N);
    rep(i, N){
        set<ll> ok;
        rep2(j, i+1, N){
            ok.insert(j);
        }
        rep(j, N){
            set<ll> ng;
            for(auto k : ok){
                if(a.at(i).at(j) + a.at(k).at(j) > K){
                    ng.insert(k);
                }
            }
            for(auto k : ng){
                ok.erase(k);
            }
        }
        for(auto j: ok){
            unite(i, j);
        }
    }
    cc.clear();
    rep(i, N){
        cc.insert(root(i));
    }
    for(auto i : cc){
        ans *= fac.at(rnk.at(i));
    }
    cout << ans << endl;
}