#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int checkAlg(string s){
	string result="";
	int count = 1;
	char cur = s[0]; 
	for(int i=1;i<s.length();++i){
		if(cur==s[i]){
			count++;
		}else{
			result += cur;
			result += to_string(count);
			cur = s[i];
			count = 1;
		}
	}
	result += cur;
	result += to_string(count);
	return result.length();
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
	while(t--){
		string s;
		cin >> s;
		int len = s.length();
		if(len>checkAlg(s)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}