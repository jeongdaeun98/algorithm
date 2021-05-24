#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            numMap.insert({nums[i], i});
        }
        for(int i = 0; i < nums.size(); i++){
            auto num = numMap.find(target - nums[i]);
            if(num != numMap.end() && num->second != i){
                answer.push_back(i);
                answer.push_back(numMap.find(target - nums[i])->second);
                break;
            }
        }
        return answer;
    }
};