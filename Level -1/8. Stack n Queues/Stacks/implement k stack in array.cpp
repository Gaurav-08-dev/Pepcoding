#include<bits/stdc++.h>
using namespace std;



class stack1{
	 
	 int* arr; // array of size n to store actual content of stacks 
	 int* top; // to store indexes of top elememt of -> size k
	 int* next; // array of size n to store next entry in all stacks and free list

	 int n,k;
	 int free; // to store beginning of free list

	public:
		stack1(int k,int n);

		bool isfull{ return (free==-1); } 


};
int main()
{

}