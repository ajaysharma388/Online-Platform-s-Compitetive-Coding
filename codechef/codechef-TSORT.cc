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
	int n;
	cin >> n;
	int arr[n]={};
	for(int i=0;i<n;++i){
		cin >> arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;++i){
		cout << arr[i] << endl;
	}
	return 0;
}