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

int main()
{
    ll N, W;
    cin >> N >> W;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> k(N);
    vector<vector<ll>> c(N);
    rep(i, N) {
        cin >> k.at(i);
        c.at(i).resize(k.at(i));
        rep(j, k.at(i)) {
            cin >> c.at(i).at(j);
            c.at(i).at(j)--;
        }
    }
    mf_graph<ll> graph(N + 2);
    rep(i, N) {
        graph.add_edge(N, i, A.at(i));
        graph.add_edge(i, N + 1, W);
        rep(j, k.at(i)) {
            graph.add_edge(c.at(i).at(j), i, INF);
        }
    }
    ll sum = 0;
    rep(i, N) {
        sum += A.at(i);
    }
    cout << sum - graph.flow(N, N + 1) << endl;
}