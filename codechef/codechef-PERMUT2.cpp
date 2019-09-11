#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	// your code goes here
	int n,i;
	
	while(1){
	    cin >> n;
	    if(!n) break;
	    int perm[n+1],inv_perm[n+1];
	    for(i=1; i<=n; i++){
	        cin >> perm[i];
	        inv_perm[perm[i]] = i;
	    }
	    for(i=1; i<=n; i++)
	        if(perm[i] != inv_perm[i]){
	            cout << "not ambiguous" << endl;
	            break;
	        }
	    if(i == n+1) cout << "ambiguous" << endl;
	}
	
	return 0;
}