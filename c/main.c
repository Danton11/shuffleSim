#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define CARDS_IN_SUIT 13
#define NUM_CARDS (NUM_SUITS * CARDS_IN_SUIT)

const char *suits[] = {"Clubs", "Spades", "Diamonds", "Hearts"};
const char *ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

typedef struct
{
    int suit;
    int rank;
} Card;

// Create a new deck of cards
Card *create_deck()
{
    Card *deck = (Card *)malloc(NUM_CARDS * sizeof(Card));
    int i = 0;
    for (int s = 0; s < NUM_SUITS; s++)
    {
        for (int r = 0; r < CARDS_IN_SUIT; r++)
        {
            deck[i].suit = s;
            deck[i].rank = r;
            i++;
        }
    }
    return deck;
}

// Display the deck of cards
void display_deck(Card *deck)
{
    for (int i = 0; i < NUM_CARDS; i++)
    {
        printf("%s of %s\n", ranks[deck[i].rank], suits[deck[i].suit]);
    }
}

// Free the memory used by the deck
void free_deck(Card *deck)
{
    free(deck);
}

// Perform a non-perfect riffle shuffle
void shuffle(Card *deck)
{
    srand(time(NULL));
    int half = NUM_CARDS / 2;
    int shuffle_index = 0;
    Card *shuffled_deck = (Card *)malloc(NUM_CARDS * sizeof(Card));
    for (int i = 0; i < half; i++)
    {
        if (rand() % 2 == 0)
        {
            shuffled_deck[shuffle_index++] = deck[i];
            shuffled_deck[shuffle_index++] = deck[i + half];
        }
        else
        {
            shuffled_deck[shuffle_index++] = deck[i + half];
            shuffled_deck[shuffle_index++] = deck[i];
        }
    }
    for (int i = 0; i < NUM_CARDS; i++)
    {
        deck[i] = shuffled_deck[i];
    }
    free(shuffled_deck);
}

int main()
{
    Card *deck = create_deck();
    printf("Original deck:\n");
    display_deck(deck);
    printf("\n");
    shuffle(deck);
    printf("Shuffled deck:\n");
    display_deck(deck);
    free_deck(deck);
    return 0;
}
