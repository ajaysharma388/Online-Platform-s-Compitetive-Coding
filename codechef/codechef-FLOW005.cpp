#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int minNotes(int data,int notes[],int i,int n){
	if(data==0) return 0;
	if(i<=n)
		return (data/notes[i])+minNotes(data%notes[i],notes,i+1,n);
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int testcases,data,notes[]={100,50,10,5,2,1};
	cin>>testcases;
	while(testcases--){
		cin>>data;
		cout<<minNotes(data,notes,0,5)<<endl;
	}
	return 0;
}