class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums1) {
        int n = nums1.size();

        //converting nums to long long to avoid overflow.
        vector<ll> nums(n,0);
        for(int i=0;i<n;i++){
            nums[i] = nums1[i];
        }

        //we created next and prev arrays to make nums as doubly linked list
        vector<int> nextIndex(n),prevIndex(n);

        for(int i=0;i<n;i++){
            nextIndex[i] = i+1;
        }

        for(int i=0;i<n;i++){
            prevIndex[i] = i-1;
        }

        //ordered set that stores {sum,i} in increasing order
        //set.begin() -> smallest sum at index i
        set<pair<ll,int>> pairSumSet;

        //stores total pairs which are in out of order.
        //if badPairCount is zero then already in asc order
        int badPairCount = 0;

        for(int i=0;i<n-1;i++){
            //count pairs
            if(nums[i] > nums[i+1])badPairCount++;

            //store {sum,i} 
            pairSumSet.insert({nums[i]+nums[i+1], i});
        }

        //stores total mergeOperations happend
        int mergeOperations = 0;

        while(badPairCount > 0){

            //pairSumSet.begin() -> {sum,i} smallest sum and index of sum
            auto it = pairSumSet.begin();
            int currIdx = it->second;
            int nextIdx = nextIndex[currIdx];
            int prevIdx = prevIndex[currIdx];

            //curr->next->next
            int nextNextIdx = nextIndex[nextIdx];

            pairSumSet.erase(it);

            if(nums[currIdx] > nums[nextIdx])badPairCount--;

            if(prevIdx >= 0){
                if(nums[prevIdx] > nums[currIdx]) badPairCount--;
                if(nums[prevIdx] > nums[currIdx] + nums[nextIdx]) badPairCount++;
                pairSumSet.erase({nums[prevIdx] + nums[currIdx], prevIdx});
            }

            if(nextNextIdx < n){
                if(nums[nextIdx] > nums[nextNextIdx]) badPairCount--;
                if(nums[currIdx] + nums[nextIdx] > nums[nextNextIdx]) badPairCount++;
                pairSumSet.erase({nums[nextIdx] + nums[nextNextIdx], nextIdx});
            }

            //updation of set after merge operation happens
            
            //before merge operation 
            // prev <=> curr <=> next <=> nextNext

            //after merge operation
            // prev <=> curr+next <=> nextNext

            nums[currIdx] = nums[currIdx] + nums[nextIdx];

            nextIndex[currIdx] = nextNextIdx;
            if(nextNextIdx < n) prevIndex[nextNextIdx] = currIdx;

            if(prevIdx >= 0){
                pairSumSet.insert({nums[prevIdx] + nums[currIdx], prevIdx});
            }

            if(nextNextIdx < n){
                pairSumSet.insert({nums[currIdx] + nums[nextNextIdx], currIdx});
            }

            mergeOperations++;
        }
        return mergeOperations;
    }
};