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
    int t,n,q,p;
    string str;
    string *dic = new string[1000];
    bool *used = new bool[1000];
    cin >> t;
    while(t--){
        cin >> n >> q;
        for(int i=0;i<n;++i){
            cin >> dic[i];
            used[i]=false;
        }
        while(q--){
            cin >> p;
            while(p--){
                cin >> str;
                for(int i=0;i<n;++i)
                    if(str==dic[i]) used[i]=true;
            }
        }
        for(int i=0;i<n;++i)
            (used[i])
            ? cout<<"YES "
            : cout<<"NO ";
        cout<<endl;
    }
    delete []dic;
    delete []used;
    return 0;
}
