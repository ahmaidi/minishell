/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:12:14 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/08/29 17:17:57 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"

/*Free the tab of String*/
void	free_it(char **s, char *str)
{
	int	i;

	i = 0;
	free(str);
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
