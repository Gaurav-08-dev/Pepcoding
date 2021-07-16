// USING TWO STACK

  public static void levelOrderLinewiseZZ(Node node){
    // write your code here
    Stack<Node> q=new Stack<>();
    Stack<Node> s=new Stack<>();
     int level=1;
    q.push(node);
    while(q.size()>0)
    {
        while(q.size() >0)
        {
            Node rem=q.pop();
            System.out.print(rem.data + " ");   
            if(level%2==1)
            {
                for(int i=0;i<rem.children.size();i++)
                {
                    s.push(rem.children.get(i));
                }
            }
            else
            {
                for(int i=rem.children.size()-1;i>=0;i--)
                {
                    s.push(rem.children.get(i));
                }
            }
        }
        
        level++;
        System.out.println();
        Stack<Node> temp=q;
        q=s;
        s=temp;
}

// Using one queue and one stack

public static void levelOrderLinewiseZZ(Node node)
{
    Queue<Node> q=new ArrayDequeue<>();
    Stack<Node> s=new Stack<>();
    

    int level=1;
    q.push();
}

