
void GrayCode(vector<int> &result, int bitLength, int Index)
{

	if (Index < bitLength)
	{
		int highest_bit = 1 << Index;
		for (int j = result.size() - 1; j >= 0; --j)
		{
			result.push_back(highest_bit | result[j]);
		}
		GrayCode(result, bitLength, Index + 1);
	}
}

vector<int> ProduceGrayCode(int n)
{
	vector<int> result;
	result.reserve(1 << n);
	result.push_back(0);
	GrayCode(result, n, 0);
	return res