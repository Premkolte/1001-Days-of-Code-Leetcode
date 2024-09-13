class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c = 0;
        int n = allowed.size();

        for (int i = 0; i < words.size(); i++) {
            int j = 0;
            while (j < words[i].size()) {
                int k = 0;
                while (k < n) {
                    if (words[i][j] == allowed[k]) {
                        break;
                    }
                    k++;
                }
                if (k == n) {
                    break;
                }
                j++;
                if (j == words[i].size()) {
                    c += 1;
                }
            }
        }
        return c;
    }
};