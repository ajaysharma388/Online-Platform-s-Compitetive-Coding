/*==========================
Author : Ajay Sharma
date : 04.05.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

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

int main() {
	fastio(true);
	int t;
	cin >> t;
	while(t--) {
		int N,Q;
		cin >> N >> Q;
		string patient;
		cin >> patient;
		while(Q--) {
			int C;
			cin >> C;
			int *Admit = new int[26]{0};
			for(char c : patient) 
				Admit[c-'a']++;
			if(C >= N) cout << 0 << endl; 
			else {
				for(int i = 0; i < 26; ++i)
					Admit[i] = (Admit[i] < C) ? 0 : Admit[i]-C;
				int ans = 0;
				for(int i = 0; i < 26; ++i) 
						ans += Admit[i];
				cout << ans << endl;
			}
		}
	}
	return 0;
}

// Sample Input :

// 1
// 20 3
// stayinghomesaveslife
// 2
// 3
// 1

// Sample Output :

// 2
// 0
// 6