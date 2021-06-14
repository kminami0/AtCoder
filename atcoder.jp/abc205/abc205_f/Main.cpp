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
    ll H, W, N;
    cin >> H >> W >> N;
    vector<ll> A(N), B(N), C(N), D(N);
    rep(i, N) {
        cin >> A.at(i) >> B.at(i) >> C.at(i) >> D.at(i);
    }
    mf_graph<ll> graph(1+H+2*N+W+1);
    rep(i, H) {
        graph.add_edge(0, i + 1, 1);
    }
    rep(i, N) {
        rep2(j, A.at(i), C.at(i) + 1) {
            graph.add_edge(j, H + 1 + i, 1);
        }
    }
    rep(i, N) {
        graph.add_edge(H + 1 + i, H + 1 + i + N, 1);
    }
    rep(i, N) {
        rep2(j, B.at(i), D.at(i) + 1) {
            graph.add_edge(H + 1 + i + N, H + 2 * N + j, 1);
        }
    }
    rep(i, W) {
        graph.add_edge(1 + H + 2 * N + i, 1 + H + 2 * N + W, 1);
    }
    cout << graph.flow(0, 1 + H + 2 * N + W) << endl;
}