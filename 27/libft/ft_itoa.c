/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyilmaz <zyilmaz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:26:02 by zyilmaz           #+#    #+#             */
/*   Updated: 2024/10/27 19:52:35 by zyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
		if (n == 0)
		return 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
static void fill_str(char *str, long nb, int len) {
    int i = len - 1;

    while (nb > 0) {
        str[i] = (nb % 10) + '0'; // Convert digit to character
        nb /= 10;
        i--;
    }
}

char *ft_itoa(int n) {
    int leng;
    char *str;
    long nb = n;

    leng = num_len(n);
    str = (char *)malloc(sizeof(char) * (leng + 1));
    if (!str) return NULL;

    str[leng] = '\0'; // Null-terminate the string

    if (nb == 0) {
        str[0] = '0'; // Handle zero
    } else if (nb < 0) {
        str[0] = '-';
        nb = -nb; // Convert to positive
        fill_str(str + 1, nb, leng - 1); // Fill the rest of the string
    } else {
        fill_str(str, nb, leng); // Fill normally
    }
    return str;
}