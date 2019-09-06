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
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n<10) cout << "What an obedient servant you are!"<<endl;
		else cout << "-1" <<endl;
	}
	return 0;
}