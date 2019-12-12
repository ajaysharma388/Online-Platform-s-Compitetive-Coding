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
		int *arr = new int[n];
		for(int i=0;i<n;++i){
			cin >> arr[i];
		}
		int count = 0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				if(arr[i]+arr[j]==arr[i]*arr[j]){
					count++;
				}				
			}
		}
		// It gives TLE as the solution is of the order O(N^2).
		cout<<count<<endl;
		delete []arr;
	}
	return 0;
}