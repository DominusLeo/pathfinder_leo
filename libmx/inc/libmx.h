#ifndef HEADER_H
#define HEADER_H

#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <malloc/malloc.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}               t_list;


//Utils pack
void mx_printchar(char c);//+
void mx_print_unicode(wchar_t c);//_________________________________________+-
void mx_printstr(const char *s);//+
void mx_print_strarr(char **arr, const char *delim);//______________________+?
void mx_printint(int n);//+
double mx_pow(double n, unsigned int pow);//+
int mx_sqrt(int x);//+
char *mx_nbr_to_hex(unsigned long nbr);//___________________________________+?
unsigned long mx_hex_to_nbr(const char *hex);//+
char *mx_itoa(int number);//________________________________________________+?
void mx_foreach(int *arr, int size, void (*f)(int));//+
int mx_binary_search(char **arr, int size, const char *s, int *count);//+
int mx_bubble_sort(char **arr, int size);//+
int mx_quicksort(char **arr, int left, int right);//________________________-?

//String pack
int mx_strlen(const char *s);//+
void mx_swap_char(char *s1, char *s2);//+
void mx_str_reverse(char *s);//+
void mx_strdel(char **str);//+
void mx_del_strarr(char ***arr);//+
int mx_get_char_index(const char *str, char c);//___________________________+?
char *mx_strdup(const char *s1);//+
char *mx_strndup(const char *s1, size_t n);//_______________________________+?
char *mx_strcpy(char *dst, const char *src);//+
char *mx_strncpy(char *dst, const char *src, int len);//+
int mx_strcmp(const char *s1, const char *s2);//+
char *mx_strcat(char *restrict s1, const char *restrict s2);//+
char *mx_strstr(const char *haystack, const char *needle);//+
int mx_get_substr_index(const char *str, const char *sub);//________________+?
int mx_count_substr(const char *str, const char *sub);//+
int mx_count_words(const char *str, char c);//+
char *mx_strnew(const int size);//+
char *mx_strtrim(const char *str);//________________________________________+?
char *mx_del_extra_spaces(const char *str);//_______________________________+?
char **mx_strsplit(const char *s, char c);//+
char *mx_strjoin(const char *s1, const char *s2);//+
char *mx_file_to_str(const char *file);//___________________________________+?
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);//on the end
char *mx_replace_substr(const char *str, const char *sub, const char *replace);//+?

//Memory pack
void *mx_memset(void *b, int c, size_t len);//______________________________+?
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);//__+?
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);//+?
int mx_memcmp(const void *s1, const void *s2, size_t n);//__________________+?
void *mx_memchr(const void *s, int c, size_t n);//__________________________+?
void *mx_memrchr(const void *s, int c, size_t n);//_________________________+?
void *mx_memmem(const void *big, size_t big_len, const void *little,
                                                 size_t little_len);//______+?
void *mx_memmove(void *dst, const void *src, size_t len);//_________________+?
void *mx_realloc(void *ptr, size_t size);//_________________________________+?

//List pack
t_list *mx_create_node(void *data);//_______________________________________+?
void mx_push_front(t_list **list, void *data);//___________________________+??
void mx_push_back(t_list **list, void *data);//____________________________+??
void mx_pop_front(t_list **head);//________________________________________+??
void mx_pop_back(t_list **head);//_________________________________________+??
int mx_list_size(t_list *list);//___________________________________________+?
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));//___________+?



//helpfull
int mx_strncmp(const char *s1, const char *s2, int n);//some bugs or no
char *mx_strchr(const char *s, int c);
bool mx_isdigit(int c);
bool mx_islower(int c);
bool mx_isupper(int c);
bool mx_isspace(char c);
int my_sort_arr_int(int *arr, int size);
int mx_atoi(const char *str);
void mx_sort_arr_char(char *arr[], int size);//my own
int mx_quicksort_int(int *arr, int left, int right);//my own
void mx_print_unicode_str(char *str);//my own

//void mx_printerr(const char *s);

#endif
