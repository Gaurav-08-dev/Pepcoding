vector<string> generate(int N)
{
	// Your code here
	queue<string> q;
	vector<string> ans;
	q.push("1");
	for(int i=1;i<=N;i++)
	{
	    string s=q.front();
	    q.pop();
	    ans.push_back(s);
	    q.push(s + "0");
	    q.push(s + "1");
	}
	
return ans;	
}