//
// Created by wzq12 on 2024/7/12.
//
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <chrono>

using namespace std;
int max_range = 100;//default max range is 100
struct history{
    bool is_right;
    string question;
    int right_ans;
    double time=0;
};
int checkInput();

void userInput(struct history* history){
    chrono::time_point<chrono::steady_clock> start, end;
    start = chrono::steady_clock::now();
    cout<<"Please enter your answer:\n";
    int ret = checkInput();
    end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_time = end - start;
    history->time = elapsed_time.count();
};
int checkInput(){
    char str[100];
    cin >> str;
    for(int i=0; i<strlen(str); i++){
        if(str[i] < '0' || str[i] > '9'){
            std::cout << "Invalid input, please enter a number: \n";
            return checkInput();
        }
    }
    return std::stoi(str);
};

int userInput(){
    std::cout << "Choose difficulty level (0: easy, 1: medium, 2: hard):\n";
    int level = checkInput();
    while(level < 0 || level > 2){
        std::cout << "Invalid input, please enter a number between 0 and 2: \n";
        level = checkInput();
    }
    switch(level){
        case 0:
            std::cout << "Easy level selected.\n";
            break;
        case 1:
            std::cout << "Medium level selected.\n";
            break;
        case 2:
            std::cout << "Hard level selected.\n choose max generation range(>100):\n";
            max_range = checkInput();
            while(max_range < 100){
                std::cout << "Invalid input, please enter a number between 10 and 100: \n";
                max_range = checkInput();
            }
            break;
            default:break;

    }
    cout<<"How many questions do you want to answer? (1-100):\n";
    int num = checkInput();
    while(num < 1 || num > 100) {
        std::cout << "Invalid input, please enter a number between 1 and 100: \n";
    }
    return num;
}

void buildQuestion() {
    srand((unsigned)(time(NULL)));
    op1 = rand() % max_range + 1;
    op2 = rand() % max_range + 1;
    switch(difficulty)
}

int main(){
    int n = 10;
    n = userInput();
    struct history* history = new struct history[n]();
    for(int i=0; i<n; i++){
        buildQuestion(history[i]);
    }
}