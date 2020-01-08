class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int> > dp(d+1, vector<int>(target + 1, 0));
        const long long MOD = pow(10, 9) + 7;
        dp[0][0] = 1;    
        for(int sum = 1; sum <= target; sum++) {
            for(int dices = 1; dices <= d; dices++) {
                for(int faces = 1; faces <= f; faces++) {
                    int req_val = (sum - faces) >= 0 ? dp[dices - 1][sum - faces] : 0;
                    dp[dices][sum] = (dp[dices][sum] + req_val) % MOD;
                }
            }
        }
        return dp[d][target];
    }
};
