#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

struct edge {
  ll to;
};
vector<vector<edge>> graph;

vector<ll> par(1000000);
vector<ll> rnk(1000000);

void init(ll n){
  rep(i, n){
    par.at(i) = i;
    rnk.at(i) = 0;
  }
}

ll root(ll x){
  if(par.at(x) == x){
    return x;
  }
  else{
    par.at(x) = root(par.at(x));
    return par.at(x);
  }
}

bool same(ll x, ll y){
  if(root(x) == root(y)){
    return true;
  }
  else{
    return false;
  }
}

void unite(ll x, ll y){
  x = root(x);
  y = root(y);
  if(x == y){
    return;
  }
  if(rnk.at(x) < rnk.at(y)){
    par.at(x) = y;
  }
  else{
    par.at(y) = x;
    if(rnk.at(x) == rnk.at(y)){
      rnk.at(x)++;
    }
  }
}

int main()
{
    ll N, M;
    cin >> N >> M;
    init(N);
    graph.resize(N);
    vector<ll> A(M), B(M);
    rep(i, M){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
        graph.at(A.at(i)).push_back({B.at(i)});
        graph.at(B.at(i)).push_back({A.at(i)});
        unite(A.at(i), B.at(i));
    }
    ll K;
    cin >> K;
    vector<ll> C(K);
    rep(i, K){
        cin >> C.at(i);
        C.at(i)--;
    }
    rep(i, K-1){
        if(!same(C.at(i), C.at(i+1))){
            cout << -1 << '\n';
            return 0;
        }
    }
    vector<vector<ll>> cost(K, vector<ll>(N, INF));
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    rep(i, K){
        q.push({0, C.at(i)});
        while(!q.empty()){
            pair<ll, ll> p = q.top();
            q.pop();
            if(cost.at(i).at(p.second) < p.first){
                continue;
            }
            else{
                cost.at(i).at(p.second) = p.first;
            }
            for(auto e : graph.at(p.second)){
                ll d = cost.at(i).at(p.second) + 1;
                if(chmin(cost.at(i).at(e.to), d)){
                    q.push({cost.at(i).at(e.to), e.to});
                }
            }
        }
    }
    ll ans = INF;
	vector<vector<ll>> dp(1 << K, vector<ll>(K, INF));
	rep(i, K){
		dp.at(1 << i).at(i) = 0;
	}
	rep(i, 1 << K){
		bitset<17> s(i);
		rep(j, K){
			if(!s.test(j)){
				continue;
			}
			rep(k, K){
				chmin(dp.at(i).at(j), dp.at(i - (1 << j)).at(k) + cost.at(j).at(C.at(k)));
			}
		}
	}
	/* rep(i, 1 << K){
		rep(j, K){
			cout << i << " " << j << " " << dp.at(i).at(j) << '\n';
		}
	} */
	rep(i, K){
		chmin(ans, dp.at((1 << K) - 1).at(i)+1);
	}
	cout << ans << '\n';
}