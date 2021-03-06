//解法一
//求解亲和数问题

//第一个for和第二个for循环是logN*N（调和级数）次遍历,第三个for循环扫描O(N)。
//所以总的时间复杂度为 O(N*logN) + O(n) =O(N*logN+N)（其中logN为调和级数）。

//关于第一个for和第二个for寻找中，调和级数的说明：
//比如给2的倍数加2，那么应该是  n/2次，3的倍数加3 应该是 n/3次，...
//那么其实就是n*（1+1/2+1/3+1/4+...1/(n/2)）=n*（调和级数）=n*logn。

//copyright@ 上善若水
//July、updated，2011.05.24。
#include<stdio.h>

int sum[5000010];   //为防越界

int main()
{
	int i, j;
	for (i = 0; i <= 5000000; i++)
		sum[i] = 1;  //1是所有数的真因数所以全部置1

	for (i = 2; i + i <= 5000000; i++)  //预处理，预处理是logN（调和级数）*N。
		//@litaoye：调和级数1/2 + 1/3 + 1/4......的和近似为ln(n)，
		//因此O(n *(1/2 + 1/3 + 1/4......)) = O(n * ln(n)) = O(N*log(N))。
	{
		//5000000以下最大的真因数是不超过它的一半的
		j = i + i;  //因为真因数，所以不能算本身，所以从它的2倍开始
		while (j <= 5000000)
		{
			//将所有i的倍数的位置上加i
			sum[j] += i;
			j += i;
		}
	}

	for (i = 220; i <= 5000000; i++)   //扫描，O（N）。
	{
		// 一次遍历，因为知道最小是220和284因此从220开始
		if (sum[i] > i && sum[i] <= 5000000 && sum[sum[i]] == i)
		{
			//去重，不越界，满足亲和
			printf("%d %d/n",i,sum[i]);
		}
	}
	return 0;
}
