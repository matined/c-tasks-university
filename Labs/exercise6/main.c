#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Helper function used for various test ensuring correct implementation.
void check(int cond, const char *errmsg) {
    if (!cond) {
        fprintf(stderr, "Check failed: %s!", errmsg);
        exit(EXIT_FAILURE);
    }
}

typedef struct Card {
    unsigned char
        suit;  // values 1-4 denote (in order) Spades, Clubs, Diamonds, Hearts
    unsigned char rank;  // values 9-14 denote (in order): 9, 10, J, Q, K, A
} Card;

typedef struct DeckElem {
    Card c;
    struct DeckElem *next, *prev;
} DeckElem;

typedef struct Deck {
    DeckElem *head, *tail;
} Deck;

Card card_init(unsigned char s, unsigned char r) {
    Card c;
    c.suit = s;
    c.rank = r;
    return c;
}

Card card_random() { return card_init(rand() % 4 + 1, rand() % 6 + 9); }

void card_print(Card c) {
    check(c.suit > 0 && c.suit <= 4, "card_print - Invalid suit!");
    check(c.rank > 8 && c.rank <= 14, "card_print - Invalid rank");
    static const char suit_lookup[] = {'S', 'C', 'D', 'H'};
    static const char rank_lookup[] = {'J', 'Q', 'K', 'A'};
    putchar('[');
    if (c.rank > 10)
        putchar(rank_lookup[c.rank - 11]);
    else
        printf("%hhu", c.rank);
    putchar(suit_lookup[c.suit - 1]);
    putchar(']');
}

DeckElem *deck_create_elem(Card c) {
    DeckElem *deck_element = (DeckElem *)malloc(sizeof(DeckElem));
    if (deck_element != NULL) {
        deck_element->c = c;
        deck_element->next = NULL;
        deck_element->prev = NULL;
    }
    return deck_element;
}

void deck_append_elem(Deck *d, DeckElem *el) {
    if (d->head == NULL) {  // an empty deck
        d->head = el;
        d->tail = el;
    } else {
        d->tail->next = el;
        el->prev = d->tail;
        el->next = NULL;
        d->tail = el;
    }
}

void deck_print(const Deck *d) {
    DeckElem *current = d->head;
    while (current != NULL) {
        card_print(current->c);
        current = current->next;
    }
}

void deck_destroy(Deck *d) {
    DeckElem *current = d->head;
    while (current != NULL) {
        DeckElem *to_delete = current;
        current = current->next;
        free(to_delete);
    }
    d->head = NULL;
    d->tail = NULL;
}

DeckElem *deck_unlink_last(Deck *d) {
    if (d->tail == NULL) return NULL;  // an empty deck
    if (d->head->next == NULL) {       // one element
        DeckElem *unlinked_card = d->head;
        d->head = NULL;
        d->tail = NULL;
        return unlinked_card;
    }
    DeckElem *unlinked_card = d->tail;  // else
    d->tail = unlinked_card->prev;
    d->tail->next = NULL;
    unlinked_card->prev = NULL;
    return unlinked_card;
}

void deck_reverse(Deck *d) {
    Deck result = {NULL, NULL};
    while (d->head != NULL) {
        DeckElem *tmp = deck_unlink_last(d);
        deck_append_elem(&result, tmp);
    }
    *d = result;
}

void deck_prepend(Deck *dst, Deck *src);

Deck deck_build();

void deck_deal(Deck *d, Deck hands[], unsigned count);

#define MAX_HANDS 10
void deck_shuffle(Deck *d);

int main(void) {
    // For Part 1 remember to uncomment two additional lines between Parts 2 and
    // 3

    puts("**********************Part 1**********************");
    Deck d = {NULL, NULL};
    int i;
    srand(9854);
    // srand((unsigned)time(NULL));
    for (i = 0; i < 10; ++i) {
        DeckElem *tmp = deck_create_elem(card_random());
        deck_append_elem(&d, tmp);
    }
    deck_print(&d);

    puts("\n**********************Part 2**********************");
    for (i = 0; i < 4; ++i) {
        DeckElem *tmp = deck_unlink_last(&d);
        printf("Last: ");
        card_print(tmp->c);
        putchar('\n');
        free(tmp);
    }

    puts("Reversing the rest...");
    deck_reverse(&d);
    deck_print(&d);

    // Uncomment the following for Part 1

    deck_destroy(&d);
    check(d.head == NULL && d.tail == NULL, "Deck should be empty");

    /*
    puts("\n**********************Part 3**********************");
    for (i = 0; i < 3; ++i)
    {
            Deck d2 = { NULL, NULL };
            int j = rand() % 10 + 1;
            while (j--)
            {
                    DeckElem *tmp = deck_create_elem(card_random());
                    deck_append_elem(&d2, tmp);
            }
            printf("d2: ");
            deck_print(&d2);
            puts("Prepending d2 to d");
            deck_prepend(&d, &d2);
            printf("d : ");
            deck_print(&d);
            check(d2.head == NULL && d2.tail == NULL, "Second deck should be
    empty");
    }
    deck_destroy(&d);

    puts("Building deck...");
    d = deck_build();
    deck_print(&d);
    */

    /*
    puts("\n**********************Part 4**********************");
    puts("Dealing cards...");
    Deck hands[3] = { {NULL, NULL} };
    deck_deal(&d, hands, 3);
    for (i = 0; i < 3; ++i)
    {
            printf("Hand %d: ", i + 1);
            deck_print(hands + i);
            deck_destroy(hands + i);
    }
    check(d.head == NULL && d.tail == NULL, "First deck should be empty");
    */

    /*
    puts("\n**********************Part 5**********************");
    d = deck_build();
    deck_print(&d);
    puts("Shuffling 10 times...");
    for (i = 0; i < 10; ++i)
            deck_shuffle(&d);
    deck_print(&d);
    deck_destroy(&d);
    */

    return 0;
}