#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// Complete the libraryFine function below.
int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    int fine=0;
    if(y2<y1){
        fine = 10000;    
    }else if(m2<m1 and y1==y2){
        fine = 500*(m1-m2);
    }else if(d1>d2 and m1==m2 and y2==y1){ 
        fine = 15*(d1-d2);
    }else{
        fine = 0;
    } 
    return fine;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d1,d2,m1,m2,y1,y2,t;
	cin >> t;
	while(t--){
		cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
		cout<<libraryFine(d1,m1,y1,d2,m2,y2)<<endl;
	}	
	return 0;
}