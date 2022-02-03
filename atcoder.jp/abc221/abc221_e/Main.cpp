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

mint op(mint a, mint b) {
    return a + b;
}

mint e() {
    return 0;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) {
        cin >> A.at(i);
        B.at(i) = A.at(i);
    }
    sort(all(B));
    map<ll, ll> comp;
    rep(i, N) {
        comp[B.at(i)] = i;
    }
    segtree<mint, op, e> seg(N);
    mint ans = 0;
    mint x = 2;
    rep(i, N) {
        if (i != 0) {
            ans += x.pow(i - 1) * seg.prod(0, comp.at(A.at(i)) + 1);
        }
        seg.set(comp.at(A.at(i)), seg.get(comp.at(A.at(i))) + x.pow(i).inv());
    }
    cout << ans.val() << endl;
}