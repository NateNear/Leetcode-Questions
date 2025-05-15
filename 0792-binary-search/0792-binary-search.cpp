class Solution {
public:

    int recBS(vector<int>& nums, int s, int e, int target) {
        if (s > e)
            return -1;

        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            return recBS(nums, mid + 1, e, target);
        else
            return recBS(nums, s, mid - 1, target);
    }

    int search(vector<int>& nums, int target) {
        return recBS(nums, 0, nums.size() - 1, target);
    }
};
