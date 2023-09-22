#include "shell.h"
/**
 * _sprintf - concatenates two strings
 * @str1: string 1
 * @str2: string 2
 * @str3: third string
 * Return: string
 */
char *_sprintf(const char *str1, const char *str2, const char *str3)
{
	int len1 = 0, len2 = 0, len3 = 0, result_len;
	char *result;
	int i, j, k;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	len3 = _strlen(str3);
	result_len = len1 + len2 + len3;
	result = malloc(result_len);
	if (result != NULL)
	{
		for (i = 0; i < len1; i++)
		{
			result[i] = str1[i];
		}
		for (j = 0; j < len2; j++)
		{
			result[i + j] = str2[j];
		}
		for (k = 0; k < len3; k++)
		{
			result[i + j + k] = str3[k];
		}
		result[result_len - 1] = '\0';
	}
	return (result);
}
