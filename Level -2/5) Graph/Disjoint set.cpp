// parent array

// rank array 


// smaller rank must be connected to higher rank -> because it improves time complexity by preventing skew tree formation
// whenever rank is different -> dont change the rank
// if rank is same -> increase rank by 1 of parent



int parent[100000];
int rank[100000];


void markset()
{
	for(int i=1;i<=n;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}

int findPar(int node)
{
	if(node==parent[node])
	{
		return node;
	}

	return parent[node]=find(parent[node]); // path compressed
}

void union(int u, int v)
{
	u=findPar(u);
	v=findPar(v);

	if(rank[u] < rank[v])
	{
		parent[u]=v;
	}
	else if(rank[u] > rank[v])
	{
		parent[v]=u;
	}
	else
	{
		parent[v] = u;
		rank[u]++;
	}
}



int main()
{
	markset();

	int n;
	cin>>n;

	while(m--)
	{
		int u,v;
		union(u, v);
	}

	// if 2 and 3 belong to the same component or not

	if(findPar(2)!=findPar(3)){
		cout<<"different  components"
	}
	else{
		cout<<"same components";
	}
}