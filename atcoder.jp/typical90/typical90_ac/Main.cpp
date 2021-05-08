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
    return 0;
}

ll mapping(ll f, ll x) {
    if (f == INF) {
        return x;
    }
    return f;
}

ll composition(ll f, ll g) {
    if (f == INF) {
        return g;
    }
    return f;
}

ll id() {
    return INF;
}

int main()
{
    ll W, N;
    cin >> W >> N;
    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(W);
    rep(i, N) {
        ll L, R;
        cin >> L >> R;
        L--;
        ll height = seg.prod(L, R);
        cout << height + 1 << '\n';
        seg.apply(L, R, height + 1);
    }
}