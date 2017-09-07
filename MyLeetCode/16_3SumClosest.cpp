class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	  sort(nums.begin(), nums.end());
    	  int result;
    	  int distance = INT_MAX;
    	  int n = nums.size();

    	  for(int i=0; i<n-2; ++i)
    	  {
    	  	//this judegement can't not use "if(i>0 && nums[i-1]==nums[i]) continue;"
    	  	//because it will be get wrong answer, when nums=[0,1,1,1];
    	  	if(i>0 && nums[i-1]==nums[i]) continue;

    	  	int high = n-1;
    	  	int low = i+1;
    	  	while(low<high)
    	  	{
    	  		int sum = nums[i]+nums[low]+nums[high];
    	  		if(sum==target)
    	  			return target;
    	  		else 
    	  		{   if(abs(sum-target) < distance)
    	  		    {
    	  		    	distance = abs(sum-target);
    	  		    	result = sum;
    	  	    	}

    	  	    	if(sum > target)
    	  	    	{
    	  	    		while(high>low && nums[high-1]==nums[high]) --high;
    	  	    		--high;
    	  	    	}
    	  	    	else if(sum < target)
    	  	    	{
    	  	    		while(high>low && nums[low]==nums[low+1]) ++low;
    	  	    		++low;
    	  	    	}
    	  		}
    	  	}
    	  }

    	  return result;
    }
};