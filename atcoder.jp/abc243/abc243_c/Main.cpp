#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) ll(v.size())
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
    cin >> N;
    vector<tuple<ll, ll, char>> P(N);
    vector<ll> X(N), Y(N);
    rep(i, N){
        cin >> X.at(i) >> Y.at(i);
    }
    string S;
    cin >> S;
    rep(i, N){
        P.at(i) = {Y.at(i), X.at(i), S.at(i)};
    }
    sort(all(P));
    map<ll, char> M;
    rep(i, N){
        if(!M.count(get<0>(P.at(i)))){
            M[get<0>(P.at(i))] = get<2>(P.at(i));
        }
        else if(M[get<0>(P.at(i))] == 'R' && get<2>(P.at(i)) == 'L'){
            cout << "Yes" << '\n';
            return 0;
        }
        else{
            M[get<0>(P.at(i))] = get<2>(P.at(i));
        }
    }
    cout << "No" << '\n';
}