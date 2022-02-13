/* This work is derived from the following exercise:
    https://www.linkedin.com/learning/c-code-challenges
    Performing a perfect shuffle
*/

#include <stdio.h>
#include <stdlib.h>

const int NUM_CARDS = 26;
const int FALSE = 0;

int is_value_in_deck(int *deck, int value, int deck_size)
{
    int i;

    if (deck_size > NUM_CARDS)
    {
        printf("deck_size(%i) is larger than NUM_CARDS(%i)!! Aborting!!", deck_size, NUM_CARDS);
        exit(-1);
    }
    if (deck_size == 0)
    {
        return FALSE;
    }

    for (i = 0; i < deck_size; i++)
    {
        if (deck[i] == value)
        {
            return !FALSE;
        }
    }
    return FALSE;
}

void init_deck(int *deck)
{
    int value;
    int in_deck = !FALSE;

    for (int i = 0; i < NUM_CARDS; i++)
    {
        // i elements have already been added
        in_deck = !FALSE;
        while (in_deck)
        {
            value = rand() % NUM_CARDS;
            in_deck = is_value_in_deck(deck, value, i);
        }
        deck[i] = value; // *(deck + i) = value;
    }
}

void print_deck(int *deck)
{
    for (int i = 0; i < NUM_CARDS; i++)
    {
        printf("%2i ", *(deck + i));
    }
    printf("\n");
}

int main()
{
    srand(152);
    int deck[NUM_CARDS];
    init_deck(deck);
    print_deck(deck);
}