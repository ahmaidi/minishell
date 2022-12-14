/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmez-za <ahmez-za@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:53:27 by ahmaidi           #+#    #+#             */
/*   Updated: 2022/08/29 15:45:20 by ahmez-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parsing.h"
/*
intialize a lexer ==> intialize lexer->c && lexer->index && lexer->contents
*/
t_lexer	*init_lexer(char *contents)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	if (!lexer)
		ft_error(errno);
	lexer->i = 0;
	lexer->c = contents[lexer->i];
	lexer->contents = contents;
	lexer->exit_status = g_data.exit_status;
	lexer->is_ambg = 0;
	lexer->split_lexer = 0;
	lexer->env_vide = 0;
	return (lexer);
}

/*
	move to the next character in  lexer->contents
*/

void	lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->contents))
	{
		lexer->i++;
		lexer->c = lexer->contents[lexer->i];
	}
}

/*
	skip all White spaces and tabulation
*/

void	lexer_skip_white_spaces(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t')
		lexer_advance(lexer);
}

/*
	get the next token 
*/

t_tocken	*lexer_advc_tocken(t_lexer *lexer, t_tocken *tocken)
{
	lexer_advance(lexer);
	return (tocken);
}

/*
	check a type of tocken 
*/

t_tocken	*lexer_get_next_tocken(t_lexer *lexer)
{
	while (lexer->c != '\0')
	{
		lexer->is_ambg = 0;
		lexer->env_vide = 0;
		lexer->split_lexer = 0;
		if (lexer->c == ' ' || lexer->c == '\t')
			lexer_skip_white_spaces(lexer);
		else if (lexer->c == '|')
			return (lexer_advc_tocken(lexer,
					init_tocken(TOCKEN_PIPE, ft_strdup("|"))));
		else if (lexer->c == '>')
			return (collect_redirect_g(lexer));
		else if (lexer->c == '<')
			return (collect_redirect_l(lexer));
		else if (lexer->c != ' ' && lexer->c != '\t')
			return (lexer_collect_string(lexer));
	}
	return (init_tocken(TOCKEN_EOF, ft_strdup_er("newline")));
}
