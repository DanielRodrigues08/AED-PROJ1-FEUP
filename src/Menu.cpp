//
// Created by pedro on 01/12/2021.
//

#include "Menu.h"

namespace screen{
    void showScreenLine(const std::string &code){
        for(int i = 0; i < WIDTH; ++i){
            std::cout << code;
        }
    }

    void showScreen(){
        std::cout << "┌"; showScreenLine("─"); std::cout << "┐" << std::endl;
        for(int i = 0; i < HEIGHT; ++i){
            std::cout << "│";
            for(int j = 0; j < WIDTH; ++j){
                std::cout << image[i][j] << "▉" << RESET;
            }
            std::cout << "│" << std::endl;
        }
        std::cout << "└"; showScreenLine("─"); std::cout << "┘" << std::endl;
    }
}

// --------------- Main Menu ---------------

MainMenu::MainMenu() : Menu() {}
void MainMenu::show() {
    unsigned int options = 0;

    std::cout << CLR_SCREEN;
    std::cout << "\n"
                 "   _____ _                            ______\n"
                 "  / ____| |                          |___  /\n"
                 " | (___ | |_ _ __ ___  __ _ _ __ ___    / / \n"
                 "  \\___ \\| __| '__/ _ \\/ _` | '_ ` _ \\  / /  \n"
                 "  ____) | |_| | |  __/ (_| | | | | | |/ /__ \n"
                 " |_____/ \\__|_|  \\___|\\__,_|_| |_| |_/_____|\n"
                 "\n";


    std::cout << "Main Menu:\n\n";
    std::cout << "[" << ++options << "] " << "Passenger Login\n";
    std::cout << "[0] Exit\n";
};

Menu * Menu::invalidOption() {
    std::cout << "Invalid option" << std::endl;
    input::waitEnter();
    return this;
};

Menu * MainMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }
    switch(option){
        case 0: return nullptr;
        case 1: return new LoginPassengerMenu();
    }
    return invalidOption();
}

// --------------- Passenger Login Menu ---------------
LoginPassengerMenu::LoginPassengerMenu(Platform &platform) : Menu(platform) {}
void LoginPassengerMenu::show() {
    if(!logged_in){
        std::cout << CLR_SCREEN;
        std::cout << "Username: " << std::endl;
    }
}
Menu * LoginPassengerMenu::getNextMenu() {
    if(!logged_in){
        std::string idNumber;
        if(!input::get(idNumber)){
            return invalidOption();
        }
        //check for the existance of said passenger
        bool passengerExists = false;
        for(auto passenger: clients){
            if(passenger.getID()==idNumber){
                passengerExists = true;
                return new BookingMenu(passenger)
            }
        }
        if(!passengerExists){
            std::cout << "Id number " << idNumber << " does not exist in our database" << std::endl;
            input::waitEnter();
        }

    }
    return nullptr;
}

// --------------- Booking Menu ---------------
BoookingMenu::BookingMenu(Passenger * passenger) : passenger(passenger) {}
void ViewerMenu::show() {
    std::cout << CLR_SCREEN;
    unsigned int option = 1;
    else{
        std::cout << "[" << option++ << "] Book Flight" << std::endl;
        std::cout << "[" << option++ << "] Book a Plane" << std::endl;
        std::cout << "[" << option++ << "] Cancel Flight" << std::endl;

    }
    std::cout << "[0] Exit" << std::endl;
}
Menu * BookingMenu::getNextMenu() {
    int option;
    if(!input::get(option))
        return invalidOption();
    if(option == 0){
        return nullptr;
    }

    else{
        unsigned int id, pos;
        std::string streamer;
        Store *store;
        switch(option){
            case 1: return new * PlaneMenu();
            //case 2 in STAN-BY still thinking what is the best option 1-Create a menu 2-Create a method in plane
            //case 2: passenger.; return this;
            //should i create ANOTHER menu??
            case 3: passenger.cancelFlight(); return this;
        }
    }
    return invalidOption();
}


