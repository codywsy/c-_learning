class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		int rows = matrix.size();
        ++rows;
		int columns = matrix[0].size();
        ++columns;
		vector<int> result;

		int start = 0;
		while(columns > start*2 && rows > start*2)
		{
			PrintMatrixInCircle(matrix, rows, columns, start, result);
			++start;
		}

		return result; 
    }

    void PrintMatrixInCircle(vector<vector<int>> matrix, int rows, int columns, int start, vector<int> result)
    {
    	int endX = columns - 1 - start;
    	int endY = rows - 1 - start;

    	//first step
    	for(int i=start; i <= endX; ++i)
    	{
    		result.push_back(matrix[start][i]);
    	}

    	//second step
    	if(start < endY)
    	{
    		for(int i = start + 1; i <= endY; ++i)
    		{
    			result.push_back(matrix[i][endX]);
    		}
    	}

    	//third step
    	if(start < endX && start < endY)
    	{
    		for(int i = endX - 1; i >= start; --i)
    		{
    			result.push_back(matrix[endY][i]);
    		}
    	}

    	//fourth step
    	if(start < endX && start < endY - 1)
    	{
    		for(int i = endY - 1; i > start; --i)
    		{
    			result.push_back(matrix[i][start]);
    		}
    	}
    }

};