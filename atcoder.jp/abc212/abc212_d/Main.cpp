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
using mint = modint1000000007;
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
    return min(a, b);
}

ll e() {
    return INF;
}

ll mapping(ll f, ll x) {
    return f + x;
}

ll composition(ll f, ll g) {
    return f + g;
}

ll id() {
    return 0;
}

ll x;

bool g(ll y) {
    return y > x;
};

int main()
{
    ll Q;
    cin >> Q;
    lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(Q+5);
    rep(i, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll X;
            cin >> X;
            seg.set(i, X);
            //cout << t << " " << X << endl;
        }
        else if (t == 2) {
            ll X;
            cin >> X;
            seg.apply(0, i, X);
            //cout << t << " " << X << endl;
        }
        else if (t == 3) {
            x = seg.prod(0, i);
            cout << x << endl;
            ll p = seg.max_right<g>(0);
            seg.set(p, INF);
            //cout << t << " " << p << endl;
        }
    }
}