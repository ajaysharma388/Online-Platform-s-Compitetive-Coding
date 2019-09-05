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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,k,count=0,temp;
	cin >> n >> k;
	while(n--){
		cin >> temp;
		if(temp%k==0) count++;
	}
	cout << count <<endl;
	return 0;
}


// Note that this problem is for testing fast input-output.
// We can use scanf, printf in C langauge, which are quite fast in general :)
#include <bits/stdc++.h> 

using namespace std;

// Usually, you can use scanf/printf in C++.
// However, if you want to use cin/cout, it is usually slow.
// To make it faster. Use cin.tie(NULL) and set ios_base::sync_with_stdio(false)
// See the below code for details.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Read the input n, k
	int n, k;
	cin >> n >> k;

	// ans denotes number of integers n divisible by k
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		
		if (t % k == 0) {
			ans++;
		}		
	}

	// Print the ans.
	cout << ans << "\n";	
		
	return 0;
}