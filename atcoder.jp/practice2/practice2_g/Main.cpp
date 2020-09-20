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

int op(int a, int b) {
	return max(a, b);
}

int e() {
	return -1;
}

int v;

bool f(int x) {
	return x < v;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    scc_graph graph(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        graph.add_edge(a, b);
    }
    vector<vector<int>> ans = graph.scc();
    cout << sz(ans) << endl;
    rep(i, sz(ans)) {
        cout << sz(ans.at(i)) << " ";
        rep(j, sz(ans.at(i)) - 1) {
            cout << ans.at(i).at(j) << " ";
        }
        cout << ans.at(i).at(sz(ans.at(i)) - 1) << endl;
    }
}