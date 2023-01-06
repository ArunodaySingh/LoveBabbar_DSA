/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
{
        vector<int>p;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1 ;)
        {
            if(nums[i]==nums[i+1])
            {
                p.push_back(nums[i]);
                i+=2;
            }
            else
            {
                i++;
            } 
        }
        return p;
}
};
// @lc code=end

