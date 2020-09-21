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
#include <numeric>

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

ll op(ll a, ll b) {
	return min(a, b);
}

ll e() {
	return (ll)(INF);
}

int main()
{
	ll N;
	cin >> N;
	vector<tuple<ll, ll, ll>> P(N);
	rep(i, N) {
		ll x, y;
		cin >> x >> y;
		P.at(i) = { x, y, i };
	}
	sort(all(P));
	dsu d(N);
	stack<ll> btm;
	btm.push(0);
	rep(i, N) {
		ll j = btm.top();
		if (get<1>(P.at(j)) > get<1>(P.at(i))) {
			btm.push(i);
		}
		else {
			d.merge(i, j);
			btm.pop();
			while (!btm.empty()) {
				ll k = btm.top();
				if (get<1>(P.at(k)) < get<1>(P.at(i))) {
					d.merge(k, i);
					btm.pop();
				}
				else {
					break;
				}
			}
			btm.push(j);
		}
	}
	vector<ll> ans(N, 0);
	rep(i, N) {
		ans.at(get<2>(P.at(i))) = d.size(i);
	}
	rep(i, N) {
		cout << ans.at(i) << endl;
	}
}