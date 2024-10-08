/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:27:34 by joseoliv          #+#    #+#             */
/*   Updated: 2024/04/26 22:27:04 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temporary;

	if (!(*lst))
		*lst = new;
	else
	{
		temporary = ft_lstlast(*lst);
		temporary->next = new;
	}
}

/* int	main(void)
{
	t_list	*list;
	t_list	*result;

	list = NULL;
	//list = ft_lstnew("era");
	ft_lstadd_back(&list, ft_lstnew("new"));
	result = ft_lstlast(list);
	printf("%s", (char *)result->content);
}
 */