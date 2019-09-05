#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int t,n,sum;
	cin >> t;
	while(t--){
		sum = 0;
		cin >> n;
		while(n){
			sum+=n%10;
			n/=10;
		}
		cout << sum << endl;
	}
	return 0;
}