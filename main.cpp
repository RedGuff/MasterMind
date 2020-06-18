#include <iostream>
#include <time.h>
#include <cassert>
using namespace std;

int NtoGuess = 0;
int Ncolors = 0;
string solution = "";
string tryPlayer = "";
int nTry = 0;
int maxiTry = 0;

char nbToChar(int n = 0) { // A = 0, ... , Z, a, ... , z, 0, 1, ... , 9
    if(n < 26) {
        return char(n + 65);
        }
    if(n < 52) {
        return char(n + 71);
        }
    if(n < 62) {
        return char(n - 4);
        }
    cerr << "nbToChar !" << endl;
    }

void init() { // Ask ? // https://fr.wikipedia.org/wiki/Mastermind
    cout << "MasterMind" << endl;
    NtoGuess = 5;
    Ncolors = 8;
    assert((Ncolors < 62) && "Nombre de couleurs trop grand !");
    assert((Ncolors > 0) && "Nombre de couleurs < 0");
    bool sameAllowed = true;
    maxiTry = 12;
    for(int a = 0; a < NtoGuess; a++) {
        solution = solution + nbToChar(rand() % Ncolors);
        }
    clog << "(Solution = " << solution << ")" << endl;
    }

void displayTitle() {
    cout << "     " << "\t\t" << " :-)"  << "\t" << ":-|" << endl;
    }
void displayGame(int nTry, int maxiTry, string solution, string tryPlayer) {
    cout << nTry << "/" << maxiTry << "\t" << tryPlayer << "\t  " ;
    int badPlace = 0;
    int good = 0;
    for(int a = 0; a < solution.size(); a++) {
        if(tryPlayer[a] == solution[a]) {
            good++;
            }
        for(int b = 0; b < solution.size()+0; b++) { // +1 ?

            if(tryPlayer[a] == solution[b]) {
                badPlace++;
            if(a == b) {
                badPlace--;
                }
                }
            }
        }
    cout << good;
    cout << "\t ";
    cout << badPlace;
    cout    << endl;
    }

void coutWin() { // Smiley ?
    cout << "You win!" << endl;
    }
void coutLose() { // Smiley ?
    cout << "You lose!" << endl;
    cout << solution << endl;
    }
string repeatStringInt ( string pattern = "", int n = 0 ) // As the name says: string first, int after. // https://github.com/RedGuff/repeatStringInt
{
    if ( n < 0 )
        {
        cerr << "Error: repeat(" << pattern << ", " << n << " < 0)" << endl;
        return "-1";
        }
    else if ( n == 0 )
        {
        return "";
        }
    else
        {
        return pattern + repeatStringInt ( pattern, n - 1 );
        }
}
int main() {
    srand(time(NULL));       // No need for better init.
    init();
    displayTitle();
    //tryPlayer = "ABCDE";
     displayGame(nTry, maxiTry, solution, repeatStringInt ( "?", NtoGuess ));
    bool finished = false;
    while(finished == false) {

        nTry++;
      getline(cin,tryPlayer);
        if (tryPlayer==solution)
        {coutWin();
            finished = true;
        }else{
        displayGame(nTry, maxiTry, solution, tryPlayer);
        if(nTry >= maxiTry) {
            coutLose();
            finished = true;
            }
            }
        }
    return 0;
    }
