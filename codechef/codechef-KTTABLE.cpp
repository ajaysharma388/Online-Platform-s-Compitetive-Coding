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
    ll t,n,ttl;
    ll *time=new long long int[10000];
    ll *job=new long long int[10000];
    cin >> t;
    while(t--){
        ttl=0;
        cin >> n;
        for(int i=0;i<n;++i) cin >> time[i];
        for(int i=0;i<n;++i) cin >> job[i];
        if(time[0]>=job[0]) ttl++;
        for(int i=1;i<n;++i)
            if(time[i]-time[i-1]>=job[i]) ttl++;
        cout<<ttl<<endl;
    }
    delete []time;
    delete []job;
    return 0;
}
