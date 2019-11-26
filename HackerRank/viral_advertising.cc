#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


ll cummulativeLike(int days){
	ll shared = 5;
	ll liked = 2;
	ll cm = liked;
	int day=1;
	for(day=2;day<=days;++day){
		shared = liked*3;
		liked = floor(shared/2);
		cm += liked;
	}
	return cm;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	cin >> testCases;
	while(testCases--){
		int days;
		cin >> days;
		cout<<cummulativeLike(days)<<endl;
	}
	return 0;
}

// Sample Input : 

// 5
// 1 7 5 6 2

// Sample Output : 

// 2
// 56
// 24
// 37
// 5