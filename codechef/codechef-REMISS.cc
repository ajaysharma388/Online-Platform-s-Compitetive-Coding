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
	ll t,a,b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		cout << max(a,b) <<" "<< a+b << endl;
	}
	return 0;
}