#include<bits/stdc++.h>
typedef long long ll;
const ll M = 1000000007;
using namespace std;

// 1001
ll toLongLong(string binstr) {
  ll res = 0;
  for (int i = 0; i < binstr.length(); i++) {
    res *= 2;
    if (binstr[i] == '1')
      res += 1;
  }
  return res;
}

// 8
string toBinString(ll num) {
  if (num == 0) return "0";
  string str = "";
  while(num > 1) {
    if (num & 1)
      str.push_back('1');
    else
      str.push_back('0');
    num = num >> 1;
  }
  str.push_back('1');
  reverse(str.begin(), str.end());
  return str;
}

string afterRabot(string binstr) {
  string str = "0";
  for (int i = 1; i < binstr.size(); i++) {
    if (binstr[i] != binstr[i - 1]) {
      continue;
    }
    str.push_back(binstr[i]);
  }
  return str;
}

ll afterBinaryRabot(ll num) {
  string binString = toBinString(num);
  string strRabotted = afterRabot(binString);
  return toLongLong(strRabotted);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  // iterating over numbers
  for (ll i = 1; i < 50; i++) {
    cout << afterBinaryRabot(i) << endl;
  }
  // cout << toBinString(8);
  // cout << toLongLong("00011011");
  // cout << afterRabot("1111111");
  return 0;
}