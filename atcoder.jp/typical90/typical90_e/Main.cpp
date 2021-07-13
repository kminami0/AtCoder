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
const int mod = 1000000007;
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

map<ll, vector<vector<mint>>> MP;
ll B;

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

vector<vector<mint>> Mpower(vector<vector<mint>> M, ll N){
    vector<vector<mint>> A(B, vector<mint>(B, 0));
    if(N == 0){
        rep(i, B){
            A.at(i).at(i) = 1;
        }
        return A;
    }
    if(N == 1){
        return M;
    }
    if(N % 2 == 0){
        vector<vector<mint>> X = Mpower(M, N/2);
        rep(i, B){
            rep(j, B){
                rep(k, B){
                    A.at(i).at(j) += X.at(i).at(k) * X.at(k).at(j);
                }
            }
        }
        return A;
    }
    vector<vector<mint>> Y(B, vector<mint>(B, 0));
    vector<vector<mint>> X = Mpower(M, N/2);
    rep(i, B){
        rep(j, B){
            rep(k, B){
                Y.at(i).at(j) += X.at(i).at(k) * X.at(k).at(j);
            }
        }
    }
    rep(i, B){
        rep(j, B){
            rep(k, B){
                A.at(i).at(j) += Y.at(i).at(k) * M.at(k).at(j);
            }
        }
    }
    return A;
}

int main()
{
    ll N, K;
    cin >> N >> B >> K;
    vector<ll> c(K);
    rep(i, K) cin >> c.at(i);
    vector<vector<mint>> dp(61, vector<mint>(B, 0));
    for(ll d : c){
        dp.at(0).at(d % B) += 1;
    }
    vector<ll> power10(60); //power10.at(i) = 10^(2^i)
    power10.at(0) = 10 % B;
    rep(i, 59){
        power10.at(i+1) = (power10.at(i) * power10.at(i)) % B;
    }
    rep(i, 60){
        rep(j, B){
            rep(k, B){
                ll next = (j * power10.at(i) + k) % B;
                dp.at(i+1).at(next) += dp.at(i).at(j) * dp.at(i).at(k);
            }
        }
    }
    vector<vector<mint>> ans(61, vector<mint>(B, 0));
    ans.at(0).at(0) = 1;
    bitset<60> s(N);
    rep(i, 60){
        if(s.test(i)){
            rep(j, B){
                rep(k, B){
                    ll next = (j * power10.at(i) + k) % B;
                    ans.at(i+1).at(next) += ans.at(i).at(j) * dp.at(i).at(k);
                }
            }
        }
        else{
            rep(j, B){
                ans.at(i+1).at(j) = ans.at(i).at(j);
            }
        }
    }
    cout << ans.at(60).at(0) << '\n';
}