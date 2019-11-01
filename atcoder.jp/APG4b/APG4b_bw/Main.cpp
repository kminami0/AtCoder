#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define chmin(x, y) x = min(x, y)

void print_int(int x){
  cout << x << endl;
}

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

vector<int> var(1000, 0);
vector<vector<int>> var2(1000);

int calculate(string s){
  int i = 0;
  int x = 0;
  bool plus = true;
  bool minus = false;
  while(s.at(i) != ';'){
    if(plus == true){
      if(islower(s.at(i))){
        x += var.at(s.at(i));
        plus = false;
      }
      else if(isdigit(s.at(i))){
        x += s.at(i) - '0';
        plus = false;
      }
    }
    else if(minus == true){
     if(islower(s.at(i))){
       x -= var.at(s.at(i));
       minus = false;
      }
      else if(isdigit(s.at(i))){
        x -= s.at(i) - '0';
        minus = false;
      }
    }
    else if(s.at(i) == '+'){
      plus = true;
    }
    else{
      minus = true;
    }
    i += 2;
  }
  return x;
}

string upto_char(string s, string a){
  int pos = s.find(a);
  if(pos == string::npos){
    return "Error";
  }
  else{
    return s.substr(0, pos+1);
  }
}
    
vector<int> make_vec(string s){ // [1, 2, a] -> {1, 2, val(a)}
  int i = 0;
  int j = 0;
  int len = count(all(s), ',') + 1;
  vector<int> a(len);
  while(s.at(i) != ']'){
    if(s.at(i) == '['){
      i += 2;
    }
    else if(isdigit(s.at(i))){
      a.at(j) = s.at(i) - '0';
      j++;
      i += 2;
    }
    else if(s.at(i) == ','){
      i += 2;
    }
    else{
      a.at(j) = var.at(s.at(i));
      j++;
      i += 2;
    }
  }
  return a;
}
  

vector<int> sum_vec(vector<int> a, vector<int> b){
  vector<int> c(a.size(), 0);
  rep(i, a.size()){
    c.at(i) = a.at(i) + b.at(i);
  }
  return c;
}

vector<int> diff_vec(vector<int> a, vector<int> b){
  vector<int> c(a.size(), 0);
  rep(i, a.size()){
    c.at(i) = a.at(i) - b.at(i);
  }
  return c;
}

vector<int> vcalculate(string s){
  int i = 0;
  int len = 0;
  int j = 0;
  if(count(all(s), '[') >= 1){
    j = s.find("[");
    while(s.at(j) != ']'){
      if(s.at(j) == ','){
        len++;
      }
      j++;
    }
    len++;
  }
  else{
    len = var2.at(s.at(0)).size();
  }
  vector<int> a(len, 0);
  bool plus = true;
  bool minus = false;
  while(s.at(i) != ';'){
    if(plus == true){
      if(islower(s.at(i))){
        rep(k, len){
          a.at(k) = sum_vec(a, var2.at(s.at(i))).at(k);
        }
        plus = false;
        i += 2;
      }
      else if(s.at(i) == '['){
        rep(k, len){
          a.at(k) = sum_vec(a, make_vec(upto_char(s.substr(i), "]"))).at(k);
        }
        plus = false;
        i += s.substr(i).find("]") + 2;
      }
    }
    else if(minus == true){
     if(islower(s.at(i))){
       rep(k, len){
         a.at(k) = diff_vec(a, var2.at(s.at(i))).at(k);
       }
        minus = false;
        i += 2;
      }
      else if(s.at(i) == '['){
        rep(k, len){
          a.at(k) = diff_vec(a, make_vec(upto_char(s.substr(i), "]"))).at(k);
        }
        minus = false;
        i += s.substr(i).find("]") + 2;
      }
    }
    else if(s.at(i) == '+'){
      plus = true;
      i += 2;
    }
    else{
      minus = true;
      i += 2;
    }
  }
  return a;
}  

vector<vector<int>> vec(100, vector<int>(5, 0));

int main(){
  int N;
  cin >> N;
  vector<string> cmd(N, "");
  vector<string> par_cmd(10000);
  int semc = 0;
  int i = 0;
  string sc = ";";
  
  while(semc != N){
    cin >> par_cmd.at(i);
    if(par_cmd.at(i) == sc){
      semc++;
    }
    i++;
  }
  
  semc = 0;
  i = 1;
  cmd.at(0) = par_cmd.at(0);
  int j = 0;
  while(semc != N){
    if(par_cmd.at(i) != sc){
      cmd.at(j) = cmd.at(j) + " " + par_cmd.at(i);
      i++;
    }
    else{
      cmd.at(j) = cmd.at(j) + " " + par_cmd.at(i);
      i++;
      semc++;
      j++;
      if(semc != N){
        cmd.at(j) = par_cmd.at(i);
        i++;
      }
    }
  }
  
  rep(i, N){
    if(cmd.at(i).compare(0, 3, "int") == 0){
      var.at(cmd.at(i).at(4)) = calculate(cmd.at(i).substr(8));
    }
    else if(cmd.at(i).compare(0, 9, "print_int") == 0){
      print_int(calculate(cmd.at(i).substr(10)));
    }
    else if(cmd.at(i).compare(0, 3, "vec") == 0){
      var2.at(cmd.at(i).at(4)) = vcalculate(cmd.at(i).substr(8));
    }
    else{
      print_vec(vcalculate(cmd.at(i).substr(10)));
    }
  }
}