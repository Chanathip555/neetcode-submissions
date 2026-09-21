class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int size = nums.size();
      unordered_map<int, int> frequentMap;

      //Conuting frequnt
      for(int i = 0; i<size;i++){
        frequentMap[nums[i]]++;
      }

      // find max frequentMap by max_heap
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    // for(int i=0; i<frequentMap.size(); i++){
    //     minHeap.push({entry.second, entry.first});
    //     if (minHeap.size() > k) {
    //         minHeap.pop(); // เอาตัวที่มีความถี้น้อยที่สุดออก
    //     }
    // }
    for (auto& entry : frequentMap) {
        minHeap.push({entry.second, entry.first});
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    // ดึงผลลัพธ์ออกจาก Heap
    vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
    reverse(result.begin(), result.end());
    return result;

    }
};
