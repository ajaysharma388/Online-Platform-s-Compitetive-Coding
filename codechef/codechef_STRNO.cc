#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define pb(x) push_back(x)
#define ppb() pop_back()
#define endl "\n"

void fastio(bool read = false) {
  if(read) {
  	#ifndef ONLINE_JUGDE
  	freopen("input.txt","r",stdin);
  	freopen("output.txt","w",stdout);
  	freopen("error.txt","w",stderr);
  	#endif
  }
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

vector<int> seieve(10000);

bool isPrime(int n) {
  if(n == 2) return true;
  if(n%2 == 0) return false;
  for(int i = 2; i*i <= n; ++i) {
    if(n%i == 0) return false;
  }
  return true;
}

void prepareSeieve() {
  seieve[0] = 2;
  int k = 1;
  for(int i = 3; i <= 100000; i+=2) {
    if(isPrime(i)) seieve[k++] = i;
  }
  return;
}

void printPrimes(int n) {
  for(int i = 0; i < n; ++i) {
    cout << seieve[i] << " ";
  }
  cout << endl;
}

int main() {
  fastio(true);
  prepareSeieve();
  int t;
  cin >> t;
  while(t--) {
    int x,k;
    cin >> x >> k;
    int num = 1;
    for(int i = 0; i < k; ++i) {
      num *= seieve[i];
    }
    int count = 0;
    for(int i = 1; i <= num; ++i) {
      if(num%i == 0) count++;
    }
    if(count == x) cout << 1 << endl;
    else cout << 0 << endl;
  }
  return 0;  
}