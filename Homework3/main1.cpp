//نمایش جمع و ضرب و تفریق دو ماتریس n*n
#include <iostream>
using namespace std;
int main()
{
    int maxsize=5; //max size of each matrixes
    int matA[maxsize][maxsize],matB[maxsize][maxsize],matC[maxsize][maxsize],n;
    cout<<"enter the size of n*n matrixes(maximum is 5):";
    cin>>n;

    //matA
    cout<<"enter elements of matrixA:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter matA["<<i<<"]["<<j<<"]element:";
            cin>>matA[i][j];
        }
    }

    //matB
    cout<<"enter elements of matrixB:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"enter matB["<<i<<"]["<<j<<"]element:";
            cin>>matB[i][j];
        }
    }

    //addition
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            matC[i][j]=matA[i][j]+matB[i][j];
    }

    //show addition mat
    cout<<"\n\nafter addition matrix c:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<"\t"<<matC[i][j];
        cout<<"\n\n";
    }

    //subtraction
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            matC[i][j]=matA[i][j]-matB[i][j];
    }

    //show subtraction mat
    cout<<"\n\nafter subtraction matrix c:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<"\t"<<matC[i][j];
        cout<<"\n\n";
    }

    //multiply
    int sum,k; //only need for multiply
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum=0;
            for(k=0;k<n;k++)
                sum= sum + (matA[i][k]* matB[k][j]);
            matC[i][j]=sum;
        }

    }

    //show multiply mat
    cout<<"\n\nafter multiplication matrix c:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<"\t"<<matC[i][j];
        cout<<"\n\n";
    }
}