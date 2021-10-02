/* brute force prims */

/* TC= greater than O(n^2) */

vector<int> parent(n,-1);
vector<int> key(n,INT_MAX);
vector<bool> mtSet(n,false);

key[0]=0;


for(int count=0;count < n-1;count++)
{
	int min_key=INT_MAX,min_index;

	// find minimal key which is not a part of mtSet
	for(int i=0;i<n;i++)
	{
		if(mtSet[i]==false and key[i]<min_key)
		{
			min_key=key[i];
			min_index=i;
		}
	}


	mtSet[min_index]=true;
	for(auto it: adj[min_index])
	{
		int v=it.first;
		int weight=it.second;
		if(mtSet[v]==false and weight<key[v])
		{
			parent[v]=min_index,key[v]=weight;
		}

	}

	// output
	for(int i=0;i<n;i++){

		cout<<parent[i]<<" - "<<i<<" \n";
	}
}


/* optimized prims implementation -> use priority queue */
/* TC-> O(n + e + nlog(n)) => nlog(n) */

vector<int> parent(n,-1);
vector<int> key(n,INT_MAX);
vector<bool> mtSet(n,false);

priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

key[0]=0;

// pair - > key[i], min_Index
pq.push({0,0});

for(int i=0;i<N-1;i++)
{
	int u=pq.top().second;
	pq.top();

	mtSet[u]=true;

	for(auto it: adj[u])
	{
		int v=it.first;
		int weight=it.second;

		if(mtSet[v]==false)
		{
			parent[v]=u;
			pq.push({key[v], v});
			key[v]=weight;
		}
	}
}