#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int a[1000005];

void possibleCases(int n){
	if(n==1 || n==2){
		a[n] = n;
		return;
	}
	if(n==3){
		a[n] = 4;
		return;
	}
	if(a[n]!=-1){
		return;
	}
	possibleCases(n-3);
	possibleCases(n-2);
	possibleCases(n-1);
	a[n] = a[n-1]+a[n-2]+a[n-3];
	return;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(a,-1,1000005);
	int n;
	cin >> n;
	while(n--){
		int data;
		cin >> data;
		possibleCases(data);
		cout << a[data] << endl;
	}	
	return 0;
}


// Sample Input : 

// 3
// 1
// 3
// 7

// Sample Output : 

// 1
// 4
// 44 