#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

ll fac(ll num){
	return (num==0)? 1:num*fac(num-1);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ll t,n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << fac(n) << endl;
	}
	return 0;
}