#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

int point_del_pos(char *c, int size)
{
	/* Description:
	 * Take a string of number and remove 
	 * its point, then return how many 
	 * digits after the point.
	 */

	int pos = -1;
	int ret;
	for ( int i = 0; i != size; ++i ) {
		if ( c[i] == '.' ) {
			pos = i;
			break;
		}
	}
	if ( pos != -1 ) {
		for ( int i = pos; i != size - 1; ++i ) {
			c[i] = c[i + 1];
			if ( i == size - 2 ) {
				c[i + 1] = '\0';
			}
		}
		ret = size - pos - 1;
	} else
		ret = 0;
	return ret;
}

void hd_multiply(char *a, char *b)
{
	int len_active = strlen(a);	// the first number
	int len_passive = strlen(b);	// the second number
	int tmp;

	int *n1 = (int *)malloc(sizeof(int) * len_active);
	int *n2 = (int *)malloc(sizeof(int) * len_passive);
	int *n3 = (int *)malloc(sizeof(int) * len_active + len_passive);

	int p_a = point_del_pos(a, len_active); 
	int p_b = point_del_pos(b, len_passive); 

	while ( a[0] == '0' ) {
		a = a + 1;
	}
	while ( b[0] == '0' ) {
		b = b + 1;
	}

	len_active = strlen(a);
	len_passive = strlen(b);

	for ( int i = 0, j = len_active - 1; i != len_active; ++i, --j ) {
		n1[i] = a[j] - '0';
	}
	for ( int i = 0, j = len_passive - 1; i != len_passive; ++i, --j ) {
		n2[i] = b[j] - '0';
	}
	for ( int i = 0; i != len_active + len_passive; ++i ) {
		n3[i] = 0;
	}
	for ( int i = 0; i != len_active; ++i ) {
		for ( int j = 0; j != len_active; ++j ) {
			n3[i + j] += n1[i] * n2[j];
		}
	}
	for ( int i = 0; i != len_active + len_passive; ++i ) {
		if ( n3[i] >= 10 ) {
			tmp = n3[i];
			n3[i] %= 10;
			n3[i + 1] += tmp / 10;
		}
	}

	if ( n3[len_active + len_passive - 1] == 0 ) {
		for ( int i = 0, j = len_active + len_passive - 2; i != len_active + len_passive - 1; ++i, --j ) {
			printf("%d", n3[j]);
		}
	} else {
		for ( int i = 0, j = len_active + len_passive - 1; i != len_active + len_passive; ++i, --j ) {
			printf("%d", n3[j]);
		}
	}
	printf("\n");
	printf("%d\n", p_a);
	printf("%d\n", p_b);
	free(n1); free(n2); free(n3);
}

int main()
{
	char *s, *n;
	s = (char *)malloc(sizeof(char) * 300);
	n = (char *)malloc(sizeof(char) * 300);

	while ( scanf("%s%s", s, n) == 2 ) {
		hd_multiply(s,n);
	}
	return 0;
}
