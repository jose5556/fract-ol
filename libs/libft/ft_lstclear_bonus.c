/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:22:17 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/22 20:08:14 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporary;

	if (!(*lst))
		return ;
	while (*lst)
	{
		temporary = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temporary;
	}
}

/*
void	delete(void *c)
{
	char *s;

	s = (char *)c;
	free(s);
}

int	main(void)
{
	t_list	*list;
	t_list  *result;

	list = ft_lstnew(ft_strdup("era"));
	list->next = ft_lstnew(ft_strdup("uma"));
	list->next->next = ft_lstnew(ft_strdup("vez"));
	result = list;
	while (result)
	{
		printf("%s\n", (char *)result->content);
		result = result->next;
	}
	ft_lstclear(&list, delete);
	
	//printf("%s", (char *)list->content);
} */