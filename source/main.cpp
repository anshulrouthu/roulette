#include "game.h"
#include "dealer.h"
#include "player.h"
#include "roulette.h"

#define MAX_NUM_LEN 12
#define HOTSTREAK 3
#define MAX_WINS 16
#define ONE_BILLION 1000000000
#define ROULETTE_SIZE 36
#define ROULETTE_SPINS 128
#define ROULETTE_SLOWS 16
#define NUM_WIN_MSGS 10
#define NUM_LOSE_MSGS 5

long cash = 0;
long wins = 0;

int is_digit(char c)
{
    return '0' <= c && c <= '9';
}

long get_long()
{
    printf("> ");
    uint64_t l = 0;
    char c = 0;
    while (!is_digit(c))
        c = getchar();
    while (is_digit(c))
    {
        if (l >= LONG_MAX)
        {
            l = LONG_MAX;
            break;
        }
        l *= 10;
        l += c - '0';
        c = getchar();
    }
    while (c != '\n')
        c = getchar();
    return l;
}

long get_rand()
{
    long seed;
    FILE *f = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(seed), 1, f);
    fclose(f);
    seed = seed % 5000;
    if (seed < 0)
        seed = seed * -1;
    srand(seed);
    return seed;
}

long get_bet()
{
    while (1)
    {
        puts("How much will you wager?");
        printf("Current Balance: $%lu \t Current Wins: %lu\n", cash, wins);
        long bet = get_long();
        if (bet <= cash)
        {
            return bet;
        }
        else
        {
            puts("You can't bet more than you have!");
        }
    }
}

long get_choice()
{
    while (1)
    {
        printf("Choose a number (1-%d)\n", ROULETTE_SIZE);
        long choice = get_long();
        if (1 <= choice && choice <= ROULETTE_SIZE)
        {
            return choice;
        }
        else
        {
            puts("Please enter a valid choice.");
        }
    }
}

int print_flag()
{
    char flag[48];
    FILE *file;
    file = fopen("flag.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open the flag file\n");
        return -1;
    }
    fgets(flag, sizeof(flag), file);
    printf("%s", flag);
    return 0;
}

const char *win_msgs[NUM_WIN_MSGS] =
{ "Wow.. Nice One!", "You chose correct!", "Winner!", "Wow, you won!",
        "Alright, now you're cooking!", "Darn.. Here you go",
        "Darn, you got it right.", "You.. win.. this round...", "Congrats!",
        "You're not cheating are you?", };

const char *lose_msgs1[NUM_LOSE_MSGS] =
{ "WRONG", "Nice try..", "YOU LOSE", "Not this time..",
        "Better luck next time..." };

const char *lose_msgs2[NUM_LOSE_MSGS] =
{ "Just give up!", "It's over for you.", "Stop wasting your time.",
        "You're never gonna win",
        "If you keep it up, maybe you'll get the flag in 100000000000 years" };

void spin_roulette(long spin)
{
    int n;
    puts("");
    printf("Roulette  :  ");
    int i, j;
    int s = 12500;
    for (i = 0; i < ROULETTE_SPINS; i++)
    {
        n = printf("%d", (i % ROULETTE_SIZE) + 1);
        usleep(s);
        for (j = 0; j < n; j++)
        {
            printf("\b \b");
        }
    }
    for (i = ROULETTE_SPINS; i < (ROULETTE_SPINS + ROULETTE_SIZE); i++)
    {
        n = printf("%d", (i % ROULETTE_SIZE) + 1);
        if (((i % ROULETTE_SIZE) + 1) == spin)
        {
            for (j = 0; j < n; j++)
            {
                printf("\b \b");
            }
            break;
        }
        usleep(s);
        for (j = 0; j < n; j++)
        {
            printf("\b \b");
        }
    }
    for (int k = 0; k < ROULETTE_SIZE; k++)
    {
        n = printf("%d", ((i + k) % ROULETTE_SIZE) + 1);
        s = 1.1 * s;
        usleep(s);
        for (j = 0; j < n; j++)
        {
            printf("\b \b");
        }
    }
    printf("%ld", spin);
    usleep(s);
    puts("");
    puts("");
}

void play_roulette(long choice, long bet)
{

    printf("Spinning the Roulette for a chance to win $%lu!\n", 2 * bet);
    long spin = (rand() % ROULETTE_SIZE) + 1;

    spin_roulette(spin);

    if (spin == choice)
    {
        cash += 2 * bet;
        puts(win_msgs[rand() % NUM_WIN_MSGS]);
        wins += 1;
    }
    else
    {
        puts(lose_msgs1[rand() % NUM_LOSE_MSGS]);
        puts(lose_msgs2[rand() % NUM_LOSE_MSGS]);
    }
    puts("");
}

int main(int argc, char *argv[])
{
    Roulette* roulette = new Roulette();
    Player* player = new Player();

    Dealer* dealer = new Dealer(*player, *roulette);
    dealer->start();

    delete dealer;
    delete player;
    delete roulette;

    return 0;
}
