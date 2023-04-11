/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrocha-v <jrocha-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:09:40 by jrocha-v          #+#    #+#             */
/*   Updated: 2023/03/28 15:39:37 by jrocha-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_sl(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	k;

	i = -1;
	while (base[++i] != '\0')
	{
		k = 0;
		while (k < i)
		{
			if (base[k] == base[i])
				return (0);
			k++;
		}
	}
	i = -1;
	while (base[++i] != '\0')
	{
		if (base[i] == '\0' || base[i] == '+'
			|| base[i] == '-'
			|| ft_sl(base) <= 1)
			return (0);
		else
			return (1);
	}
	return (1);
}

int	ft_convert(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_number_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (base[i] == c)
		return (1);
	return (0);
}

char *ft_convert_to(int nb, char *base_to, char *l_out)
{
	long	n;
	unsigned int			j;
	static unsigned int		k;

	j = ft_sl(base_to);
	if (nb < 0)
	{
		k = 0;
		n = -nb;
		l_out[0] = '-';
	}
	else
		n = nb;
	if (n >= j)
		ft_convert_to((n / j), base_to, l_out);
	if (l_out[0] == '-' && k <= 0)
		k = 0;
	l_out[++k] = base_to[n % j];
	l_out[k + 1] = '\0';
	return (l_out);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*l_out;
	int 	i;
	int 	sign;
	long 	n_cv;

	i = 0;
	sign = 1;
	n_cv = 0;
	l_out = malloc(40);
	if (ft_check_base(base_from) == 0 || ft_check_base(base_to) == 0)
		return (NULL);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '+' || nbr [i] == '-')
		if (nbr[i++] == '-')
			sign = sign * -1;
	if ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		return (0);
	while (nbr[i] && ft_number_in_base(nbr[i], base_from))
	{
		n_cv = n_cv * ft_sl(base_from);
		n_cv = n_cv + ft_convert(nbr[i], base_from);
		i++;
	}
	return (ft_convert_to((n_cv * sign), base_to, l_out));
}

/*int	main(void)
{
	printf("%s", ft_convert_base("    +--28a", "0123456789abcdef", "0123456789"));
	return (0);
}*/

int		main(void)
{
	char nbr[] = "-+--11112111";
	char base_to[] = "0123456789abcdef";
	char base_from[] = "01";
	char *res;

	res = ft_convert_base(nbr, base_from, base_to);
	if (res == NULL)
		return (1);
	printf("%s\n", res);
	free(res);
	return (0);
}