class Solution {
public:
    string clearDigits(string s) {
        int index = 0;
        
        while (index < s.size()) {
            if (isdigit(s[index])) {
                s.erase(index, 1);
                
                if (index > 0) {
                    s.erase(index - 1, 1);
                    index--;
                }
            } else {
                index++;
            }
        }
        
        return s;
    }
};