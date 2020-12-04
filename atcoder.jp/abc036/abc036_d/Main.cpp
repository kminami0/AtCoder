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

struct edge {
  ll to;
};
vector<vector<edge>> graph;

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

queue<pair<ll, ll>> q;
vector<ll> dst(100000, -1);

void bfs(ll x, ll d){
  dst.at(x) = d;
  q.push({x, d});
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N-1){
      ll a, b;
      cin >> a >> b;
      a--;
      b--;
      graph.at(a).push_back({b});
      graph.at(b).push_back({a});
    }
    q.push({0, 0});
    dst.at(0) = 0;
    set<ll> leaf;
    vector<ll> vst(0);
    vst.push_back(0);
    while(!q.empty()){
      pair<ll, ll> p = q.front();
      q.pop();
      bool lf = true;
      for(auto e : graph.at(p.first)){
        if(dst.at(e.to) != -1){
          continue;
        }
        lf = false;
        vst.push_back(e.to);
        bfs(e.to, p.second+1);
      }
      if(lf){
        leaf.insert(p.first);
      }
    }
    vector<vector<mint>> dp(N, vector<mint>(2, -1));
    // 0を根とする
    // dp.at(i).at(0)はiを根とする部分木の、iを黒く塗ったときの塗り方
    // dp.at(i).at(1)はiを根とする部分木の、iを白く塗ったときの塗り方
    for(auto l : leaf){
      dp.at(l).at(0) = 1;
      dp.at(l).at(1) = 1;
    }

    reverse(all(vst));
    rep(i, N){
      if(leaf.count(vst.at(i))){
        continue;
      }
      dp.at(vst.at(i)).at(0) = 1;
      dp.at(vst.at(i)).at(1) = 1;
      for(auto e : graph.at(vst.at(i))){
        if(dst.at(e.to) < dst.at(vst.at(i))){
          continue;
        }
        dp.at(vst.at(i)).at(0) *= dp.at(e.to).at(1);
        dp.at(vst.at(i)).at(1) *= dp.at(e.to).at(0) + dp.at(e.to).at(1);
      }
    }
    cout << dp.at(0).at(0) + dp.at(0).at(1) << endl;
}