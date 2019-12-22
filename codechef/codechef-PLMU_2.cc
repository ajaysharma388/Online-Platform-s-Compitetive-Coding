#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

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
		int n;
		cin >> n;
		int *a = new int[n];
		int count_0=0;
		int count_2=0;
		for(int i=0;i<n;++i){
			cin >> a[i];
			if(a[i]==2) count_2++;
			else if(a[i]==0) count_0++;
		}
		int result = ((count_0*(count_0-1))+(count_2*(count_2-1)))/2;
		cout<<result<<endl;
	}
	return 0;
}

// Sample Input :

// 2
// 3
// 2 4 2
// 3
// 0 2 3

// Sample Output :

// 1
// 0