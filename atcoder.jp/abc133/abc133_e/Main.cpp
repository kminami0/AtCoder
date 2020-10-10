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

struct edge {
  ll to;
};
vector<vector<edge>> graph;

vector<mint> fac(2000003, 1);
void calc(int n){
  rep(i, n){
    fac.at(i+1) = fac.at(i) * (i+1);
  }
  return;
}

mint mperm(ll x, ll y){ // xPy
  if(x < y){
      return 0;
  }
  mint a = fac.at(x);
  mint b = fac.at(x-y);
  return a / b;
}

queue<set<ll>> q;
vector<bool> painted(100000, false);

int main()
{
    calc(2000000); //階乗を計算しておく
    ll N, K;
    cin >> N >> K;
    graph.resize(N);
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
    }
    set<ll> nodes;
    painted.at(0) = true;
    for(auto e : graph.at(0)){
        nodes.insert(e.to);
        painted.at(e.to) = true;
    }
    mint ans = mperm(K-1, sz(nodes)) * K; //根と根に隣接する節の塗り方の数
    for(auto x : nodes){
        set<ll> p;
        for(auto e : graph.at(x)){
            if(e.to != 0){
                p.insert(e.to);
                painted.at(e.to) = true;
            }
        }
        q.push(p); //節に隣接している葉方向の節の集合をキューに入れる
    }
    while(!q.empty()){
        set<ll> p = q.front();
        q.pop();
        ans *= mperm(K-2, sz(p)); //取り出した集合に属している節をまとめて塗る
        for(auto x : p){
            set<ll> r;
            for(auto e : graph.at(x)){
                if(!painted.at(e.to)){
                    r.insert(e.to);
                    painted.at(e.to) = true;
                }
            }
            q.push(r);
        }
    }
    cout << ans << endl;
}