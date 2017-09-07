class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size();
	int m = nums2.size();
	int total = m + n;
	int k = total / 2;
	int pA = 0;
	int pB = 0;
	int index = 0;

	if (k>total || (nums1.empty() && nums2.empty()))
		return -1;
	else if (n == 1 && m<1)
		return (double)nums1.front();
	else if (n<1 && m == 1)
		return (double)nums2.front();

	if (!(total & 0x01))
	{
		int temp;
		while (index<total)
		{
			if (pA<n && pB<m)
			{
				if (nums1[pA] <= nums2[pB])
				{
					if (index == (k - 1))
					{
						temp = nums1[pA];
					}
					else if (index == k)
						return (double)(nums1[pA] + temp) / 2;

					++pA;
					index++;
				}
				else
				{
					if (index == (k - 1))
					{
						temp = nums2[pB];
					}
					else if (index == k)
						return (double)(nums2[pB] + temp) / 2;

					++pB;
					index++;
				}
			}
			else if (pA < n)
			{
					if (index == (k - 1))
					{
						temp = nums1[pA];
					}
					else if (index == k)
						return (double)(nums1[pA] + temp) / 2;
				++pA;
				index++;
			}
			else if (pB<m)
			{
					if (index == (k - 1))
					{
						temp = nums2[pB];
					}
					else if (index == k)
						return (double)(nums2[pB] + temp) / 2;
				++pB;
				index++;
			}
		}
	}
	else
	{
		while (index<total)
		{
			if (pA<n && pB<m)
			{
				if (nums1[pA] <= nums2[pB])
				{
					if (index == k)
						return (double)nums1[pA];

					++pA;
					index++;
				}
				else
				{
					if (index == k)
						return (double)nums2[pB];

					++pB;
					index++;
				}
			}
			else if (pA < n)
			{
				if (index == k)
					return (double)nums1[pA];
				++pA;
				index++;
			}
			else if (pB<m)
			{
				if (index == k)
					return (double)nums2[pB];
				++pB;
				index++;
			}
		}
	}


}


};

