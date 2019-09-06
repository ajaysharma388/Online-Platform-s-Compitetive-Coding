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
	int n,a,b;
	cin >> n;
	while(n--){
		cin >> a >> b;
		if(a>b) cout<<">"<<endl;
		else if(a<b) cout<<"<"<<endl;
		else cout<<"="<<endl;
	}
	return 0;
}