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
    return a ^ b;
}

ll e() {
    return 0;
}

int main()
{
    ll H, W, M;
    cin >> H >> W >> M;
    vector<ll> X(M), Y(M);
    rep(i, M) {
        cin >> X.at(i) >> Y.at(i);
        X.at(i)--;
        Y.at(i)--;
    }
    map<ll, ll> rowrock;
    rep(i, H) {
        rowrock[i] = W;
    }
    rep(i, M) {
        chmin(rowrock.at(X.at(i)), Y.at(i));
    }
    map<ll, ll> columnrock;
    rep(i, W) {
        columnrock[i] = H;
    }
    rep(i, M) {
        chmin(columnrock.at(Y.at(i)), X.at(i));
    }
    ll ans = 0;
    rep(i, columnrock.at(0)) {
        ans += rowrock.at(i);
    }
    rep(i, rowrock.at(0)) {
        ans += columnrock.at(i);
    }
    fenwick_tree<ll> fw(W);
    rep(i, rowrock.at(0)) {
        fw.add(i, 1);
    }
    vector<set<ll>> rowrocks(H);
    rep(i, M) {
        rowrocks.at(X.at(i)).insert(Y.at(i));
    }
    rep(i, columnrock.at(0)) {
        ans -= fw.sum(0, rowrock.at(i));
        if (i < H - 1) {
            for (auto p : rowrocks.at(i + 1)) {
                if (fw.sum(p, p + 1) == 1) {
                    fw.add(p, -1);
                }
            }
        }
    }
    cout << ans << endl;
}