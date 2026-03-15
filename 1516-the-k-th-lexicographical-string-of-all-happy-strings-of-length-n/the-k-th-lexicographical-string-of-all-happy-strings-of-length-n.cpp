#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> happy;

    string getHappyString(int n, int k) {
        string chars = "abc";
        generateHappyString("", n, chars);
        return k > happy.size() ? "" : happy[k - 1];
    }

    void generateHappyString(string path, int n, string &chars) {
        if (path.length() == n) {
            happy.push_back(path);
            return;
        }
        for (char c : chars) {
            if (path.empty() || path.back() != c) {
                generateHappyString(path + c, n, chars);
            }
        }
    }
};