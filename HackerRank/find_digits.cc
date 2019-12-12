#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"


int findDigits(int n) {
	int temp = n;
	vector<int> digit;
	while(n){
		digit.push_back(n%10);
		n/=10;
	}
	int count=0;
	for(int i=0;i<digit.size();++i){
		if(digit[i] && temp%digit[i]==0){
			count++;
		}
	}
	return count;
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
		cout<<findDigits(n)<<endl;
	}
	return 0;
}