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
	int t,q;
	double p,cost;
	cin >> t;
	while(t--){
		cin >> q >> p;
		cost=q*p;
		if(q>1000) cost-=(cost/10);
		cout<<fixed<<setprecision(6)<<cost<<endl;
	}
	return 0;
}