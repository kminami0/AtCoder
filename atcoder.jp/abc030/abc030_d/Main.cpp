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

struct edge {
  ll to;
};
vector<vector<edge>> graph;

int main()
{
    ll N, a;
    string k; //kは極めて大きい可能性があるのでstringとして受け取る
    cin >> N >> a >> k;
    a--; //0-basedにする
    graph.resize(N);
    //単語iの説明が「単語bと同じ意味である」の場合、iからbへ辺を張る
    rep(i, N){
        ll b;
        cin >> b;
        b--;
        graph.at(i).push_back({b});
    }
    //aから出発して辺を辿ると、必ずループに入るので、ループの開始位置と長さを調べる
    vector<bool> vst(N, false); //頂点iをすでに訪れたか
    ll pos = a; //現在位置
    ll ls = -1; //ループの開始位置
    ll length = 0; //ループの長さ
    ll cnt = 0; //ループに入るまでの移動回数
    while(true){
        if(pos == ls){
            break;
        }
        if(vst.at(pos) && ls == -1){
            ls = pos;
        }
        else{
            vst.at(pos) = true;
        }
        if(ls != -1){
            length++;
        }
        else{
            cnt++;
        }
        pos = graph.at(pos).at(0).to;
    }
    cnt -= length;
    ll ans = a;
    if(sz(k) <= 18){ //kが18桁以下なら、llに変換する
        ll K = stoll(k);
        if(K <= cnt){ //ループに入る前に操作が終了するなら、操作をシミュレートする
            rep(i, K){
                ans = graph.at(ans).at(0).to;
            }
            cout << ans+1 << endl;
            return 0;
        }
        ans = ls;
        K -= cnt;
        K %= length; //ループの開始位置から、残り回数をループの長さで割った回数だけ操作すればよい
        rep(i, K){
            ans = graph.at(ans).at(0).to;
        }
        cout << ans+1 << endl;
        return 0;
    }
    vector<ll> rem(sz(k), 0); //rem.at(i)は10^iをlengthで割った余り
    rem.at(0) = 1;
    rep(i, sz(k)-1){
        rem.at(i+1) = (10 * rem.at(i)) % length;
    }
    ll K = 0;
    // kが大きいとき、必ずループに入るので、(k-cnt)%lengthを求める
    rep(i, sz(k)){
        K += (k.at(sz(k)-1-i) - '0') * rem.at(i);
        K %= length;
    }
    K -= cnt % length;
    while(K < 0){
        K += length;
    }
    ans = ls;
    rep(i, K){
        ans = graph.at(ans).at(0).to;
    }
    cout << ans+1 << endl;
}