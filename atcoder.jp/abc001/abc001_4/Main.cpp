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
    vector<string> rain(N);
    rep(i, N){
        cin >> rain.at(i);
    }
    vector<pair<ll, ll>> round(N);
    rep(i, N){
        round.at(i).first = stoll(rain.at(i).substr(0, 4)) - stoll(rain.at(i).substr(0, 4)) % 5;
        if(stoll(rain.at(i).substr(5, 4)) % 5 == 0){
            round.at(i).second = stoll(rain.at(i).substr(5, 4)) - 5;
        }
        else{
            round.at(i).second = stoll(rain.at(i).substr(5, 4)) - stoll(rain.at(i).substr(5, 4)) % 5;
        }
        if(round.at(i).second % 100 == 60){
            round.at(i).second += 40;
        }
    }
    map<ll, ll> kannu;
    rep(i, N){
        ll p = round.at(i).first;
        while(p <= round.at(i).second){
            kannu[p]++;
            p += 5;
            if(p % 100 == 60){
                p += 40;
            }
        }
    }
    ll time = 0;
    bool started = false;
    while(time <= 2400){
        if(kannu[time] > 0){
            if(!started){
                started = true;
                cout << setfill('0') << right << setw(4) << time;
                cout << "-";
            }
        }
        else{
            if(started){
                started = false;
                cout << setfill('0') << right << setw(4) << time << endl;
            }
        }
        time += 5;
        if(time % 100 == 60){
            time += 40;
        }
    }
}