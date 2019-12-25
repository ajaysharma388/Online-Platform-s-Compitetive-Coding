#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void matrixRotation(int**a,int m,int n){
    int x=0,y=0;
    while(x<n/2 && y<n/2){
        int i=x,j=y;
        int t=a[i][j];
        for(;j<n-1-y;++j){
            a[i][j] = a[i][j+1];  // first Line
        }
        for(;i<m-1-x;++i){
            a[i][j] = a[i+1][j]; // last col.
        }
        for(;j>y;--j){
            a[i][j] = a[i][j-1];
        }
        for(i=m-1-x;i>x;--i){
            a[i][j] = a[i-1][j];
        }
        x++;y++;
        a[x][j]=t;
    }
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n,r;
	cin >> m >> n >> r;
	int **arr = new int*[m];
	for(int i=0;i<m;++i){
		arr[i] = new int[n];
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < r; ++i){
		matrixRotation(arr,m,n);
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout << arr[i][j] <<" ";
		}
		cout<<endl;
	}
	return 0;
}

// Sample Input :

// 4 4 2
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// 5 4 7
// 1 2 3 4
// 7 8 9 10
// 13 14 15 16
// 19 20 21 22
// 25 26 27 28


// Sample Output :

// 3  4  8 12
// 2 11 10 16
// 1  7  6 15
// 5  9 13 14

// 28 27 26 25
// 22 9 15 19
// 16 8 21 13
// 10 14 20 7
// 4 3 2 1