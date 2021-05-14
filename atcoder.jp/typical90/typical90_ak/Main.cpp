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

ll op(ll a, ll b) {
    return max(a, b);
}

ll e() {
    return -INF;
}

int main()
{
    ll W, N;
    cin >> W >> N;
    vector<ll> L(N), R(N), V(N);
    rep(i, N) {
        cin >> L.at(i) >> R.at(i) >> V.at(i);
    }
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, -INF));
    dp.at(0).at(0) = 0;
    segtree<ll, op, e> seg(W + 1);
    seg.set(0, 0);
    rep(i, N) {
        rep(j, W + 1) {
            dp.at(i + 1).at(j) = dp.at(i).at(j);
            if (L.at(i) <= j) {
                chmax(dp.at(i + 1).at(j), seg.prod(max(j - R.at(i), 0LL), j - L.at(i) + 1) + V.at(i));
            }
        }
        rep(j, W + 1) {
            seg.set(j, dp.at(i + 1).at(j));
        }
    }
    if (dp.at(N).at(W) < 0) {
        cout << -1 << '\n';
    }
    else {
        cout << dp.at(N).at(W) << '\n';
    }
}