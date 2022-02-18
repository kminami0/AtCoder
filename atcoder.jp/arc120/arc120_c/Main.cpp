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

using mint = modint998244353;

ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) {
        cin >> A.at(i);
        A.at(i) += i;
    }
    rep(i, N) {
        cin >> B.at(i);
        B.at(i) += i;
    }
    multiset<ll> as, bs;
    rep(i, N) {
        as.insert(A.at(i));
        bs.insert(B.at(i));
    }
    if (as != bs) {
        cout << -1 << endl;
        return 0;
    }
    map<ll, queue<ll>> bm;
    rep(i, N) {
        bm[B.at(i)].push(i);
    }
    vector<ll> s(N);
    rep(i, N) {
        ll p = bm.at(A.at(i)).front();
        bm.at(A.at(i)).pop();
        s.at(i) = p;
    }
    segtree<ll, op, e> seg(N);
    ll ans = 0;
    rep(i, N) {
        seg.set(s.at(i), seg.get(s.at(i)) + 1);
        ans += seg.prod(s.at(i) + 1, N);
    }
    cout << ans << endl;
}