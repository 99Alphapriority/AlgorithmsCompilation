/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *sol = (int *)malloc(sizeof(int)*(*returnSize));
    

    for(int idx = 0; idx < numsSize; idx++)
    {
        for(int idx2 = idx + 1; idx2 < numsSize; idx2++)
        {
            if(nums[idx] + nums[idx2] == target)
            {
                sol[0] = idx;
                sol[1] = idx2;
            }
        }
    }
return sol;

}
