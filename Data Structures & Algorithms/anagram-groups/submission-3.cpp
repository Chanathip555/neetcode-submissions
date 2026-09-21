class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> table; // Hash Table
        // (เรียงแล้ว, คำเเดิม)
        for(int i = 0; i < strs.size(); i++){
            string sort_word = strs[i]; //ดึงคำ 1 คำมาเพื่อจะเรียงตัวอักษร
            sort(sort_word.begin(), sort_word.end());
            table[sort_word].push_back(strs[i]);
            // key = sort, value = original_word
        }
        
        vector<vector<string>> result;
        for(auto& pair : table){
            result.push_back(pair.second);
        }
        return result;
    }
};
