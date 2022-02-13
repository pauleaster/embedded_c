
#include <stdio.h>
#include <stdlib.h>

const char *FORMAT_STR = "%5.2f %5.2f %5.2f";

char *ordinal(int i)
{

    int tens, units, mod_tens;
    size_t num_chars;
    char *result = "00";

    units = i % 10;
    tens = i / 10;
    mod_tens = tens % 10;

    if (mod_tens == 1)
    {
        result = "th";
        return result;
    }

    switch (units)
    {
    case 0:
    case 4 ... 9:
        result = "th";
        break;
    case 1:
        result = "st";
        break;
    case 2:
        result = "nd";
        break;
    case 3:
        result = "rd";
        break;
    }
    return result;
}

int main(void)
{

    int i;

    for (i = 1; i <= 200; i++)
    {
        printf(" %3d%s ", i, ordinal(i));
        if ((i % 20) == 0)
        {
            printf("\n");
        }
    }
    return 0;
}