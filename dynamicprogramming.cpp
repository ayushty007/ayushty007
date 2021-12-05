// this is dynamic programming problem based on kanpsack 
// this problem name is subset sum problem 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

vector<int> vec = {2, 3, 7, 8, 10};
int size = vec.size();
int sum = 13;
int t[14][6];

bool check = false;
int subset(vector<int> vec, int size, int sum)
{
    if( sum <= 0 || size <=0 )
    {
    if (sum == 0)
    {
       
        check = true ;
    }
        return 0;
    }
   if (t[sum][size] != -1 )
    {
        return t[sum][size];
    }

    if(sum >=0 )
    {
        
       return t[sum][size]=   max(sum - subset(vec,size -1 ,sum - vec[size -1 ]), subset(vec , size-1 , sum ));
    }
    else
    {
       return  subset(vec , size-1 , sum );
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(t , -1 , sizeof(t));
   subset(vec, size, sum);
    if (check == true)
        cout << "YES ";
    else
        cout << "NO";
    return 0;
}
