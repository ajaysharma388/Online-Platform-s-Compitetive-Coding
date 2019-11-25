#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


void shift(vector<int>&a,int n,int k){
	vector<int> v;
	int i;
	for(i=0;i<k;++i){
		v.push_back(-1);
	}
	for(;i<n+k;++i){
		v.push_back(a[i-k]);
	}
	for(i=0;i<k;++i){
		a[i] = v[n+i];
	}
	for(int i=k;i<n;++i){
		a[i] = v[i];
	}
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,q;
	cin >> n >> k >> q;
	vector<int> A(n);
	vector<int> Q(q);
	for(int i=0;i<n;++i){
		cin >> A[i];
	}
	for(int i=0;i<q;++i){
		cin >> Q[i];
	}
	k%=n;
	shift(A,n,k);
	for(int i=0;i<q;++i){
		cout<<A[Q[i]]<<" ";
	}
	return 0;
}

// Sample Input : 

// 5 2 3
// 1 2 3 4 5
// 0
// 1
// 2

// Sample Output : 

// 4 5 1 