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



int main()
{
    ll N;
    string S, T;
    cin >> N >> S >> T;
    string RT = "";
    string GT = "";
    string BT = "";
    rep(i, N) {
        if (T.at(i) == 'G') {
            RT+='B';
            GT+='G';
            BT+='R';
        }
        else if (T.at(i) == 'B') {
            RT+='G';
            GT+='R';
            BT+='B';
        }
        else {
            RT+='R';
            GT+='B';
            BT+='G';
        }
    }
    vector<mint> sh(N + 1, 0), rh(N + 1, 0), gh(N + 1, 0), bh(N + 1, 0);
    //sh.at(i)はSの初めi文字のハッシュ値
    rep(i, N) {
        sh.at(i + 1) = sh.at(i) * 83 + S.at(i);
        rh.at(i + 1) = rh.at(i) * 83 + RT.at(i);
        gh.at(i + 1) = gh.at(i) * 83 + GT.at(i);
        bh.at(i + 1) = bh.at(i) * 83 + BT.at(i);
    }
    vector<mint> p(N + 1, 1);
    rep(i, N) {
        p.at(i + 1) = p.at(i) * 83;
    }
    ll ans = 0;
    rep2(k, -N + 1, 0) {
        mint Shash = sh.at(N) - sh.at(-k) * p.at(N + k);
        mint Rhash = rh.at(N + k);
        mint Ghash = gh.at(N + k);
        mint Bhash = bh.at(N + k);
        if (Shash == Rhash || Shash == Ghash || Shash == Bhash) {
            ans++;
        }
    }
    rep(k, N) {
        mint Shash = sh.at(N - k);
        mint Rhash = rh.at(N) - rh.at(k) * p.at(N - k);
        mint Ghash = gh.at(N) - gh.at(k) * p.at(N - k);
        mint Bhash = bh.at(N) - bh.at(k) * p.at(N - k);
        if (Shash == Rhash || Shash == Ghash || Shash == Bhash) {
            ans++;
        }
    }
    cout << ans << endl;
}