class Solution {
 public:
  int numTilePossibilities(string tiles) {
    vector<int> count(26);
    for (const char t : tiles)
      ++count[t - 'A'];
    return dfs(count);
  }

 private:
  int dfs(vector<int>& count) {
    int possibleSequences = 0;
    for (int& c : count) {
      if (c == 0)
        continue;
      --c;
      possibleSequences += 1 + dfs(count);
      ++c;
    }
    return possibleSequences;
  }
};