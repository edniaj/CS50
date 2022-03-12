#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Validation
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    // End of validation

    // Populate array of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false; // i.e. candidates[0] = {name: 'Alpha', votes :5, eliminated: true}
    }
    // End of populating array

    // Initialising number of votes to loop
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }
    // End of intialisation

    // Query ith time where i is the number of voters
    for (int i = 0; i < voter_count; i++)
    {

        // User input : Rank1 : Alpha, Rank2 : beta ... Rank 100 : Olel
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name)) // Name == Valid candidate ->  You should update the global preferences array to
            {
                printf("Invalid vote.\n"); // Manage Invalid votes
                return 4;
            }
        }
        // End of user input

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }
        // End of checking winner -> Break loop if theres a winner

        // Eliminate last-place candidates
        int min = find_min(); // Find that loser
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{

    for (int i = 0; i < candidate_count; i++)
    {
        candidate test = candidates[i];
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    printf("\nTabulating Scores\n");
    for (int i = 0; i < voter_count; i++) // N^3
    {
        for (int j = 0; j < candidate_count; j++) // J -> Rank
        {
            if (candidates[preferences[i][j]].eliminated)
            {
                printf(")
                continue;
            }
            else
            {
                candidates[preferences[i][j]].votes++;
                printf("%i : %s\n",candidates[preferences[i][j]].votes, candidates[preferences[i][j]].name );
                break;
            }
        }
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int winnerIndex = 0;
    int minimumVote = (voter_count + 1) / 2;
    printf("\nPrinting winners\n");
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%i : %s\n",candidates[i].votes, candidates[i].name );
        if (candidates[i].votes > minimumVote)
        {
            printf("%s", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int loserIndex = -1;
    int minimumVote = 99999;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < minimumVote && !candidates[i].eliminated)
        {
            loserIndex = i;
            minimumVote = candidates[i].votes;
        }
    }
    printf("\nminimumVote: %i\n",minimumVote)
    return minimumVote;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes != min && !candidates[i].eliminated)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes < min)
        {
            candidates[i].eliminated = true;
            printf("%s is eliminated",candidates[i].name);
        }
    }
    return;
}