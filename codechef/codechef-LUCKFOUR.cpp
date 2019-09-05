#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int n,num;
	cin >> n;
	while(n--){
		int count=0;
		cin >> num;
		while(num){
			if(num%10==4) count++;
			num/=10;
		}
		cout << count << endl;
	}
	return 0;
}