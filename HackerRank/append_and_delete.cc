#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string appendAndDelete(string s, string t, int k) {
    int i=0,j=0;
    int sLen = s.length();
    int tLen = t.length();
    while(i<sLen && j<tLen){
        if(s[i]!=t[j]){
            break;
        }
        i++;j++;
    }
    if(((tLen-sLen)&1 and k%2==0) and sLen<tLen){
        return "No";
    }else if((i>sLen and j>tLen) or 
        ( ((sLen+tLen) - (i+j)) <= k and sLen-i <= k))
        return "Yes";
    else return "No";
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	cin >> testCases;
	while(testCases--){
    	string s1,s2;
	    int n;
	    cin >> s1 >> s2 >> n;
	    cout<<appendAndDelete(s1,s2,n)<<endl;
	}	
	return 0;
}

// Sample Input :

// 7
// hackerhappy
// hackerrank
// 9
// abc
// def
// 6
// aba
// aba
// 7
// ashley
// ash
// 2
// qwerasdf
// qwerbsdf
// 6
// y
// yu
// 2
// aaaaaaaaaa
// aaaaa
// 7

// Sample Output :

// Yes
// Yes
// Yes
// No
// No
// No
// Yes