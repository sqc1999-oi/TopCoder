#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class KingdomAndTrees
{
	bool check(vector<int> a, int x)
	{
		a[0] = max(1, a[0] - x);
		for (int i = 1; i < a.size(); i++)
		{
			if (a[i] <= a[i - 1])
			{
				if (a[i] + x <= a[i - 1]) return false;
				a[i] = a[i - 1] + 1;
			}
			else a[i] = max(a[i - 1] + 1, a[i] - x);
		}
		return true;
	}
public:
	int minLevel(const vector<int> &a)
	{
		int l = 0, r = INT_MAX, ans = 0;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (check(a, mid))
			{
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		return ans;
	}
};