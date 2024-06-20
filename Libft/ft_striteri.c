/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaic <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:38:34 by rpaic             #+#    #+#             */
/*   Updated: 2023/10/25 19:38:36 by rpaic            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	capital_letter(unsigned int i, char *s) 
{
	if (i == 0))
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] -= 32;
		}
	}
	else if (s[i - 1] == ' ')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] -= 32;
			}
	}
}*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main()
{
	char	s[] = "prima seconda trz a";
	void	*f;
	
	//f = capital_letter;
	//s = "prima seconda trz a";
	ft_striteri(s, capital_letter);
	printf("%s\n", s);
}*/
