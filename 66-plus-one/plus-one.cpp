class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int n=digits.size();
        bool carry=1;// plus 1
        for(int i=n-1; i>=0; i--){
            int& d=digits[i];// by ref
            d+=carry;
            carry=d==10;
            if (!carry) return digits;// early stop
            d-=10;// in fact 0
        }
        // this takes O(n) time
        digits.insert(digits.begin(), 1);
        return digits;
    }
};