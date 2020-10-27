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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
  if ((x += a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator-=(const mint a) {
  if ((x += mod-a.x) >= mod) x -= mod;
  return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
  if (!t) return 1;
  mint a = pow(t>>1);
  a *= a;
  if (t&1) a *= *this;
  return a;
  }
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main()
{
    ll N;
    cin >> N;
    vector<vector<mint>> dp(N+1, vector<mint>(64));
    //0:AAA 1:AAC 2:AAG 3:AAT 4:ACA 5:ACC 6:ACG 7:ACT
    //8:AGA 9:AGC 10:AGG 11:AGT 12:ATA 13:ATC 14:ATG 15:ATT
    //16:CAA 17:CAC 18:CAG 19:CAT 20:CCA 21:CCC 22:CCG 23:CCT
    //24:CGA 25:CGC 26:CGG 27:CGT 28:CTA 29:CTC 30:CTG 31:CTT
    //32:GAA 33:GAC 34:GAG 35:GAT 36:GCA 37:GCC 38:GCG 39:GCT
    //40:GGA 41:GGC 42:GGG 43:GGT 44:GTA 45:GTC 46:GTG 47:GTT
    //48:TAA 49:TAC 50:TAG 51:TAT 52:TCA 53:TCC 54:TCG 55:TCT
    //56:TGA 57:TGC 58:TGG 50:TGT 60:TTA 61:TTC 62:TTG 63:TTT
    rep(i, 64){
        if(i == 6 || i == 9 || i == 33){
            dp.at(3).at(i) = 0;
        }
        else{
            dp.at(3).at(i) = 1;
        }
    }
    rep2(i, 3, N){
        dp.at(i+1).at(0) = dp.at(i).at(0)+dp.at(i).at(16)+dp.at(i).at(32)+dp.at(i).at(48);
        dp.at(i+1).at(1) = dp.at(i).at(0)+dp.at(i).at(16)+dp.at(i).at(32)+dp.at(i).at(48);
        dp.at(i+1).at(2) = dp.at(i).at(0)+dp.at(i).at(16)+dp.at(i).at(32)+dp.at(i).at(48);
        dp.at(i+1).at(3) = dp.at(i).at(0)+dp.at(i).at(16)+dp.at(i).at(32)+dp.at(i).at(48);
        dp.at(i+1).at(4) = dp.at(i).at(1)+dp.at(i).at(17)+dp.at(i).at(49);
        dp.at(i+1).at(5) = dp.at(i).at(1)+dp.at(i).at(17)+dp.at(i).at(49);
        dp.at(i+1).at(7) = dp.at(i).at(1)+dp.at(i).at(17)+dp.at(i).at(49);
        dp.at(i+1).at(8) = dp.at(i).at(2)+dp.at(i).at(18)+dp.at(i).at(34)+dp.at(i).at(50);
        dp.at(i+1).at(10) = dp.at(i).at(2)+dp.at(i).at(18)+dp.at(i).at(34)+dp.at(i).at(50);
        dp.at(i+1).at(11) = dp.at(i).at(2)+dp.at(i).at(18)+dp.at(i).at(34)+dp.at(i).at(50);
        dp.at(i+1).at(12) = dp.at(i).at(3)+dp.at(i).at(19)+dp.at(i).at(35)+dp.at(i).at(51);
        dp.at(i+1).at(13) = dp.at(i).at(3)+dp.at(i).at(19)+dp.at(i).at(35)+dp.at(i).at(51);
        dp.at(i+1).at(14) = dp.at(i).at(3)+dp.at(i).at(19)+dp.at(i).at(35)+dp.at(i).at(51);
        dp.at(i+1).at(15) = dp.at(i).at(3)+dp.at(i).at(19)+dp.at(i).at(35)+dp.at(i).at(51);
        dp.at(i+1).at(16) = dp.at(i).at(4)+dp.at(i).at(20)+dp.at(i).at(36)+dp.at(i).at(52);
        dp.at(i+1).at(17) = dp.at(i).at(4)+dp.at(i).at(20)+dp.at(i).at(36)+dp.at(i).at(52);
        dp.at(i+1).at(18) = dp.at(i).at(4)+dp.at(i).at(20)+dp.at(i).at(36)+dp.at(i).at(52);
        dp.at(i+1).at(19) = dp.at(i).at(4)+dp.at(i).at(20)+dp.at(i).at(36)+dp.at(i).at(52);
        dp.at(i+1).at(20) = dp.at(i).at(5)+dp.at(i).at(21)+dp.at(i).at(37)+dp.at(i).at(53);
        dp.at(i+1).at(21) = dp.at(i).at(5)+dp.at(i).at(21)+dp.at(i).at(37)+dp.at(i).at(53);
        dp.at(i+1).at(22) = dp.at(i).at(5)+dp.at(i).at(21)+dp.at(i).at(37)+dp.at(i).at(53);
        dp.at(i+1).at(23) = dp.at(i).at(5)+dp.at(i).at(21)+dp.at(i).at(37)+dp.at(i).at(53);
        dp.at(i+1).at(24) = dp.at(i).at(22)+dp.at(i).at(38)+dp.at(i).at(54);
        dp.at(i+1).at(25) = dp.at(i).at(22)+dp.at(i).at(38)+dp.at(i).at(54);
        dp.at(i+1).at(26) = dp.at(i).at(22)+dp.at(i).at(38)+dp.at(i).at(54);
        dp.at(i+1).at(27) = dp.at(i).at(22)+dp.at(i).at(38)+dp.at(i).at(54);
        dp.at(i+1).at(28) = dp.at(i).at(7)+dp.at(i).at(23)+dp.at(i).at(39)+dp.at(i).at(55);
        dp.at(i+1).at(29) = dp.at(i).at(7)+dp.at(i).at(23)+dp.at(i).at(39)+dp.at(i).at(55);
        dp.at(i+1).at(30) = dp.at(i).at(7)+dp.at(i).at(23)+dp.at(i).at(39)+dp.at(i).at(55);
        dp.at(i+1).at(31) = dp.at(i).at(7)+dp.at(i).at(23)+dp.at(i).at(39)+dp.at(i).at(55);
        dp.at(i+1).at(32) = dp.at(i).at(8)+dp.at(i).at(24)+dp.at(i).at(40)+dp.at(i).at(56);
        dp.at(i+1).at(34) = dp.at(i).at(8)+dp.at(i).at(24)+dp.at(i).at(40)+dp.at(i).at(56);
        dp.at(i+1).at(35) = dp.at(i).at(8)+dp.at(i).at(24)+dp.at(i).at(40)+dp.at(i).at(56);
        dp.at(i+1).at(36) = dp.at(i).at(25)+dp.at(i).at(41)+dp.at(i).at(57);
        dp.at(i+1).at(37) = dp.at(i).at(25)+dp.at(i).at(41)+dp.at(i).at(57);
        dp.at(i+1).at(38) = dp.at(i).at(25)+dp.at(i).at(41)+dp.at(i).at(57);
        dp.at(i+1).at(39) = dp.at(i).at(25)+dp.at(i).at(41)+dp.at(i).at(57);
        dp.at(i+1).at(40) = dp.at(i).at(10)+dp.at(i).at(26)+dp.at(i).at(42)+dp.at(i).at(58);
        dp.at(i+1).at(41) = dp.at(i).at(26)+dp.at(i).at(42)+dp.at(i).at(58);
        dp.at(i+1).at(42) = dp.at(i).at(10)+dp.at(i).at(26)+dp.at(i).at(42)+dp.at(i).at(58);
        dp.at(i+1).at(43) = dp.at(i).at(10)+dp.at(i).at(26)+dp.at(i).at(42)+dp.at(i).at(58);
        dp.at(i+1).at(44) = dp.at(i).at(11)+dp.at(i).at(27)+dp.at(i).at(43)+dp.at(i).at(59);
        dp.at(i+1).at(45) = dp.at(i).at(27)+dp.at(i).at(43)+dp.at(i).at(59);
        dp.at(i+1).at(46) = dp.at(i).at(11)+dp.at(i).at(27)+dp.at(i).at(43)+dp.at(i).at(59);
        dp.at(i+1).at(47) = dp.at(i).at(11)+dp.at(i).at(27)+dp.at(i).at(43)+dp.at(i).at(59);
        dp.at(i+1).at(48) = dp.at(i).at(12)+dp.at(i).at(28)+dp.at(i).at(44)+dp.at(i).at(60);
        dp.at(i+1).at(49) = dp.at(i).at(12)+dp.at(i).at(28)+dp.at(i).at(44)+dp.at(i).at(60);
        dp.at(i+1).at(50) = dp.at(i).at(12)+dp.at(i).at(28)+dp.at(i).at(44)+dp.at(i).at(60);
        dp.at(i+1).at(51) = dp.at(i).at(12)+dp.at(i).at(28)+dp.at(i).at(44)+dp.at(i).at(60);
        dp.at(i+1).at(52) = dp.at(i).at(13)+dp.at(i).at(29)+dp.at(i).at(45)+dp.at(i).at(61);
        dp.at(i+1).at(53) = dp.at(i).at(13)+dp.at(i).at(29)+dp.at(i).at(45)+dp.at(i).at(61);
        dp.at(i+1).at(54) = dp.at(i).at(13)+dp.at(i).at(29)+dp.at(i).at(45)+dp.at(i).at(61);
        dp.at(i+1).at(55) = dp.at(i).at(13)+dp.at(i).at(29)+dp.at(i).at(45)+dp.at(i).at(61);
        dp.at(i+1).at(56) = dp.at(i).at(14)+dp.at(i).at(30)+dp.at(i).at(46)+dp.at(i).at(62);
        dp.at(i+1).at(57) = dp.at(i).at(30)+dp.at(i).at(46)+dp.at(i).at(62);
        dp.at(i+1).at(58) = dp.at(i).at(14)+dp.at(i).at(30)+dp.at(i).at(46)+dp.at(i).at(62);
        dp.at(i+1).at(59) = dp.at(i).at(14)+dp.at(i).at(30)+dp.at(i).at(46)+dp.at(i).at(62);
        dp.at(i+1).at(60) = dp.at(i).at(15)+dp.at(i).at(31)+dp.at(i).at(47)+dp.at(i).at(63);
        dp.at(i+1).at(61) = dp.at(i).at(15)+dp.at(i).at(31)+dp.at(i).at(47)+dp.at(i).at(63);
        dp.at(i+1).at(62) = dp.at(i).at(15)+dp.at(i).at(31)+dp.at(i).at(47)+dp.at(i).at(63);
        dp.at(i+1).at(63) = dp.at(i).at(15)+dp.at(i).at(31)+dp.at(i).at(47)+dp.at(i).at(63);
    }
    mint ans = 0;
    rep(i, 64){
        ans += dp.at(N).at(i);
    }
    cout << ans << endl;
}