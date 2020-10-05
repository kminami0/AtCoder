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

ll N, M, V, P;
vector<ll> A;

// 降順ソートされたAにて、A.at(x)が選ばれうるか
bool choice(ll x){
    if(x <= P-1){
        return true;
    }
    if(A.at(x) + M < A.at(P-1)){
        return false;
    }
    ll cnt = (P - 1 + N - x) * M;
    // A.at(0),...,A.at(P-2),A.at(x),...,A.at(N-1)には全ジャッジが投票して問題ない
    rep2(i, P-1, x){
        cnt += A.at(x) + M - A.at(i);
        // A.at(i)にはA.at(x) + M - A.at(i)人まで投票して問題ない
    }
    return cnt >= M * V;
}

int main()
{
    cin >> N >> M >> V >> P;
    A.resize(N+1);
    rep(i, N) cin >> A.at(i);
    A.at(N) = -1 * INF;
    sort(all(A));
    reverse(all(A));
    // 降順としても一般性を失わない
    ll l = 0;
    ll r = N;
    // A.at(l)は選ばれる可能性があり、A.at(r)は決して選ばれない
    // 二分探索で境界を求める
    while(r-l > 1){
        ll c = (l+r) / 2;
        if(choice(c)){
            l = c;
        }
        else{
            r = c;
        }
    }
    cout << l+1 << endl;
}