#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int sqInTri(int n){
	int sum=0;
	if(n==0||n==1||n==2||n==3) return sum;
	n-=2;
	n/=2;
	for(int i=1;i<=n;++i) sum+=i;
	return sum;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << sqInTri(n) << endl;
	}
	return 0;
}