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
    ll t;
    cin >> t;
    while(t--){
        ll primes[] = {2,3,5,7,11,13,17,19};
        ll ans = 0;
        ll n;
        cin >> n;
        ll subsets = (1<<8)-1;
        for(ll i=1;i<=subsets;++i){
            ll deno = 1ll;
            ll setbits = __builtin_popcount(i);
            for(ll j=0;j<=7;++j){
                if(i & (1<<j)){
                    deno *= primes[j];
                }
            }
            if(setbits&1){
                ans += n/deno;  
            } 
            else{
                ans -= n/deno;  
            } 
        }
        cout<<ans<<endl;
    }
    return 0;
}