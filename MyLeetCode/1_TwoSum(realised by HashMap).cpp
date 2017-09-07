class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  		map<int ,int> HashMap;
  		vector<int> result;
  		for(int i = 0; i < nums.size(); ++i)
  			HashMap[nums[i]] = i;

  		for(int i=0; i<nums.size(); ++i)
  		{
  			const int gap = target - nums[i];
  			if(HashMap.find(gap)!=HashMap.end() && HashMap[gap] > i)
  			{
  				result.push_back(i);
  				result.push_back(HashMap[gap]);
  				break;
  			}
  		}

  		return result;
    }
};