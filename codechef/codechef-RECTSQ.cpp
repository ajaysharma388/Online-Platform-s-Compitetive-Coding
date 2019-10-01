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
    ll t,l,b;
    cin >> t;
    while(t--){
        cin >> l >> b;
        ll sq = __gcd(l,b);
        cout<<(l/sq)*(b/sq)<<endl;        
    }
    return 0;
}
