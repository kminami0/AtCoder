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
    string s;
    cin >> N >> s;
    stack<char> T;
    ll cnt = 0;
    rep(i, sz(s)){
        if(s.at(i) == 'f' || s.at(i) == 'o'){
            T.push(s.at(i));
        }
        else if(s.at(i) == 'x'){
            if(sz(T) >= 2){
                char a = T.top();
                T.pop();
                char b = T.top();
                T.pop();
                if(a == 'o' && b == 'f'){
                    cnt++;
                }
                else{
                    stack<char> U;
                    swap(T, U);
                }
            }
            else{
                stack<char> U;
                swap(T, U);
            }
        }
        else{
            stack<char> U;
            swap(T, U);
        }
    }
    cout << sz(s) - 3 * cnt << endl;
}