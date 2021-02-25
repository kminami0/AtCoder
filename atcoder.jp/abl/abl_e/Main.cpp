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
#define INF 1e17
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

vector<mint> repunit(200001);

struct num {
    mint val;
    ll len;
};

num op(num x, num y) {
    mint z = 10;
    return { x.val * z.pow(y.len) + y.val, x.len + y.len };
}

num e() {
    return { 0, 0 };
}

num mapping(mint f, num x) {
    if (f == 0) {
        return x;
    }
    else {
        return { repunit.at(x.len) * f, x.len };
    }
}

mint composition(mint f, mint g) {
    if (f == 0) {
        return g;
    }
    else {
        return f;
    }
}

mint id() {
    return 0;
}

int main()
{
    repunit.at(1) = 1;
    rep(i, 199999) {
        repunit.at(i + 2) = repunit.at(i + 1) * 10 + 1;
    }
    ll N, Q;
    cin >> N >> Q;
    lazy_segtree<num, op, e, mint, mapping, composition, id> seg(N);
    rep(i, N) {
        seg.set(i, { 1, 1 });
    }
    rep(i, Q) {
        ll L, R, D;
        cin >> L >> R >> D;
        seg.apply(L - 1, R, mint(D));
        cout << seg.all_prod().val.val() << endl;
    }
}