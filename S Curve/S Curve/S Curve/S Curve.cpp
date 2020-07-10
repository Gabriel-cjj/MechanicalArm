// S Curve.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

void SCurve(int T, double a, double v, double S)
{
	int j = 0;

	int T0 = T;
	double a0 = a;
	double v0 = v;

	double i = 0.001;
	int n = T0 / i;

	//定义动态数组
	double* s = new double[n];
	double* s1 = new double[n];
	double* s2 = new double[n];
	//初始化动态数组
	s = { 0 };
	s1 = { 0 };
	s2 = { 0 };

	double J = v0 * a0 * a0 / (T0 * v0 * a0 - S * a0 - v0 * v0);
	double t1 = T0 - S / v0;
	double t2 = T0 - t1;
	double ta = a0 / J;

	if (v0 * T0 > S && J > 0 && ta > 0)
	{
		for (double t = 0; t <= T0; t = t + i)
		{

			if (t < ta)
			{
				s[j] = 1 / 6 * a0 / ta * t * t * t;
			}
			else if (t >= ta && t < t1 - ta)
			{
				s[j] = a0 * t * t / 2 - 1 / 2 * a0 * ta * t + 1 / 6 * a0 * ta * ta;
			}
			else if (t >= t1 - ta && t < t1)
			{
				s[j] = -1 / 6 * a0 / ta * (t - t1) * (t - t1) * (t - t1) + a0 * (t1 - ta) * t - 1 / 2 * a0 * t1 * t1 + 1 / 2 * a0 * t1 * ta;
			}
			else if (t >= t1 && t < t2)
			{
				s[j] = a0 * (t1 - ta) * t - 1 / 2 * a0 * t1 * t1 + 1 / 2 * a0 * t1 * ta;
			}
			else if (t >= t2 && t < t2 + ta)
			{
				s[j] = -1 / 6 * a0 / ta * (t - t2) * (t - t2) * (t - t2) + a0 * (t1 - ta) * t - 1 / 2 * a0 * t1 * (t1 - ta);
			}
			else if (t >= t2 + ta && t < T0 - ta)
			{
				s[j] = -1 / 2 * a0 * t * t + a0 * (T0 - 1 / 2 * ta) * t - 1 / 6 * a0 * ta * ta - 1 / 2 * a0 * t1 * t1 - 1 / 2 * a0 * t2 * t2 - 1 / 2 * a0 * T0 * ta + a0 * t1 * ta;
			}
			else if (t >= T0 - ta && t <= T0)
			{
				s[j] = 1 / 6 * a0 / ta * (t - T0) * (t - T0) * (t - T0) - a0 * t2 * ta + a0 * t1 * t2;
			}
			j = j + 1;
		}
	}
	else
	{
		std::cout << "Error!";
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
