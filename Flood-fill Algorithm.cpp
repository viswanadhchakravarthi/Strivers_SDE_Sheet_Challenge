void helper(vector<vector<int>> &image, int x, int y, int oldColor, int newColor)
{
    if(x<0 || y<0 || x>=image.size() || y>=image[0].size())
        return;
    if(image[x][y]!=oldColor )
        return;
    image[x][y]=newColor;
    helper(image,x-1,y,oldColor,newColor);
    helper(image,x+1,y,oldColor,newColor);
    helper(image,x,y-1,oldColor,newColor);
    helper(image,x,y+1,oldColor,newColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldColor = image[x][y];
    // this edge is v.imp to handle bcz if not added then non-neighbour oldColor will also be painted & 
    // if not added , stack overFlow may occurs bcz of infinite recursion-> Runtime error
    if(oldColor == newColor) // why to paint again, just return
        return image;
    helper(image,x,y,oldColor,newColor);
    return image;
}
