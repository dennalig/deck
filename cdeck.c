
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
    struct Card *next; //next pointer


}a_card;

struct Card *topCard=NULL; // head of Deck



void shuffle(); // rearranges LL
void freeDeck(); // frees deck
void printDeck();
void createDeck(struct Card *first);

int main (){

//printf("deck\n");

createDeck(topCard);
//printf("The topCard is %d of %s.\n", topCard->value, topCard->suit);
printDeck();
freeDeck();

return 0;

}

void createDeck(struct Card *top){
    //first should be of topCard (head)
    top=(struct Card*) malloc(sizeof(struct Card));
    strcpy(top->suit,spade);
    top->value=Ace;
    //topCard->next= NULL;
    topCard=top;

    struct Card *current=topCard;// current
    for(int i=2;i<=King;i++){ // spades
    current->next=(struct Card*) malloc(sizeof(struct Card));
     strcpy(current->next->suit,spade);
     current->next->value=i;
     current=current->next;


    }
    //printf("Here\n");

    for(int i=1;i<=King;i++){ //hearts 
    current->next=(struct Card*) malloc(sizeof(struct Card));
     strcpy(current->next->suit,heart);
     current->next->value=i;
     current=current->next;
    }

    for(int i=1;i<=King;i++){ //clubs 
    current->next=(struct Card*) malloc(sizeof(struct Card));
     strcpy(current->next->suit,club);
     current->next->value=i;
     current=current->next;
    }

    for(int i=1;i<=King;i++){ //diamonds
    current->next=(struct Card*) malloc(sizeof(struct Card));
     strcpy(current->next->suit,diamond);
     current->next->value=i;
     current=current->next;
    }

    current->next=NULL;

     


}
void shuffle(){ // randomly rearranges the cards 

}

void freeDeck(){ // feees the structs 

struct Card *curr=topCard;// current

while(curr!=NULL){

    struct Card *freeCard= curr;
    curr=curr->next;
    free(freeCard);
}


}

void printDeck(){ //prints the LL 

struct Card *curr=topCard;// current

while(curr!=NULL){
    int cardVal=curr->value;
    
    
        if(cardVal==Ace){
  printf(" Ace of %s.\n", curr->suit); //Ace
        }
        else if(cardVal==Jack){
            printf(" Jack of %s.\n", curr->suit); //Jack
        }
        else if(cardVal==Queen){
            printf(" Queen of %s.\n", curr->suit);//Queen
        }
        else if(cardVal==King){
        printf(" King of %s.\n", curr->suit);// King 
        printf("-----------\n");
        }
        else{
            printf(" %d of %s.\n", curr->value, curr->suit); //Default
        }
        
    curr=curr->next; //next
}

    
}