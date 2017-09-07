class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.size() <= 0 || num2.size() <= 0)
			return "";
		string result("0");
		int shift = 0;
	
		for (int i = num2.size() - 1; i >= 0; --i)
		{
			if (num2[i] != '0')
			{
				string n = multiplyOneDigit(num1, num2[i]);
				for (int j = 0; j<shift; ++j)
					n.insert(n.end(), '0');
				result = strPlus(result, n);
			}
			++shift;
		}
	
		if (result[0] == '0') return "0";
		return result;
	}

	string multiplyOneDigit(string &num, char ch)
	{
		int n = ch - '0';
		int carry = 0;
		string result;
		for (int i = num.size() - 1; i >= 0; --i)
		{
			int x = (num[i] - '0') * n + carry;
			result.insert(result.begin(), x % 10 + '0');
			carry = x / 10;
		}
	
		if (carry > 0)
			result.insert(result.begin(), carry + '0');
	
		return result;
	}
	
	string strPlus(string &num1, string &num2)
	{
		string result;
		int n = num1.size();
		int m = num2.size();
		int carry=0;
		for (int i = n - 1, j = m - 1; i >= 0 || j >= 0; --i, --j)
		{
			int x = i >= 0 ? num1[i] - '0' : 0;
			int y = j >= 0 ? num2[j] - '0' : 0;
			int sum = x + y + carry;
			result.insert(result.begin(), sum % 10 + '0');
			carry = sum / 10;
		}
	
		if (carry>0)
			result.insert(result.begin(), carry + '0');
	
		return result;
	}

};