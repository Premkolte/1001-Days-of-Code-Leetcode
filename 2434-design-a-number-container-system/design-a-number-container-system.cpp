class NumberContainers {
public:
    unordered_map<long, priority_queue<long, vector<long>, greater<long>>> mp;  // number -> min-heap of indices
    unordered_map<long, long> ind; // index -> number

    NumberContainers() {}
    
    void change(int index, int number) {
        ind[index] = number;  // Update index-to-number mapping
        mp[number].push(index); // Push index to min-heap
    }
    
    int find(int number) {
        while (!mp[number].empty()) {
            int minIndex = mp[number].top();  // Get smallest index
            if (ind[minIndex] == number) {
                return minIndex; // Return if still valid
            }
            mp[number].pop(); // Remove outdated entry
        }
        return -1; // No valid index found
    }
};