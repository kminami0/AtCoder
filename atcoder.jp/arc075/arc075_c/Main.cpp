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
#define INF 4e18
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

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    fenwick_tree<ll> fw(N+2);
    rep(i, N) cin >> a.at(i);
    vector<ll> acc(N + 1, 0);
    rep(i, N) {
        acc.at(i + 1) = acc.at(i) + a.at(i);
    }
    vector<ll> b(N + 1, 0);
    rep(i, N) {
        b.at(i + 1) = acc.at(i + 1) - (i + 1) * K;
    }
    set<ll> val;
    rep(i, N + 1) {
        val.insert(b.at(i));
    }
    vector<ll> c(0);
    c.emplace_back(-INF);
    for (ll p : val) {
        c.emplace_back(p);
    }
    rep(i, N + 1) {
        ll l = 0;
        ll r = sz(c)-1;
        // c.at(l) < b.at(i) <= c.at(r)
        while (r - l > 1) {
            ll ct = (l + r) / 2;
            if (c.at(ct) < b.at(i)) {
                l = ct;
            }
            else {
                r = ct;
            }
        }
        b.at(i) = r;
    }
    ll ans = 0;
    rep(i, N + 1) {
        ans += fw.sum(0, b.at(i) + 1);
        fw.add(b.at(i), 1);
    }
    cout << ans << '\n';
}