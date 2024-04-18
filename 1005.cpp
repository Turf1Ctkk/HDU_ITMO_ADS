// Time complexity: O(N)
// Space complexity: O(1)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double DB;
#define For(i, s, t) for(int i = (s); i <= (t); i++)
#define Ford(i, s, t) for(int i = (s); i >= (t); i--)
#define Rep(i, t) for(int i = (0); i < (t); i++)
#define Repd(i, t) for(int i = ((t)-1); i >= (0); i--)
#define rep(i, s, t) for(int i = (s); i < (t); i++)
//int dp[max]
//dp[c]=max(dp[c],dp[c-wgt[i-1]]+val[i-1])
//wgt[i - 1]=a[i],val[i-1]=a[i]

int main()
{
	int n;
	while(cin>>n)
	{
		int sum=0;
		int a[n];
		Rep(i, n){
			cin>>a[i];
			sum+=a[i];
		}
		int half=sum/2;
		int dp[half + 1] = {0};
		//memset(dp,0,sizeof(dp));
		Rep(i ,n){
			Ford(j,half,a[i])
			{
				dp[j] = max(dp[j], dp[j-a[i]] + a[i]);
			}
		}
		cout << sum - dp[half] * 2 << endl;
	}
	return 0;
}
