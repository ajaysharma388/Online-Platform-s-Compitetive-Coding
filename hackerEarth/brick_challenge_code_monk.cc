#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;
	int i=1;
	while(n){
		n-=i;
		if(n<=0){printf("Patlu\n");break;} 
		n-=2*i;
		if(n<=0){printf("Motu\n");break;} 
		i++;
	}	
	return 0;
}