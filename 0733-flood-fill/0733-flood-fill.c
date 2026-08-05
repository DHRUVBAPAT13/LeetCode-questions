/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int** image, int rowSize, int colSize, int r, int c, int oldColor, int newColor)
{
    if(r < 0 || r >= rowSize || c < 0 || c >= colSize)
    {
        return;
    }

    if(image[r][c] != oldColor)
    {
        return;
    }

    image[r][c] = newColor;

    dfs(image,rowSize,colSize,r-1,c,oldColor,newColor);     //up
    dfs(image,rowSize,colSize,r+1,c,oldColor,newColor);     //down
    dfs(image,rowSize,colSize,r,c-1,oldColor,newColor);     //left
    dfs(image,rowSize,colSize,r,c+1,oldColor,newColor);     //right

}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    int oldColor = image[sr][sc];

    if(oldColor != color)
    {
        dfs(image,imageSize,imageColSize[0],sr,sc,oldColor,color);
    }

    return image;
}



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna