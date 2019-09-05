#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int findsetbits(int n){
	int bit=0;
	if(n>2048) bit=n/2048;
	n%=2048;
	while(n){
		if(n&1) bit++;
		n>>=1;
	}
	return bit;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,num,bit;
	cin >> n;
	while(n--){
		bit=0;
		cin >> num;
		cout << findsetbits(num) << endl;	 
	}
	return 0;
}