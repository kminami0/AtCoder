#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 1000000009
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

map<string, vector<string>> graph;
queue<string> str;

int main(){
  ll N;
  cin >> N;
  str.push("a");
  graph["a"] = {};
  set<string> ans;
  while(!str.empty()){
    if(sz(str.front()) == N){
      ans.insert(str.front());
      str.pop();
      continue;
    }
    if(sz(str.front()) > N){
      break;
    }
    string t = str.front();
    char d = 'a';
    rep(i, sz(t)){
      chmax(d, t.at(i));
    }
    rep(i, d-'a'+2){
      char c = 'a' + i;
      string s = t + c;
      graph.at(t).push_back(s);
      graph[s] = {};
      str.push(s);
    }
    str.pop();
  }
  for(auto st : ans){
    cout << st << endl;
  }
}