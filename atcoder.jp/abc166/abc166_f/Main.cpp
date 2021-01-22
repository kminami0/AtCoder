#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(v) begin(v), end(v)
#define sz(v) v.size()
#define INF 1000000000000000000 //10^17
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
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<string> s(N);
    rep(i, N){
        cin >> s.at(i);
    }
    string ans = "";
    rep(i, N){
        if(s.at(i) == "AB"){
            if(A == 0 && B == 0){
                cout << "No" << '\n';
                return 0;
            }
            if(A > B){
                ans += "B";
                A--;
                B++;
            }
            else if(B > A){
                ans += "A";
                A++;
                B--;
            }
            else{
                if(i == N-1){
                    ans += "A";
                    A++;
                    B--;
                    break;
                }
                rep2(j, i+1, N){
                    if(s.at(j) == "AC"){
                        ans += "A";
                        A++;
                        B--;
                        break;
                    }
                    else if(s.at(j) == "BC"){
                        ans += "B";
                        A--;
                        B++;
                        break;
                    }
                    if(j == N-1){
                        ans += "A";
                        A++;
                        B--;
                    }
                }
            }
        }
        else if(s.at(i) == "AC"){
            if(A == 0 && C == 0){
                cout << "No" << '\n';
                return 0;
            }
            if(A > C){
                ans += "C";
                A--;
                C++;
            }
            else if(C > A){
                ans += "A";
                A++;
                C--;
            }
            else{
                if(i == N-1){
                    ans += "A";
                    A++;
                    C--;
                    break;
                }
                rep2(j, i+1, N){
                    if(s.at(j) == "AB"){
                        ans += "A";
                        A++;
                        C--;
                        break;
                    }
                    else if(s.at(j) == "BC"){
                        ans += "C";
                        A--;
                        C++;
                        break;
                    }
                    if(j == N-1){
                        ans += "A";
                        A++;
                        C--;
                    }
                }
            }
        }
        else{
            if(B == 0 && C == 0){
                cout << "No" << '\n';
                return 0;
            }
            if(B > C){
                ans += "C";
                B--;
                C++;
            }
            else if(C > B){
                ans += "B";
                B++;
                C--;
            }
            else{
                if(i == N-1){
                    ans += "B";
                    B++;
                    C--;
                    break;
                }
                rep2(j, i+1, N){
                    if(s.at(j) == "AB"){
                        ans += "B";
                        B++;
                        C--;
                        break;
                    }
                    else if(s.at(j) == "AC"){
                        ans += "C";
                        B--;
                        C++;
                        break;
                    }
                    if(j == N-1){
                        ans += "B";
                        B++;
                        C--;
                    }
                }
            }
        }
    }
    cout << "Yes" << '\n';
    rep(i, N){
        cout << ans.at(i) << '\n';
    }
}