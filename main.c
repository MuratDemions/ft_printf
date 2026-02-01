#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    printf("[%d]\n", printf("%c", 'a'));
	printf("[%d]\n", ft_printf("%c", 'a'));
	printf("[%d]\n", printf("%d", 42));
	printf("[%d]\n", ft_printf("%d", 42));
	printf("[%d]\n", printf("%s", "Murat"));
	printf("[%d]\n", ft_printf("%s", "Murat"));
	printf("[%d]\n", ft_printf("Murat"));
	printf("[%d]\n", printf("%u", 142));
	printf("[%d]\n", ft_printf("%u", 142));
	printf("[%d]\n", printf("%x", 99999));
	printf("[%d]\n", ft_printf("%x", 99999));
	printf("[%d]\n", printf("%X", 99999));
	printf("[%d]\n", ft_printf("%X", 99999));
    printf("[%d]\n", printf("%p", "a"));
	printf("[%d]\n", ft_printf("%p", "a"));
    printf("[%d]\n", printf((void *)0));
	printf("[%d]\n", ft_printf((void *)0));
	printf("[%d]\n", printf("%c%s%p%d%i%u%x%X", 'a',"samet","asd",142,1142,11142,111142,1111142));
	printf("[%d]\n", ft_printf("%c%s%p%d%i%u%x%X", 'a',"samet","asd",142,1142,11142,111142,1111142));
    return 0;
}
