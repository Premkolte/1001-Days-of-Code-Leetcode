class Solution {
public:
    bool isPalindrome(int x) {
        double y = x;
        double newt = 0;
        while(x>0){
            double u=0;
            u=x%10;
            // int new = 0;
            newt = (newt * 10) +u;

            x=x/10;

        }

        if(y == newt){ 
            return 1;
        }

        return 0;
        
    }
};