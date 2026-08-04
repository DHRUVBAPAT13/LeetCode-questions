int mySqrt(int x) 
{
    if (x == 0 || x == 1) 
    {
        return x;
    }
    
    int left = 1;
    int right = x;
    int ans = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Use division instead of (mid * mid <= x) to prevent integer overflow
        if (mid <= x / mid) 
        {
            ans = mid;     // mid could be the potential answer
            left = mid + 1; // Try to find a larger value
        } 
        else 
        {
            right = mid - 1; // mid is too large, search the left half
        }
    }
    
    return ans;
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna