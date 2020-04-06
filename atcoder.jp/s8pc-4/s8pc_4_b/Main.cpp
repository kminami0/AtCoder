#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define INF 100000000999 // 10^11 + 999 1000億999
// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}

template<class T>
void combination(const vector<T>& seed, int target_size, bool (*callback)(const vector<T>&)) {
    vector<int> indices(target_size);
    const int seed_size = seed.size();
    int start_index = 0;
    int size = 0;

    while (size >= 0) {
        for (int i = start_index; i < seed_size; ++i) {
            indices[size++] = i;
            if (size == target_size) {
                vector<T> comb(target_size);
                for (int x = 0; x < target_size; ++x) {
                    comb[x] = seed[indices[x]];
                }
                if (callback(comb)) return;
                break;
            }
        }
        --size;
        if (size < 0) break;
        start_index = indices[size] + 1;
    }
}

///////////////// How to use

bool my_callback(const vector<ll>& comb) {
    int n = comb.size();
    for (int i=0; i<n; ++i)
        cout << comb[i] << " ";
    cout << endl;
    return false;
}

vector<ll> a;
ll ans = INF;
ll N;

bool raise(const vector<ll>& comb) {
  vector<ll> b(0);
  rep(i, N){
    b.push_back(a.at(i));
  }
  ll n = sz(comb);
  ll h = 0;
  rep(j, comb.at(0)){
    chmax(h, b.at(j));
  }
  ll m = 0;
  rep(i, n){
    if(i == 0){
      if(h >= b.at(comb.at(0))){
        m += h-b.at(comb.at(0))+1;
        b.at(comb.at(0)) = h+1;
      }
    }
    else{
      h = b.at(comb.at(i-1));
      rep(j, comb.at(i)){
        chmax(h, b.at(j));
      }
      if(h >= b.at(comb.at(i))){
        m += h-b.at(comb.at(i))+1;
        b.at(comb.at(i)) = h + 1;
      }
    }
  }
  chmin(ans, m);
  return false;
}

int main(){
  ll K;
  cin >> N >> K;
  a.resize(N);
  rep(i, N){
    cin >> a.at(i);
  }
  vector<ll> vals;
  rep(i, N){
    vals.push_back(i);
  }
  combination(vals, K, raise);
  cout << ans << endl;
}