/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgargant <dgargant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:03:46 by dgargant          #+#    #+#             */
/*   Updated: 2024/09/17 14:28:25 by dgargant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strdup(const char *s1);

char	**ft_split(char const *s, char c);

int		ft_printf(char const *str, ...);

int		ft_putchar(char c);

int		ft_putstr(char *str);

int		ft_putnbr(int n);

int		ft_putunbr(unsigned int n);

int		ft_puthexadecimal_lowercase(unsigned int n);

int		ft_puthexadecimal_uppercase(unsigned int n);

int		ft_putpadress(size_t n);

size_t	ft_strlen(const char *s);

void	*ft_free_array(char **array);

char	*ft_strjoin(const char *s1, const char *s2);

#endif