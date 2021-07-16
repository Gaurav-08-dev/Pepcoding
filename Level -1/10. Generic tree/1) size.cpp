int size(Node root)
{
    int sz=0;

    for(Node child: root.children)
    {
        sz+=size(child);
    }
    return sz+1;
}