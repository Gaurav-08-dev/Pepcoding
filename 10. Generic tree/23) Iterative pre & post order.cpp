public static class Pair {
    Node node;
    int state;

    public Pair(Node node, int state) {
        this.node = node;
        this.state = state;
    }
}



public static void IterativePreandPostOrder(Node node) {
    Stack<Pair> st = new Stack<>();

    st.push(new Pair(node, 0));

    ArrayList<Integer> pre = new ArrayList<>();
    ArrayList<Integer> post = new ArrayList<>();

    while(!st.empty()) {
        Pair p = st.peek();
        if(p.state == 0) {
            pre.add(p.node.data);
            p.state++;
        } else if(p.state <= p.node.children.size()) {
            Node child = p.node.children.get(p.state - 1);
            p.state++;
            st.push(new Pair(child, 0));
        } else {
            post.add(p.node.data);
            st.pop();
        }
    }

    for(int val : pre) {
        System.out.print(val + " ");
    }
    System.out.println();

    for(int val : post) {
        System.out.print(val + " ");
    }
    System.out.println();
}
