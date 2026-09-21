class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};

        vector<pair<string, string>> pair_strs; // ใช้เก็บทั้ง(เรียงแล้ว,คำเดิม)
        for(int i = 0; i < strs.size(); i++){
            string sort_word = strs[i]; // word คำที่ไม่ได้เรียง
            sort(sort_word.begin(), sort_word.end()); // sort ตัวอักษรด้านใน
            pair_strs.push_back({sort_word, strs[i]});
        }
        // sort pair จะดู first ก่อน นี่คือเหตุผล ทำไมเอา (เรียงแล้ว, คำเดิม)
        sort(pair_strs.begin(), pair_strs.end());

        vector<vector<string>> group;
        vector<string>check;

        check.push_back(pair_strs[0].second);//เอาคำแรกใส่ลงไป = คำแรกของกลุ่ม
        
        for(int i = 1 ; i < strs.size(); i++){
            // check กับ คำแรกว่าเป็นคำเดียวกันมั้ย
            if(pair_strs[i].first == pair_strs[i-1].first){
                check.push_back(pair_strs[i].second); // เอาคำเดิมใส่ลงไป 
            }else{
                group.push_back(check);
                check.clear();
                check.push_back(pair_strs[i].second);
            }
        }
        group.push_back(check); //ปิดท้ายด้วยการเอาคำในกลุ่มสุดท้ายใส่ลงไป
        return group;
    }
};
