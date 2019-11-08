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
	ll n,num,rev;
	cin >> n;
	while(n--){
		cin >> num;
		rev=0;
		while(num){
			rev*=10;
			rev+=(num%10);
			num/=10;
		}
		cout << rev << endl;
	}
	return 0;
}