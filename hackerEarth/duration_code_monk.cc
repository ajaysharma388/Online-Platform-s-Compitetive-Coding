#include <iostream>

using namespace std;

int main(){
	int t,sh,sm,eh,em;
	cin>>t;
	while(t--){
		cin>>sh>>sm>>eh>>em;
		//if (sh==12) sh=0;
		if(em-sm<0){
			cout<<eh-sh-1<<" "<<60+em-sm<<"\n";
		}else{
			cout<<eh-sh<<" "<<abs(sm-em)<<"\n";
		}
	}
	return 0;
}