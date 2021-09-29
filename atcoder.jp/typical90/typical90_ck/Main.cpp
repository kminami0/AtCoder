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

using mint = modint1000000007;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<ll> comp(N);
    rep(i, N) {
        comp.at(i) = A.at(i);
    }
    sort(all(comp));
    comp.erase(unique(all(comp)), end(comp));
    map<ll, ll> p;
    rep(i, sz(comp)) {
        p[comp.at(i)] = i;
    }
    vector<ll> cl(N);
    // cl.at(i)は区間[l, r]の転倒数がK以下となる最小のl
    ll l = N - 1;
    ll r = N - 1;
    ll inv = 0;
    bool flag = true;
    fenwick_tree<ll> fw(N);
    while (r >= 0) {
        if (flag) {
            fw.add(p.at(A.at(l)), 1);
            inv += fw.sum(0, p.at(A.at(l)));
        }
        if (l == 0 && inv <= K) {
            cl.at(r) = 0;
            r--;
        }
        flag = false;
        if (inv > K) {
            cl.at(r) = l + 1;
            inv -= fw.sum(p.at(A.at(r)) + 1, N);
            fw.add(p.at(A.at(r)), -1);
            r--;
        }
        else {
            if (l > 0) {
                l--;
                flag = true;
            }
        }
    }
    vector<mint> dp(N + 1, 0);
    dp.at(0) = 1;
    vector<mint> acc(N + 2, 0);
    acc.at(0) = 0;
    acc.at(1) = 1;
    rep(i, N) {
        dp.at(i + 1) += acc.at(i + 1) - acc.at(cl.at(i));
        acc.at(i + 2) = acc.at(i + 1) + dp.at(i + 1);
    }
    cout << dp.at(N).val() << '\n';
}