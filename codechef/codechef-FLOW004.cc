#include <bits/stdc++.h>
using namespace std;

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
		sum=0;
		cin >> n;
		sum+=n%10;
		while(n>9){
			n/=10;
		}
		sum+=n;
		cout<<sum<<endl;
	}
	return 0;
}