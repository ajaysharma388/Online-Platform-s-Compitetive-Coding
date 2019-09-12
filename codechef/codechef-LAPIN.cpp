#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool check(int a[]){
	for(int i=0;i<26;++i)
		if(a[i]!=0) return true;
	return false;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	while(t--){
		int a[26]={};
		cin >> s;
		int l=s.length();
		for(int i=0;i<l/2;++i)
			a[s[i]-'a']++;
		if(l&1){
			for(int i=l;i>l/2;--i)
				a[s[i]-'a']--;
		}else{
			for(int i=l;i>=l/2;--i)
				a[s[i]-'a']--;
		}
		if(check(a)) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}