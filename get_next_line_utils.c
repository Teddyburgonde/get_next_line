#include "get_next_line.h"

int ft_strlen(const char *str)
{
    int  i;

	if (!str)
   		return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++; 
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int	i;
	int	j;
	char	*tab= NULL;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (NULL);
	j = ft_strlen(s + start);
	if (j < len)
		len = j;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
