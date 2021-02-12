#include <stdio.h>
#include <stdlib.h>

void subArray(int arr[], int len, int target, int output[])
{
    int left = 0;
    int right = 1;
    int sum = arr[left];
    while(right < len && left < len)
    {
        sum += arr[right];
        if ((target - sum) > 0)
            right++;
        else if((target - sum) < 0)
        {   
            sum -= arr[left];
            left++;
        }
        
        if(target == sum)
        {
            output[0] = left;
            output[1] = right;
            return;
        }
    }
}

int main()
{
    int N = 10; 
    int S = 15;
    int A[] = {1,2,3,4,5,6,7,8,9,10};
    int output[2] = {-1,-1};
 
    subArray(A, N, S, output);
    printf("%d --> %d\n", output[0], output[1]);
    return 0;
}
