#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

struct edge {
	int to;
	int id;
};

vector<vector<edge>> tree;
vector<int> ans;

void dfs(int v, int p = -1, int c = -1) {
	int col = 1;
	rep(i, sz(tree.at(v))) {
		if (col == c) {
			col++;
		}
		if (tree.at(v).at(i).to == p) {
			continue;
		}
		ans.at(tree.at(v).at(i).id) = col;
		dfs(tree.at(v).at(i).to, v, col);
		col++;
	}
}

int main() {
	int N;
	cin >> N;
	tree.resize(N);
	ans.resize(N - 1);
	vector<int> a(N - 1);
	vector<int> b(N - 1);
	rep(i, N - 1) {
		cin >> a.at(i) >> b.at(i);
		a.at(i)--;
		b.at(i)--;
		tree.at(a.at(i)).push_back({ b.at(i), i });
		tree.at(b.at(i)).push_back({ a.at(i), i });
	}
	dfs(0);
	int mx = 0;
	rep(i, N) {
		int s = sz(tree.at(i));
		chmax(mx, s);
	}
	cout << mx << endl;
	rep(i, N - 1) {
		cout << ans.at(i) << endl;
	}
}