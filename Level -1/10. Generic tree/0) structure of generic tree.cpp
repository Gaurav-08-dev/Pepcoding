public static class Node {
        int data;
        ArrayList<Node> children;

        public Node() {
            this.data = 0;
            this.children = new ArrayList<>();
        }

        public Node(int data) {
            this.data = data;
            this.children = new ArrayList<>();
        }
    }

    public static Node construct(Integer[] arr) {
        Node root = null;
        Stack<Node> st = new Stack<>();

        for(int i = 0; i < arr.length; i++) {
            Integer data = arr[i];
            if(data != null) {
                Node nn = new Node(data);
                if(st.size() == 0) {
                    root = nn;
                    st.push(nn);
                } else {
                    st.peek().children.add(nn);
                    st.push(nn);
                }
            } else {
                st.pop();
            }
        }

    return root;

    /***** C++ *****/

    struct Node{
        int key;
        vector<Node*> child;
    }

    Node *newNode(int key){
        Node *temp=new Node;
        temp->key=key;
        return temp;
    }

    void LevelOrderTraversal(Node* root){
        
    }
    