#include <stdio.h>

//abs value of int

int myAbs(int num)
{
    //-n = ~n + 1
    //~n = -n - 1 
    //n = ~(-n -1)
    
    int mask = num >> 31;
    num = (num + mask) ^ mask;

    return num;
}

void swapNums(int* a, int* b)
{
    //a = 3 = 011
    //b = 4 = 100
    //b = a^b = 111
    //a = a^b = 100
    //b = a^b = 011
    *b = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
}

int isEqual(int a, int b)
{
    // a = 5: 101, b = 4:100, a ^ b = 001
    // a = 6: 110, b = 6:110, a^b = 000
    
    return ( (a^b) > 0 ? 0: 1);
}

int isPowerOf2(int num)
{
    //num = 4 = 100, num - 1 = 3 = 011
    //num & num -1 = 0
    
    //num = 6 = 110, num - 1 = 5 = 101
    //num & num-1 = 100
    
    return ((num&num-1) > 0? 0 : 1);
}

int isPowerOf4(int num)
{
    if (isPowerOf2(num) && ((num % 3) == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isPowerOf8(int num)
{
    if (isPowerOf2(num) && ((num % 7) == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isPowerOf16(int num)
{
    if (isPowerOf2(num) && ((num % 15) == 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int previousPowerOf2(int num)
{
    if ( isPowerOf2(num) )
    {
        return num;
    }
    else
    {
        while (num & num - 1)
        {
            num = num & num - 1;
        }
    }
    
    return num;
}

int nextPowerOf2(int num)
{
    if ( isPowerOf2(num) )
    {
        return num;
    }
    
    return previousPowerOf2(num) << 1;
}


int main()
{
    int a = 257, b = 4;
    
    printf("Previous Power of 2: %d\n", previousPowerOf2(a));
    printf("Next Power of 2: %d\n", nextPowerOf2(a));
    

    return 0;
}
