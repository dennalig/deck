
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10 // for names
#define spade "spades"
#define heart "hearts"
#define club "clubs"
#define diamond "diamonds"
#define Ace 1 //royalty card vals
#define Jack 11
#define Queen 12
#define King 13


struct Card{

    //char type[MAX];
    char suit[MAX];
    int value;


}a_card;

struct Card *topCard=NULL; // head of Deck



void shuffle(); // rearranges LL
void freeDeck(); // frees deck
void createDeck(struct Card *first);

int main (){

//printf("deck\n");

createDeck(topCard);
printf("The topCard is %d of %s.\n", topCard->value, topCard->suit);
freeDeck();

return 0;

}

void createDeck(struct Card *top){
    //first should be of topCard (head)
    top=(struct Card*) malloc(sizeof(struct Card));
    strcpy(top->suit,spade);
    top->value=Ace;
    topCard=top;


}
void shuffle(){

}

void freeDeck(){

    free(topCard);
}
