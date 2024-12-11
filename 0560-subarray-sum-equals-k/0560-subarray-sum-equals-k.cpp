class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
         unordered_map<int, int> prefixSumMap; 
        int sum = 0; 
        int count = 0; 

        prefixSumMap[0] = 1;

        for (int num : nums) {
            sum += num; 
     
            if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
                count += prefixSumMap[sum - k];
            }

            prefixSumMap[sum]++;
        }

        return count;
    }
};