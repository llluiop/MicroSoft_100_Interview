#include <vector>

using namespace std;



int Partition(vector<int>& v, int first, int last)
{
	int low = first;
	int high = last;

	int tmp = v[low];
	while (low < high)
	{
		while (v[high] >= tmp && high > low)
		{
			high--;
		}

		v[low] = v[high];

		while (v[low] < tmp && high > low)
		{
			low++;
		}

		v[high] = v[low];
	}

	v[low] = tmp;

	return low;
}

void topk(vector<int>& v, int k, vector<int>& ret, int start, int end)
{
	int pivot = Partition(v, start, end);
	if (pivot-start == k - 1)
	{
		ret.insert(ret.end(), v.begin() + start, v.begin() + pivot + 1);
	}
	else if (pivot - start > (k - 1))
	{
		topk(v, k, ret, start, pivot - 1);
	}
	else
	{
		ret.insert(ret.end(), v.begin() + start, v.begin() + pivot + 1);
		topk(v, k - pivot + start - 1, ret, pivot + 1, end);
	}
}

vector<int> TopKArray(vector<int> v, int k)
{
	if (v.size() < k)
	{
		return v;
	}

	vector<int> ret;
	topk(v, k, ret, 0, v.size()-1);
	return ret;
}

int main()
{
	TopKArray({ 1, 3, 10, 3, -4, 7, 3, -5 }, 6);
	return 0;
}