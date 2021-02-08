#include <stdio.h>

#define	FROM 0
#define	TO 300
#define	STEP 20

float f_to_c(float f);

float f_to_c(float f)
{
	return (5.0	/ 9.0) * (f	- 32.0);
}

int	main()
{
	float fahr;

	printf("%3s	%6s\n",	"F", "C");
	for	(fahr =	FROM; fahr <= TO; fahr = fahr +	STEP)
		printf("%3.0f %6.1f\n",	fahr, f_to_c(fahr));
	
	return 0;
}
