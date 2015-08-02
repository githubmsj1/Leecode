#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<stack>
#include<math.h>
//#include<tr1/unordered_map>

using namespace std;
class Solution
{
	public:
		vector<int> grayCode(int n)
		{
			vector<int> result;
			const size_t size=1<<n;
			for(size_t i=0;i<size;i++)
			{
				result.push_back(binary_to_gray(i));
			}
			return result;
		}

		vector<int> grayCode1(int n)
		{
			vector<int> result;
			result.push_back(0);
			for(int i=0;i<n;i++)
			{
				const int highest_bit=1<<i;
				for(int j=result.size()-1;j>=0;j--)
				{
					result.push_back(highest_bit|result[j]);
				}
			}
			return result;
		}

	private:
		static unsigned int binary_to_gray(unsigned int i)
		{
			return i^(i>>1);
		}
			
};



int main()
{
	int src[]={9,9,9,9};
	vector<int>srcv(src,src+sizeof(src)/sizeof(int));
	
	//cout<<sizeof(matrix)/sizeof(matrix[0])<<endl;
	Solution s;
	vector<int>gray=s.grayCode1(2);
	int n=gray.size();

	while(n--)
	{	
		cout<<gray[gray.size()-1-n]<<endl;
	}
	//s.pulsOne(srcv);
	//for(int i=0;i<srcv.size();i++)
	//{
	//	cout<<srcv[i];
	//}
	//cout<<endl;


	return 0;
}
