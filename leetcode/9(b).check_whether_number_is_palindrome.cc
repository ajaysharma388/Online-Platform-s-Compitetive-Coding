class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 or (x%10 == 0 and x!=0)) return false;
        else if(x == 0) return true;
        int num = 0;
        while(x > num) {
            num = num*10 + (x%10);
            x/=10;
        }
        return num == x or x == num/10;
    }
};