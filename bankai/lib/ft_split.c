#include "../include/includes.h"


static int	get_word_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count + 1);
}

static char	*get_next_word(int *pos, const char *s, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	i = 0;
	while (s[*pos] == c)
		(*pos)++;
	while (s[*pos + len] && s[*pos + len] != c)
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
		word[i++] = s[(*pos)++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**words;
	int		i;
	int		pos;

	if (!s)
		return (NULL);
	wc = get_word_count(s, c);
	words = malloc(wc * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < wc - 1)
		words[i++] = get_next_word(&pos, s, c);
	words[i] = 0;
	return (words);
}
