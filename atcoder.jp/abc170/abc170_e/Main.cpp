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

vector<multiset<ll>> kindergartens(200000); //各幼稚園に所属する幼児のレートの多重集合
multiset<ll> maxs; //幼児が1人以上いる各幼稚園の最高レートの多重集合
vector<ll> A, B; //A.at(i)は園児iのレート、B.at(i)は園児iの所属幼稚園

// 園児Cを幼稚園Dに転園させたあとの平等さを返す関数
ll equality(ll C, ll D){
    kindergartens.at(B.at(C)).erase(kindergartens.at(B.at(C)).find(A.at(C)));
    if(!kindergartens.at(B.at(C)).empty()){
      if(*rbegin(kindergartens.at(B.at(C))) < A.at(C)){
        maxs.erase(maxs.find(A.at(C)));
        maxs.insert(*rbegin(kindergartens.at(B.at(C))));
      }
    }
    else{
      maxs.erase(maxs.find(A.at(C)));
    }
    B.at(C) = D;
    if(!kindergartens.at(D).empty()){
      if(*rbegin(kindergartens.at(D)) < A.at(C)){
        maxs.erase(maxs.find(*rbegin(kindergartens.at(D))));
        maxs.insert(A.at(C));
      }
    }
    else{
      maxs.insert(A.at(C));
    }
    kindergartens.at(D).insert(A.at(C));
    return *begin(maxs);
}

int main()
{
    ll N, Q;
    cin >> N >> Q;
    A.resize(N);
    B.resize(N);
    rep(i, N){
      cin >> A.at(i) >> B.at(i);
      B.at(i)--; //幼稚園の番号は0-basedにする
      kindergartens.at(B.at(i)).insert(A.at(i));
    }
    rep(i, 200000){
      if(!kindergartens.at(i).empty()){
        maxs.insert(*rbegin(kindergartens.at(i)));
      }
    }
    rep(i, Q){
      ll C, D;
      cin >> C >> D;
      C--; //園児の番号を0-basedにする
      D--; //幼稚園の番号を0-basedにする
      cout << equality(C, D) << endl;
    }
}