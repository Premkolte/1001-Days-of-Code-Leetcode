class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        int n = height.size();
        int i = 0, j = n-1;
        int maxArea = 0;
        while(i < j){
            int area = min(height[i], height[j]) * (j - i);
            maxArea = max(area, maxArea);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};