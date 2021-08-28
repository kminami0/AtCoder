#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
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

int N, M, K;
vector<int> A(300);

int scoring(int c){
    double s = 0;
    rep(i, N){
        s += (log2(K) - log2(A[i]+1));
    }
    int cnt = 0;
    rep(i, N){
        if(A[i] != 0){
            cnt++;
        }
    }
    if(cnt <= 1){
        s += M - c;
    }
    return ceil(s);
}

chrono::system_clock::time_point start_time;
vector<pair<int, int>> ans(0);

void magic(){
    double limit = 1900;
    while(true){
        double elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_time).count();
        if(elapsed_time >= limit){
            break;
        }
        int p = 0;
        int t = 0;
        rep(i, N){
            if(chmax(t, A[i])){
                p = i;
            }
        }
        int c = 0;
        while(t < K){
            t *= 2;
            c++;
        }
        if(t - K < A[p] && int(sz(ans))+c <= M){
            rep(i, c){
                ans.push_back({p, p});
            }
            A[p] = t - K;
        }
    }
}

void magic2(){
    double limit = 1900;
    while(true){
        double elapsed_time = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start_time).count();
        if(elapsed_time >= limit){
            break;
        }
        double d = 0;
        int p = -1;
        int q = -1;
        rep(i, N){
            rep(j, N){
                if(chmin(d, log2((A[i]+A[j])%K+1) - log2(A[i]+1))){
                    p = i;
                    q = j;
                }
            }
        }
        if(p != -1 && q != -1){
            ans.push_back({p, q});
            A[p] = (A[p] + A[q]) % K;
        }
        if(int(sz(ans)) == M){
            break;
        }
    }
}

int main()
{
    start_time = chrono::system_clock::now();
    cin >> N >> M >> K;
    rep(i, N){
        cin >> A[i];
    }
    magic2();
    magic();
    rep(i, sz(ans)){
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    //cout << "score: " << scoring(sz(ans)) << endl;
}