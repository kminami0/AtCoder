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
int main()
{
    ll N;
    string S;
    cin >> N >> S;
    deque<ll> left;
    deque<ll> right;
    char d = 'x';
    rep(i, sz(S)){
        if(S.at(i) != d && S.at(i) == 'L'){
            right.push_front(i);
        }
        else if(S.at(i) != d && S.at(i) == 'R'){
            left.push_back(i);
        }
        else if(S.at(i) == d && S.at(i) == 'L'){
            right.push_front(i);
        }
        else if(S.at(i) == d && S.at(i) == 'R'){
            left.push_back(i);
        }
        d = S.at(i);
    }
    while(!left.empty()){
        ll p = left.front();
        left.pop_front();
        cout << p << " ";
    }
    cout << N;
    if(!right.empty()){
        cout << " ";
    }
    while(!right.empty()){
        ll p = right.front();
        right.pop_front();
        cout << p;
        if(!right.empty()){
            cout << " ";
        }
    }
    cout << endl;
}