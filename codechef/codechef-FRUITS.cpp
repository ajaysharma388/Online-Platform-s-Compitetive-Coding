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
    int a,o,k,t;
    cin >> t;
    while(t--){
        cin >> a >> o >> k;
        int x = max(a,o)-min(a,o);
        if(x>k) cout<<x-k<<endl;
        else cout<<"0"<<endl;  
    }
    return 0;
}