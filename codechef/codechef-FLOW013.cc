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
	int n,a,b,c;
	cin >> n;
	while(n--){
		cin>>a>>b>>c;
		if(a+b+c==180) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}