class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res(words.size(), 0);
        int i = 0;

        for (auto& word : words) {
            int sum = 0;

            // Compute the total weight of the current word.
            for (auto& c : word)
                sum += weights[(c & 31) - 1];

            /*
             * We need: remainder = sum % 26.
             *
             * Instead of using division, we approximate sum / 26
             * with a fixed-point reciprocal:
             *
             *     2521 / 2^16 ≈ 1 / 26
             *
             * For the bounded values of 'sum' in this problem,
             * the expression below evaluates to the exact value of
             * floor(sum / 26).
             */
            int q = (sum * 2521) >> 16;

            // Reconstruct the remainder:
            // sum = 26 * q + remainder
            int r = sum - q * 26;

            // Reverse alphabet mapping:
            // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            res[i++] = 'z' - r;
        }

        return res;
    }
};