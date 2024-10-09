/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:09:01 by joseoliv          #+#    #+#             */
/*   Updated: 2024/10/09 03:26:41 by joseoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

t_list	*ft_newlst(int content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc(sizeof(t_list));
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, int content)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = ft_newlst(content);
	if (!new_node)
		return ;
	if (!(*lst))
	{
		*lst = new_node;
		new_node->next = *lst;
	}
	else
	{
		temp = *lst;
		while (temp->next != *lst && temp->next)
			temp = temp->next;
		temp->next = new_node;
		new_node->next = *lst;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*next_node;

	temp = *lst;
	if (!(*lst))
		return ;
	while (temp->next != *lst)
		temp = temp->next;
	temp->next = NULL;
	temp = *lst;
	while (temp)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
	*lst = NULL;
}
