#include <iostream>
#include <queue>
#include <ctime>
#include <list>
#include <cstdio>

unsigned long long N, result, a, b, c, newc;



void expand(unsigned long long a, unsigned long long b, unsigned long long c)
{
	result += N/c;

	if ((newc = 2L * a - 2L * b + 3L * c) <= N) {
		expand(a - 2L * b + 2L * c,2L * a - b + 2L * c,newc);
	}
	if ((newc = 2L * a + 2L * b + 3L * c) <= N) {
		expand(a + 2L * b + 2L * c,2L * a + b + 2L * c,newc);
	}
	if ((newc = 2L * b + 3L * c - 2L * a) <= N) {
		expand(2L * b + 2L * c - a,b + 2L * c - 2L * a,newc);
	}
}


int main_pytrip3()
{
	//std::cout << "starting" << std::endl;
	//clock_t begin = clock();

	std::cin >> N;
	//  121000000
	result = 0Lu;

	expand(3,4,5);

	std::cout << result << std::endl;

//	clock_t end = clock();
//	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;


//	std::cout << elapsed_secs << " seconds" << std::endl;
	return 0;
}
//
//
//int main()
//{
//	//std::cout << "starting" << std::endl;
//	//clock_t begin = clock();
//
//	aQueue.push(3);
//	bQueue.push(4);
//	cQueue.push(5);
//
//	//std::cin >> N;
//	//  121000000
//	N = 10000000Lu;
//	result = 0l;
//
//	while (!cQueue.empty())
//	{
//		a = aQueue.front();
//		b = bQueue.front();
//		c = cQueue.front();
//		aQueue.pop();
//		bQueue.pop();
//		cQueue.pop();
//
//		result += N / c;
//
//		/*T1: 	a − 2b + 2c 	2a − b + 2c 	2a − 2b + 3c
//		T2: 	a + 2b + 2c 	2a + b + 2c 	2a + 2b + 3c
//		T3: 	−a + 2b + 2c 	−2a + b + 2c 	−2a + 2b + 3c*/
//		if ((newc = 2L * a - 2L * b + 3L * c) <= N) {
//			aQueue.push(a - 2L * b + 2L * c);
//			bQueue.push(2L * a - b + 2L * c);
//			cQueue.push(newc);
//		}
//		if ((newc = 2L * a + 2L * b + 3L * c) <= N) {
//			aQueue.push(a + 2L * b + 2L * c);
//			bQueue.push(2L * a + b + 2L * c);
//			cQueue.push(newc);
//		}
//		if ((newc = 2L * b + 3L * c - 2L * a) <= N) {
//			aQueue.push(2L * b + 2L * c - a);
//			bQueue.push(b + 2L * c - 2L * a);
//			cQueue.push(newc);
//		}
//	}
//
//	std::cout << result << std::endl;
//
////	clock_t end = clock();
////	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//
//
////	std::cout << elapsed_secs << " seconds" << std::endl;
//	return 0;
//}