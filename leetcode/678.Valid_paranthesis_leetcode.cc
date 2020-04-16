#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	return;
}


 bool checkValidString(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int bal = 0;
    for(char ch : s) {
        if(ch == ')') bal--;
        else bal++;
        if(bal < 0) return false;
    }
    bal = 0;
    for(int i = s.length()-1; i>= 0; --i) {
        if(s[i] == '(') bal--;
        else bal++;
        if(bal < 0) return false;
    }
    return true;
}



int main(){
	fastio(true);
	int testCases;
	cin >> testCases;
	while(testCases--) {
		string s;
		cin >> s;
		(checkValidString(s)) 
			? cout << "true" << endl 
			: cout << "false" << endl;
	}
	return 0;
}

// Sample Input :

// 6
// (())((())()()(*)(*()(())())())()()((()())((()))(*
// ((())****)))
// ((())))
// (())((()))((****))
// (((((((())))))**
// (*)

// Sample Output :

// false
// true
// false
// true
// true
// true