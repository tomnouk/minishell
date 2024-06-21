/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 22:03:40 by aeid              #+#    #+#             */
/*   Updated: 2024/06/21 22:52:09 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "minishell.h"

void expander(t_list *mini_env, int variable_len, char **tkn_str, t_types tkn_type);
char *search_env(t_list *mini_env, char *variable);

#endif