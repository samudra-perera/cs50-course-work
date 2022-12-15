#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
    return 0;
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //Case of the single person running in the election
    if (candidate_count == 1)
    {
        printf("%s\n", candidates[0].name);
    }

    int winning_votes = 0;
    //Should be the largest ammount of votes

    // Case of more than a single candidate running
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= winning_votes)
        {
            winning_votes = candidates[i].votes;
        }
    }

    //Print out all the winnners
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == winning_votes)
        {
            printf("%s\n", candidates[j].name);
        }
    }
}

//Votes pseudocode
//To add votes to the candidates
//Loop over the array of candidates
//Check if the name matches
//if the name matches, add one to the vote
//if not return false

//Print Winner
//Find the winner
//Then find all occurrences of the winning number of votes and print

//14/14 cases solved and 100% on the styling