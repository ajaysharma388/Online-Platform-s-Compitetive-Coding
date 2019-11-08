#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll A[n],sum=0;
    for(int i=0;i<n;++i){
    	cin>>A[i];
    	sum+=A[i];
    	A[i]=sum;
    }
    while(q--){
    	ll r,l,N,s;
    	cin>>l>>r;
    	if(l-2>=0)
    		s=A[r-1]-A[l-2];
    	else
    		s=A[r-1];
    	N=r-l+1;
    	cout<<s/N<<"\n";
    }
    return 0;
}