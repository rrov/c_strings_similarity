#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// 5 -> 5 + 4 + 3 + 2 + 1
size_t get_order_combination_count(size_t len)
{
    if (len == 0)
    {
        return len;
    }

    return len + get_order_combination_count(len - 1);
}

void substr(char* source, char* dest, size_t from, size_t to)
{
    for (size_t i = from; i < to; i++)
    {
        dest[i - from] = source[i];
    }
}

float get_strings_similarity_fraction(char* x, char* y)
{
    const size_t x_length = strlen(x);
    const size_t y_length = strlen(y);

    if (x_length == 0 || y_length == 0)
    {
        return 1.0f;
    }

    const size_t x_order_combination_count = get_order_combination_count(x_length);
    const size_t y_order_combination_count = get_order_combination_count(y_length);

    size_t matches = 0;

    size_t x_letters_template_length    = 1;
    size_t x_letters_template_start     = 0;
    size_t x_letters_template_end       = 1;

    size_t y_letters_template_length    = 1;
    size_t y_letters_template_start     = 0;
    size_t y_letters_template_end       = 1;

    size_t iterations = 0;

    if (x_order_combination_count > y_order_combination_count)
    {
        iterations = x_order_combination_count;
    }
    else
    {
        iterations = y_order_combination_count;
    }

    bool x_iteration_is_over = false;
    bool y_iteration_is_over = false;
    
    for (size_t i = 0; i < iterations; i++)
    {
        if (!x_iteration_is_over)
        {
            const size_t substring_length = x_letters_template_end - x_letters_template_start;
            char x_substring[substring_length + 1];

            substr(x, x_substring, x_letters_template_start, x_letters_template_end);
            x_substring[substring_length] = '\0';

            if (x_substring == NULL)
            {
                x_iteration_is_over = true;
            }

            if (strstr(y, x_substring) != NULL)
            {
                matches++;
            }

            if (x_letters_template_end >= x_length)
            {
                if (x_letters_template_length >= x_length)
                {
                    x_iteration_is_over = true;
                }
                else
                {
                    x_letters_template_length++;
                    x_letters_template_start = 0;
                    x_letters_template_end = x_letters_template_start + x_letters_template_length;
                }
            }
            else
            {
                x_letters_template_start++;
                x_letters_template_end++;
            }
        }
        
        if (!y_iteration_is_over)
        {
            const size_t substring_length = y_letters_template_end - y_letters_template_start;
            char y_substring[substring_length + 1];

            substr(y, y_substring, y_letters_template_start, y_letters_template_end);
            y_substring[substring_length] = '\0';

            if (y_substring == NULL)
            {
                y_iteration_is_over = true;
            }

            if (strstr(x, y_substring) != NULL)
            {
                matches++;
            }

            if (y_letters_template_end >= y_length)
            {
                if (y_letters_template_length >= y_length)
                {
                    y_iteration_is_over = true;
                }
                else
                {
                    y_letters_template_length++;
                    y_letters_template_start = 0;
                    y_letters_template_end = y_letters_template_start + y_letters_template_length;
                }
            }
            else
            {
                y_letters_template_start++;
                y_letters_template_end++;
            }
        }
    }

    return (float)((double)matches / ((double)x_order_combination_count + (double)y_order_combination_count));
}
