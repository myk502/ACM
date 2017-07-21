/* THE PROGRAM IS MADE BY PYY */
/*----------------------------------------------------------------------------//
Copyright (c) 2011 panyanyany All rights reserved.

URL   : http://acm.hdu.edu.cn/showproblem.php?pid=1175
Name  : 1175 连连看

Date  : Wednesday, August 17, 2011
Time Stage : long , very long.......

Result:

Test Data:

Review:
可惜有了数据还是弄不明白原理，好笨啊～～～
//----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------
1175 连连看 随机数据生成器
**---------------------------------------------------------------------------*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 10009
#define LIMIT	10		// 生成的图表都是 10*10 的规格的，方便人工跟踪找错
// 这里也可以设得大点，或小点，我觉得10个比较合适

#define getNotZeroRand(x) while (!((*x) = rand() % LIMIT)) ;
#define getNumUpperThan(x, y) while ((*(x) = rand() % LIMIT) < y) ;
#define getNumInRange(x, lower, upper) while ((*(x) = rand() % upper) < lower) ;

int repeat[MAXSIZE] ;
int map[MAXSIZE][MAXSIZE] ;

int main ()
{
	//freopen ("D:\\Computer Language\\C++\\Test\\in.txt", "r", stdin) ;
	int i, j, k ;
	int n, m, num, tmp, q ;
	int x1, y1, x2, y2 ;

	//puts ("input data number : ") ;	// 提示语言不能输入到文件中，所以要先写

	// 文件重定向，把原来要输出到屏幕上的内容，输出到文件上去
	freopen ("in.txt", "w", stdout) ;
	//scanf ("%d", &num) ;
	num=10;
	srand(unsigned(time(0)));
	//srand (0) ;	// 设置随机数种子，貌似不设也可以。。。。。。
	// 当时只是想让产生的随机数更"随机"一点，其实反而不方便找错
	// 固定的数据，可以经得起反复的查找

	for (i = 0 ; i < num ; ++i)
	{
		// 生成 10 * 10 的数据量
		// 用 getNumInRange 也可以，不过这个是先写的，也就没有去改了
		getNumUpperThan (&n, 1) ;
		getNumUpperThan (&m, 1) ;

		// 想获得多少组数据，就输入多少，我10000条左右就能测出错误来了
		// 当然，你得先有个标准的答案代码，利用这里的数据产生标准答案，
		// 再和自己产生的答案对比，才有意义。
		printf ("%d %d\n", n, m) ;

		memset (repeat, 0, sizeof (repeat)) ;	// 用来计算数字的重复次数，
		// 一张图里面的一个数字只能重复两次

		for (j = 0 ; j < n ; ++j)
		{
			for (k = 0 ; k < m; ++k)
			{
			    tmp = rand () % (n * m) ;
				/*

				// 其实这个限制重复次数的循环有时候会很花时间的
				// 但实际上好像影响不大，所以没有想去改进
				while (repeat[tmp] >= 2)
					tmp = rand () % (n * m) ;
				++repeat[tmp] ;

				// 这里，限定0的分布频率，为50%
				// 也就是说，不管你输出多少数，总有50%的数是0
				// 如果0太少，这样的数据是没有什么意义的
				// 不过从我实验的情况来看，貌似0多点更能查检出错误来。。。。。
				if ((n*m)/2 <= tmp)
					tmp = 0 ;

                */

				// 记录新鲜出炉的数，趁热，别凉了 :)
				map[j][k] = tmp ;
			}
		}

		//输出图表
		for (j = 0 ; j < n ; ++j)
		{
			for (k = 0 ; k < m - 1; ++k)
			{
				printf ("%d ", map[j][k]) ;
			}
			printf ("%d\n", map[j][k]) ;
		}

		// 把询问次数限定在50以内。。。且不能为0
		while (!(q = rand () % 50)) ;

		printf ("%d\n", q) ;

		for (j = 0 ; j < q ; ++j)
		{
			// 这里获得的数据要求 1 <= x < n + 1
			getNumInRange (&x1, 1, n + 1) ;
			getNumInRange (&y1, 1, m + 1) ;
			getNumInRange (&x2, 1, n + 1) ;
			getNumInRange (&y2, 1, m + 1) ;

			printf ("%d %d %d %d\n", x1, y1, x2, y2) ;
		}
		// 刷新缓冲区，现在已经没什么作用了。
		// 但刚开始的时候，这个程序有些错误，需要及时刷新来查看究竟是运行到哪了
		//fflush (stdout);
	}
	// 别忘了还要有结束的一行
	printf ("0 0\n") ;
	return 0 ;
}
