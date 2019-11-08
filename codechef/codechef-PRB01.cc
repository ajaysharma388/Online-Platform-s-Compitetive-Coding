#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool isPrime(ll num){
	if(num==1 || num==0){
		return false;
	}else if(n==2){
		cout<<"yes"<<endl;
	}else if(num&1){
		int i;
		for(i=3;i*i<=num;i+=2){
			if(num%i==0){
				return false;
			}
		}
		if(i*i>num) return true;
	}else{
		return false;
	}
}
int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ll n,num;
	cin >> n;
	while(n--){
		cin>>num;
		(isPrime(num))
			? cout<<"yes"<<endl
			: cout<<"no"<<endl;
	}
	return 0;
}