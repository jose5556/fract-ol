/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:31:19 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/14 16:31:22 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (n)
	{
		((char *)s)[i] = c;
		n--;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	char str[9] = "eraumavez";
	printf("%s\n", ft_memset(str, 'z', 5));
	//printf("%s\n", memset(str, 'z', 5));
	return (0);
}
 */
