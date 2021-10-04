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
    ll N, T;
    cin >> N >> T;
    mf_graph<ll> graph(2 * N + 2);
    vector<ll> AX(N), AY(N);
    rep(i, N) {
        cin >> AX.at(i) >> AY.at(i);
    }
    vector<ll> BX(N), BY(N);
    rep(i, N) {
        cin >> BX.at(i) >> BY.at(i);
    }
    map<pair<ll, ll>, ll> pos;
    rep(i, N) {
        pos[{BX.at(i), BY.at(i)}] = i + 1;
    }
    vector<ll> dx = { 1, 1, 0, -1, -1, -1, 0 ,1 };
    vector<ll> dy = { 0, 1, 1, 1, 0, -1, -1, -1 };
    ll cnt = 0;
    rep(i, N) {
        vector<ll> idx(8);
        rep(j, 8) {
            idx.at(j) = pos[{AX.at(i) + dx.at(j) * T, AY.at(i) + dy.at(j) * T}];
        }
        rep(j, 8) {
            if (idx.at(j) != 0) {
                graph.add_edge(i, idx.at(j) + N - 1, 1);
                cnt++;
            }
        }
    }
    rep(i, N) {
        graph.add_edge(2 * N, i, 1);
        cnt++;
    }
    rep(i, N) {
        graph.add_edge(N + i, 2 * N + 1, 1);
        cnt++;
    }
    if (graph.flow(2 * N, 2 * N + 1) < N) {
        cout << "No" << '\n';
        return 0;
    }
    cout << "Yes" << '\n';
    vector<ll> D(N);
    rep(i, cnt) {
        if (graph.get_edge(i).flow == 1 && graph.get_edge(i).from < N) {
            ll pl = graph.get_edge(i).to - N;
            rep(j, 8) {
                ll idx = pos[{AX.at(graph.get_edge(i).from) + dx.at(j) * T, AY.at(graph.get_edge(i).from) + dy.at(j) * T}];
                if (idx == pl + 1) {
                    D.at(graph.get_edge(i).from) = j + 1;
                }
            }
        }
    }
    rep(i, N - 1) {
        cout << D.at(i) << " ";
    }
    cout << D.at(N - 1) << '\n';
}