/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 00:50:36 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/08/25 02:46:55 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int is_Exist_on_env_list(char *arg)
{
    int i;
	char *str;

    i = 0;
	str = ft_strdup_er(arg);
	str = ft_strjoin(str, "=");
    while (g_data.env_list[i])
    {

        if (!ft_strncmp(g_data.env_list[i],str, ft_strlen(str)))
            return (i);
        i++;
    }
	free(str);
    return (-1);
}

void    delete_env(char *arg)
{
    int i;
    int j;
    char **new_env_list;
	int remove_index;

    i = 0;
    j = 0;
	remove_index = is_Exist_on_env_list(arg);
	if (remove_index == -1)
		return ;
    g_data.size_env_list -= 1;
    // printf("old env size == %d\n",g_data.size_env_list);
    new_env_list = ft_calloc(sizeof(char *) , g_data.size_env_list);

    if (!new_env_list)
        return ;
		
    while (g_data.env_list[i])
    {

        if (i == remove_index)
        {
            // free (g_data.env_list[i]);
            i++;
            continue ;
        }
        new_env_list[j] = ft_strdup(g_data.env_list[i]);
		// free (g_data.env_list[i]);
		i++;
		j++;
	}

	g_data.env_list = new_env_list;
    // printf("unsetadadadd\n");
    // i = 0;
    // while (new_env_list[i])
    // {
    //     printf("%s\n",new_env_list[i]);
    //     i++;
    // }
    
}
