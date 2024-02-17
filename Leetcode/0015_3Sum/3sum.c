/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return (*((int*)a)) - (*((int*)b));
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    int i = 0, left = 0, right = 0;
    (*returnSize) = 0;
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * numsSize * numsSize);
    int **ret = (int**)malloc(sizeof(int) * numsSize * numsSize);

    if(numsSize == 3)
    {
        if(0 == (nums[0] + nums[1] + nums[2]))
        {
            ret[(*returnSize)] = (int*)malloc(sizeof(int) * 3);
            ret[(*returnSize)][0] = nums[0];
            ret[(*returnSize)][1] = nums[1];
            ret[(*returnSize)][2] = nums[2];
            (*returnColumnSizes)[(*returnSize)] = 3;
            (*returnSize)++;
            return ret;
        }
    }

    qsort(nums, numsSize, sizeof(int), cmp);

    for(i=0; i < numsSize-2; i++)
    {
        if(i == 0 || (nums[i] != nums[i-1]))
        {
        left = i + 1;
        right = numsSize - 1;

        while(left < right)
        {
            
            if((nums[i] + nums[left] + nums[right]) < 0)
                left++;
            else if((nums[i] + nums[left] + nums[right]) > 0)
                right--;
            else
            {
                ret[*returnSize] = (int*)malloc(sizeof(int) * 3);
                ret[*returnSize][0] = nums[i];
                ret[*returnSize][1] = nums[left];
                ret[*returnSize][2] = nums[right];
                (*returnColumnSizes)[(*returnSize)] = 3;
                (*returnSize) ++;
                left++;
                while((left < right) && (nums[left] == nums[left - 1]))
                    left++;
            }
            
        }
        }
    }

    return ret;
}
