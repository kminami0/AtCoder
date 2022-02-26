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
#define sz(v) ll(v.size())
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
    return a+b;
}

ll e() {
    return 0;
}

int main()
{
    ll Q;
    cin >> Q;
    vector<tuple<ll, ll, ll>> query(0);
    set<ll> S;
    rep(i, Q) {
        ll c;
        cin >> c;
        if (c == 1) {
            ll x;
            cin >> x;
            S.insert(x);
            query.push_back({ c, x, -1 });
        }
        else {
            ll x, k;
            cin >> x >> k;
            S.insert(x);
            query.push_back({c, x, k });
        }
    }
    map<ll, ll> T;
    ll cnt = 0;
    map<ll, ll> R;
    for (ll x : S) {
        T[x] = cnt;
        R[cnt] = x;
        cnt++;
    }
    segtree<ll, op, e> seg(cnt);
    rep(i, Q) {
        if (get<0>(query.at(i)) == 1) {
            seg.set(T.at(get<1>(query.at(i))), seg.get(T.at(get<1>(query.at(i)))) + 1);
            //cout << "seg " << T.at(get<1>(query.at(i))) << " " << seg.get(T.at(get<1>(query.at(i)))) << endl;
        }
        else if (get<0>(query.at(i)) == 2) {
            ll count = seg.prod(0, T.at(get<1>(query.at(i))) + 1);
            //cout << count << endl;
            if (count < get<2>(query.at(i))) {
                cout << -1 << endl;
            }
            else {
                ll l = 0;
                ll r = T.at(get<1>(query.at(i))) + 1;
                while (r - l > 1) {
                    ll c = (l + r) / 2;
                    if (seg.prod(c, T.at(get<1>(query.at(i))) + 1) < get<2>(query.at(i))) {
                        r = c;
                    }
                    else {
                        l = c;
                    }
                }
                cout << R.at(l) << endl;
            }
        }
        else {
            ll count = seg.prod(T.at(get<1>(query.at(i))), cnt);
            //cout << count << endl;
            if (count < get<2>(query.at(i))) {
                cout << -1 << endl;
            }
            else {
                ll l = T.at(get<1>(query.at(i)));
                ll r = cnt;
                while (r - l > 1) {
                    ll c = (l + r) / 2;
                    if (seg.prod(T.at(get<1>(query.at(i))), c) < get<2>(query.at(i))) {
                        l = c;
                    }
                    else {
                        r = c;
                    }
                }
                cout << R.at(r-1) << endl;
            }
        }
    }
}