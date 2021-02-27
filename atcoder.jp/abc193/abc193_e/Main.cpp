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

using mint = modint;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll solve(ll X, ll Y, ll P, ll Q) {
    ll ans = INF;
    ll g = gcd(2 * X + 2 * Y, P + Q);
    rep(i, Q) {
        if ((P + i - X) % g != 0) {
            continue;
        }
        mint::set_mod((P+Q)/g);
        mint a = (P + i - X) / g;
        mint b = (2 * X + 2 * Y) / g;
        mint n = a / b;
        chmin(ans, (2 * X + 2 * Y) * n.val() + X);
    }
    rep(i, Y) {
        if ((X + i - P) % g != 0) {
            continue;
        }
        mint::set_mod((2 * X + 2 * Y) / g);
        mint a = (X + i - P) / g;
        mint b = (P + Q) / g;
        mint m = a / b;
        chmin(ans, (P + Q) * m.val() + P);
    }
    return ans;
}

int main()
{
    ll T;
    cin >> T;
    rep(i, T) {
        ll X, Y, P, Q;
        cin >> X >> Y >> P >> Q;
        ll s = solve(X, Y, P, Q);
        if (s == INF) {
            cout << "infinity" << endl;
        }
        else {
            cout << s << endl;
        }
    }
}