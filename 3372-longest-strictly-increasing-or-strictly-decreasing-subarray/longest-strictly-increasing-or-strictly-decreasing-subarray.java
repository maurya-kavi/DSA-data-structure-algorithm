import java.util.*;

class Solution {
    public ArrayList<Integer> inc, dec;

    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;

        inc = new ArrayList<>(Collections.nCopies(n, 1));
        dec = new ArrayList<>(Collections.nCopies(n, 1));

        int ans = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                inc.set(i, inc.get(i - 1) + 1);

            ans = Math.max(ans, inc.get(i));

            if (nums[i] < nums[i - 1])
                dec.set(i, dec.get(i - 1) + 1);

            ans = Math.max(ans, dec.get(i));
        }

        return ans;
    }
}