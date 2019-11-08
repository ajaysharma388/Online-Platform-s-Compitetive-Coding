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
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		int l=s.length(),i;
		for(i=0;i<l/2;++i){
			if(s[i]!=s[l-i-1]){
				break;
			}
		}
		if(i<l/2) cout<<"losses"<<endl;
		else cout<<"wins"<<endl;
	}
	return 0;
}