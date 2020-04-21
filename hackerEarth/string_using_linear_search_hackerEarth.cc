#include<bits/stdc++.h>
using namespace std;

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

int main() {
	fastio(true);
	string a = "SUVO";
	string b = "SUVOJIT";
	string inp;
	int t;
	cin >> t;
	while(t--) {
		cin >> inp;
		int n = inp.length();
		int acount = 0,bcount = 0;
		for(int i = n-1; i >= 0; --i) {
			if(inp[i] == 'T') {
				int k = b.length();
				int j = k-1;
				for(; j >= 0; --j) {
					if(inp[i] != b[j]) {
						break;
					} 
					i--;
				}
				if(j < 0) bcount++;
			} 
			if(inp[i] == 'O') {
				int k = a.length();
				int j = k-1;
				for(; j >= 0; --j) {
					if(inp[i] != a[j]) {
						break;
					} 
					i--;
				}
				// cout << j << endl;
				if(j < 0) acount++;
			}
		}
		cout << a << " = " << acount << ", " << b << " = " << bcount << endl;
	}
	return 0;
}