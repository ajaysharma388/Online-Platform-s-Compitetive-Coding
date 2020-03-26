#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class Game{
	int myNumber;
public:
	Game(const int number) {
		this->myNumber = number;
	}
	int guess(int n) {
		if(n == this->myNumber) return 0;
		else if(n < this->myNumber) return -1;
		return 1;
	}
	int guessNumber(int n) {
	    long l = 1,r = n;
	    while(l <= r) {
	        long m = (l+r)/2;
	        int res = guess(m);
	        if(res == 0) return m;
	        else if(res == 1) r = m-1;
	        else l = m+1;
	    }
	    return -1;
	}	
};



int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Game game(6);
	cout << game.guessNumber(10) << endl;
	return 0;
}