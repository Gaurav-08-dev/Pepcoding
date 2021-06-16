// Approach : 1 
// static boolean isAvailable=false;
//   public static boolean find(Node node, int data) {
    
//     if(node.data==data)
//     {
//         isAvailable=true;
//         return isAvailable;
//     }
    
//     for(Node child: node.children)
//     {
//         find(child,data);
//     }
    
//     return isAvailable;
//   }



/* ----------------------------------------------*/

public static boolean find(Node node, int data)
{
	if(node.data==data)
	{
		return true;
	}

	boolean res=false;
	for(Node child: node.children)
	{
		res=find(child,data);

		if(res==true)
		{
			return true;
		}

		// res=res || find(child,data);
	}
	
	return false;
}
