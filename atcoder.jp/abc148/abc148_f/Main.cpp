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
int u, v;
vector<int> distT;
vector<int> distA;

void dfsT(int x, int p = -1, int d = 0){
  rep(i, sz(tree.at(x))) {
    distT.at(x) = d;
    if (tree.at(x).at(i).to == p) {
			continue;
    }
    dfsT(tree.at(x).at(i).to, x, d+1);
  }
}

void dfsA(int x, int p = -1, int d = 0){
  rep(i, sz(tree.at(x))) {
    distA.at(x) = d;
    if (tree.at(x).at(i).to == p) {
			continue;
    }
    dfsA(tree.at(x).at(i).to, x, d+1);
  }
}
  
int main(){
  int N;
  cin >> N;
  tree.resize(N);
  distT.resize(N);
  distA.resize(N);
  cin >> u >> v;
  u--;
  v--;
  vector<int> a(N - 1);
  vector<int> b(N - 1);
  rep(i, N - 1) {
		cin >> a.at(i) >> b.at(i);
		a.at(i)--;
		b.at(i)--;
		tree.at(a.at(i)).push_back({ b.at(i), i });
		tree.at(b.at(i)).push_back({ a.at(i), i });
  }
  dfsT(u);
  dfsA(v);
  int mx = 0;
  rep(i, N){
    if(distT.at(i) < distA.at(i)){
      chmax(mx, distA.at(i));
    }
  }
  cout << mx - 1 << endl;
}