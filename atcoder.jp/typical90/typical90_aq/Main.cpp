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


struct edge {
    ll to;
    ll cost;
};

vector<vector<edge>> graph;

int main()
{
    ll H, W;
    ll rs, cs, rt, ct;
    cin >> H >> W >> rs >> cs >> rt >> ct;
    rs--;
    cs--;
    rt--;
    ct--;
    vector<string> S(H);
    rep(i, H) {
        cin >> S.at(i);
    }
    graph.resize(H * W * 2);
    rep(i, H) {
        rep(j, W) {
            if (S.at(i).at(j) == '#') {
                continue;
            }
            if (i > 0) {
                if (S.at(i - 1).at(j) == '.') {
                    graph.at(W * i + j).push_back({ W * (i - 1) + j, 0 });
                    graph.at(W * i + j + H * W).push_back({ W * (i - 1) + j, 1 });
                }
            }
            if (i < H - 1) {
                if (S.at(i + 1).at(j) == '.') {
                    graph.at(W * i + j).push_back({ W * (i + 1) + j, 0 });
                    graph.at(W * i + j + H * W).push_back({ W * (i + 1) + j, 1 });
                }
            }
            if (j > 0) {
                if (S.at(i).at(j - 1) == '.') {
                    graph.at(W * i + j).push_back({ W * i + j - 1 + H * W, 1 });
                    graph.at(W * i + j + H * W).push_back({ W * i + j - 1 + H * W, 0 });
                }
            }
            if (j < W - 1) {
                if (S.at(i).at(j + 1) == '.') {
                    graph.at(W * i + j).push_back({ W * i + j + 1 + H * W, 1 });
                    graph.at(W * i + j + H * W).push_back({ W * i + j + 1 + H * W, 0 });
                }
            }
        }
    }
    deque<pair<ll, ll>> q;
    q.push_back({ 0, W * rs + cs });
    vector<ll> dst(H * W * 2, INF);
    dst.at(W * rs + cs) = 0;
    while (!q.empty()) {
        pair<ll, ll> p = q.front();
        q.pop_front();
        for (edge e : graph.at(p.second)) {
            if (chmin(dst.at(e.to), p.first + e.cost)) {
                if (e.cost == 0) {
                    q.push_front({ dst.at(e.to), e.to });
                }
                else {
                    q.push_back({ dst.at(e.to), e.to });
                }
            }
        }
    }
    ll ans = dst.at(W * rt + ct);
    chmin(ans, dst.at(W* rt + ct + H * W));
    rep(i, H* W * 2) {
        dst.at(i) = INF;
    }
    dst.at(W* rs + cs + H * W) = 0;
    q.push_back({ 0, W * rs + cs + H * W });
    while (!q.empty()) {
        pair<ll, ll> p = q.front();
        q.pop_front();
        for (edge e : graph.at(p.second)) {
            if (chmin(dst.at(e.to), p.first + e.cost)) {
                if (e.cost == 0) {
                    q.push_front({ dst.at(e.to), e.to });
                }
                else {
                    q.push_back({ dst.at(e.to), e.to });
                }
            }
        }
    }
    chmin(ans, dst.at(W* rt + ct));
    chmin(ans, dst.at(W* rt + ct + H * W));
    cout << ans << endl;
}