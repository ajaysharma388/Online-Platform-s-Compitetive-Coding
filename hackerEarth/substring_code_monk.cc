#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
string s;
ll t,a[10];
void solve()
{
    ll i,j,k;
    cin>>t;
    a[0]=a[6]=a[9]=6;
    a[1]=2;
    a[2]=a[3]=a[5]=5;
    a[4]=4;
    a[7]=3;
    a[8]=7;
    while(t--)
    {
        cin>>s;
        ll val=0;
        for(i=0;i<s.size();i++)
        {
            val+=a[s[i]-'0'];
        }
        cout<<val<<endl;
        if(val%2==1)
        {
            cout<<"7";
            val-=3;
        }
        while(val>=2)
        {
            val-=2;
            cout<<"1";
        }
        cout<<"\n";
    }
}
int main()
{
    solve();
    return 0;
}