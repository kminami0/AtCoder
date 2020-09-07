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
    vector<ll> A(N);
    rep(i, N) cin >> A.at(i);
    vector<bitset<20>> B(N);
    rep(i, N){
        bitset<20> s(A.at(i));
        B.at(i) = s;
    }
    ll ans = 0;
    //[i, j]でビットの重複があるか調べる、尺取り法
    set<ll> S;
    bool flag = false;
    bool comp = false;
    ll p = 0;
    rep(i, N){
        rep2(j, p, N){
            rep(k, 20){
                if(B.at(j).test(k) && S.count(k)){
                    rep(l, 20){
                        if(B.at(i).test(l)){
                            S.erase(l);
                        }
                    }
                    flag = true;
                    break;
                }
            }
            if(flag){
                flag = false;
                ans += j - i;
                p = j;
                break;
            }
            rep(k, 20){
                if(B.at(j).test(k)){
                    S.insert(k);
                }
            }
            if(j == N-1){
                comp = true;
                ans += (N - i) * (N - i + 1) / 2; 
            }
        }
        if(comp){
            break;
        }
    }
    cout << ans << endl;
}