#include <iostream>
#include <stdlib.h>     // rand
#include <time.h>       // time
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

enum Suit {NONE, CLUBS, HEARTS, DIAMONDS, SPADES};
enum hand_type {NOTHING, PAIR, TWO_PAIR, THREE_OF_A_KIND,
											 FULL_HOUSE, FOUR_OF_A_KIND};

const int MAX_HAND_SIZE = 7;
class Card
{
public:
    int value;
    Suit suit;
};

class CardHand
{
private:
	Card hand[MAX_HAND_SIZE];
	hand_type current_type;
	int HandSize;
	void SortCards (Card hand[], int size)
	{
		int max_value = hand[0].value, max_index = 0;
		//every value will always be larger than 0
		Card sorted_hand[size];
		for (int sort_card_index = 0; sort_card_index < size; sort_card_index++)
		{
			max_value = 0;
		for (int card_index = 0; card_index < size; card_index++)
		{
			if (hand[card_index].value > max_value)
			{
				sorted_hand[sort_card_index].value = hand[card_index].value;
				sorted_hand[sort_card_index].suit = hand[card_index].suit;
				max_value = hand[card_index].value;
				max_index = card_index;
			}
		}
		hand[max_index].value = 0; //every value will always be larger than 0
		}
		for (int card_index = 0; card_index < size; card_index++)
		{
		int repetition = 0, max_index = 0, repetition_index = 0;
		repetition_index = card_index;
		while (sorted_hand[card_index].value == 
			sorted_hand[repetition_index].value)
			{
				repetition_index++;
			}
		max_value = 0;
		for (int sort_card_index = 0; sort_card_index < repetition_index &&
									 sort_card_index < size; sort_card_index++)
		{
			if (sorted_hand[sort_card_index].suit > max_value)
			{
				hand[card_index].value = sorted_hand[sort_card_index].value;
				hand[card_index].suit = sorted_hand[sort_card_index].suit;
				max_value = sorted_hand[sort_card_index].suit;
				max_index = sort_card_index;
			}
		}
		sorted_hand[max_index].suit = NONE;
		}
	}

public:
	CardHand()
	{
		HandSize = 5;
		for (int card_index = 0; card_index < 5; card_index++)			
		{
			hand[card_index].value = 0; //value of 0 no card at that index
		}
		for (int card_index = 5; card_index < MAX_HAND_SIZE; card_index++)
		{
			hand[card_index].value = -1; //value of -1 means don't use these
										// spaces in this card game
		}
	}
	CardHand(int size) //make sure to only call this constructor once
	{
		if (size > 0 && size <= 7) 
		//from http://www.wsop.com/poker-games/ find max hand size is 7
		{
			HandSize = size;
			for (int card_index = 0; card_index < size; card_index++)
			{
				hand[card_index].value = 0;
			}
			for (int card_index = size; 
									card_index < MAX_HAND_SIZE; card_index++)
			{
				hand[card_index].value = -1;
			}
		}
		else
		{
			CardHand();
		}
	}
	int GetHandSize() const;
    bool AddCard(Card new_card)
    {
    	bool FullHand = true;
    	int card_index = 0, empty_index = 0;
    	while (FullHand == true && card_index < HandSize)
    	{
    		FullHand = true;
    		if (hand[card_index].value == 0)
    		{
    			FullHand = false;
    			empty_index = card_index;
			}
			card_index++;
		}
		if (FullHand == true)
		{
			return false;
		}
		hand[empty_index].value = new_card.value;
		hand[empty_index].suit = new_card.suit;
		return true;
	}
	hand_type type_of_hand ()
	//returns probability of hand in hand_type, only able to do:
	//four of a kind, full house, three of a kind, two pairs and one pair.
	{
		int repetition = 0, repetition_index = 0, number_of_repetitions = 0;
		int card_index = 0, max_repetition = 0;
		current_type = NOTHING;
		SortCards(hand, HandSize);
		while (card_index < HandSize)
		{
			repetition = 0;
			while (hand[card_index].value == hand[repetition_index].value)
			{
				repetition_index++;
				repetition++;
			}
			if (repetition >= 2)
			{
				number_of_repetitions++;
			}
			
			if (repetition > max_repetition)
			{
				max_repetition = repetition;
			}
			card_index = repetition_index;
		}
		//assume use the traditional high poker rankings
		//using poker probabilities http://mathworld.wolfram.com/Poker.html
		if (max_repetition == 4)//meanning 4 of a kind
		{
			current_type = FOUR_OF_A_KIND;
		}
		else if (max_repetition == 3 && number_of_repetitions == 2)//full house
		{
			current_type = FULL_HOUSE;	
		}
		else if (max_repetition == 3 && number_of_repetitions == 1)//3 of a kind
		{
			current_type = THREE_OF_A_KIND;
		}
		else if (max_repetition == 2 && number_of_repetitions == 2)//two pair
		{
			current_type = TWO_PAIR;
		}
		else if (max_repetition == 2 && number_of_repetitions == 1)//one pair
		{
			current_type = PAIR;
		}
		return current_type;
	}
	int best_hand (CardHand compare_hand)
	{
		if (type_of_hand() > compare_hand.type_of_hand())
		{
			return 1;
		}
		if (type_of_hand() < compare_hand.type_of_hand())
		{
			return -1;
		}
		return 0;
	}

	void output_cards (ostream & output_type)
	{
		if (type_of_hand() == NOTHING)
		output_type << "Horrible Hand" << endl;
		if (type_of_hand() == PAIR)
		{ //why does type_of_hand() work but not current_type
			output_type << "Pair" << endl;
		}
		if (type_of_hand() == TWO_PAIR)
		{
			output_type << "Two Pair" << endl;
		}
		if (type_of_hand() == THREE_OF_A_KIND)
		{
			output_type << "Three of a Kind" << endl;
		}
		if (type_of_hand() == FULL_HOUSE)
		{
			output_type << "Full House" << endl;
		}
		if (type_of_hand() == FOUR_OF_A_KIND)
		{
			output_type << "Four of a Kind" << endl;
		}
		output_type << "Value" << setw(8) << "Suit" << endl;
		for (int hand_index = 0; hand_index < HandSize; hand_index++)
		{
			output_type << setw(2);
			if (hand[hand_index].value == 1)
			{
				output_type << " A";
			}
			else if (hand[hand_index].value == 11)
			{
				output_type << " J";
			}
			else if (hand[hand_index].value == 12)
			{
				output_type << " Q";
			}
			else if (hand[hand_index].value == 13)
			{
				output_type << " K";
			}
			else
			{
				output_type << hand[hand_index].value;
			}
			output_type << setw(13);
			if (hand[hand_index].suit == 1)
			{
				output_type << "Clubs";
			}
			if (hand[hand_index].suit == 2)
			{
				output_type << "Hearts";
			}
			if (hand[hand_index].suit == 3)
			{
				output_type << "Diamonds";
			}
			if (hand[hand_index].suit == 4)
			{
				output_type << "Spades";
			}
			output_type << endl;
		}
	}
};
bool DealCards(CardHand hands[], int num_hands)
{
    // check if there are enough cards (only 52 cards available)
    int cards_needed = 0;
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        cards_needed += hands[hand_index].GetHandSize();
    }
    if (cards_needed > 52)
        return false;

    const int NUM_CARDS = 52;
    Card deck[NUM_CARDS];
    int current_value = 1;
    Suit current_suit = CLUBS;

    // create the deck of cards
    for (int card_index = 0; card_index < NUM_CARDS; card_index++)
    {
        deck[card_index].value = current_value;
        deck[card_index].suit = current_suit;

        current_value++;
        if (current_value > 13)
        {
            switch (current_suit)
            {
                case CLUBS: current_suit = HEARTS;
                    break;
                case HEARTS: current_suit = DIAMONDS;
                    break;
                case DIAMONDS: current_suit = SPADES;
                    break;
                default: break;
            }
            current_value = 1;
        }
    }

    // seed the random number generator
    srand(time(NULL));

    // randomly pull cards from the deck and assign them to each hand
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        for (int card_index = 0; card_index < hands[hand_index].GetHandSize(); card_index++)
        {
            Card assign_card;
            assign_card.value = 0;
            assign_card.suit = NONE;

            while (assign_card.value == 0)
            {
                int try_card = rand() % 52;

                if (deck[try_card].value > 0)
                {
                    assign_card.value = deck[try_card].value;
                    assign_card.suit = deck[try_card].suit;
                    deck[try_card].value = 0;
                    deck[try_card].suit = NONE;
                }
            }

            hands[hand_index].AddCard(assign_card);
        }
    }
    return true;
}
int sum_comparison (CardHand hand[], int players, int player_index)
{
	int sum = 0;
	for (int hand_index = 0; hand_index < players; hand_index++)
	{
		sum += hand[player_index].best_hand(hand[hand_index]);
		//no need to worry about sum with itself as compare just returns 0
	}
	return sum;
}
int main()
{
	const int PLAYERS = 4;
	CardHand Ben_hand;
	CardHand Brendan_hand;
	CardHand Niel_hand;
	CardHand Sam_hand;
	CardHand Hands[PLAYERS] = {Ben_hand, Brendan_hand,
											 Niel_hand, Sam_hand};
	DealCards (Hands, PLAYERS);
	int best_hand_index = 1; //if no one is a set winner, then default to me
	int max_sum = 0, max_sum_index = 0;
	max_sum = sum_comparison(Hands,PLAYERS, 0);
	for(int sum_index = 0; sum_index < PLAYERS; sum_index++)
	{
		if (sum_comparison(Hands, PLAYERS, sum_index) > max_sum)
		{
			max_sum_index = sum_index;
			max_sum = sum_comparison(Hands, PLAYERS, sum_index);
		}
	}
	if (max_sum_index == 0)
	{
		cout << "Ben had the best hand with a ";
	}
		if (max_sum_index == 1)
	{
		cout << "Brendan had the best hand with a ";
	}
		if (max_sum_index == 2)
	{
		cout << "Niel had the best hand with a ";
	}
		if (max_sum_index == 3)
	{
		cout << "Sam had the best hand with a ";
	}
	
	Hands[max_sum_index].output_cards(cout);
	return EXIT_SUCCESS;
}

int CardHand::GetHandSize() const
{
    return HandSize;
}
