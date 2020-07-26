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
int main()
{
  ll N;
  cin >> N;
  vector<ll> X(N), Y(N);
  vector<char> U(N);
  map<ll, map<ll, char>> yzahyou;
  map<ll, map<ll, char>> xzahyou;
  map<ll, map<ll, char>> wa;
  map<ll, map<ll, char>> sa;
  rep(i, N){
    cin >> X.at(i) >> Y.at(i) >> U.at(i);
    yzahyou[Y.at(i)][X.at(i)] = U.at(i);
    xzahyou[X.at(i)][Y.at(i)] = U.at(i);
    wa[X.at(i) + Y.at(i)][Y.at(i)] = U.at(i);
    sa[X.at(i) - Y.at(i)][Y.at(i)] = U.at(i);
  }
  bool safe = true;
  ll time = INF;
  for(auto a : yzahyou){
    char pd = 'X';
    ll pp = 0;
    for(auto b : a.second){
      if(pd == 'R' && b.second == 'L'){
        chmin(time, (b.first - pp)*5);
        safe = false;
      }
      pd = b.second;
      pp = b.first;
    }
  }
  for(auto a : xzahyou){
    char pd = 'X';
    ll pp = 0;
    for(auto b : a.second){
      if(pd == 'U' && b.second == 'D'){
        chmin(time, (b.first - pp)*5);
        safe = false;
      }
      pd = b.second;
      pp = b.first;
    }
  }
  for(auto a : wa){
    char pd = 'X';
    ll pp = 0;
    for(auto b : a.second){
      if(pd == 'U' && b.second == 'R'){
        chmin(time, (b.first-pp)*10);
        safe = false;
      }
      if(pd == 'L' && b.second == 'D'){
        chmin(time, (b.first-pp)*10);
        safe = false;
      }
      pd = b.second;
      pp = b.first;
    }
  }
  for(auto a : sa){
    char pd = 'X';
    ll pp = 0;
    for(auto b : a.second){
      if(pd == 'U' && b.second == 'L'){
        chmin(time, (b.first-pp)*10);
        safe = false;
      }
      if(pd == 'R' && b.second == 'D'){
        chmin(time, (b.first-pp)*10);
        safe = false;
      }
      pd = b.second;
      pp = b.first;
    }
  }
  if(safe){
    cout << "SAFE" << endl;
  }
  else{
    cout << time << endl;
  }
}