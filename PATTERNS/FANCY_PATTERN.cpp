//FANCY PATTERN OF NUMERIC AND STAR ONLY
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==1 || i==n || j==1 || j==n)
            {
                cout<<"* ";
            }
            else
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
