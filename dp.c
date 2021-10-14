#include<stdio.h>
#include<limits.h>
//used to find the maximum vaule between two numbers
int max(int a, int b) { return (a > b)? a : b;}
 
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;
 
   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }
 
   return val[n];
}
 
int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 18};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d", cutRod(arr, size));
    return 0;
}
