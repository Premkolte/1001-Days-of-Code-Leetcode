class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>v;
       unordered_map<int, int> frequencyMap;
       for (int num : nums) {
        frequencyMap[num]++;
    } 
     priority_queue< pair<int,int>>max_heap;
     for (const auto& pair : frequencyMap) {
            max_heap.push({ pair.second,pair.first});
        }
        for(int i=0;i<k;i++){
            v.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return v; 
    }
};