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
    return a + b;
}

ll e() {
    return 0;
}

int main()
{
    ll Q;
    cin >> Q;
    segtree<ll, op, e> seg(200001);
    rep(i, Q) {
        ll T, X;
        cin >> T >> X;
        if (T == 1) {
            seg.set(X, 1);
        }
        else {
            ll l = 0;
            ll r = 200001;
            //l未満の数の個数 < X <= r未満の数の個数
            while (r - l > 1) {
                ll c = (l + r) / 2;
                if (seg.prod(0, c) < X) {
                    l = c;
                }
                else {
                    r = c;
                }
            }
            cout << r - 1 << endl;
            seg.set(r - 1, 0);
        }
    }
}