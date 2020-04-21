/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    bool searchInCol(BinaryMatrix &binaryMatrix,int c,int n) {
        for(int i = 0; i < n; ++i) 
            if(binaryMatrix.get(i,c) == 1) return true;
        return false;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	    cout.tie(NULL);
        vector<int> dim = binaryMatrix.dimensions();
        int r = dim[0];
        int c = dim[1];
        if(r == 0 or c == 0) return -1;
        int s = 0;
        int e = c-1;
        int pos = -1;
        while(s<=e) {
            int m = (s+e)/2;
            if(searchInCol(binaryMatrix,m,r)) {
                e = m-1;
                pos = m;
            } else {
                s = m+1;
            }
        }
        return pos;
    }
};