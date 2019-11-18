#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c,a;
		cin>>r>>c>>a;
		int grid[r]={};
		for(int i=0;i<r;++i){
			char ch;
			for(int j=0;j<c;++j){
				cin>>ch;
				if('*'==ch)grid[i]++;
			}
		}
		sort(grid,grid+r);
		int i=0;
		while(a>0 && i<r && c-grid[i]>grid[i]){
			grid[i]=c-grid[i];
			--a;
			++i;
		}
		while(a!=0){
			auto it=min_element(grid,grid+r);
			*it=c-*it;
			a--;
		}
		cout<<accumulate(grid,grid+r,0)<<"\n";
	}
    return 0;
}