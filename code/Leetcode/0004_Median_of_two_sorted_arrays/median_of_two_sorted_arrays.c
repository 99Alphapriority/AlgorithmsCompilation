double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int i = 0, j = 0, k = 0;
    int *nums3 = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    double res = 0.0;

    for(k = 0; k < (nums1Size + nums2Size); k++)
    {
        if((i != nums1Size) && (j != nums2Size))
        {
            nums3[k] = (nums1[i] < nums2[j]? nums1[i]: nums2[j]);

            if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        else
        {
            if(nums1Size == i)
            {
                nums3[k] = nums2[j++]; 
            }
            else
            {
                nums3[k] = nums1[i++];
            }
        }

    }

    if( 0 == (nums1Size + nums2Size) % 2)
    {
        res = (nums3[(nums1Size + nums2Size)/2] + nums3[((nums1Size + nums2Size)/2) - 1])/2.0;
    }
    else
        res = nums3[(nums1Size + nums2Size)/2];

    return res;
}
