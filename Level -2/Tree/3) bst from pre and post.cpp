public static TreeNode construct(int[] inord,ArrayList<Integer> lvl,int instart,int inend)
    {
        if(lvl.size()==0) return null;
        
        TreeNode root=new TreeNode(lvl.get(0));
        int index=instart;
        
        HashSet<Integer> set=new HashSet<>();
        
        while(inord[index]!=lvl.get(0))
        {
            set.add(inord[index]);
            index++;
        }
        
        ArrayList<Integer> llvl=new ArrayList<>();
        ArrayList<Integer> rlvl=new ArrayList<>();
        
        for(int i=1;i<lvl.size();i++)
        {
            int val=lvl.get(i);
            
            if(set.contains(val))
            {
                llvl.add(val);
            }
            else
            {
                rlvl.add(val);
            }
        }
        
        root.left=construct(inord,llvl,instart,index-1);
        root.right=construct(inord,rlvl,index+1,inend);
        
        return root;
    }
  public static TreeNode buildTree(int[] inord, int[] level){
ArrayList<Integer> lvl=new ArrayList<>();
        
        for(int val: level)
        {
            lvl.add(val);
        }
        
        return construct(inord,lvl,0,level.length-1);
  }
