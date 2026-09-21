class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int>ans;
        for(int i = 0;i+1 < size; i++){
            for(int j = 1; j < size;j++){
                // frist slove i use j < size - i; for protect overflow
                // in vector example size = 10 but j use 11.
                if(i != j && nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                    // return {i,j}; is modern c++ and clean.
                }
            }
        }
        return ans;
        // return {};
    }
};
