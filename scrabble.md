
/*
 * @ SCRABBLE PROJECT IDEA BY kaiofour(AI GENERATED PROBLEM DESCRIPTION)
 */ 
C Coding Project: Scrabble Game using Stacks, Queues, and Dictionaries

Objective:
Build a simplified version of Scrabble where players take turns forming words using a set of tiles. The game uses stacks to manage the letter tiles, queues for player turns, and dictionaries (hashmaps or similar) to store valid words.

Requirements:

1. Stacks:
   Use a stack to represent the bag of letter tiles. When players draw tiles, they "pop" from the stack. When new tiles are added, they are "pushed" onto the stack.

2. Queues:
   Implement a queue to manage player turns. Players take turns in the order they join the game. After a player's turn, they are enqueued back into the queue.

3. Dictionaries:
   Use a dictionary (or hash table) to store a list of valid words. The game should check if a player’s word is valid by looking it up in the dictionary.

Features:

1. Game Setup:
   Initialize a stack of letter tiles (A-Z, with predefined counts).  
   Allow 2-4 players to join the game. Store player details in a queue.

2. Player Turns:
   Each player starts with 7 random letter tiles drawn from the stack.  
   On a player's turn, they form a word using their tiles and submit it.  
   The game checks if the word is valid (from the dictionary).  
   After submitting, the player draws new tiles from the stack to replace the used ones, if available.

3. Word Validation:
   Check if the formed word exists in the dictionary.  
   Implement word scoring based on Scrabble letter values.

4. End Game:
   The game ends when the stack of letter tiles is empty, and no player can form a valid word.  
   The player with the highest score wins.

Tasks Breakdown:

1. Define Data Structures:
   - Stack for letter tiles
   - Queue for player turns
   - Dictionary (or hash table) for valid words

2. Initialize Tiles:
   Create a function to populate the stack with a random distribution of letter tiles.

3. Create Queue for Players:
   Implement a queue that rotates the players’ turns.

4. Word Formation:
   Let players use their tiles to form a word, and check if it exists in the dictionary.

5. Scoring:
   Assign points for each letter and calculate total word score.

6. Dictionary Lookup:
   Use a predefined dictionary (stored in a file or array) to validate the submitted word.

7. Endgame Conditions:
   The game ends when there are no more tiles or when players cannot form valid words.

Optional Features:
- Add a leaderboard to track player scores over multiple games.
- Implement special tiles (like double letter or triple word scores).
- Save and load game state.

Sample Data Structures:

Additional Files:
- Dictionary File: A text file containing valid Scrabble words.
- Scoring File: A file that assigns points to each letter.

Deliverables:
- A fully functional C program simulating the Scrabble game.
- Use of stacks for tile management, queues for turn rotation, and a dictionary for word validation.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 100
#define NUM_TILES 100
#define PLAYER_TILES 7
#define MAX_PLAYERS 4
// Node structure for each word in the dictionary
struct WordNode {
    char word[100];                // Array to store the word
    struct WordNode* next;         // Pointer to the next word in the list
};

// Dictionary structure using a linked list
struct Dictionary {
    struct WordNode* head;         // Pointer to the first word in the list
};

// Structure for a player
struct Player {
    char name[50];                 // Player's name
    int score;                     // Player's score
    char tiles[7];                 // Player's tiles
};

// Structure for the stack (letter tiles)
struct Stack {
    char tiles[100];               // Total letters in the stack (e.g. A-Z tiles)
    int top;                       // Top of the stack
};

// Structure for the queue (player turns)
struct Queue {
    struct Player players[4];      // Array to store players (max 4 players)
    int front, rear;               // Front and rear for queue operations
};
// you can add double pointer to the struct if u want to deal with double pointers
// you can also add more fields to the struct if you need them

@function prototypes for the Scrabble game, including those for managing the linked list dictionary, the stack of letter tiles, and the queue for player turns:

Function Prototypes

```c
// Dictionary functions
void initializeDictionary(struct Dictionary* dict);
void insertWord(struct Dictionary* dict, const char* newWord);
int searchWord(struct Dictionary* dict, const char* word);
void freeDictionary(struct Dictionary* dict);

// Stack functions
void initializeStack(struct Stack* stack);
int isStackEmpty(struct Stack* stack);
int isStackFull(struct Stack* stack);
void push(struct Stack* stack, char tile);
char pop(struct Stack* stack);
char peek(struct Stack* stack);

// Queue functions
void initializeQueue(struct Queue* queue);
int isQueueEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, struct Player player);
struct Player dequeue(struct Queue* queue);
struct Player front(struct Queue* queue);

// Player functions
void initializePlayer(struct Player* player, const char* name);
void updateScore(struct Player* player, int points);

// Game functions
void drawTiles(struct Stack* stack, struct Player* player);
void validateWord(struct Dictionary* dict, const char* word, struct Player* player);
void endGame(struct Queue* queue);
```

Overview of Each Function Prototype:

1. Dictionary Functions:
   - `initializeDictionary`: Initializes the dictionary.
   - `insertWord`: Inserts a new word into the dictionary.
   - `searchWord`: Searches for a word in the dictionary.
   - `freeDictionary`: Frees memory used by the dictionary.

2. Stack Functions:
   - `initializeStack`: Initializes the stack of letter tiles.
   - `isStackEmpty`: Checks if the stack is empty.
   - `isStackFull`: Checks if the stack is full.
   - `push`: Adds a tile to the stack.
   - `pop`: Removes and returns the top tile from the stack.
   - `peek`: Returns the top tile without removing it.

3. Queue Functions:
   - `initializeQueue`: Initializes the queue for player turns.
   - `isQueueEmpty`: Checks if the queue is empty.
   - `enqueue`: Adds a player to the end of the queue.
   - `dequeue`: Removes and returns the player at the front of the queue.
   - `front`: Returns the player at the front of the queue without removing them.

4. Player Functions:
   - `initializePlayer`: Initializes a player's details.
   - `updateScore`: Updates the player's score based on points earned.

5. Game Functions:
   - `drawTiles`: Draws tiles from the stack for a player.
   - `validateWord`: Validates a player's word against the dictionary.
   - `endGame`: Handles end game conditions.

