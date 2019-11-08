#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int g,p,s,m=0,n=0;
		cin>>g>>p>>s;
		int a[s][2];
		for(int i=0;i<s;++i){
			for(int j=0;j<2;++j){
				cin>>a[i][j];
				if(j==0) m+=a[i][j];
				else n+=a[i][j];
			}
		}
		cout<<min((m*g+n*p),(n*g+m*p))<<"\n";
	}	
	return 0;
}