class Solution {
public:
    int climbStairs(int n) {
        int curr = 0, prev1, prev2;

        prev2 = 1;
        prev1 = 2;

        for (int i = 3; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return (n == 1) ? 1 : (n == 2) ? 2 : curr; 
    }
};