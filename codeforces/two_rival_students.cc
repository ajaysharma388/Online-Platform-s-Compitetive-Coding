#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int maxDistance(int n,int x,int minV,int maxV){
	while(maxV<n && x){
		maxV++;
		x--;
	}
	while(minV>1 && x){
		minV--;
		x--;
	}
	return abs(maxV-minV);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,x,a,b;
	cin >> t;
	while(t--){
		cin >> n >> x >> a >> b;
		if(a>b){
			cout << maxDistance(n,x,b,a) << endl;
		}else{
			cout << maxDistance(n,x,a,b) << endl;
		}
	}	
	return 0;
}

// Input : 

// 3
// 5 1 3 2
// 100 33 100 1
// 6 0 2 3


// Output : 

// 2
// 99
// 1