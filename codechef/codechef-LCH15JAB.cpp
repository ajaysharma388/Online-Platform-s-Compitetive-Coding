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
    ll testCases;
    string s;
    cin >> testCases;
    while(testCases--){
        int a[26]={};
        cin >> s;
        for(int i=0;i<s.length();++i){
            a[s[i]-'a']++;
        }
        int m=0;
        for(int i=0;i<26;++i){
            if(a[i]>a[m]) m=i;
        }
        (a[m]!=s.length()-a[m])?cout<<"NO\n":cout<<"YES\n";
    }
    return 0;
}