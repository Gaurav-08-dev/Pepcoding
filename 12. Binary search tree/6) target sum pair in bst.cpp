public static boolean find(Node node, int data){
  
  if(node==null) return false;

  if(data > node.data)
  {
    return find(node.right, data);
  }
  else if(data < node.data)
  {
    return find(node.left, data);
  }
  else{
    return true;
  }
}



// method 1 :- time: O(nh), space : O(h), h->height

public static void printTargetSumPair(Node node, Node root,int target)
{

	if(node==null)
	{
		return;
	}
	int n1=node.data;
	int n2=target-n1;
	printTargetSumPair(node.left,root, target);

	if(n1 < n2 && find(root,n2)==true)
	{
		System.out.println(n1 + " " + n2);
	}

	printTargetSumPair(node.right,root, target);
}



// method 2: time: O(n) space : O(n)


// method 2, time : O(n), space : O(n), h-> height
    public static void inorderFiller(Node node, ArrayList<Integer> list) {
        if(node == null) return;

        inorderFiller(node.left, list);
        list.add(node.data);
        inorderFiller(node.right, list);
    }

    public static void printTargetSumPair2(Node node, int target) {
        ArrayList<Integer> list = new ArrayList<>();
        inorderFiller(node, list);

        int left = 0;
        int right = list.size() - 1;

        while(left < right) {
            int sum = list.get(left) + list.get(right);
            if(sum > target) {
                right--;
            } else if(sum < target) {
                left++;
            } else {
                System.out.println(list.get(left) + " " + list.get(right));
                left++;
                right--;
            }
        }
    }
    


    // method 3, time : O(n), space : O(h), h-> height
    

    public static class Pair {
        Node node;
        int state;

        public Pair(Node node, int state) {
            this.node = node;
            this.state = state;
        }
    }
    
    public static int inorderItr(Stack<Pair> st) {
        while(st.size() > 0) {
            Pair p = st.peek();

            if(p.state == 0) {
                // left child
                if(p.node.left != null) {
                    st.push(new Pair(p.node.left, 0));
                }
                p.state++;
            } else if(p.state == 1) {
                // right child
                if(p.node.right != null) {
                    st.push(new Pair(p.node.right, 0));
                }
                p.state++;
                return p.node.data;
            } else {
                // pop
                st.pop();
            }
        }
        return -1;
    }

    public static int revInorderItr(Stack<Pair> st) {
        while(st.size() > 0) {
            Pair p = st.peek();

            if(p.state == 0) {
                // right child
                if(p.node.right != null) {
                    st.push(new Pair(p.node.right, 0));
                }
                p.state++;
            } else if(p.state == 1) {
                // left child
                if(p.node.left != null) {
                    st.push(new Pair(p.node.left, 0));
                }
                p.state++;
                return p.node.data;
            } else {
                // pop
                st.pop();
            }
        }
        return -1;
    }


    public static void printTargetSumPair3(Node node, int target) {
        Stack<Pair> ls = new Stack<>();
        Stack<Pair> rs = new Stack<>();

        ls.push(new Pair(node, 0));
        rs.push(new Pair(node, 0));


        int left = inorderItr(ls);
        int right = revInorderItr(rs);

        while(left < right) {
            int sum = left + right;
            if(sum > target) {
                right = revInorderItr(rs);
            } else if(sum < target) {
                left = inorderItr(ls);
            } else {
                System.out.println(left + " " + right);
                left = inorderItr(ls);
                right = revInorderItr(rs);
            }
        }
    }