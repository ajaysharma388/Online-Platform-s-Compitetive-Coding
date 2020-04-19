#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool isValid(string s) {
   	stack<char> st;     
    for(auto ch : s) {
        if(ch == '(' or ch == '[' or ch == '{') st.push(ch);
        else {
        	if(st.empty()) return false;
            char t = st.top();
            if(t == '(' and ch == ')') st.pop();
            else if(t == '{' and ch == '}') st.pop();
            else if(t == '[' and ch == ']') st.pop();
            else return false;
        }
    }
    return st.empty();
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
	while(t--) {
		string s;
		cin >> s;
		if(isValid(s)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}	
	return 0;
}

// Sample Input :

// 4
// {{(([]))}}}
// ({)}
// ()
// (((({[]})))){{{[()]}}}

// Sample Output :

// No
// No
// Yes
// Yes