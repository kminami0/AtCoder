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
vector<vector<edge>> graph;

vector<vector<ll>> dp(100000, vector<ll>(20, -1));
vector<ll> X(100000);

void dfs(ll v, ll p = -1) {
    if (sz(graph.at(v)) == 1) {
        dp.at(v).at(0) = X.at(v);
        return;
    }
    for (edge e : graph.at(v)) {
        if (e.to == p) {
            continue;
        }
        dfs(e.to, v);
        vector<ll> tmp(40);
        rep(i, 20) {
            tmp.at(i) = dp.at(v).at(i);
        }
        rep(i, 20) {
            tmp.at(i + 20) = dp.at(e.to).at(i);
        }
        sort(all(tmp));
        reverse(all(tmp));
        rep(i, 20) {
            dp.at(v).at(i) = tmp.at(i);
        }
    }
    dp.at(v).push_back(X.at(v));
    sort(all(dp.at(v)));
    reverse(all(dp.at(v)));
    dp.at(v).pop_back();
}

using mint = modint998244353;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    vector<vector<vector<mint>>> dp(N + 1, vector<vector<mint>>(1024, vector<mint>(11, 0)));
    dp.at(0).at(0).at(10) = 1;
    rep(i, N) {
        ll p = S.at(i) - 'A';
        rep(j, 1024) {
            bitset<10> s(j);
            if (s.test(p)) {
                continue;
            }
            rep(k, 10) {
                if (k == p) {
                    dp.at(i + 1).at(j).at(p) += dp.at(i).at(j).at(k);
                    if (dp.at(i).at(j).at(k) != 0) {
                        // cout << i + 1 << " " << j << " " << p << " " << dp.at(i + 1).at(j).at(p).val() << endl;
                    }
                }
                else if (s.test(k)) {
                    ll x = 1023 - (1 << k);
                    dp.at(i + 1).at(j).at(p) += dp.at(i).at(j & x).at(k);
                    if (dp.at(i).at(j & x).at(k) != 0) {
                        // cout << i + 1 << " " << j << " " << p << " " << dp.at(i + 1).at(j).at(p).val() << endl;
                    }
                }
            }
        }
        dp.at(i + 1).at(0).at(p) += dp.at(i).at(0).at(10);
        // cout << i + 1 << " " << 0 << " " << p << " " << dp.at(i + 1).at(0).at(p).val() << endl;
        rep(j, 1024) {
            rep(k, 11) {
                dp.at(i + 1).at(j).at(k) += dp.at(i).at(j).at(k);
            }
        }
    }
    mint ans = 0;
    rep(i, 1024) {
        rep(j, 10) {
            ans += dp.at(N).at(i).at(j);
        }
    }
    cout << ans.val() << '\n';
}