#include <iostream>
#include <stdlib.h>
#include <array>

#ifdef _WIN32
    #define CLS "cls"
#else
    #define CLS "clear"
#endif

#ifdef _WIN32
    #include <windows.h>
    void _sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>
    void _sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000);
    }
#endif

int win[][3] = {
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},

    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},

    {0, 4, 8},
    {2, 4, 6}
};

char places[9];
bool won = false;

char turn = 'X';

void tictactoe();
void debug();

void init() {
    won = false;
    turn = 'X';
    for(int i = 0; i < 9; i++) {
        places[i] = (i+1) + '0';
    }
}

int main(void) {
    while(true) {
        init();
        system(CLS);
        int user;
        std::cout << "--------------MENU--------------" << std::endl;
        std::cout << "1. Play Tic Tac Toe" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> user;

        switch(user) {
            case 1:
                tictactoe();
                break;
            case 2:
                return 0;
                break;
        }
    }
}

void draw() {
    system(CLS);
    std::cout << "----------TIC-TAC-TOE-----------" << std::endl;
    std::cout << std::endl << std::endl;
    for(int x = 0; x < 3; x++) {
        std::cout << " " << places[(3*x)] << "  | ";
        std::cout << " " << places[(3*x)+1] << "  | " ;
        std::cout << " " << places[(3*x)+2];
        if(x != 2)
            std::cout << std::endl << "---------------";
        std::cout << std::endl;
    }
}

void logic() {
    int input;
    std::cout << "Turn (" << turn << "): ";
    std::cin >> input;
    
    if(!(input < 1) || !(input > 9)) {
        if(places[input-1] != 'X' && places[input-1] != 'O') {
            places[input-1] = turn;
        }
    }
}

void check_cond() {
    bool all = true;
    for(int i = 0; i < (sizeof(win)/sizeof(*win)); i++) {
        if(places[win[i][0]] == turn && places[win[i][1]] == turn && places[win[i][2]] == turn) {
            won = true;
        }
    }
    for(int i = 0; i < 9; i++) {
        if(places[i] != 'X' && places[i] != 'O') {
            all = false;
        }
    }
    if(all) {
        won = true;
        turn = 'N';
    }
}

void tictactoe() {
    while(!won) {
        draw();
        logic();
        check_cond();
        if(!won) {
            switch(turn) {
                case 'X':
                    turn = 'O';
                    break;
                case 'O':
                    turn = 'X';
                    break;
            }
        }
    }
    if(turn == 'N')
        std::cout << "None of players won!" << std::endl;
    else
        std::cout << "Player " << turn << " won!" << std::endl;
    _sleep(5000);
}

void debug() {
    for(int i = 0; i < 9; i++) {
        std::cout << places[i] << " ";
    }
    std::cout << std::endl;
}