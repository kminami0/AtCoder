#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1e18
#define EPSILON 1e-14
template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

struct edge {
    ll to;
    ll weight;
};
vector<vector<edge>> graph;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

vector<bool> vst(200000, false);
vector<ll> dst(200000, 0);

void dfs(ll x, ll w, ll p = -1) {
    if (vst.at(x)) {
        return;
    }
    vst.at(x) = true;
    if (p != -1) {
        dst.at(x) = dst.at(p) ^ w;
    }
    for (edge e : graph.at(x)) {
        dfs(e.to, e.weight, x);
    }
}

vector<mint> fac(2000003, 1);
void calc(int n) {
    rep(i, n) {
        fac.at(i + 1) = fac.at(i) * (i + 1);
    }
    return;
}

mint mpow(mint x, ll y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        mint a = mpow(x, y / 2);
        return a * a;
    }
    else {
        mint a = mpow(x, y / 2);
        return a * a * x;
    }
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    calc(N);
    rep(i, N - 1) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph.at(u).push_back({ v, w });
        graph.at(v).push_back({ u, w });
    }
    dfs(0, 0);
    vector<ll> cnt(60);
    rep(i, N) {
        bitset<60> d(dst.at(i));
        rep(j, 60) {
            if (d.test(j)) {
                cnt.at(j)++;
            }
        }
    }
    mint ans = 0;
    rep(i, 60) {
        ans += mpow(2, i) * cnt.at(i) * (N - cnt.at(i));
    }
    cout << ans << '\n';
}