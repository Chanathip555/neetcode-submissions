class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int temp;
        bool result = false;
        sort(nums.begin(), nums.end());

        for(int i = 0;i+1 <nums.size();i++){
            temp = nums[i];
            if(temp == nums[i+1]){
                result = true;
                break;
            }
        }
        return result; 
    }
};