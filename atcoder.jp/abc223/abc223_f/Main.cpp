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
#define sz(v) ll(v.size())
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
    return x + f;
}

ll composition(ll f, ll g) {
    return f + g;
}

ll id() {
    return 0;
}

string S;

lazy_segtree<ll, op, e, ll, mapping, composition, id> seg(200001);

void solve() {
    ll x, l, r;
    cin >> x >> l >> r;
    if (x == 1) {
        if (S.at(l - 1) == '(' && S.at(r - 1) == ')') {
            seg.apply(l, r, -2);
        }
        else if (S.at(l - 1) == ')' && S.at(r - 1) == '(') {
            seg.apply(l, r, 2);
        }
        swap(S.at(l - 1), S.at(r - 1));
    }
    else {
        ll m = seg.prod(l, r + 1);
        if (m < seg.get(l - 1)) {
            cout << "No" << endl;
        }
        else if (seg.get(l - 1) != seg.get(r)) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
}

int main()
{
    ll N, Q;
    cin >> N >> Q >> S;
    seg.set(0, 0);
    rep(i, N) {
        if (S.at(i) == '(') {
            seg.set(i + 1, seg.get(i) + 1);
        }
        else {
            seg.set(i + 1, seg.get(i) - 1);
        }
    }
    rep(i, Q) {
        solve();
    }
}