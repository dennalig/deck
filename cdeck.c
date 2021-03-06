
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 10 // for names
#define SPADES "spades"
#define HEARTS "hearts"
#define CLUBS "clubs"
#define DIAMONDS "diamonds"
#define Ace 1 //royalty card vals
#define Jack 11
#define Queen 12
#define King 13


struct Card{

    //char type[MAX];
    char suit[MAX];
    int value;
   // struct Card *next; //next pointer


}a_card;

//struct Card *topCard=NULL; // head of Deck
struct Card *cardArray[52]; // add card array for random access ... random pointers 
double randTime=0; //since the time that is gathered is so the same for each rand, 
//we also add this to the given time that we call srand on
void shuffle(); // rearranges the array of cards in a different order 
void freeDeck(struct Card *card[52]); // frees deck
void printDeck();//prints deck
void createDeck();

// operational functions 
int arrayIter(int num); 

int main (){

//printf("deck\n");

createDeck();

// shuffle();
// shuffle();
printDeck();
//printf("The topCard is %d of %s.\n", topCard->value, topCard->suit);

freeDeck(cardArray);


return 0; 

}

void createDeck(){ // initializes and creates the deck (in order)
    //first should be of topCard (head)

    char suitArray[4][9]; // array of each suit
    strcpy(suitArray[0], SPADES);
    strcpy(suitArray[1],DIAMONDS);
    strcpy(suitArray[2],CLUBS);
    strcpy(suitArray[3],HEARTS);
    // printf("%s\n",suitArray[0]);

    int suitPosition=0; // position in the suit string array, allowing us to not repeat code
    int cardValueInd=0; // numbers 1-13, resets after each batch of 13

    for(int i=0;i<52;i++){ // for loop of 52

        cardArray[i]=(struct Card*) malloc(sizeof(struct Card)); // malloc memory of that card 
        strcpy(cardArray[i]->suit, suitArray[suitPosition]); // assign suit
        cardArray[i]->value=cardValueInd+1; // assign numeric value 

       // printf("%d of %s \n", cardArray[deckCounter]->value, cardArray[deckCounter]->suit);

        cardValueInd++; //increment of a card 

        if((i+1)%13==0){ //counting the card that is marked ... could also use cardValueInd here 
            suitPosition++;
            cardValueInd=0; // reset to 0
        }
    }


} // end createDeck()


void shuffle(){ // randomly rearranges the cards 


    // int numberBoard[52];

    // for(int i=0;i<52;i++){
    //     numberBoard[i]=i;
    // }

struct Card *newArray[52]; // new array of Card pointers 
int newArrInd=0;

randTime+=4.67;

    time_t t;

    srand((unsigned) time(&t)+randTime); // should only be used once 

    for(int i=0;i<52;i++){
         int randInd= (rand()%52); // returns random num from 0 to 52

         struct Card *location= cardArray[randInd];

        while(location==NULL){ // while the random location that we end up at is null

          randInd= arrayIter(randInd); // increments random index by one
          location= cardArray[randInd];
          //printf(" repeated num %d \n ", randInd);
        }

        newArray[newArrInd]=cardArray[randInd];
        newArrInd++;
        cardArray[randInd]=NULL; // sets the the random object to NULL



        //printf("%d \n", randInd);


    
}

  memcpy(&cardArray, &newArray, (sizeof(newArray)));// assign cardArray to the new array
  //https://stackoverflow.com/questions/1693853/copying-arrays-of-structs-in-c
//printf("------\n");




}


int arrayIter(int index){ // array iteration function

    if(index <52){
        index+=1;
        return index;
    }
    else{
        return 0;
    }
      
}


void freeDeck(struct Card *card[52]){ // frees the structs 


for(int i=0;i<52;i++){
    free(card[i]);
}

}

void printDeck(){ //prints the LL 

for(int i=0;i<52;i++){

    struct Card *currentCard= cardArray[i];

    int val= currentCard->value;

    switch(val){
        case 1: // ace 
            printf("ace of %s \n",currentCard->suit);
            break; // break is necessary here so that we dont print a case and the default 
        case 11: // jack
            printf("jack of %s \n", currentCard->suit);
            break;
        case 12: //queen
            printf("queen of %s \n", currentCard->suit);
            break;
        case 13: //king
            printf("king of %s \n", currentCard->suit);
            break;
        default: // any other num
             printf("%d of %s \n", currentCard->value,currentCard->suit);
    }

}

printf("------\n");
    
}