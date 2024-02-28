#include "newss.h"

/**
 * duplicate_string - Create a duplicate of a given string.
 * @s: The string to duplicate.
 *
 * Returns: A pointer to the duplicated string, or NULL on failure.
 */
char *duplicate_string(const char *s) {
	// Implementation goes here
	char *duplicate = NULL;
	size_t len = _strlen(s) + 1;
	duplicate = malloc(len);
	if (duplicate) {
		for (size_t i = 0; i < len; i++) {
			duplicate[i] = s[i];
		}
	}
	return duplicate;
}

/**
 * copy_string - Copy the contents of one string to another.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Returns: A pointer to the destination string.
 */
char *copy_string(char *dest, const char *src) {
	// Implementation goes here
	char *start = dest;
	while ((*dest++ = *src++))
		;
	return start;
}

/**
 * concatenate_strings - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Returns: A pointer to the destination string.
 */
char *concatenate_strings(char *dest, const char *src) {
	// Implementation goes here
	while (*dest) {
		dest++;
	}
	while ((*dest++ = *src++))
		;
	return dest;
}

/**
 * find_character - Find the first occurrence of a character in a string.
 * @s: The string to search in.
 * @c: The character to find.
 *
 * Returns: A pointer to the first occurrence of the character, or NULL if not found.
 */
char *find_character(const char *s, int c) {
	// Implementation goes here
	while (*s && *s != c) {
		s++;
	}
	return (*s == c) ? (char *)s : NULL;
}

