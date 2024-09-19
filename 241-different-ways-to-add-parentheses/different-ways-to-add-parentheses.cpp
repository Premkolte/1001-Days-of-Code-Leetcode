class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>ans;

        for(int i = 0 ; i < expression.size() ; i++) {
            char ch = expression[i];

            if(ch == '+' || ch == '-' || ch == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);
                
                vector<int> L_res = diffWaysToCompute(left);
                vector<int> R_res = diffWaysToCompute(right);

                for(int  l : L_res) {
                    for(int r : R_res) {
                        if(ch == '+') {
                            ans.push_back(l + r);
                        }
                        else if (ch == '-') {
                            ans.push_back(l - r);
                        } 
                        else if (ch == '*') {
                            ans.push_back(l * r);
                        }

                    }
                }
            }
        }

        if(ans.empty()) {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};