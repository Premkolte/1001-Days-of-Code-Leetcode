#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColors;  // Stores ball -> color mapping
        unordered_map<int, int> colorFreq;   // Stores color -> frequency
        vector<int> result; // Stores the number of distinct colors after each query

        for(auto& query : queries) {
            int ball = query[0], color = query[1];

            // If the ball already has a color, update frequency
            if(ballColors.count(ball)) {
                int oldColor = ballColors[ball];
                colorFreq[oldColor]--;

                if(colorFreq[oldColor] == 0) {
                    colorFreq.erase(oldColor);
                }
            }

            // Assign the new color
            ballColors[ball] = color;
            colorFreq[color]++;

            // Store the count of distinct colors
            result.push_back(colorFreq.size());
        }

        return result;
    }
};