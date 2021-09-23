public static ArrayList<TreeNode> nodeToRootPathNodeType(TreeNode node, int data) {
        if(node == null) {
            return new ArrayList<>();
        }
        ArrayList<TreeNode> res = new ArrayList<>();
        if(node.val == data) {
            res.add(node);
            return res;
        }
        ArrayList<TreeNode> lres = nodeToRootPathNodeType(node.left, data);
        if(lres.size() > 0) {
            lres.add(node);
            return lres;
        }
        ArrayList<TreeNode> rres = nodeToRootPathNodeType(node.right, data);
        if(rres.size() > 0) {
            rres.add(node);
            return rres;
        }
        return res;
    }


   private static void burningTree_1(TreeNode node, TreeNode blockage, 
                            int time, ArrayList<ArrayList<Integer>> res) {
        if(node == null || node == blockage) return;

        if(time < res.size()) {
            res.get(time).add(node.val);
        } else {
            // time == res.size()
            ArrayList<Integer> subres = new ArrayList<>();
            subres.add(node.val);
            res.add(subres);
        }

        burningTree_1(node.left, blockage, time + 1, res);
        burningTree_1(node.right, blockage, time + 1, res);
    }
    public static ArrayList<ArrayList<Integer>> burningTree(TreeNode root, int data) {
        ArrayList<TreeNode> n2rpath = nodeToRootPathNodeType(root, data);
        TreeNode blockage = null;
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
 
        for(int t = 0; t < n2rpath.size(); t++) {
            TreeNode node = n2rpath.get(t);
            burningTree_1(node, blockage, t, res);
            blockage = node;
        }
        return res;
    }