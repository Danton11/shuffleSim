// Creating an enumeration of suits
enum Suit {
    CLUBS, SPADES, DIAMONDS, HEARTS
}

// Card class representing a single card
class Card {
    String value;
    Suit suit;

    public Card(String value, Suit suit) {
        this.value = value;
        this.suit = suit;
    }
}

// Class representing a deck of cards
class Deck {
    private Card[] deck;
    private int top;

    public Deck() {
        deck = new Card[52];
        int index = 0;
        String[] values = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

        for (String value : values) {
            for (Suit suit : Suit.values()) {
                deck[index++] = new Card(value, suit);
            }
        }
        top = 51;
    }

    // Method for performing a single pass of non-perfect riffle shuffle
    public void shuffle() {
        int mid = top / 2;
        int l = 0, r = mid + 1;
        Card[] shuffledDeck = new Card[52];
        int index = 0;

        while (l <= mid && r <= top) {
            if (Math.random() < 0.5) {
                shuffledDeck[index++] = deck[l++];
            } else {
                shuffledDeck[index++] = deck[r++];
            }
        }
        while (l <= mid) {
            shuffledDeck[index++] = deck[l++];
        }
        while (r <= top) {
            shuffledDeck[index++] = deck[r++];
        }
        deck = shuffledDeck;
    }

    // Method to print the deck of cards
    public void printDeck() {
        for (int i = 0; i <= top; i++) {
            System.out.println(deck[i].value + " of " + deck[i].suit);
        }
    }

    public static void main(String[] args) {
        // Create a deck of cards
        Deck deck = new Deck();

        // Perform a non-perfect riffle shuffle
        deck.shuffle();

        // Print the shuffled deck of cards
        System.out.println("Shuffled deck of cards: ");
        deck.printDeck();
    }

}
