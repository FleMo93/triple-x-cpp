#include <iostream>
#include <ctime>
using namespace std;

int GetRandomNumberByDifficulty(int Difficulty) {
    const int BaseDifficulty = 2;
    return (rand() + BaseDifficulty + Difficulty) % (Difficulty + BaseDifficulty + Difficulty);
}

bool PlayGame(int Difficulty)
{
    const int CodeA = GetRandomNumberByDifficulty(Difficulty);
    const int CodeB = GetRandomNumberByDifficulty(Difficulty);
    const int CodeC = GetRandomNumberByDifficulty(Difficulty);

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    cout << endl;
    cout << "+ There are 3 numbers in the code\n";
    cout << "+ The numbers add-up to: " << CodeSum << "\n";
    cout << "+ The codes multiply to give: " << CodeProduct << "\n";

    int GuessA, GuessB, GuessC;
    cin >> GuessA >> GuessB >> GuessC;
    cout << "\n";
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    return GuessSum == CodeSum && GuessProduct == CodeProduct;
}

int main()
{
    srand(time(NULL));
    cout << "You are a secrect agent breaking into a secure server room\n";
    cout << "You need to enter the correct codes to continue...\n";

    int Difficulty = 0;
    int MaxDifficulty = 10;

    while (Difficulty < MaxDifficulty)
    {
        if (PlayGame(Difficulty))
        {
            Difficulty++;

            if (Difficulty == MaxDifficulty)
            {
                cout << "You break that shid ouda here";
            }
            else
            {
                cout << "You won that round!\nGo further.\n";
                cout << MaxDifficulty - Difficulty << " levels to go...\n";
            }
        }
        else
        {
            cout << "You lose!";
            break;
        }
    }

    return 0;
}