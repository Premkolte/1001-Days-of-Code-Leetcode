typedef pair<int, int> pii;
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n= nums.size();
        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        for(int i = 0;i<n;i++){
            minheap.push(make_pair(nums[i],i));
        }

        while(k--){
            pii curr = minheap.top();
            minheap.pop();

            curr.first *= multiplier;
            nums[curr.second] *= multiplier;

            minheap.push(curr);

        }

        return nums;
    }
};