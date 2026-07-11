class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> paper_count(n+1, 0);
        for(int i = 0; i<n; i++){

            if(citations[i] >= n) paper_count[n]++;
            else paper_count[citations[i]]++;
        }
        int h = n;
        int papers = 0;

        for(int i = n; i>=0; i--){
            papers += paper_count[i];
            if(papers >= h) break;
            h--;
            
        }
        return h;

    }

};