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
    string S;
    cin >> N >> S;
    deque<char> cyl;
    rep(i, N){
        if(cyl.empty()){
            cyl.push_back(S.at(i));
        }
        else if(S.at(i) == cyl.front()){
            cyl.pop_front();
        }
        else if(S.at(i) == cyl.back()){
            cyl.pop_back();
        }
        else if(i == N-1){
            cyl.push_back(S.at(i));
        }
        else if(S.at(i+1) == cyl.front()){
            cyl.push_back(S.at(i));
        }
        else if(S.at(i+1) == cyl.back()){
            cyl.push_front(S.at(i));
        }
        else{
            cyl.push_back(S.at(i));
        }
    }
    cout << sz(cyl) << endl;
}