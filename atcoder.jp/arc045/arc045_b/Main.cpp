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
#include <numeric>

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
    return min(a, b);
}

ll e() {
    return INF;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> s(M), t(M);
    rep(i, M) {
        cin >> s.at(i) >> t.at(i);
    }
    //いもす法で各教室が何個の区間で覆われているか調べる
    vector<ll> imos(N + 2, 0);
    rep(i, M) {
        imos.at(s.at(i))++;
        imos.at(t.at(i) + 1)--;
    }
    rep(i, N) {
        imos.at(i + 1) += imos.at(i);
    }
    //セグメント木で区間ごとの含まれる教室の覆われる区間の数の最小値を求める
    segtree<ll, op, e> seg(N+2);
    rep(i, N + 2) {
        seg.set(i, imos.at(i));
    }
    vector<ll> ans(0);
    rep(i, M) {
        if (seg.prod(s.at(i), t.at(i) + 1) >= 2) {
            ans.push_back(i);
        }
    }
    cout << sz(ans) << endl;
    rep(i, sz(ans)) {
        cout << ans.at(i) + 1 << endl;
    }
}