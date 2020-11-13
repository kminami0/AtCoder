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
#include <numeric>

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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    vector<ll> dp(300001, 0); //dp.at(i)は最後にiを選んだときのBの最大長
    segtree<ll, op, e> seg(300001); //区間最大値を求めるセグ木
    rep(i, N) {
        chmax(dp.at(A.at(i)), seg.prod(max(A.at(i) - K, 0LL), min(A.at(i) + K, 300000LL) + 1) + 1);
        seg.set(A.at(i), dp.at(A.at(i)));
    }
    ll ans = 0;
    rep(i, 300001) {
        chmax(ans, dp.at(i));
    }
    cout << ans << endl;
}