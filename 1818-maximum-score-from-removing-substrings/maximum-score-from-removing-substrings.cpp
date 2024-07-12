//resolve 
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != 'a' && s[i] != 'b') continue;
            int j = i;
            string t = "";
            while(j < n && (s[j] == 'a' || s[j] == 'b')) {
                t += s[j];
                j++;
            }
            ans += max(processAB(t, x, y), processBA(t, x, y));
            i = j - 1;
        }
        return ans;
    }
    
    int processAB(string& s, int x, int y) { //process AB first
        vector<char> stk;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(stk.size() > 0 && stk.back() == 'a' && s[i] == 'b') {
                stk.pop_back();
                ans += x;
            } else {
                stk.push_back(s[i]);
            }
        }
        int a = 0, b = 0;
        for(int i = 0; i < stk.size(); i++) {
            if(stk[i] == 'a') a++;
            else b++;
        }
        return min(a, b) * y + ans;
    }
    
    int processBA(string& s, int x, int y) { //process AB first
        vector<char> stk;
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            if(stk.size() > 0 && stk.back() == 'b' && s[i] == 'a') {
                stk.pop_back();
                ans += y;
            } else {
                stk.push_back(s[i]);
            }
        }
        int a = 0, b = 0;
        for(int i = 0; i < stk.size(); i++) {
            if(stk[i] == 'a') a++;
            else b++;
        }
        return min(a, b) * x + ans;
    }
};