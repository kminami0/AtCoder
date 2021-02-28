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
#define INF 4e18
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
    ll N;
    cin >> N;
    vector<string> c(N);
    rep(i, N) {
        cin >> c.at(i);
    }
    rep(i, N) {
        rep(j, N) {
            if (i % 2 == 0) {
                if (j % 2 == 1) {
                    if (c.at(i).at(j) == 'B') {
                        c.at(i).at(j) = 'W';
                    }
                    else if(c.at(i).at(j) == 'W'){
                        c.at(i).at(j) = 'B';
                    }
                }
            }
            else if (j % 2 == 0) {
                if (c.at(i).at(j) == 'B') {
                    c.at(i).at(j) = 'W';
                }
                else if (c.at(i).at(j) == 'W') {
                    c.at(i).at(j) = 'B';
                }
            }
        }
    }
    mf_graph<ll> graph(N*N+2);
    rep(i, N) {
        rep(j, N) {
            if (c.at(i).at(j) == 'B') {
                graph.add_edge(N * N, i * N + j, INF);
                graph.add_edge(i * N + j, N * N + 1, 0);
            }
            else if (c.at(i).at(j) == 'W') {
                graph.add_edge(N * N, i * N + j, 0);
                graph.add_edge(i * N + j, N * N + 1, INF);
            }
        }
    }
    rep(i, N) {
        rep(j, N - 1) {
            graph.add_edge(i * N + j, i * N + j + 1, 1);
            graph.add_edge(i * N + j + 1, i * N + j, 1);
        }
    }
    rep(i, N - 1) {
        rep(j, N) {
            graph.add_edge(i * N + j, (i + 1) * N + j, 1);
            graph.add_edge((i + 1) * N + j, i * N + j, 1);
        }
    }
    cout << 2 * N * (N - 1) - graph.flow(N * N, N * N + 1) << '\n';
}