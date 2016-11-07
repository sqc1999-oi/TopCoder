#include <string>
#include <queue>
using namespace std;
class ColorfulChocolates
{
public:
	int maximumSpread(const string &s, int x)
	{
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			queue<int> q1, q2;
			for (int j = i - 1; j >= 0; j--)
				if (s[j] == s[i]) q1.push(i - j - 1 - q1.size());
			for (int j = i + 1; j < s.size(); j++)
				if (s[j] == s[i]) q2.push(j - i - 1 - q2.size());
			int cnt = 1, sum = 0;
			while (!q1.empty() || !q2.empty())
			{
				if (q2.empty() || (!q1.empty() && q1.front() < q2.front()))
				{
					sum += q1.front();
					q1.pop();
				}
				else
				{
					sum += q2.front();
					q2.pop();
				}
				if (sum > x) break;
				cnt++;
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};
