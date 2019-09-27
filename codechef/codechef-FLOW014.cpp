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
		int hr,te;
		float ca;
		cin >> hr >> ca >> te;
		if(hr>50&&ca<0.7&&te>5600){
			cout<<"10"<<endl;
		}else if(hr>50&&ca<0.7){
			cout<<"9"<<endl;
		}else if(ca<0.7&&te>5600){
			cout<<"8"<<endl;
		}else if(hr>50&&te>5600){
			cout<<"7"<<endl;
		}else if(hr>50||ca<0.7||te>5600){
			cout<<"6"<<endl;
		}else{
			cout<<"5"<<endl;
		}
	}
	return 0;
}