#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

	// if(entry.find(x)!=entry.end() and entry[x].find(y)!=entry.end())

int queensAttack(int n, int k, int r, int c, vector<vector<int>> obs) {
	map<int,set<int>> entry;   
    for(int i=0;i<k;++i){
    	if(entry.find(obs[i][0]-1)!=entry.end()){
	    	entry[obs[i][0]-1].insert(obs[i][1]-1);
    	}else{
    		set<int> s;
    		s.insert(obs[i][1]-1);
    		entry[obs[i][0]-1] = s;
    	} 
    }
	int count=0;
    int x=c;
    while(x<n){
    	if(entry.find(r-1)!=entry.end() and entry[r-1].find(x)!=entry[r-1].end()) break;
        // if(board[r-1][x]=='X') break;
        count++;// +ve x direction.
        x++;
    }
    x=c-2;
    while(x>-1){
    	if(entry.find(r-1)!=entry.end() and entry[r-1].find(x)!=entry[r-1].end()) break;
        // if(board[r-1][x]=='X') break;
        count++;// -ve x direction.
        x--;
    }
    x=r;
    while(x<n){
    	if(entry.find(x)!=entry.end() and entry[x].find(c-1)!=entry[x].end()) break;
        // if(board[x][c-1]=='X') break;
        count++;// -ve y direction.
        x++;
    }
    x=r-2;
    while(x>-1){
    	if(entry.find(x)!=entry.end() and entry[x].find(c-1)!=entry[x].end()) break;
        // if(board[x][c-1]=='X') break;
        count++;// +ve y direction.
        x--;
    }
    int y=c;
    x=r;
    while(x<n && x>-1 && y<n && y>-1){
    	if(entry.find(x)!=entry.end() and entry[x].find(y)!=entry[x].end()) break;
        // if(board[x][y]=='X') break;
        count++;
        x++;y++;
    }
    y=c-2;
    x=r-2;
    while(x<n && x>-1 && y<n && y>-1){
    	if(entry.find(x)!=entry.end() and entry[x].find(y)!=entry[x].end()) break;
        // if(board[x][y]=='X') break;
        count++;
        x--;y--;
    }
    y=c-2;
    x=r;
    while(x<n && x>-1 && y<n && y>-1){
    	if(entry.find(x)!=entry.end() and entry[x].find(y)!=entry[x].end()) break;
        // if(board[x][y]=='X') break;
        count++;
        x++;y--;
    }
    y=c;
    x=r-2;
    while(x<n && x>-1 && y<n && y>-1){
    	if(entry.find(x)!=entry.end() and entry[x].find(y)!=entry[x].end()) break;
        // if(board[x][y]=='X') break;
        count++;
        x--;y++;
    }
    return count;
}


int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,rq,cq;
	cin >> n >> k >> rq >> cq;
	vector<vector<int>> obs(k);
	for(int i=0;i<k;++i){
		int r,c;
		cin>>r>>c;
		obs[i].push_back(r);
		obs[i].push_back(c);
	}
	cout<<queensAttack(n,k,rq,cq,obs)<<endl;
	return 0;
}