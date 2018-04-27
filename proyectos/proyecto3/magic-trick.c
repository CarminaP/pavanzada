#include <stdio.h>

typedef long long Long;
typedef long double Double;

//to reverse the elements of the list
void reverse(Long a[], int start, int end)
{
	int i = start;
	int j = end;
	Long temp;
	while( i < j ) {
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		i++;
		j--;
	}
}

//fast multiplication for long long exceeding problem
Long multiply(Long a, Long b, Long c)
{
	Long q = (Long)((Double)a * (Double)b / (Double)c);
	return (a * b - q * c + 6 * c) % c;
}

int main() {
    int t; //number of test cases
    int n; // size of list L, size of string S
	int i; //used int the loops
	Long A, B, C; //provided by the second volunteer
	Long K, D; //Ki * L[] + Di

	scanf("%d", &t);

	while(t--)
    {
		scanf("%d", &n);

		Long L[n]; //list of integers
		char s[n+2]; //string

		for(i=0 ; i<n ; i++)
		{
			scanf("%lld", &L[i]);
		}

		scanf("%lld %lld %lld", &A, &B, &C);
		scanf("%s", s);

		i=0;
		K=1; // Identity element of multiplication
		D=0; //Identity element of addition

		// The Ancient Algorithm
		while(s[i])
		{
			if(s[i] == 'R')
			{
				reverse(L, i, n-1);
			}
			else if(s[i] == 'A')
      {
				D = (D+A)%C;
			}
			else if(s[i] == 'M')
			{
				K = multiply(K, B, C);
				D = multiply(D, B, C);
			}
			//Ki * Li[] + Di
			L[i] = multiply(L[i], K, C);
			L[i] = (L[i] + D)%C;
			i++;
		}
		for(i=0 ; i<n ; i++)
        {
			printf("%lld ", L[i]%C);
		}
	}
	return 0;
}
