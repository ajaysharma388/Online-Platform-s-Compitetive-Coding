#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}

string createProgram(string s) {
	string res = "";
	int n = s.length();
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'N' or s[i] == 'S' or s[i] == 'E' or s[i] == 'W') {
			res+=s[i];
		} else {
			int k = i;
			int fac = 0;
			while(s[k]!='(') {
				fac*=10;
				fac+=(s[k]-'0');
				k++;
			}
			cout << fac << endl;
			// k++;
			// string a;
			// while(k < n) {
			// 	a+=s[k];
			// }
			// while(fac) {
			// 	res+=a;
			// 	fac--;
			// }
		}
	}		
	return res;
}

string createToken(char *s) {
	vector<string> vec;
	char*str = strtok(s,")");
	while(str) {
		string s(str);
		vec.push_back(s);
		str = strtok(NULL,")");
	}
	string res = "";
	for(string s : vec) {
		res += createProgram(s);
	}
	return res;
}

char *s = new char[10000];

int main() {
	fastio(true);
	ll cs = 1,ce = 1000000000;
	ll rs = 1,re = 1000000000;
	ll t;
	cin >> t;
	for(int testCase = 1; testCase <= t; ++testCase) {
		cin >> s;
		cout << createProgram(s) << endl;

		// for(char ch : s) {
		// 	switch(ch){
		// 		case 'N':
		// 				i--;
		// 				if(i == 0) i = re;
		// 				break;
		// 		case 'E':
		// 				j++;
		// 				if(j-1 == ce) j = 1;
		// 				break;
		// 		case 'W':
		// 				j--;
		// 				if(j == 0) j = ce;
		// 				break;
		// 		default:
		// 				i++;
		// 				if(i-1 == re) i = 1;
		// 	}
		// }
		// cout << "Case #" << testCase << ": "<< j << " " << i << endl;
	}
	return 0;
}