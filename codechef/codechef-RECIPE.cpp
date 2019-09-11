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
	int t,n,m;
	cin >> t;
	while(t--){
		cin >> n;
		int r[n]={};
		cin>>r[0];
		int res=r[0];
		for(int i=1;i<n;++i){
			cin>>r[i];
			res=__gcd(res,r[i]);
		}
		for(int j=0;j<n;++j){
			cout<<r[j]/res<<" ";
		}
		cout<<endl;
	}
	return 0;
}