#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;
class Solution
{
	public:
		double findMedianSortedArrays(int A[],int m,int B[],int n)
		{
			int total=m+n;
			if(total&0x1)
			{
				return find_kth(A,m,B,n,total/2+1);
			}
			else
			{
				return (find_kth(A,m,B,n,total/2)+find_kth(A,m,B,n,total/2))/2;
			}
		}
	private:
		static double find_kth(int A[],int m,int B[],int n,int k)
		{
			 if(m>n)return find_kth(B,n,A,m,k);
			 if(m==0)return B[k-1];
			 if(k==1)return min(A[0],B[0]);

			 int pa=min(k/2,m);int pb=k-pa;
			 if(A[pa-1]<B[pb-1]) 
			 	return find_kth(A+pa,m-pa,B,n,k-pa);
			 else if(A[pa-1]>B[pb-1]) 
			 	return find_kth(A,m,B+pb,n-pb,k-pb);
			 else 
			 	return A[pa-1];

			 
		}
};

int main()
{
	int a[]={2,3,4,5,6,7,8};
	int b[]={1,3,5,5,8,9,10,13};
	Solution s;
	cout<<s.findMedianSortedArrays(a,sizeof(a)/sizeof(int),b,sizeof(b)/sizeof(int))<<endl; 

	return 0;
}

