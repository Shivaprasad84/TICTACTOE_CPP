#include <iostream>
#include <ctime>
using namespace std;

string board;
char player1, player2;
bool winFlag;
char first, second;
void choose_first_player();
void drawBorad();
void clearScreen();
void placeMarker(int, char);
bool winnerFound(int);
void get_user_info();
int begin();
bool isDraw(int);
bool isSafe(int);

int main()
{
    char choice;
    srand(time(NULL));
    while (true)
    {
        winFlag = false;
        board = "123456789";
        get_user_info();
        choose_first_player();
        int count = begin();

        if (isDraw(count))
        {
            cout << "It's a Draw!!!" << endl;
        }
        cout << "Do you Want To Play Again? (y/n)" << endl;
        cin >> choice;
        if ((choice == 'n' || choice == 'N'))
        {
            break;
        }
        if ((choice == 'y' || choice == 'Y'))
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

// Game Logic

void get_user_info()
{
    cout << "Player 1 Choose your Symbol (X or O): ";
    cin >> player1;
    player2 = (player1 == 'X' || player1 == 'x') ? 'O' : 'X';
}

void choose_first_player()
{
    if (rand() % 2)
    {
        first = player1;
        second = player2;
        cout << "Player 1 Plays First "
             << "(" << player1 << ")" << endl;
    }
    else
    {
        first = player2;
        second = player1;
        cout << "Player 2 Plays First "
             << "(" << player2 << ")" << endl;
    }
    cin.get();
    cin.get();
}

int begin()
{
    int pos, count = 0;
    for (int i = 0; i < 9; i++)
    {
        drawBorad();
        cout << "Enter Position: ";
        cin >> pos;
        count++;
        if (isSafe(pos))
        {
            if ((count % 2))
            {
                placeMarker(pos - 1, first);
                if (winnerFound(pos - 1))
                {
                    winFlag = true;
                    drawBorad();
                    cout << ((player1 == first) ? "Player 1 " : "Player 2 ") << "Wins!" << endl;
                    break;
                }
            }
            else
            {
                placeMarker(pos - 1, second);
                if (winnerFound(pos - 1))
                {
                    winFlag = true;
                    drawBorad();
                    cout << ((player1 == first) ? "Player 1 " : "Player 2 ") << "Wins!" << endl;
                    break;
                }
            }
        }
        else
        {
            i -= 1;
        }
        
    }
    return count;
}

// Utilities

void drawBorad()
{
    clearScreen();
    cout << "\t\t  " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "\t\t"
         << "-------------" << endl;
    cout << "\t\t  " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "\t\t"
         << "-------------" << endl;
    cout << "\t\t  " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << endl;
}

inline void clearScreen()
{
    for (int i = 0; i < 100; i++)
    {
        cout << endl;
    }
}

void placeMarker(int pos, char val)
{
    board[pos] = val;
}

bool winnerFound(int current_pos)
{
    bool state;
    cout << current_pos << endl;
    switch (current_pos)
    {
    case 0:
    {
        state = (board[0] == board[1] && board[0] == board[2]) || (board[0] == board[4] && board[0] == board[8]) || (board[0] == board[3] && board[0] == board[6]);
        break;
    }

    case 1:
    {
        state = (board[0] == board[1] && board[0] == board[2]) || (board[1] == board[4] && board[1] == board[7]);
        break;
    }

    case 2:
    {
        state = (board[0] == board[1] && board[0] == board[2]) || (board[2] == board[4] && board[2] == board[6]) || (board[2] == board[5] && board[2] == board[8]);
        break;
    }

    case 3:
    {
        state = (board[0] == board[3] && board[0] == board[6]) || (board[3] == board[4] && board[3] == board[5]);
        break;
    }

    case 4:
    {
        state = (board[0] == board[4] && board[0] == board[8]) || (board[2] == board[4] && board[2] == board[6]) || (board[1] == board[4] && board[1] == board[7]) || (board[3] == board[4] && board[3] == board[5]);
        break;
    }

    case 5:
    {
        state = (board[2] == board[5] && board[2] == board[8]) || (board[3] == board[4] && board[3] == board[5]);
        break;
    }

    case 6:
    {
        state = (board[6] == board[3] && board[6] == board[0]) || (board[6] == board[4] && board[6] == board[2]) || (board[6] == board[7] && board[6] == board[8]);
        break;
    }

    case 7:
    {
        state = (board[6] == board[7] && board[6] == board[8]) || (board[1] == board[4] && board[1] == board[7]);
        break;
    }

    case 8:
    {
        state = (board[0] == board[4] && board[0] == board[8]) || (board[6] == board[7] && board[6] == board[8]) || (board[2] == board[5] && board[2] == board[8]);
        break;
    }
    }
    return state;
}

bool isDraw(int count)
{
    return (count == 9 && !winFlag);
}

bool isSafe(int position)
{
    return (board[position] != 'X') && (board[position] != 'O');
}
