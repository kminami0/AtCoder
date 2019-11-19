#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)

string substrBack(string str, size_t pos, size_t len) {
    const size_t strLen = str.length();
 
    return str.substr(strLen - pos, len);
}

int main(){
  string S;
  cin >> S;
  string T = S;
  int64_t sum = 0;
  int k = 1;
  for (int tmp = 0; tmp < (1 << S.size()-1); tmp++) {
    bitset<9> s(tmp);
    rep(i, S.size()-1){
      if(s.test(i)){
        sum += stoll(substrBack(T, k, k));
        T.erase(T.size()-k);
        k = 0;
      }
      k++;
    }
    sum += stoll(T);
    k = 1;
    T = S;
  }
  cout << sum << endl;
}