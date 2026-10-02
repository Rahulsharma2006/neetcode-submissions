class Solution {
public:
  int climbStairs(int n) {
         if (n <= 2) return max(1, n);
        int prev = 2;
        int prev_prev = 1;
        int ans =0;
        for(int i =3;i<=n;i++){
         ans = prev+prev_prev;
         prev_prev = prev;
         prev = ans;
        }
        return ans;
    }
};