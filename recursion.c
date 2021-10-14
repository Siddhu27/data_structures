#include<stdio.h>
#include<limits.h>
 
// used to get the maximum of two integers
int max(int a, int b) { return (a > b)? a : b;}
 
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
   if (n<=0)
   {
	   return 0;
   }
   int max_val=INT_MIN;
   int i;
   for (i= 0; i < n; i++)
   {
	   max_val = max(max_val, price[i] + cutRod(price,n-i-1));
   }
 
   return max_val;
}
 
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 18};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d", cutRod(arr, size));
    return 0;
}
