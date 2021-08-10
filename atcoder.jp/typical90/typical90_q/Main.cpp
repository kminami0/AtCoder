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
    return a + b;
}

ll e() {
    return 0;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> L(M), R(M);
    vector<ll> Lcnt(N), Rcnt(N);
    vector<ll> Racc(N + 1, 0);
    vector<pair<ll, ll>> seg(M);
    rep(i, M) {
        cin >> L.at(i) >> R.at(i);
        L.at(i)--;
        R.at(i)--;
        seg.at(i) = { R.at(i), L.at(i) };
        Lcnt.at(L.at(i))++;
        Rcnt.at(R.at(i))++;
    }
    sort(all(seg));
    rep(i, N) {
        Racc.at(i + 1) = Racc.at(i) + Rcnt.at(i);
    }
    ll ans = 0;
    rep(i, N) {
        ll cnt = Lcnt.at(i) + Rcnt.at(i);
        ans += cnt * (cnt - 1) / 2;
    }
    rep(i, M) {
        ans += Racc.at(L.at(i));
    }
    segtree<ll, op, e> st(N);
    rep(i, M) {
        ll left = seg.at(i).second;
        ll right = seg.at(i).first;
        ans += st.prod(left + 1,  right);
        st.set(left, st.get(left) + 1);
    }
    ans = M * (M - 1) / 2 - ans;
    cout << ans << '\n';
}