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

ll K;

map<ll, vector<mint>> b;
//b.at(i).at(j)はa.at(i)をa.at(0),...,a.at(K-1)の線形結合で表したときのa.at(K-1-j)の係数

vector<mint> convolution(vector<mint> a, vector<mint> b) {
    vector<mint> c(sz(a) + sz(b) - 1, 0);
    rep(i, sz(a) + sz(b) - 1) {
        rep(j, i + 1) {
            if (j >= sz(a) || i - j >= sz(b)) {
                continue;
            }
            c.at(i) += a.at(j) * b.at(i - j);
        }
    }
    return c;
}

vector<mint> kitamasa(ll N) {
    if (N < K) {
        return b.at(N);
    }
    vector<mint> c = kitamasa(N / 2);
    vector<mint> beta = convolution(c, c);
    if (!b.count(2 * (N / 2))) {
        b[2 * (N / 2)] = {};
        rep(i, K) {
            b.at(2 * (N / 2)).push_back(beta.at(K - 1 + i));
        }
        rep2(i, K, 2 * K - 1) {
            rep(j, K) {
                b.at(2 * (N / 2)).at(j) += b.at(i).at(j) * beta.at(2 * K - 2 - i);
            }
        }
    }
    if (N % 2 == 0) {
        return b.at(N);
    }
    if (!b.count(N)) {
        b[N] = {};
        rep(i, K - 1) {
            b.at(N).push_back(b.at(N - 1).at(i + 1));
        }
        b.at(N).push_back(0);
        rep(i, K) {
            b.at(N).at(K - 1 - i) += b.at(N - 1).at(0);
        }
    }
    return b.at(N);
}

int main()
{
    ll N;
    cin >> K >> N;
    if (N < K) {
        cout << 1 << '\n';
        return 0;
    }
    b[K] = {};
    rep(i, K) {
        b.at(K).push_back(1);
    }
    rep(i, K) {
        b[i] = {};
        rep(j, K) {
            if (i + j == K - 1) {
                b.at(i).push_back(1);
            }
            else {
                b.at(i).push_back(0);
            }
        }
    }
    rep2(i, K + 1, 2 * K - 1) {
        b[i] = b[i - 1];
        rep(j, K) {
            b.at(i).at(j) *= 2;
        }
        rep(j, K) {
            b.at(i).at(j) -= b.at(i - 1 - K).at(j);
        }
    }
    vector<mint> v = kitamasa(N-1);
    mint ans = 0;
    rep(i, K) {
        ans += v.at(i);
    }
    cout << ans.val() << endl;
}