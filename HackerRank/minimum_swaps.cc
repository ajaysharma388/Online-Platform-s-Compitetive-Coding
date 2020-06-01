/*==========================
Author : Ajay Sharma
date : 01.06.2020
============================*/
#include <bits/stdc++.h>
using namespace std;

// Some useful macros that are helpful to reduce code size.
#define vi vector<int>
#define int long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ld long double
#define endl "\n"

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
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

int minimumSwaps(vi &arr) {
    int no_swaps = 0;
    // this set consist only those elements which are incorrectly placed.
    // and here, is the details for that pair.
    // first -> store the element value.
    // second -> stores the element index.
    set<pair<int,int>> wrglyPlaced;
    // we will maintain the lookup table as this is 
    // requirement of our algorithm.
    unordered_map<int,int> lookUp;
    // doing entries.
    for(int i = 0; i < arr.size(); ++i){
        lookUp[arr[i]] = i;
        if(i+1 != arr[i]) wrglyPlaced.insert({arr[i],i});
    }
    // we will try to swap until we have no element which is wrongly placed.
    while(!wrglyPlaced.empty()){
        // 1. find the first Pair from set using begin() as it return iterator to first
        // element in the set.
        auto it1 = *(wrglyPlaced.begin());
        // 2. we are trying to find the appropriate location for the 
        // element so that we can swap it.
        auto it2 = *(wrglyPlaced.find(mp(it1.S+1,lookUp[it1.S+1])));
        // here we are swapping the elements.
        swap(arr[it1.S],arr[it2.S]);
        // now we either have placed both elements into the right place.
        // or one of them is placed to the right spot.
        no_swaps++;
        // we are erasing the pair as we have done the swapping.
        wrglyPlaced.erase(it1);wrglyPlaced.erase(it2);
        // now finally it's time to check whether we have placed both the
        // elements into the right place or only one of them is placed ?.
        if(arr[it2.S] != it2.S+1) wrglyPlaced.insert({arr[it2.S],it2.S});
    }
    return no_swaps;
}

int32_t main() {
    fastio(true);
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        std::vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];
        cout << minimumSwaps(arr) << " : ";
        for(auto e : arr) cout << e << " ";
        cout << endl;
    }
    return 0;
}

// Sample Input :

// 3
// 7
// 1 3 5 2 4 6 7
// 4
// 4 3 1 2
// 5
// 2 3 4 1 5

// Sample Output :

// 3 : 1 2 3 4 5 6 7 
// 3 : 1 2 3 4 
// 3 : 1 2 3 4 5 