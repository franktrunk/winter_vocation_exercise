#include<iostream>
#include<string>
using namespace std;

// 害死人不偿命的(3n+1)猜想 
int calculate_Callatz(int n)
{
    int cnt=0;
    while(n!=1)
    {
        if(n%2)
        n=(3*n+1)/2;
        else
        n=n/2;

        cnt++;
    }
    return cnt;
} 