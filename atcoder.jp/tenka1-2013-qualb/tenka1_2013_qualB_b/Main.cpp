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
    ll Q, L;
    cin >> Q >> L;
    stack<pair<ll, ll>> s;
    ll size = 0;
    rep(i, Q){
        string com;
        cin >> com;
        if(com == "Push"){
            ll N, M;
            cin >> N >> M;
            if(size > L-N){
                cout << "FULL" << endl;
                return 0;
            }
            if(!s.empty() && s.top().first == M){
                ll x = s.top().second;
                s.pop();
                s.push(make_pair(M, x+N));
            }
            else{
                s.push(make_pair(M, N));
            }
            size += N;
        }
        if(com == "Pop"){
            ll N;
            cin >> N;
            if(size < N){
                cout << "EMPTY" << endl;
                return 0;
            }
            ll c = 0;
            while(c < N){
                if(s.top().second > N-c){
                    ll x = s.top().first;
                    ll y = s.top().second;
                    s.pop();
                    s.push(make_pair(x, y-(N-c)));
                    c = N;
                }
                else{
                    c += s.top().second;
                    s.pop();
                }
            }
            size -= N;
        }
        if(com == "Top"){
            if(size == 0){
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << s.top().first << endl;
        }
        if(com == "Size"){
            cout << size << endl;
        }
    }
    cout << "SAFE" << endl;
}