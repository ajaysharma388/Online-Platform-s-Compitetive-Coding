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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t,n;
	cin >> t;
	while(t--){
		cin >> n;
		ll x=INT_MAX,y=INT_MAX;
		ll *a=new long long[n];
		for(int i=0;i<n;++i){
			cin >> a[i];
			if(x>a[i]){
				y=x;
				x=a[i];
			}else if(y>a[i]){
				y=a[i];
			}
		}	
		cout<<x+y<<endl;
	}
	return 0;
}