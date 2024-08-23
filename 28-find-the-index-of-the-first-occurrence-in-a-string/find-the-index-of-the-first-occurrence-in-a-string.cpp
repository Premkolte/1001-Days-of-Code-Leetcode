class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=needle.size();
        int len_hay=haystack.size();
        for(int i=0 ; i<=len_hay-len ; i++)
        {
            if(haystack.substr(i,len)==needle)
            return i;
        }
        return -1;
    }
};