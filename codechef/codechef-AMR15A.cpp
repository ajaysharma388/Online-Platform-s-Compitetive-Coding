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
	int n,o=0,e=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
		if(a[i]&1) o++;
		else e++;
	}
	if(e<=o){
		cout<<"NOT READY"<<endl;
	}else{
		cout<<"READY FOR BATTLE"<<endl;
	}
	return 0;
}