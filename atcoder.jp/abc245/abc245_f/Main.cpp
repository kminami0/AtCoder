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

struct edge {
    ll to;
};
vector<vector<edge>> G;

int main()
{
    ll N, M;
    cin >> N >> M;
    scc_graph graph(N);
    G.resize(N);
    rep(i, M) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        graph.add_edge(u, v);
        G.at(u).push_back({ v });
    }
    vector<vector<int>> SCC = graph.scc();
    vector<ll> idx(N);
    rep(i, sz(SCC)) {
        for (int v : SCC.at(i)) {
            idx.at(v) = i;
        }
    }
    vector<bool> dp(sz(SCC), false);
    ll ans = 0;
    for (ll i = sz(SCC) - 1; i >= 0; i--) {
        if (sz(SCC.at(i)) == 1) {
            for (edge e : G.at(SCC.at(i).at(0))) {
                dp.at(i) = dp.at(i) || dp.at(idx.at(e.to));
            }
        }
        else {
            dp.at(i) = true;
        }
        if (dp.at(i)) {
            ans += sz(SCC.at(i));
        }
    }
    cout << ans << '\n';
}