#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

ll saveThePrisoner(ll n, ll m, ll s) {
	int i = (s+m-1)%n;
    return (i==0)?n:i;
}

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
		ll n,m,s;
		cin >> n >> m >> s;
		cout<<saveThePrisoner(n,m,s)<<endl;
	}	
	return 0;
}