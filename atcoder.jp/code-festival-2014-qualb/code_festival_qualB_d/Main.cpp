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
#define INF 100000000000000 //10^14
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

int main()
{
    ll N;
    cin >> N;
    segtree<ll, op, e> seg(N + 2);
    vector<ll> h(N + 2);
    seg.set(0, INF);
    h.at(0) = INF;
    rep(i, N) {
        cin >> h.at(i+1);
        seg.set(i + 1, h.at(i+1));
    }
    seg.set(N + 1, INF);
    h.at(N + 1) = INF;
    vector<ll> ans(N);
    rep(i, N) {
        ll l = 0;
        ll r = i + 1;
        // seg.prod(r, i+1) <= h.at(i+1) < seg.prod(l, i+1)
        while (r - l > 1) {
            ll c = (l + r) / 2;
            if (seg.prod(c, i + 1) <= h.at(i + 1)) {
                r = c;
            }
            else {
                l = c;
            }
        }
        ll left = i - r + 1;
        l = i + 1;
        r = N + 2;
        // seg.prod(i+1, l) <= h.at(i+1) < seg.prod(i+1, r);
        while (r - l > 1) {
            ll c = (l + r) / 2;
            if (seg.prod(i + 1, c) <= h.at(i + 1)) {
                l = c;
            }
            else {
                r = c;
            }
        }
        ll right = l - i - 2;
        ans.at(i) = left + right;
    }
    rep(i, N) {
        cout << ans.at(i) << endl;
    }
}