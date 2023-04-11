/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jf <jf@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:45:09 by jf                #+#    #+#             */
/*   Updated: 2023/03/23 20:47:23 by jf               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	
	i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			if (('a' <= argv[1][i] && 'y' >= argv[1][i]) || ('A' <= argv[1][i] && 'Y' >= argv[1][i])) 
			{	
				argv[1][i] = argv[1][i] + 1;
				write(1, &argv[1][i], 1);
			}	
			else if (argv[1][i] == 'z')  
			{	
				argv[1][i] = 'a';
				write(1, &argv[1][i], 1);
			}
			else if (argv[1][i] == 'Z')
			{
			
				argv[1][i] = 'A';
				write(1, &argv[1][i], 1);
			}
			else
			write(1, &argv[1][i], 1);
			i++;		
		}
	}
	write(1, "\n", 1);
}