
#include "libft.h"

static char	*ft_crt_word(char **str, size_t len_word, size_t i)
{
	str[i] = (char *)malloc(sizeof(char) * (len_word + 1));
	if (str[i] == NULL)
	{
		while (i > -1)
			free(str[i--]);
		free(str);
		return (NULL);
	}
	return (str[i]);
}

static size_t	ft_len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	word_count;
	size_t	len_word;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (str == NULL)
		return (NULL);
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		len_word = ft_len_word(s, c);
		str[i] = ft_crt_word(str, len_word, i);
		if (str[i] == NULL)
			return (NULL);
		ft_strlcpy(str[i++], s, len_word + 1);
		s = s + len_word;
	}
	str[i] = 0;
	return (str);
}
