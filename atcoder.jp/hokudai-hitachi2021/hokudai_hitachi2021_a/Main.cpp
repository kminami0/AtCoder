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

struct NanoGrid{
    ll xposgrid; //ナノグリッドの位置
    ll Chginitgrid; // 開始時の蓄電量
    ll typePVgrid; // PV設備の種類
    ll APVgrid; // 発電容量で見たPV導入量
    ll typeFEgrid; // 自家発電機の種類
    ll typeRBgrid; // 蓄電池の種類
    ll ARBgrid; // 蓄電池の導入量
    ll typeEVCgrid; // EV充放電装置の種類
};
struct EV{
    ll xposEV; // t=0で配置される位置
    ll ChginitEV; // 開始時の蓄電量
    ll typeEV; // 製品の種類
};

int main()
{
    ll Cinit; // テストケース毎に指定される予算総額
    cout << "budget" << endl;
    cin >> Cinit;
    cout << "end" << endl;
    ll Ngrid = 0; // 設置するナノグリッドの数
    vector<NanoGrid> grid_info(Ngrid);
    cout << Ngrid << endl;
    ll NEV = 0; // 配置する電気自動車の台数
    vector<EV> EV_info(NEV);
    cout << NEV << endl;
    ll opt1 = 0;
    cout << "submit" << " " << 0 << " " << opt1 << endl;
}