#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)

vector<ll> A(100);
ll P, Q;
ll ans = 0;

int main()
{
    ll N;
    cin >> N >> P >> Q;
    rep(i, N) cin >> A[i];
    rep(i, N){
        rep2(j, i+1, N){
            rep2(k, j+1, N){
                rep2(l, k+1, N){
                    rep2(m, l+1, N){
                        ll tmp = 1;
                        tmp *= A[i];
                        tmp %= P;
                        tmp *= A[j];
                        tmp %= P;
                        tmp *= A[k];
                        tmp %= P;
                        tmp *= A[l];
                        tmp %= P;
                        tmp *= A[m];
                        tmp %= P;
                        if(tmp == Q){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}