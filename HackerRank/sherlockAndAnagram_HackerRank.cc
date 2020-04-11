#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int sherlockAndAnagrams(string s) {
	unordered_map<string,int> mp;
	int count = 0;
	for(int i = 0; i < s.length(); ++i) {
		for(int j = i; j < s.length(); ++j) {
			string str = s.substr(i,j-i+1);
			sort(str.begin(),str.end());
			if(mp.find(str) == mp.end()) mp[str] = 1;
			else mp[str]++;
		} 
	}
	for(auto node : mp) {
		int n = node.second;
		count+= (n*(n-1))/2;
	}
	return count;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	cout << sherlockAndAnagrams(s) << endl;
	return 0;
}