#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// this solution uses recursion but it due to it's time complexity 
// it will not be preffered.

int find(int n,int a[][100],int r,int c){
	if(r==n-1) return a[r][c];
	return a[r][c]+max(find(n,a,r+1,c),find(n,a,r+1,c+1));
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	int t,n,a[100]={},s[100][100],res=0;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> a[0];
		s[0][0]=a[0];
		res = s[0][0];
		for(int i=1;i<n;++i){
			for(int j=0;j<=i;++j){
				cin >> a[j];
				if(j==0)
					s[i][j]=a[j]+s[i-1][j];
				else if(i==j)
					s[i][j]=s[i-1][j-1]+a[j];
				else
					s[i][j]=max(s[i-1][j],s[i-1][j-1])+a[j];
				res=max(res,s[i][j]);
			}
		}
		cout << res << endl;	
	}
	return 0;
}


// solution you should think of.

#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int A[100][100];
	int t, i, n, j, res;
	cin >> t;
	while(t--) {
		cin >> n;
		for (i = 0; i < n; i++) {
			for (j = 0; j <= i; j++) {
				cin >> A[i][j];
			}
		}
		for (i = n - 2; i >= 0; i--) {
            for (j = i; j >= 0; j--) {
                A[i][j] += max(A[i + 1][j],A[i + 1][j + 1]);
            }
		}
		cout << A[0][0] << endl;
	}
	return 0;
}
