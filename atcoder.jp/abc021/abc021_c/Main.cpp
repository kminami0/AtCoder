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
  ll id;
};
vector<vector<edge>> graph;

vector<ll> dist(100, INF);
queue<ll> q;
vector<mint> num(100, 0);
vector<bool> used(200, false);

int main()
{
    ll N, a, b, M;
    cin >> N >> a >> b >> M;
    a--;
    b--;
    graph.resize(N);
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        graph.at(x).push_back({y, i});
        graph.at(y).push_back({x, i});
    }
    dist.at(a) = 0;
    num.at(a) = 1;
    q.push(a);
    while(!q.empty()){
        ll r = q.front();
        q.pop();
        for(auto e : graph.at(r)){
            if(used.at(e.id)){
                continue;
            }
            if(dist.at(r)+1 < dist.at(e.to)){
                dist.at(e.to) = dist.at(r)+1;
                num.at(e.to) = num.at(r);
            }
            else if(dist.at(r)+1 == dist.at(e.to)){
                num.at(e.to) += num.at(r);
            }
            q.push(e.to);
            used.at(e.id) = true;
//            cout << e.to << " " << dist.at(e.to) << " " << num.at(e.to) << endl;
        }
    }
    cout << num.at(b) << endl;
}