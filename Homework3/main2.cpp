//ترانهاده و دترمینان و معکوس
#include <iostream>
#include <math.h>
using namespace std;
const int maxsize=4;

void transpose(int arry[maxsize][maxsize])
{
    int arr[maxsize][maxsize];
    arr==arry;
    for(int i=0;i<maxsize;i++)
    {
        for(int j=0;j<maxsize;j++)
        {

                arr[i][j]=arry[j][i];

        }
    }//end of for
    cout<<"\n\nafter addition matrix c:"<<endl;
    for(int i=0;i<maxsize;i++)
    {
        for(int j=0;j<maxsize;j++)
            cout<<"\t"<<arr[i][j];
        cout<<"\n\n";
    }
}//end of transpose

int determinant(int arry[maxsize][maxsize],int n)
{
    if(maxsize==1)
    {
        return arry[0][0];
    }
    else if(maxsize==2)
    {
        return (arry[0][0] * arry[1][1]-arry[0][1] * arry[1][0]);
    }
    else
    {
        int det=0;
        int submat[maxsize][maxsize];
        for(int x=0;x<maxsize;x++)
        {
            int subi=0;
            for(int i=1;i<maxsize;i++)
            {
                int subj=0;
                for(int j=0;j<maxsize;j++)
                {
                    if(j==x)
                        continue;
                    submat[subi][subj]=arry[i][j];
                    subj++;
                }
                subi++;
            }
            det=det+(pow(-1,x)*arry[0][x]* determinant(submat,maxsize-1));
            return det;
        }

    }

}

int main()
{
    int n,matA[maxsize][maxsize];
    //cout<<"enter the size of n*n matrixes(maximum is 5):";
    //cin>>n;
    n=maxsize;
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
    //transpose(matA);
    determinant(matA,maxsize);
}
