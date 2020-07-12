#include<bits/stdc++.h>
using namespace std;

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
        #endif
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

int merge(int* arr,int s,int e) {
    int count = 0;
    int m = (s+e)/2;
    int i = s, j = m+1;
    int k = 0;
    int temp[e-s+1];
    while(i <= m and j <= e) {
        if(arr[i] > arr[j]) {
            count += m + 1 - i;
            temp[k++] = arr[j++];
        }
        else temp[k++] = arr[i++];
    }
    while(i <= m) temp[k++] = arr[i++];
    while(j <= e) temp[k++] = arr[j++];
    for(i = 0; i <= e-s; ++i) arr[s+i] = temp[i];
    return count;
}

void mergesort(int *arr,int s,int e,int &count) {
    if(s >= e) return;
    // make recursive call.
    int m = (s+e)/2;
    mergesort(arr,s,m,count);
    mergesort(arr,m+1,e,count);
    // we will merge the array.
    count += merge(arr,s,e);
    return;
}


long countInversions(int* arr,int n) {
    int count = 0;
    int s = 0, e = n-1;
    mergesort(arr,s,e,count);
    return count;
}

void solve() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << countInversions(arr,n) << endl;
}

int main() {
    fastio(true);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}