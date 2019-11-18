#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 
int main(){
	ll testCases;
	cin>>testCases;
	while(testCases--){
		double n;ll sum=0;
		cin>>n;
		ll a[(int)n]={0};
		for(int i=0;i<n;++i){
			cin>>a[i];sum+=a[i];
		}
		int i;
		double mean = sum/n;
		sort(a,a+(int)n);
		int start=0,end=(int)n;
		while(end>start){
			int mid=(start+end)/2;
			if(a[mid]>mean){
				end = mid-1;
			}else if(a[mid]<mean){
				start = mid+1;
			}else{
				cout<<mid+1<<endl;
			}
		}
	}
	return 0;
}