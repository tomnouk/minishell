/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:21:20 by rpaic             #+#    #+#             */
/*   Updated: 2024/08/09 15:53:10 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*strjoin_free(char *s1, char *s2, int frees);
void	free_all(t_data *data);
t_data	initialize_data(void);
int		check_if_empty(char *args);
void	prompt_loop(t_data *data);
void	reinitialize_data(t_data *data);

#endif