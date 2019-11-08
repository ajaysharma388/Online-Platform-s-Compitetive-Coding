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
    int t;
    cin >> t;
    while(t--){
    	ll n,k,m=0;
    	cin >> n >> k;
    	for(ll i = 2;i<=k;++i){
    		m=max(n%i,m);
    	}
    	cout << m << endl;
    }
	return 0;
}