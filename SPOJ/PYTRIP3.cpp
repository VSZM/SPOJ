#include <iostream>
#include <queue>

std::queue<int> aQueue, bQueue, cQueue;
long long N, result, a, b, c, newc;

int main()
{
	aQueue.push(3);
	bQueue.push(4);
	cQueue.push(5);

	std::cin >> N;
	result = 0;

	while (!cQueue.empty())
	{
		a = aQueue.front();
		b = bQueue.front(); 
		c = cQueue.front();
		aQueue.pop();
		bQueue.pop();
		cQueue.pop();

		result += N / c;

		/*T1: 	a − 2b + 2c 	2a − b + 2c 	2a − 2b + 3c
		T2: 	a + 2b + 2c 	2a + b + 2c 	2a + 2b + 3c
		T3: 	−a + 2b + 2c 	−2a + b + 2c 	−2a + 2b + 3c*/
		if ((newc = 2 * a - 2 * b + 3 * c) <= N) {
			aQueue.push(a - 2 * b + 2 * c);
			bQueue.push(2 * a - b + 2 * c);
			cQueue.push(newc);
		}
		if ((newc = 2 * a + 2 * b + 3 * c) <= N) {
			aQueue.push(a + 2 * b + 2 * c);
			bQueue.push(2 * a + b + 2 * c);
			cQueue.push(newc);
		}
		if ((newc = 2 * b + 3 * c - 2 * a) <= N) {
			aQueue.push(2 * b + 2 * c - a);
			bQueue.push(b + 2 * c - 2 * a);
			cQueue.push(newc);
		}
	}

	std::cout << result << std::endl;
	return 0;
}