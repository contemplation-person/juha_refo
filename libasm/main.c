#include <stdio.h>
#include <string.h>

#include "libasm.h"

int main() {
	char *test = "test";
	char test_cpy[10];
	char *null = "";

	printf("real strlen : %d\n", strlen("test"));
	printf("my strlen : %d\n", ft_strlen("test"));
	
	printf("-----------------------------------------\n");

	printf("1. my strcmp: %d\n", ft_strcmp("test", "test"));
	printf("1. real strcmp %d\n", strcmp("test", "test"));

	printf("2. my strcmp: %d\n", ft_strcmp("test2","test"));
	printf("2. real strcmp: %d\n", strcmp("test2","test"));

	printf("3. my strcmp: %d\n", ft_strcmp("aets","test"));
	printf("3. real strcmp: %d\n", strcmp("aets","test"));

	printf("4. my strcmp: %d\n", ft_strcmp("tet","test"));
	printf("4. real strcmp: %d\n", strcmp("tet","test"));

	printf("-----------------------------------------\n");

	printf("1. my strcpy: %d\n", ft_strcpy(test_cpy, test));
	printf("1. my strcpy result: %s\n", test_cpy);

	printf("1. real strcpy: %d\n", strcpy(test_cpy, test));
	printf("1. real strcpy result: %s\n", test_cpy);

	printf("2. my strcpy: %d\n", ft_strcpy(test_cpy, null));
	printf("2. my strcpy result: %s\n", test_cpy);

	printf("2. real strcpy: %d\n", strcpy(test_cpy, null));
	printf("2. real strcpy result: %s\n", test_cpy);
	
//	printf("3. my strcpy: %d\n", ft_strcpy(test_cpy, NULL));
//	printf("3. my strcpy result: %s\n", test_cpy);

//	printf("3. real strcpy: %d\n", strcpy(test_cpy, NULL));
//	printf("3. real strcpy result: %s\n", test_cpy);
}
