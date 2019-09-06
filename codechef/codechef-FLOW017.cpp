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
	ll a,b,c,n;
	cin >> n;
	while(n--){
		cin >> a >> b >> c;
		if(a>b && a>c){
			(b>c)?cout<<b<<endl:cout<<c<<endl;
		}else if(b>a && b>c){
			(a>c)?cout<<a<<endl:cout<<c<<endl;
		}else{
			(b>a)?cout<<b<<endl:cout<<a<<endl;
		}
	}
	return 0;
}