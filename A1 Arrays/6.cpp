#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n;
  map<int, long int> mp;
  long int prefixSum = 0, maxLength = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    prefixSum = (prefixSum + x) % 7;
    if (prefixSum == 0) {
		  maxLength = i+1;
	  }
	  else {
	  	if (mp.find(prefixSum) == mp.end()) {
	  		mp[prefixSum] = i;
	  	}
	  	else {
	  		maxLength = max(maxLength, i - mp[prefixSum]);
	  	}
	  }
  }
	cout << maxLength;
}