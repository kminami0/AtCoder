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



int main()
{
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) {
        cin >> A.at(i);
    }
    ll shift = 0;
    rep(i, Q) {
        ll T, x, y;
        cin >> T >> x >> y;
        if (T == 1) {
            x--;
            y--;
            x -= shift;
            y -= shift;
            if (x < 0) {
                x += N;
            }
            if (y < 0) {
                y += N;
            }
            swap(A.at(x), A.at(y));
        }
        else if (T == 2) {
            shift++;
            shift %= N;
        }
        else {
            x--;
            x -= shift;
            if (x < 0) {
                x += N;
            }
            cout << A.at(x) << endl;
        }
    }
}