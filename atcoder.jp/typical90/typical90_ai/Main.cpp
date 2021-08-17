#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1e18+999999
#define EPSILON 1e-14
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
using Graph = vector<vector<edge>>;
Graph G;

vector<bool> vst(100000, false);
vector<ll> dp(100000, 0);

void treeDP(ll x){
    vst.at(x) = true;
    for(edge e : G.at(x)){
        if(vst.at(e.to)){
            continue;
        }
        treeDP(e.to);
        dp.at(x) += dp.at(e.to);
    }
}

struct LCA{
    vector<vector<ll>> parent; // parent.at(k).at(u) = u の 2^k 先の親
    vector<ll> dist;
    LCA(const Graph &G, ll root = 0){
        init(G, root);
    }

    void init(const Graph &G, ll root = 0){
        ll V = sz(G);
        ll K = 1;
        while((1<<K) < V){
            K++;
        }
        parent.assign(K, vector<ll>(V, -1));
        dist.assign(V, INF);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
        q.push({0, root});
        while(!q.empty()){
            pair<ll, ll> p = q.top();
            q.pop();
            if(dist.at(p.second) < p.first){
                continue;
            }
            else{
                dist.at(p.second) = p.first;
            }
            for(auto e : G.at(p.second)){
                ll d = dist.at(p.second) + 1;
                if(chmin(dist.at(e.to), d)){
                    q.push({dist.at(e.to), e.to});
                    parent.at(0).at(e.to) = p.second;
                }
            }
        }
        rep(k, K-1){
            rep(v, V){
                if(parent.at(k).at(v) < 0){
                    parent.at(k+1).at(v) = -1;
                }
                else{
                    parent.at(k+1).at(v) = parent.at(k).at(parent.at(k).at(v));
                }
            }
        }
    }

    ll query(ll u, ll v){
        if(dist.at(u) < dist.at(v)){
            swap(u, v);
        }
        ll K = sz(parent);
        rep(k, K){
            if(((dist.at(u) - dist.at(v)) >> k) & 1){
                u = parent.at(k).at(u);
            }
        }
        if(u == v){
            return u;
        }
        for(ll k = K - 1; k >= 0; k--){
            if(parent.at(k).at(u) != parent.at(k).at(v)){
                u = parent.at(k).at(u);
                v = parent.at(k).at(v);
            }
        }
        return parent.at(0).at(u);
    }

    ll get_dist(ll u, ll v){
        return dist.at(u) + dist.at(v) - 2 * dist.at(query(u, v));
    }  
};

vector<ll> tour(0);
 
void dfs(ll x, ll p = -1){
    if(vst.at(x)){
        return;
    }
    vst.at(x) = true;
    tour.push_back(x);
    for(edge e : G.at(x)){
        if(e.to == p){
            continue;
        }
        dfs(e.to, x);
    }
}

int main()
{
    ll N;
    cin >> N;
    G.resize(N);
    rep(i, N-1){
        ll A, B;
        cin >> A >> B;
        A--;
        B--;
        G.at(A).push_back({B});
        G.at(B).push_back({A});
    }
    dfs(0);
    vector<ll> crp(N);
    rep(i, N){
        crp.at(tour.at(i)) = i;
    }
    LCA lca(G);
    ll Q;
    cin >> Q;
    rep(i, Q){
        ll K;
        cin >> K;
        vector<ll> V(K);
        vector<pair<ll, ll>> cir(K);
        rep(j, K){
            cin >> V.at(j);
            V.at(j)--;
            cir.at(j) = {crp.at(V.at(j)), V.at(j)};
        }
        sort(all(cir));
        ll ans = 0;
        rep(j, K-1){
            ans += lca.get_dist(cir.at(j).second, cir.at(j+1).second);
        }
        ans += lca.get_dist(cir.at(K-1).second, cir.at(0).second);
        ans /= 2;
        cout << ans << endl;
    }
}