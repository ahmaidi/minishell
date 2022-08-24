/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:33:41 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/08/24 04:59:47 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/parsing.h"

int	read_cmd_line(char **cmd)
{
	*cmd = readline("\033[32mMinishell$ \033[0m");
	if (*cmd == NULL)
	{
		write(1, "\033[91mMinishell$ Exit\033[0m\n", 26);
		exit(EXIT_SUCCESS);
	}
	if (cmd[0][0] == '\0')
	{
		free(*cmd);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_pipes		*ast;
	t_parser	*parser;
	char		*cmd_line;

	(void)ac;
	(void)av;
	env_variable(env);
	while (1)
	{
		if (!read_cmd_line(&cmd_line))
			continue ;
		add_history(cmd_line);
		check_error_max_here_doc(cmd_line);
		parser = init_parser(cmd_line);
		ast = parser_parse(parser);
		free_parser(parser);
		// visitor(ast);
		if (ast)
		{
			ft_herdoc(ast);
			execution(ast, env);
			free_ast_pipe(ast);
		}
		// free (ast->tab_cmd[0]->args[0]);
		// free(g_data.env_list[5]);
		//system("leaks minishell");
	}
	return (g_data.exit_status);
}
