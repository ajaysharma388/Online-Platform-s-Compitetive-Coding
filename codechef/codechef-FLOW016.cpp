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
	ll n,a,b,g;
	cin >> n;
	while(n--){
		cin >> a >> b;
		g=__gcd(a,b);
		cout<<g<<" "<<(a*b)/g<<endl;
	}
	return 0;
}