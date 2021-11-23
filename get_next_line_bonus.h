/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:19:07 by ael-bekk          #+#    #+#             */
/*   Updated: 2021/11/23 13:47:58 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define TRUE 1

void	*ft_free(char **s);
char	*read_buff(int fd, char **buff);
char	*read_line(int fd, char **buff);
char	*get_next_line(int fd);

int		find_new_line(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int end);
void	ft_new_buff(char **buff, int start);

#endif
