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

ll op(ll a, ll b) {
    return a + b;
}

ll e() {
    return 0;
}

int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    rep(i, N) {
        cin >> B.at(i);
        B.at(i) *= -1;
    }
    vector<pair<ll, ll>> present(N);
    rep(i, N) {
        present.at(i) = { A.at(i), B.at(i) };
    }
    sort(all(A));
    map<ll, ll> compA;
    rep(i, N) {
        compA[A.at(i)] = i;
    }
    sort(all(B));
    map<ll, ll> compB;
    rep(i, N) {
        compB[B.at(i)] = i;
    }
    rep(i, N) {
        present.at(i) = { compA.at(present.at(i).first), compB.at(present.at(i).second) };
    }
    sort(all(present));
    segtree<ll, op, e> seg(N);
    ll ans = 0;
    ll cnt = 1;
    rep(i, N) {
        if (i < N-1 && present.at(i) == present.at(i + 1)) {
            cnt++;
            continue;
        }
        seg.set(present.at(i).second, seg.get(present.at(i).second) + cnt);
        ans += cnt * seg.prod(0, present.at(i).second + 1);
        cnt = 1;
    }
    cout << ans << endl;
}