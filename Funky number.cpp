#include <bits/stdc++.h>
using namespace std;
long long int arr[100050];
void tr(){

    int i;
    for(i=1; i<=100000; i++){
        arr[i] = arr[i-1] + i;
    }

}

bool binary(long long int arr[], int n, long long int search_element)
{
    long long int high, low, mid;
    low = 1;
    high = n+1;
    mid = (low+high)/2;

    while(low < high)
    {
        if(arr[mid]==search_element)
            return true;

        else if (search_element < arr[mid])
        {
            high = mid;
            mid = (high+low)/2;
        }

        else if (search_element > arr[mid])
        {
            low = mid+1;
            mid = (high+low)/2;
        }
    }

    return false;
}

int main()
{
    long long int n, i, j, k, result;

    tr();

    scanf("%I64d", &n);

    for (i=1; i<(100000/2); i++){

        k = n-arr[i];
        result = binary(arr, 100000, k);

        if(result == true)
        {
            printf("YES\n");

            return 0;
        }
    }

        printf("NO\n");



    return 0;
}
