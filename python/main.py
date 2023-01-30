
import random
import unittest

class Card: # card object with a value and suit, i.e (3,hearts)
    def __init__(self, value, suit):
        match value: # switch statement for card generation
            case 1: # if an ace
                self.value = 'Ace'
            case 11:
                self.value = 'Jack'
            case 12:
                self.value = 'Queen'
            case 13:
                self.value = 'King'
            case _:
                self.value = value
            

        self.suit = suit


def non_perfect_riffle_shuffle(deck):
    """
    Performs a non-perfect riffle shuffle on a deck of cards.
    :param deck: list of elements representing a deck of cards
    :return: list of elements representing a shuffled deck of cards
    """
    # Split the deck into two halves
    deck1 = deck[:len(deck)//2]
    deck2 = deck[len(deck)//2:]

    # Initialize the shuffled deck
    shuffled_deck = []

    # Alternate randomly taking cards from deck1 and deck2
    while deck1 and deck2:
        if random.random() < 0.5:
            shuffled_deck.append(deck1.pop(0))
        else:
            shuffled_deck.append(deck2.pop(0))

    # Add the remaining cards from the non-empty deck to the shuffled deck
    shuffled_deck.extend(deck1)
    shuffled_deck.extend(deck2)

    return shuffled_deck


def perfect_riffle_shuffle(deck):
    """
    Performs a perfect riffle shuffle on a deck of cards.
    :param deck: list of elements representing a deck of cards
    :return: list of elements representing a shuffled deck of cards
    """
    middle_point = len(deck) // 2

    # Split the deck into two halves
    deck, second_deck = deck[:middle_point], deck[middle_point:] # first card up to middle point, middle to the last card


    # Take elements from the second deck and add them to the correct place in the first deck
    for index, item in enumerate(second_deck):

        # finds the index in the other half of the deck and adds 1 to find where to insert
        insert_index = index*2 + 1 
        
        deck.insert(insert_index, item)

    return deck





if __name__ == '__main__':
    suits = ['hearts', 'diamonds', 'spades', 'clubs']
    ordered_deck = [Card(value, suit) for value in range(1, 14) for suit in suits] # list comp to generate a list of Card objects with a range of values

    print("Perfect riffle shuffle:")

    #output the deck following the perfect riffle shuffle
    for card in (perfect_riffle_shuffle(ordered_deck)):
        print(f"{card.value} of {card.suit}")

    print("Non-Perfect riffle shuffle:")
    # output the deck following the non-perfect riffle shuffle
    for card in (non_perfect_riffle_shuffle(ordered_deck)):
        print(f"{card.value} of {card.suit}")





# Testing 

class RiffleTestCase(unittest.TestCase):
    def test_perfect_riffle_shuffle(self):
        """
        Tests the perfect_riffle_shuffle function with a simple deck of cards.
        """
        riffleEight = perfect_riffle_shuffle(perfect_riffle_shuffle(perfect_riffle_shuffle(perfect_riffle_shuffle(
            perfect_riffle_shuffle(perfect_riffle_shuffle(perfect_riffle_shuffle(perfect_riffle_shuffle(ordered_deck))))))))
        # eight perfect riffle shuffles on any deck generates the oringal deck
        self.assertEqual(ordered_deck, riffleEight)

        # Create a deck of cards as a list of integers from 1 to 10
        deck = list(range(1, 11))

        # Call the perfect_riffle_shuffle function with the deck
        shuffled_deck = perfect_riffle_shuffle(deck)

        # Assert that the original deck and the shuffled deck are not equal
        self.assertNotEqual(deck, shuffled_deck)

        # Assert that the lengths of the original deck and the shuffled deck are equal
        self.assertEqual(len(deck), len(shuffled_deck))

        # Assert that the shuffled deck satisfies the perfect riffle shuffle pattern
        for i in range(len(deck)//2):
            self.assertEqual(shuffled_deck[2*i], deck[i])
            self.assertEqual(shuffled_deck[2*i + 1], deck[i + len(deck)//2])

    def test_non_perfect_riffle_shuffle(self):
        """
        Tests the non_perfect_riffle_shuffle function with a simple deck of cards.
        """
        # Create a deck of cards as a list of integers from 1 to 10
        deck = list(range(1, 11))

        # Call the non_perfect_riffle_shuffle function with the deck
        shuffled_deck = non_perfect_riffle_shuffle(deck)

        # Assert that the original deck and the shuffled deck are not equal
        self.assertNotEqual(deck, shuffled_deck)

        # Assert that the lengths of the original deck and the shuffled deck are equal
        self.assertEqual(len(deck), len(shuffled_deck))

        # Assert that all elements in the original deck are in the shuffled deck and vice versa
        self.assertCountEqual(deck, shuffled_deck)



unittest.main()