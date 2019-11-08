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
    int t,n,x1,x2,x3,y1,y2,y3;
    cin>>t;
    while(t--){
        cin>>n>>x1>>y1>>x2>>y2>>x3>>y3;
        if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=n*n
        &&(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)<=n*n
        ||(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)<=n*n
        &&(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)<=n*n
        ||(x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)<=n*n
        ||(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)<=n*n)
           cout<<"yes"<<endl;
        else 
          cout<<"no"<<endl;
    }
    return 0;
}