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
vector<vector<edge>> graph;

vector<bool> vst(100000, false);
vector<ll> topos(0);
ll N, K;
vector<vector<ll>> ans_list;
vector<ll> perm(100000, -1);
vector<ll> st(0);
vector<ll> ind(100000, 0);

bool dfs(ll depth){
    if(depth == N){
        ans_list.push_back(perm);
        return true;
    }
    if(st.empty()){
        return false;
    }
    for(ll i = sz(st)-1; i >= 0; i--){
        if(ll(sz(ans_list)) == K){
            break;
        }
        ll x = st.at(i);
        st.erase(begin(st)+i);
        for(edge e : graph.at(x)){
            ind.at(e.to)--;
            if(ind.at(e.to) == 0){
                st.push_back(e.to);
            }
        }
        perm.at(depth) = x;
        bool sign = dfs(depth + 1);
        if(!sign){
            return false;
        }
        for(edge e : graph.at(x)){
            if(ind.at(e.to) == 0){
                st.pop_back();
            }
            ind.at(e.to)++;
        }
        st.insert(begin(st)+i, x);
    }
    return true;
}

int main()
{
    ll M;
    cin >> N >> M >> K;
    graph.resize(N);
    vector<ll> A(M), B(M);
    rep(i, M){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
        graph.at(A.at(i)).push_back({B.at(i)});
    }
    rep(i, N){
        for(edge e : graph.at(i)){
            ind.at(e.to)++;
        }
    }
    rep(i, N){
        if(ind.at(i) == 0){
            st.push_back(i);
        }
    }
    dfs(0);
    if(ll(sz(ans_list)) != K){
        cout << -1 << '\n';
    }
    else{
        for(vector<ll> v : ans_list){
            rep(i, N-1){
                cout << v.at(i)+1 << " ";
            }
            cout << v.at(N-1)+1 << endl;
        }
    }
}