double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    double median;

    int i=0;
    int j=0;
    int k=0;

    int c = nums1Size + nums2Size;
    int farray[c];

    while(i<nums1Size && j<nums2Size)
    {
        if(nums1[i] < nums2[j])
        {
            farray[k] = nums1[i];
            i++;
            k++;
        }
        else
        {
            farray[k] = nums2[j];
            k++;
            j++;
        }
    }
    while(i<nums1Size)
    {
        farray[k] = nums1[i];
        i++;
        k++;
    }
    while(j<nums2Size)
    {
        farray[k] = nums2[j];
        j++;
        k++;
    }
    double temp1, temp2;
    int id = c/2;
    if(c%2 == 0)
    {
        temp1 = (double)farray[id];
        temp2 = (double)farray[id-1];
        median = (temp1 + temp2)/2;
    }
    else
    {
        median = (double)farray[id];
    }


    return median;

}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna