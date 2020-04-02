class Solution {
public:
    bool isHappy(int n) {
        vector<int> check;
        while(1)
        {
            int sum=0;
            while(n>0)
            {
                int temp=n%10;
                sum+=(temp*temp);
                n=n/10;
            }
            if(sum==1)
                return 1;
            auto it=find(check.begin(),check.end(),sum);
            if(it!=check.end())
                return 0;
            check.push_back(sum);
            n=sum;            
            
        }
    }
};