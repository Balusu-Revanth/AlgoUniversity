#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  string e;
  getline(cin, e);
  stack<int> s;
  for (int i = 0; i < e.size(); i++) {
    if (e[i] == ' ') continue;
    else if (e[i] >= '0' && e[i] <= '9') {
      s.push(e[i]-'0');
    }
    else {
      int a = s.top();
      s.pop();
      int b = s.top();
      s.pop();
      if (e[i] == '+') s.push(a+b);
      if (e[i] == '-') s.push(b-a);
      if (e[i] == '*') s.push(a*b);
      if (e[i] == '/') s.push(b/a);
    }
  }
  cout << s.top();
}