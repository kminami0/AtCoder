#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

int main(){
  int N;
  cin >> N;
  vector<double> x(N);
  vector<double> y(N);
  rep(i, N){
    cin >> x.at(i) >> y.at(i);
  }
  vector<vector<double>> dist(N, vector<double>(N));
  rep(i, N){
    rep(j, N){
      dist.at(i).at(j) = pow(pow((x.at(i)-x.at(j)), 2)+pow((y.at(i)-y.at(j)), 2), 0.5);
    }
  }
  vector<int> a(N);
  rep(i, N){
    a.at(i) = i;
  }
  int fac = 1;
  rep(i, N){
    fac *= (i+1);
  }
  vector<double> route(fac, 0);
  int c = 0;
  do {
    rep(i, N-1){
      route.at(c) += dist.at(a.at(i)).at(a.at(i+1));
    }
    c++;
  } while (next_permutation(all(a)));
  double sum = 0;
  rep(i, fac){
    sum += route.at(i);
  }
  cout << fixed << setprecision(10);
  cout << sum / (double)fac << endl;
}