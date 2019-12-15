#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int minimumDistances(vector<int> &a) {
	map<int,int> mp;
	int d=INT_MAX;
	for(int i=0;i<a.size();++i){
		if(mp.count(a[i])==1){
			d=min(d,abs(i-mp[a[i]]));
		}
		mp[a[i]]=i;
	}
	return (d==INT_MAX)?-1:d;
}

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
		vector<int> v(n);
		for(int i=0;i<n;++i){
			cin >> v[i];
		}
		cout<<minimumDistances(v)<<endl;
	}	
	return 0;
}

// Sample Input : 

// 3
// 5
// 3 2 1 2 3
// 6
// 7 1 3 4 1 7
// 7
// 1 2 3 4 5 6 7

// Sample Output :

// 2 
// 3
// -1