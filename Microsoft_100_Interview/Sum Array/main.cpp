#include <vector>

using namespace std;


int MaxSubArray(vector<int> v)
{
	int sum = 0;
	int max = 0;

	for (auto i : v)
	{
		sum += i;
		if (sum > max)
		{
			max = sum;
		}

		if (sum < 0)
		{
			sum = 0;
		}
	}

	return max;
}

int main()
{
	MaxSubArray({ 1, -2, 3, 10, -4, 7, 2, -5 });
	return 0;
}