/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:24:14 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/03/15 16:18:25 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (32 <= str[i] && 127 > str[i])
			i++;
		else
			return (0);
	}
	return (1);
}

/*
int	main(void)
{
	char	*str1;
	char	*str2;
	char	*str3;	
	char	*str4;
	char	*str5;
	
	str1 = "";
	printf("%i\n", ft_str_is_printable(str1));
	str2 = calloc(11, sizeof(char));
	str2 = "A\1jhsad2gd";
	printf("%i\n", ft_str_is_printable(str2));
	str3 = calloc(11, sizeof(char));
	str3 = "3hs,\adgrkdj";
	printf("%i\n", ft_str_is_printable(str3));	
	str4 = calloc(11, sizeof(char));
	str4 = "AJHEFCUGJD";
	printf("%i\n", ft_str_is_printable(str4));
	str5 = calloc(11, sizeof(char));
	str5 = "1452145794";
	printf("%i\n", ft_str_is_printable(str5));
}
*/