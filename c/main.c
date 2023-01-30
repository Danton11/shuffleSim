#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define DECK_SIZE (NUM_SUITS * NUM_RANKS)

const char *suits[] = {"clubs", "spades", "diamonds", "hearts"};
const char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

// Card object
typedef struct
{
    int suit;
    int rank;
} Card;

// Initialize deck of cards in order
void initializeDeck(Card *deck)
{
    int i, j;
    for (i = 0; i < NUM_SUITS; i++)
    {
        for (j = 0; j < NUM_RANKS; j++)
        {
            deck[i * NUM_RANKS + j].suit = i;
            deck[i * NUM_RANKS + j].rank = j;
        }
    }
}

// Perform non-perfect riffle shuffle
void nonPerfectRiffleShuffle(Card *deck)
{
    int i, j;
    Card tempDeck[DECK_SIZE];
    int deckIndex = 0;
    int halfDeckSize = DECK_SIZE / 2;

    // Split deck into two halves
    for (i = 0; i < halfDeckSize; i++)
    {
        tempDeck[deckIndex++] = deck[i];
        tempDeck[deckIndex++] = deck[i + halfDeckSize];
    }

    // Interleave cards randomly
    for (i = 0; i < DECK_SIZE; i++)
    {
        int randomIndex = rand() % (deckIndex--);
        deck[i] = tempDeck[randomIndex];
        for (j = randomIndex; j < deckIndex; j++)
        {
            tempDeck[j] = tempDeck[j + 1];
        }
    }
}

// Print deck of cards
void printDeck(Card *deck)
{
    int i;
    for (i = 0; i < DECK_SIZE; i++)
    {
        printf("%s of %s\n", ranks[deck[i].rank], suits[deck[i].suit]);
    }
}

int main()
{
    srand(time(NULL));

    // Allocate memory for deck of cards
    Card *deck = (Card *)malloc(DECK_SIZE * sizeof(Card));

    // Initialize deck of cards
    initializeDeck(deck);

    // Perform non-perfect riffle shuffle
    nonPerfectRiffleShuffle(deck);

    // Print deck of cards
    printDeck(deck);

    // Free memory
    free(deck);

    return 0;
}
