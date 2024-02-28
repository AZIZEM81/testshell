#include "newss.h"
#include <stdlib.h> // For malloc, free

/**
 * custom_strdup - Duplicates a string
 * @s: The string to duplicate
 *
 * Return: Pointer to the newly allocated string
 */
char *custom_strdup(const char *s) {
    if (s == NULL) return NULL;

    size_t len = 0;
    const char *temp = s;
    while (*temp != '\0') {
        len++;
        temp++;
    }

    char *dup = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the duplicate string

    if (dup == NULL) return NULL; // Check if memory allocation was successful

    char *ptr = dup;
    while (*s != '\0') {
        *ptr = *s;
        ptr++;
        s++;
    }
    *ptr = '\0'; // Add null terminator to the end of the string

    return dup;
}

/**
 * custom_strcpy - Copies a string
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to the destination buffer
 */
char *custom_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return dest;

    char *ptr = dest;
    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0'; // Add null terminator to the end of the destination string

    return dest;
}

/**
 * custom_strcat - Concatenates two strings
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to the destination buffer
 */
char *custom_strcat(char *dest, const char *src) {
    if (dest == NULL || src == NULL) return dest;

    char *ptr = dest;
    while (*ptr != '\0') {
        ptr++; // Move pointer to the end of destination string
    }

    while (*src != '\0') {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0'; // Add null terminator to the end of the destination string

    return dest;
}

/**
 * custom_strchr - Finds the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to find
 *
 * Return: Pointer to the first occurrence of the character, or NULL if not found
 */
char *custom_strchr(const char *s, int c) {
    if (s == NULL) return NULL;

    while (*s != '\0') {
        if (*s == (char)c) {
            return (char *)s; // Return pointer to the first occurrence of the character
        }
        s++;
    }

    return NULL; // Character not found
}

