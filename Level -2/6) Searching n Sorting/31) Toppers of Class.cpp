/*struct node                 //Structure of the node
{                             
    int marks,index;
};
*/

bool comp(node a, node b){
    
    if(a.marks==b.marks) return a.index < b.index;
    
    return a.marks > b.marks;
}

void kTop(node a[],int n)
{
    // Your code goes here
    
    sort(a,a+n,comp);
}