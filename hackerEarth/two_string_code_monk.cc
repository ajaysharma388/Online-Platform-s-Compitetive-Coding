#include <iostream>
using namespace std;
#define ll long long
int main(){
	char s[1000005];
	int t;
	cin>>t;
	while(t--){
		ll a[26]={0};
		cin>>s;
		for(int i=0;s[i]!='\0';++i)
			a[s[i]-97]++;
		cin>>s;
		for(int i=0;s[i]!='\0';++i)
			a[s[i]-97]--;
		int i=0;
		for(;i<26;++i)if(a[i]>0){ cout<<"NO\n";break;}
		if(i>25)cout<<"YES\n";
	}
	return 0;
}