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
	int n;
	cin >> n;
	while(n--){
		int num;
		cin >> num;
		if(num%10==0){
			cout<<"0"<<endl;
		}else if(num%10==5){
			cout<<"1"<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}	
	return 0;
}