#include <iostream>

using namespace std;

int main(){
	int t,a=0,b=7,n;cin>>t;
	while(t--){
		cin>>n;
		if(abs(n-a)<abs(b-n)){
			cout<<"A\n";
			a=n;
		}
		else if(abs(n-a)>abs(b-n)){ 
			cout<<"B\n";
			b=n;
		}
		else{
			if(a<b){
				cout<<"A\n";
				a=n;
			}else{ 
				cout<<"B\n";
				b=n;
			}
		}
	}
	return 0;
}