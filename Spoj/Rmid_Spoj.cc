#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define endl "\n"
#define pqmin priority_queue<int,vector<int>,greater<int>>
#define pqmax priority_queue<int>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	fastio;
	pqmax left;
	pqmin right;
	int data;
    int r = 0;
    int l = 0;
	while(scanf("%d",&data)!=EOF){
		if(data==-1){
			if(r>l){
				cout<<right.top()<<endl;
				right.pop();
				r--;
			}else{
				cout<<left.top()<<endl;
				left.pop();
				l--;
			}
		}
		else{
	        if(left.empty() && right.empty()){
	            left.push(data);
	            l++;
            }else if(left.top()<=data){
				right.push(data);
				r++;
			}else{
				left.push(data);
				l++;
			}
			if(abs(l-r)>1){
				if(l<r){
					int t = right.top();
					right.pop();
					r--;
					l++;
					left.push(t);
				}else{
					int t = left.top();
					left.pop();
					l--;
					r++;
					right.push(t);
				}
			}
		}
	}
	return 0;
}