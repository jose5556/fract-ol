/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:37:39 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/22 20:19:08 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main(void)
{
	t_list	*n1 = ft_calloc(1, sizeof(t_list));
	t_list	*n2 = ft_calloc(1, sizeof(t_list));
	t_list	*n3 = ft_calloc(1, sizeof(t_list));
	t_list	*n4 = ft_calloc(1, sizeof(t_list));
	
	n1->content = ft_strdup("str1");
	n1->next = n2;
	n2->content = ft_strdup("str2");
	n2->next = n3;
	n3->content = ft_strdup("str3");
	n3->next = n4;
	n4->content = ft_strdup("str4");
	printf("%s", ft_lstlast(n2)->content);
} */