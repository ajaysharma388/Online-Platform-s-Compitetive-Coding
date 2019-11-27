#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int digitSum(string s){
	int res=0;
	for(int i=0;i<s.length();++i){
		res+=s[i]-'0';
	}
	if(res<10){
		return res;
	}
	return digitSum(to_string(res));
}

// Complete the superDigit function below.
int superDigit(string n, int k) {
	string sum = to_string(digitSum(n));
	string res = "";
    for(int i=1;i<=k;++i){
    	res+=sum;
    }
    return digitSum(res);
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	string n;
	cin >> n >> k;
	cout << superDigit(n,k) << endl;
	return 0;
}

// Sample Input : 

// 9785 4

// Sample Output : 

// 8