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

using mint = modint998244353;

vector<mint> fac(3000003, 1);
void calc(int n) {
    rep(i, n) {
        fac.at(i + 1) = fac.at(i) * (i + 1);
    }
    return;
}

mint mcom(int n, int k) { // nCk
    if (n - k < 0) {
        return 0;
    }
    mint a = fac.at(n);
    mint b = fac.at(k);
    mint d = fac.at(n - k);
    mint ans = a / (b * d);
    return ans;
}

int main()
{
    calc(3000000);
    ll R, G, B, K, X, Y, Z;
    cin >> R >> G >> B >> K >> X >> Y >> Z;
    vector<ll> a(K+1, 0), b(K+1, 0), c(K+1, 0);
    rep(i, K + 1) {
        if (K - Y <= i && i <= R) {
            a.at(i) = mcom(R, i).val();
        }
        if (K - Z <= i && i <= G) {
            b.at(i) = mcom(G, i).val();
        }
        if (K - X <= i && i <= B) {
            c.at(i) = mcom(B, i).val();
        }
    }
    vector<ll> d = convolution(a, b);
    mint ans = 0;
    rep(i, K + 1) {
        ans += d.at(i) * c.at(K - i);
    }
    cout << ans.val() << endl;
}