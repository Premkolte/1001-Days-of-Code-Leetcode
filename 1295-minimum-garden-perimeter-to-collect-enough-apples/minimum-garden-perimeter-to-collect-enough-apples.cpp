class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
            long long n = INT_MAX;
            long long cnt = 0;
            long long sum=0;


            while(sum<neededApples){
                cnt++;
                sum+=(12*cnt*cnt);
            }



            

            return 8*cnt;


    }
};