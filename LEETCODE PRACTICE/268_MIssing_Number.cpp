public int missingNumber(int[] nums) { //xor
    int res = nums.length;
    for(int i=0; i<nums.length; i++){
        res ^= i;
        res ^= nums[i];
    }
    return res;
}

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i=0; i<nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] != nums.size())
                    swap(nums[i], nums[nums[i]]);
                else {
                    missing = i;
                    break;
                }
            }
        }
        return missing;
    }
};