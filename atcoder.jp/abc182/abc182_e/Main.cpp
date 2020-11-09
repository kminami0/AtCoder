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
    ll H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<ll> A(N), B(N);
    rep(i, N){
        cin >> A.at(i) >> B.at(i);
        A.at(i)--;
        B.at(i)--;
    }
    vector<ll> C(M), D(M);
    rep(i, M){
        cin >> C.at(i) >> D.at(i);
        C.at(i)--;
        D.at(i)--;
    }
    vector<vector<ll>> akari_yoko(H, vector<ll>(W, 0));
    vector<vector<ll>> akari_tate(H, vector<ll>(W, 0));
    rep(i, M){
      akari_yoko.at(C.at(i)).at(D.at(i)) = -1;
      akari_tate.at(C.at(i)).at(D.at(i)) = -1;
    }
    ll ans = 0;
    rep(i, N){
      for(int j = B.at(i); j >= 0; j--){
        if(akari_yoko.at(A.at(i)).at(j) != 0){
          break;
        }
        akari_yoko.at(A.at(i)).at(j) = 1;
      }
      for(int j = B.at(i)+1; j < W; j++){
        if(akari_yoko.at(A.at(i)).at(j) != 0){
          break;
        }
        akari_yoko.at(A.at(i)).at(j) = 1;
      }
    }
    rep(i, N){
      for(int j = A.at(i); j >= 0; j--){
        if(akari_tate.at(j).at(B.at(i)) != 0){
          break;
        }
        akari_tate.at(j).at(B.at(i)) = 1;
      }
      for(int j = A.at(i)+1; j < H; j++){
        if(akari_tate.at(j).at(B.at(i)) != 0){
          break;
        }
        akari_tate.at(j).at(B.at(i)) = 1;
      }
    }
    rep(i, H){
      rep(j, W){
        if(akari_yoko.at(i).at(j) ==1 || akari_tate.at(i).at(j) ==1){
          ans++;
        }
      }
    }
    cout << ans << endl;
}