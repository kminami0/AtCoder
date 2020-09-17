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
    ll N;
    string s1, s2;
    cin >> N >> s1 >> s2;
    init(36);
    rep(i, N){
      if(isdigit(s1.at(i)) && !isdigit(s2.at(i))){
        unite(s1.at(i)-'0', s2.at(i)-'A'+10);
      }
      else if(!isdigit(s1.at(i)) && isdigit(s2.at(i))){
        unite(s1.at(i)-'A'+10, s2.at(i)-'0');
      }
      else if(!isdigit(s1.at(i)) && !isdigit(s2.at(i))){
        unite(s1.at(i)-'A'+10, s2.at(i)-'A'+10);
      }
    }
    set<char> kakutei;
    rep(i, 10){
      rep(j, 26){
        if(same(i, j+10)){
          kakutei.insert('A'+j);
        }
      }
    }
    set<char> occur;
    set<ll> sentou;
    rep(i, N){
      if(!isdigit(s1.at(i))){
        occur.insert(s1.at(i));
        if(i == 0){
          sentou.insert(root(s1.at(i)-'A'+10));
        }
      }
      if(!isdigit(s2.at(i))){
        occur.insert(s2.at(i));
        if(i == 0){
          sentou.insert(root(s2.at(i)-'A'+10));
        }
      }
    }
    ll ans = 1;
    set<ll> sumi;
    for(auto p : kakutei){
      sumi.insert(root(p-'A'+10));
    }
    for(auto p : occur){
      if(sumi.count(root(p-'A'+10))){
        continue;
      }
      if(sentou.count(root(p-'A'+10))){
        ans *= 9;
        sumi.insert(root(p-'A'+10));
      }
      else{
        ans *= 10;
        sumi.insert(root(p-'A'+10));
      }
    }
    cout << ans << endl;
}