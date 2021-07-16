    
    public static void pre(node)
    {
        Stack<Pair> st=new Stack<>();
        st.push(new Pair(node,0));

        ArrayList<Integer> pre=new ArrayList<>();
        ArrayList<Integer> post=new ArrayList<>();
        ArrayList<Integer> in=new ArrayList<>();

        while(st.size()>0)
        {
            Pair p=st.peek();
            if(p.state==0)
            {
                pre.add(p.node.data);
                p.state++;
                st.push(new Pair(p.node.left,0);
            }
            
            else if(p.state==1)
            {
                // inorder
                in.add(p.node.data);
                if(p.node.right)
                {
                    st.push(new Pair(p.node.right,0);
                }
                p.state++;
            }

            else
            {
                post.add(p.node.data);
                st.pop();
            }
        }
    }    