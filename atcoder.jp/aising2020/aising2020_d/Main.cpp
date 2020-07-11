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

ll popcount(string x){
    ll ans = 0;
    rep(i, sz(x)){
        if(x.at(i) == '1'){
            ans++;
        }
    }
    return ans;
}

ll popcountl(ll x){
    if(x == 0){
        return 0;
    }
    bitset<200000> s(x);
    ll a = 0;
    rep(i, log2(x)+1){
        if(s.test(i)){
            a++;
        }
    }
    return a;
}

ll f(ll x, ll c){
    if(x == 0){
        return c;
    }
    return f(x % popcountl(x), c+1);
}

int main()
{
    ll N;
    string X;
    cin >> N >> X;
    ll K = popcount(X);
    vector<ll> rem1(N, 0); // 2^iをpopcount(X)+1で割った余り
    vector<ll> rem2(N, 0); // 2^iをpopcount(X)-1で割った余り
    rem1.at(0) = 1 % (K+1);
    if(K != 1){
        rem2.at(0) = 1 % (K-1);
    }
    rep(i, N-1){
        rem1.at(i+1) = (rem1.at(i) * 2) % (K+1);
        if(K != 1){
            rem2.at(i+1) = (rem2.at(i) * 2) % (K-1);
        }
    }
    ll R1 = 0; //Xをpopcount(X)+1で割った余り
    ll R2 = 0; //Xをpopcount(X)-1で割った余り
    rep(i, N){
        if(X.at(i) == '1'){
            R1 += rem1.at(N-1-i);
            R2 += rem2.at(N-1-i);
        }
    }
    rep(i, N){
        if(X.at(i) == '1'){
            if(K == 1){
                cout << 0 << endl;
            }
            else{
                cout << f((R2-rem2.at(N-1-i))%(K-1), 1) << endl;
            }
        }
        else{
            cout << f((R1+rem1.at(N-1-i))%(K+1), 1) << endl;
        }
    }
}