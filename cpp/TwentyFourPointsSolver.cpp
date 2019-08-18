#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<cmath>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class TwentyFourPointsSolver
{
private:
	char s[4][100];		//用来输出结果
	double num[4];
	int visit[4];

public:
	bool dfs(int step)
	{
		//递归结束，判断是否得到24
		if (step == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				if (visit[i] == 0 && abs(num[i] - 24) < 1e-6)
				{
					for (int j = 0; j < 3; j++)
					{
						cout << s[j] << endl;
					}
					return true;
				}
			}
			return false;
		}

		//枚举第i张a和第j张b，选择没有用过的两张，算出结果c放入a中重复利用数组
		for (int i = 0; i < 4; i++)
		{
			if (this->visit[i] != 0)
				continue;
			for (int j = i + 1; j < 4; j++)
			{
				if (this->visit[j] != 0)
					continue;
				visit[j] = 1;

				double a = num[i], b = num[j], c;
				c = a + b;
				num[i] = c;
				sprintf(s[step], "%lf + %lf = %lf", a, b, c);
				if (dfs(step + 1))
				{
					return true;
				}
				c = a - b;
				num[i] = c;
				sprintf(s[step], "%lf - %lf = %lf", a, b, c);
				if (dfs(step + 1))
				{
					return true;
				}
				c = b - a;
				num[i] = c;
				sprintf(s[step], "%lf - %lf = %lf", b, a, c);
				if (dfs(step + 1))
				{
					return true;
				}
				c = a * b;
				num[i] = c;
				sprintf(s[step], "%lf * %lf = %lf", a, b, c);
				if (dfs(step + 1))
				{
					return true;
				}
				c = a / b;
				num[i] = c;
				sprintf(s[step], "%lf / %lf = %lf", a, b, c);
				if (dfs(step + 1))
				{
					return true;
				}
				c = b / a;
				num[i] = c;
				sprintf(s[step], "%lf / %lf = %lf", b, a, c);
				if (dfs(step + 1))
				{
					return true;
				}

				/*
				此处还可以枚举更多的运算方式，如 a % b, pow(a, b)等 
				*/

				num[i] = a;
				
				visit[j] = 0;
			}
		}
		return false;
	}

	void solve(vector<int> nums)
	{
		if (nums.size() != 4)
		{
			cout << "the number of number is wrong." << endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			this->num[i] = nums[i];
			this->visit[i] = 0;
		}

		if (!dfs(0))
		{
			cout << "Can't solve this problem." << endl;
		}

		return;
	}
};

int main()
{
	//有点LeetCode风格
	TwentyFourPointsSolver().solve(vector<int>{1,5,5,5});
	cin.get();
}