class Solution {
public:
    int triSum(int n) { return n * (n + 1) >> 1; }

    int totalMoney(int days) {
        const auto [nWeeks, rDays] = div(days, 7);

        return
            triSum(days)                //+ add up all days
            - 42 * triSum(nWeeks - 1)   //- add up the loses of full weeks
            - 6 * nWeeks * rDays;       //- add up the loses of remaining days
    }
};
