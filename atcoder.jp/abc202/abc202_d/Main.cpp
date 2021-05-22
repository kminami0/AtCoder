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


std::vector<std::vector<long long>> comb(int n, int r) {
    std::vector<std::vector<long long>> v(n + 1, std::vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
    return v;
}

int main()
{
    ll A, B, K;
    cin >> A >> B >> K;
    string ans = "";
    ll length = A + B;
    vector<vector<ll>> combi = comb(60, 30);
    ll Acnt = 0;
    ll Bcnt = 0;
    ll smaller = 0;
    rep(i, A + B) {
        ll rem = combi.at(A + B - Acnt - Bcnt).at(A - Acnt);
        ll astart = combi.at(A + B - Acnt - 1 - Bcnt).at(A - Acnt - 1);
        if (smaller + astart >= K) {
            ans += "a";
            Acnt++;
        }
        else {
            ans += "b";
            Bcnt++;
            smaller += astart;
        }
        if (Acnt == A) {
            rep(i, B - Bcnt) {
                ans += "b";
            }
        }
        else if (Bcnt == B) {
            rep(i, A - Acnt) {
                ans += "a";
            }
        }
        if (Acnt == A || Bcnt == B) {
            break;
        }
    }
    cout << ans << endl;
}