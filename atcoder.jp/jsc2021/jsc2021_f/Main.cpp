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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<ll> T(Q), X(Q), Y(Q);
    rep(i, Q) {
        cin >> T.at(i) >> X.at(i) >> Y.at(i);
        X.at(i)--;
    }
    map<ll, ll> cnt;
    rep(i, Q) {
        cnt[Y.at(i)]++;
    }
    vector<ll> comp(0);
    comp.push_back(-1);
    comp.push_back(0);
    for (auto p : cnt) {
        rep(i, p.second) {
            comp.push_back(p.first);
        }
    }
    comp.push_back(INF);
    ll ans = 0;
    segtree<ll, op, e> Acnt(Q+2);
    segtree<ll, op, e> Bcnt(Q+2);
    segtree<ll, op, e> Atot(Q+2);
    segtree<ll, op, e> Btot(Q+2);
    Acnt.set(0, N);
    Bcnt.set(0, M);
    vector<ll> a(N, 0), b(M, 0);
    rep(i, Q) {
        if (T.at(i) == 1) {
            ll x = a.at(X.at(i));
            ll y = Y.at(i);
            ll l = 0;
            ll r = sz(comp) - 1;
            // comp.at(l) < x <= comp.at(r)
            while (r - l > 1) {
                ll c = (l + r) / 2;
                if (comp.at(c) < x) {
                    l = c;
                }
                else {
                    r = c;
                }
            }
            Acnt.set(r, Acnt.get(r) - 1);
            Atot.set(r, Atot.get(r) - comp.at(r));
            ll f = Bcnt.prod(0, l + 1) * x;
            ll s = Btot.prod(r, Q+2);
            ans -= f + s;
            l = 0;
            r = sz(comp) - 1;
            // comp.at(l) < y <= comp.at(r)
            while (r - l > 1) {
                ll c = (l + r) / 2;
                if (comp.at(c) < y) {
                    l = c;
                }
                else {
                    r = c;
                }
            }
            Acnt.set(r, Acnt.get(r) + 1);
            Atot.set(r, Atot.get(r) + comp.at(r));
            f = Bcnt.prod(0, l + 1) * y;
            s = Btot.prod(r, Q+2);
            ans += f + s;
            a.at(X.at(i)) = y;
        }
        else {
            ll x = b.at(X.at(i));
            ll y = Y.at(i);
            ll l = 0;
            ll r = sz(comp) - 1;
            // comp.at(l) < x <= comp.at(r)
            while (r - l > 1) {
                ll c = (l + r) / 2;
                if (comp.at(c) < x) {
                    l = c;
                }
                else {
                    r = c;
                }
            }
            Bcnt.set(r, Bcnt.get(r) - 1);
            Btot.set(r, Btot.get(r) - comp.at(r));
            ll f = Acnt.prod(0, l + 1) * x;
            ll s = Atot.prod(r, Q+2);
            ans -= f + s;
            l = 0;
            r = sz(comp) - 1;
            // comp.at(l) < y <= comp.at(r)
            while (r - l > 1) {
                ll c = (l + r) / 2;
                if (comp.at(c) < y) {
                    l = c;
                }
                else {
                    r = c;
                }
            }
            Bcnt.set(r, Bcnt.get(r) + 1);
            Btot.set(r, Btot.get(r) + comp.at(r));
            f = Acnt.prod(0, l + 1) * y;
            s = Atot.prod(r, Q+2);
            ans += f + s;
            b.at(X.at(i)) = y;
        }
        cout << ans << endl;
    }
}