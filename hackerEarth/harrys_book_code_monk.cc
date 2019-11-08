#include <iostream>

using namespace std;

int main(){
	char isbn[20];
	cin>>isbn;
	int d=0,sum=0;
	for(int i=0;isbn[i]!='\0';++i){
		d++;
		sum+=((i+1)*(isbn[i]-48));
	}
	if(d!=10) cout<<"Illegal ISBN\n";
	else{
		if(sum%11==0) cout<<"Legal ISBN\n";
		else cout<<"Illegal ISBN\n";
	}
	return 0;
}