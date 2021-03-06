class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        if(nums.size()<3) 
        	return result;

        sort(nums.begin(), nums.end());
        const int target = 0;

        for(int i=0, last = nums.size(); i<last-2; ++i)
        {
        	//caution
            //this judegement can't not use "if(i>0 && nums[i-1]==nums[i]) continue;"
            //because it will be get wrong answer, when nums=[0,1,1,1]; //
        	if( i>0 && nums[i-1]==nums[i] ) continue;
        	int low = i+1;
        	int high = last - 1;
        	while(low<high)
        	{
        		if(nums[i]+nums[low]+nums[high]==target)
        		{
        			vector<int> v;
        			v.push_back(nums[i]);
        			v.push_back(nums[low]);
        			v.push_back(nums[high]);
        			result.push_back(v);

        			while(low<high && nums[low]==nums[low+1]) ++low;
        			while(high>low && nums[high]==nums[high-1]) --high;
        			++low;
        			--high;	
        		}
        		else if(nums[i]+nums[low]+nums[high]>target)
        		{
        			//the order of the following two sentence is important
        			while(high>low && nums[high-1]==nums[high]) --high;
        			--high;
        			
        		}
        		else if(nums[i]+nums[low]+nums[high]<target)
        		{
        			while(high>low && nums[low]==nums[low+1]) ++low;
        			++low;
        			
        		}
        	}
        }

        return result;
    }
};