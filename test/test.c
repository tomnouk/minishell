#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len_s1;
	size_t	len_s2;
	char	*original_start;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoin = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	original_start = strjoin;
	while (len_s1--)
		*strjoin++ = *s1++;
	while (len_s2--)
		*strjoin++ = *s2++;
	*strjoin = '\0';
	return (original_start);
}

int main ()
{
	char *s1 = "Hello";
	char *s2 = NULL;

	printf("%s\n", ft_strjoin(s1, s2));
}