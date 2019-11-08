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
	ll n,num;
	cin >> n;
	while(n--){
		cin >> num;
		num = sqrt(num);
		cout << num << endl;
	}
	return 0;
}
