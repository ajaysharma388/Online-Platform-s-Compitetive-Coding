#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool isHappy(int n) {
	if(n==1) return true;
	unordered_map<int,bool> mp;
    int ans = 0;
    mp[n] = true;
    while(true) {
    	// this loop runs endlessly.
    	while(n) {
        	int cur = n%10;
        	ans += (cur*cur);
        	n/=10;
        }
       	if(mp[ans]) return false;
       	else mp[ans] = true;
        n = ans;
        ans = 0;
        if(n == 1) break;
    }
    return true;
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
		int n;
		cin >> n;
		if(isHappy(n)) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}	
	}
	return 0;
}

// Sample Input :

// 2
// 181
// 19

// Sample Output :

// No
// Yes