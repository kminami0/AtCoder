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

int main()
{
	ll N, Q;
	cin >> N >> Q;
	vector<ll> c(N);
	rep(i, N) cin >> c.at(i);
	vector<tuple<ll, ll, ll>> points(Q);
	rep(i, Q) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		points.at(i) = { l, -r, i };
	}
	vector<ll> prepos(N + 1, -1);
	rep(i, N) {
		if (prepos.at(c.at(i)) != -1) {
			points.push_back({ prepos.at(c.at(i)) , -i, Q });
		}
		prepos.at(c.at(i)) = i;
	}
	sort(all(points));
	reverse(all(points));
	fenwick_tree<ll> fw(N+3);
	vector<ll> ans(Q);
//	rep(i, sz(points)) {
//		cout << get<0>(points.at(i)) << " " << get<1>(points.at(i)) << " " << get<2>(points.at(i)) << endl;
//	}
	rep(i, sz(points)) {
		if (get<2>(points.at(i)) == Q) {
			fw.add(-get<1>(points.at(i)), 1);
		}
		else {
			ans.at(get<2>(points.at(i))) = -get<1>(points.at(i)) - get<0>(points.at(i)) + 1 - fw.sum(0, -get<1>(points.at(i)) + 1);
		}
	}
	rep(i, Q) {
		cout << ans.at(i) << endl;
	}
}