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
	string s;
	ll n,count=0;
	cin >> s >> n;
	ll len = s.length();
	for(ll i=0;i<len;++i){
		if(s[i]=='a'){
			count++;
		}
	}
	ll oc = (n/len)*count;
	for(ll i=0;i<(n%len);++i){
		if(s[i]=='a'){
			oc++;
		}
	}	
	cout<<oc<<endl;
	return 0;
}