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
    ll T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    if((A1 - B1 > 0 && A2 - B2 > 0) || (A1 - B1 < 0 && A2 - B2 < 0)){ //常に一方が他方より速ければ出会わない
        cout << 0 << endl;
        return 0;
    }
    if(A1 < B1){ //対称性よりA1 > B1としてよい
        swap(A1, B1);
        swap(A2, B2);
    }
    if(A1*T1 + A2*T2 > B1*T1 + B2*T2){ //最初のT1分間は高橋君が前にいるから、次のT2分間で青木君が追いつけなければ出会わない
        cout << 0 << endl;
        return 0;
    }
    if(A1*T1 + A2*T2 == B1*T1 + B2*T2){ //T1+T2分後に出会うなら、無限回出会う
        cout << "infinity" << endl;
        return 0;
    }
    ll diff = B1*T1 + B2*T2 - (A1*T1 + A2*T2); //T1+T2分ごとに、どれだけ青木君が高橋君の前に出るか
    ll chase = A1*T1 - B1*T1; //T1分で、高橋君が青木君との距離をどれだけ詰められるか
    //高橋君が青木君に追いつけなくなるまでに、T1+T2分ごとに2回出会う。ただし最初のT1+T2分は1回だけ
    if(chase % diff == 0){
        cout << 2 * chase / diff << endl;
    }
    else{
        cout << 2 * (chase / diff + 1) - 1 << endl;
    }
}