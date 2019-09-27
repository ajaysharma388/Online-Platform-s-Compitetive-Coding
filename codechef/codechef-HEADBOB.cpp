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
	int t,n;
	cin>>t;
	while(t--){
		bool ci=false,cy=false;
		cin >> n;
		char ques[n];
		cin >> ques;
		for(int i=0;ques[i]!='\0';++i){
			if(ques[i]=='I'){
				ci=true;
			}else if(ques[i]=='Y'){
				cy=true;
			}
		}
		if(ci) cout<<"INDIAN"<<endl;
		else if(cy) cout<<"NOT INDIAN"<<endl;
		else cout<<"NOT SURE"<<endl;
	}
	return 0;
}