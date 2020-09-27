#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000000000 //10^14
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
stack<ll> q;
vector<bool> check(100000, false);
vector<ll> color(100000, 0);
vector<ll> prever(100000, -1);

void bfs(ll x, ll y){
    if(check.at(x)){
        return;
    }
    check.at(x) = true;
    prever.at(x) = y;
    q.push(x);
}

ll fennec = 0;
ll snuke = 0;

void paint(ll x, ll y){
    if(color.at(x) != 0){
        return;
    }
    color.at(x) = y;
    if(y == 1){
        fennec++;
    }
    else{
        snuke++;
    }
    q.push(x);
}

int main()
{
    ll N;
    cin >> N;
    graph.resize(N);
    rep(i, N-1){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        graph.at(a).push_back({b});
        graph.at(b).push_back({a});
    }
    q.push(0);
    while(!q.empty()){
        ll p = q.top();
        q.pop();
        for(auto e : graph.at(p)){
            bfs(e.to, p);
        }
    }
    vector<ll> route(0);
    route.push_back(N-1);
    ll x = N-1;
    while(true){
        if(x == 0){
            break;
        }
        route.push_back(prever.at(x));
        x = prever.at(x);
    }
    rep(i, sz(route)-2){
        if(i % 2 == 0){
            color.at(route.at(sz(route)-i/2-2)) = 1;
        }
        else{
            color.at(route.at(i/2+1)) = 2;
        }
    }
    vector<ll> black(0);
    vector<ll> white(0);
    rep(i, sz(route)){
        if(i % 2 == 0){
            black.push_back(route.at(sz(route)-i/2-1));
        }
        else{
            white.push_back(route.at(i/2));
        }
    }
    color.at(0) = 1;
    color.at(N-1) = 2;
    rep(i, sz(black)){
        q.push(black.at(i));
        while(!q.empty()){
            ll p = q.top();
            q.pop();
            for(auto e : graph.at(p)){
                paint(e.to, 1);
            }
        }
    }
    rep(i, sz(white)){
        q.push(white.at(i));
        while(!q.empty()){
            ll p = q.top();
            q.pop();
            for(auto e : graph.at(p)){
                paint(e.to, 2);
            }
        }
    }
//    cout << fennec << " " << snuke << endl;
    if(sz(route) % 2 == 0){
        if(fennec > snuke){
            cout << "Fennec" << endl;
        }
        else{
            cout << "Snuke" << endl;
        }
    }
    else{
        if(snuke > fennec){
            cout << "Snuke" << endl;
        }
        else{
            cout << "Fennec" << endl;
        }
    }
}