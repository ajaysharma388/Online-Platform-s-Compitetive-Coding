#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string roman[] = {"I","IV","V","IX","X","XL","L",
    					"XC","C","CD","D","CM","M"};
int value[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};

string intToRoman(int num) {
	int n = sizeof(value)/sizeof(value[0])-1;
	string s = "";
	while(num){
        if(value[n]<=num){
			while(value[n]<=num){
			    num-=value[n];
			    s+=roman[n];
		    }
		}
		n--;
	}
	return s;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int number,testCases;
	cin >> testCases;
	while(testCases--){
		cin >> number;
		cout<<intToRoman(number)<<endl;
	}
	return 0;
}

// Input : 

// 5
// 3
// 4
// 58
// 9
// 1994

// Output : 

// III
// IV
// LVIII
// IX
// MCMXCIV