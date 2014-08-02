#include<iostream>
#include<cstring>
//#include<chrono>

#define M 45165824
#define PRIME_COUNT 2727584
bool prime_lookup[M],is_p = true;
unsigned int concrete_primes[PRIME_COUNT];
unsigned long actual_number,squareroot_of_act, mod;
int i,j;	
char output[1000002];


unsigned int  // OR uint16 OR uint8  
	isqrt32 (unsigned int n) // OR isqrt16 ( uint16 n ) OR  isqrt8 ( uint8 n ) - respectively [ OR overloaded as isqrt (uint?? n) in C++ ]  
{  
	register unsigned int // OR register uint16 OR register uint8 - respectively  
		root, remainder, place;  

	root = 0;  
	remainder = n;  
	place = 0x40000000; // OR place = 0x4000; OR place = 0x40; - respectively  

	while (place > remainder)  
		place = place >> 2;  
	while (place)  
	{  
		if (remainder >= root + place)  
		{  
			remainder = remainder - root - place;  
			root = root + (place << 1);  
		}  
		root = root >> 1;  
		place = place >> 2;  
	}  
	return root;  
}  
/*
unsigned int sqrt32(unsigned long n)  
{  
	unsigned int c = 0x8000;  
	unsigned int g = 0x8000;  

	for(;;) {  
		if(g*g > n)  
			g ^= c;  
		c >>= 1;  
		if(c == 0)  
			return g;  
		g |= c;  
	}  
}*/
int main_old()
{
	//auto start = std::chrono::high_resolution_clock::now();
	// Sieve of Erathosthenes
	std::memset(prime_lookup,true,sizeof(prime_lookup));
	prime_lookup[0] = prime_lookup[1] = false;

	actual_number = 1L;

	mod = (1L << 31L);


	squareroot_of_act = isqrt32(M);
	for (i=2; i<=squareroot_of_act;++i)
	{
		if(prime_lookup[i])
			for (j=i*i;j<M;j+=i)
				prime_lookup[j] = false;
	}

	j=0;
	for (i=0;i<M;++i)
		if (prime_lookup[i])
			concrete_primes[j++] = i;			


	/*auto end = std::chrono::high_resolution_clock::now();
	auto duration =end - start;
	std::cout << "\n Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "\n";
	*/
	j=0;
	do
	{

		if(actual_number%2 == 1)// actual number is odd
		{
			if(actual_number < M)// actual number is predecided
			{
				is_p = prime_lookup[actual_number];
			}
			else
			{
				squareroot_of_act =isqrt32(actual_number)+1;
				is_p = true;

				for (i = 1; concrete_primes[i] <= squareroot_of_act ;++i)
					if( actual_number%concrete_primes[i] == 0)
					{
						is_p = false;
						break;
					}
			}
		}
		else// even numbers are not primes except 2
		{
			if(actual_number != 2)is_p = false;
			else is_p = true;
		}
		output[j]=(is_p?'1':'0');
		actual_number = (actual_number + 1234567890L) % mod;
	}while(j++<400000);
	output[j] = '\0';

	printf("%s", output);

	
	return 0;
}