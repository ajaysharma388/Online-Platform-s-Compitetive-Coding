#include <bits/stdc++.h>
using namespace std;

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
		cout << a%b << endl;
	}
	return 0;
}