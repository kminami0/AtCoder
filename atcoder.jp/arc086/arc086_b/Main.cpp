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
    vector<ll> a(N);
    ll maxp = 0; //最大の正の値の位置
    ll maxpc = 0; //最大の正の値の出現回数
    ll maxn = 0; //最小の負の値の位置
    ll maxnc = 0; //最小の負の値の出現回数
    rep(i, N){
        cin >> a.at(i);
        if(a.at(i) > a.at(maxp) && a.at(i) > 0){
            maxp = i;
            maxpc = 1;
        }
        else if(a.at(i) == a.at(maxp) && a.at(i) > 0){
            maxpc++;
        }
        else if(a.at(i) < a.at(maxn) && a.at(i) < 0){
            maxn = i;
            maxnc = 1;
        }
        else if(a.at(i) == a.at(maxn) && a.at(i) < 0){
            maxnc++;
        }
    }
    if(maxpc == 0 && maxnc == 0){ //全て0なら答えは0
        cout << 0 << endl;
        return 0;
    }
    vector<pair<ll, ll>> ans(0);
    if(maxpc != 0 && maxnc != 0){ //正の値と負の値がともに出現するか
        if(a.at(maxp) > -a.at(maxn)){ //絶対値が最大の値は正のみか
            rep(i, N){
                if(a.at(i) <= 0){ //0以下の箇所にa.at(maxp)を加えて、数列の値を全て正にする
                    ans.push_back({maxp, i});
                    a.at(i) += a.at(maxp);
                }
            }
        }
        else if(a.at(maxp) < -a.at(maxn)){ //絶対値が最大の値は負のみか
            rep(i, N){
                if(a.at(i) >= 0){ //0以上の箇所にa.at(maxn)を加えて、数列の値を全て負にする
                    ans.push_back({maxn, i}); 
                    a.at(i) += a.at(maxn);
                }
            }
        }
        else if(maxpc >= maxnc){ //絶対値最大の値が正と負ともにあるとき、正の値のほうが多いか
            rep(i, N){
                if(a.at(i) == a.at(maxn)){ //a.at(maxn)の箇所にa.at(maxp)を2回加える
                    ans.push_back({maxp, i});
                    ans.push_back({maxp, i});
                    a.at(i) += a.at(maxp);
                    a.at(i) += a.at(maxp);
                }
                else if(a.at(i) <= 0){ //ほかの0以下の箇所にa.at(maxp)を加える
                    ans.push_back({maxp, i});
                    a.at(i) += a.at(maxp);
                }
            } //ループ終了後数列の値は全て正
        }
        else{
            rep(i, N){
                if(a.at(i) == a.at(maxp)){ //a.at(maxp)の箇所にa.at(maxn)を2回加える
                    ans.push_back({maxn, i});
                    ans.push_back({maxn, i});
                    a.at(i) += a.at(maxn);
                    a.at(i) += a.at(maxn);
                }
                else if(a.at(i) >= 0){ //ほかの0以上の箇所にa.at(maxn)を加える
                    ans.push_back({maxn, i});
                    a.at(i) += a.at(maxn);
                }
            } //ループ終了後数列の値は全て負
        }
    }
    bool nonnega = true; //数列の値が全て0以上か
    rep(i, N){
        if(a.at(i) < 0){
            nonnega = false;
            break;
        }
    }
    maxp = 0;
    maxn = 0;
    if(nonnega){
        rep(i, N){
            if(a.at(i) > a.at(maxp)){
                maxp = i;
            }
        }
        rep(i, N){ //その時点での最大の値をi番目に加える
            ans.push_back({maxp, i});
            maxp = i;
        }
    }
    else{
        rep(i, N){
            if(a.at(i) < a.at(maxn)){
                maxn = i;
            }
        }
        rep(i, N){ ////その時点での最大の値をN-1-i番目に加える
            ans.push_back({maxn, N-1-i});
            maxn = N-1-i;
        }
    }
    cout << sz(ans) << endl;
    rep(i, sz(ans)){
        cout << ans.at(i).first+1 << " " << ans.at(i).second+1 << endl; //1-indexedに直して出力
    }
}