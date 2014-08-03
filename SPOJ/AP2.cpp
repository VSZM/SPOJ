#include <iostream>
#include <cstdio>

unsigned long long a0, a1, a2, an_minus_3, an_minus_2, an_minus_1, sum, act_sum, n, d;

int main()
{
	int case_count;
	std::fscanf(stdin, "%d", &case_count);

	while (case_count-- > 0)
	{
		std::fscanf(stdin, "%llu %llu %llu", &a2, &an_minus_3, &sum);

		n = 2 * sum / (a2 + an_minus_3);
		d = (an_minus_3 - a2) / (n - 5);

		a0 = a2 - 2 * d;
		std::fprintf(stdout, "%llu\n%llu", n, a0);
		a0 += d;
		for (int i = 1; i < n; ++i)
		{
			std::fprintf(stdout, " %llu", a0);
			a0 += d;
		}
		std::fprintf(stdout, "\n");
	}

	return 0;
}
