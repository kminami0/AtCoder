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

int main()
{
    ll N, K;
    string S;
    cin >> N >> K >> S;
    if (2*(K-1)+1 > N) {
        cout << sz(S) << '\n';
        return 0;
    }
    fenwick_tree<ll> fw(N+10);
    ll cnt = 1;
    ll p = 0;
    rep(i, sz(S) - 1) {
        if (S.at(i) != S.at(i + 1)) {
            fw.add(p, cnt);
            p++;
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    fw.add(p, cnt);
    if (fw.sum(1, 2) == 0) {
        cout << sz(S) << '\n';
        return 0;
    }
    ll ans = 0;
    ll i = 0;
    if (S.at(0) == '0') {
        while (i + 2 * (K - 1) < N) {
            if (i == 0) {
                chmax(ans, fw.sum(i, i + 2 * (K - 1) + 2));
            }
            else {
                chmax(ans, fw.sum(i-1, i + 2 * (K - 1) + 2));
            }
            i += 2;
        }
    }
    else {
        while (i + 1 + 2 * (K - 1) < N) {
            chmax(ans, fw.sum(i, i + 1 + 2 * (K - 1) + 2));
            i += 2;
        }
    }
    cout << ans << '\n';
}