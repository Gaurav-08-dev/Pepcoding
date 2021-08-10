vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
	vector<int> ans;

	if(mat.size()==0 or mat[0].size()==0)
	{
		return ans;
	}


	int sc=0,sr=0;
	bool dir=true;


	while(sr < mat.size() and sc<mat[0].size())
	{
		if(dir)
		{
			while(sr>0 and sc < mat[0].size()-1)
			{
				ans.push_back(mat[sr][sc]);
				sr--; sc++;
			}

			ans.push_back(mat[sr][sc]);

			if(sc==mat[0]-1)
			{
				sr++;
			}
			else
			{
				sc++;
			}
		}
		else
		{
			while(sr<mat.size()-1 and sc>0)
			{
				ans.push_back(mat[sr][sc]);
				sr++; sc--;
			}
			if(sr == mat.size()-1)
			{
				sc++;
			}
			else
			{
				sr++;
			}
		}
		dir=!dir;
	}

	return ans;
}