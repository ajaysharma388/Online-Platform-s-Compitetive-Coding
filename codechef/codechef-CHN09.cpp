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
    int t,am,br,no;
    string ballons;
    cin >> t;
    while(t--){
        cin >> ballons;
        am=br=0;
        no=ballons.length();
        for(int i=0;i<no;++i){
            if(ballons[i]=='a') am++;
            else br++;
        }
        cout<<min(am,br)<<endl;
    }
    return 0;
}