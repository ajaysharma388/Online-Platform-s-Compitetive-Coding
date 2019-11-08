#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int nextPrime(int n){
    int j,inc;
    if(n&1) inc=2;
    else inc=1;
    for(int i=n+inc;i<INT_MAX;i+=2){
        for(j=2;j*j<=i;++j)
            if(i%j==0) break;
        if(j*j>i) return i;
    }
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x,y; cin >> t;
    while(t--){
        cin >> x >> y;
        cout<<nextPrime(x+y)-(x+y)<<endl;
    }
    return 0;
}