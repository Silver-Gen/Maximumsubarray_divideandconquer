#include <iostream>
#include <climits>
using namespace std;
int findmaxcrosssubaaray(int A[],int low,int mid,int high)
{
    int leftsum=INT_MIN;
    int maxleft,maxright,sum=0;
    for(int i=mid;i>=low;i--)
    {
        sum=sum+A[i];
        if(sum>leftsum)
        {
            leftsum=sum;
            maxleft=i;
        }
    }
    int rightsum=INT_MIN;
    sum=0;
    for(int j=mid+1;j<=high;j++)
    {
        sum=sum+A[j];
        if(sum>rightsum)
        {
            rightsum=sum;
            maxright=j;
        }
    }
    return (maxleft,maxright,leftsum+rightsum);
}
int findmaxsubaaray(int A[],int low,int high)
{
    if(high==low)
        return(low,high,A[low]);
    else
    {
        int mid=(low+high)/2;
        int leftlow,lefthigh,leftsum,rightlow,righthigh,rightsum,crosslow,crosshigh,crosssum; 
        (leftlow,lefthigh,leftsum)=findmaxsubaaray(A,low,mid);
        (rightlow,righthigh,rightsum)=findmaxsubaaray(A,mid+1,high);
        (crosslow,crosshigh,crosssum)=findmaxcrosssubaaray(A,low,mid,high);
        if((leftsum>=rightsum)&&(leftsum>=crosssum))
            return (leftlow,lefthigh,leftsum);
        else if((rightsum>=leftsum)&&(rightsum>=crosssum))
            return (rightlow,righthigh,rightsum);
        else
            return (crosslow,crosshigh,crosssum);
    }
}
int main()
{
	int t,n;
	cout<<"Enter total no. of test cases: ";
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cout<<"Test Case: "<<i+1;
		cout<<"\nEnter total elements: ";
		cin>>n;
		cout<<"Enter elements with space separated: ";
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
    	int max_sum = findmaxsubaaray(arr, 0, n - 1);
    	cout<<"Maximum sum of the subarray is: "<<max_sum<<endl;		
	}
    return 0;
}
