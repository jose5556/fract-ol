/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:24:09 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/22 18:55:14 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temporary;
	t_list	*result;
	void	*arrow;

	result = NULL;
	while (lst)
	{
		arrow = f(lst->content);
		temporary = ft_lstnew(arrow);
		if (!temporary)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, temporary);
		lst = lst->next;
	}
	return (result);
}
