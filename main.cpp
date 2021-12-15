#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/Menu.h"
#include "src/Menu.cpp"
#include <stack>
#include <iomanip>

int main() {

    std::stack<Menu *> menus;
    menus.push(new MainMenu());

    while(!menus.empty()){
        menus.top()->show();
        Menu * ptr = menus.top()->getNextMenu();
        if(ptr){
            if(ptr != menus.top()){
                menus.push(ptr);
            }
        }
        else{
            delete menus.top();
            menus.pop();
        }
    }
    return 0;
}