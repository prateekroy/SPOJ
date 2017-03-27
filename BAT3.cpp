/* Dynamic Programming C/C++ implementation of LIS problem */
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
 
using namespace std;
 
int mymax(int a, int b){
    if (a > b)
    {
        return a;
    }
    return b;
}
 
/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis( int arr[], int n, int batpos)
{
    int *lis, i, j, max = 0;
    lis = (int*) malloc ( sizeof( int ) * n );
    int answerwbat = -1;
    bool done = false;
 
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ ){
        for (j = 0; j < i; j++ ) {
            if ( arr[i] < arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
                if (i > batpos && arr[i] >= arr[batpos])
                {
                    // answerwbat++;
                    lis[i] = mymax(lis[batpos]+1, lis[i]);
                    // done = true;
                }
        }
                // if (i == batpos)
                // {
                //     answerwbat = lis[i];
                //     // cout << answerwbat << endl;
                // }
 
    }
 
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << lis[i] << " " ;
    // }
 
    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++ )
        if (max < lis[i])
            max = lis[i];
 
    /* Free memory to avoid memory leak */
    free(lis);
 
    return mymax(max, answerwbat);
}
 
/* Driver program to test above function */
int main()
{
    int testcases;
    cin >> testcases;
    for (int tc = 0; tc < testcases; ++tc)
    {
        int N, batpos;
        cin >> N >> batpos;
        int* arr = new int[N];
 
        for (int i = 0; i < N; ++i)
        {
            cin >> arr[i];
        }
 
        cout << lis(arr, N, batpos) << endl;
    }
 
    return 0;
} 