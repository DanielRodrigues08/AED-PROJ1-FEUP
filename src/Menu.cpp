#include "Menu.h"
#include "Plane.h"


using namespace std;

set<Passenger*> Menu::users ;
set<Person* > Menu::admins = { new Person("Pedro",20,30243315,"pedro","123"),new Person("Daniel",19,30243316,"dani","123")};
vector<Location*> Menu::locations;
vector<Plane*> Menu::planes;
vector<Person*> Menu::staff;
Treadmill Menu::treadmill;
CheckIn Menu::checkIn(treadmill);




Menu::Menu() {}

Menu * Menu::invalidOption() {
    cout << "Invalid option" << std::endl;
    input::waitEnter();

    return this;
}


// --------------- Main Menu ---------------
MainMenu::MainMenu():Menu(){
    populate::planes(planes,staff);
    populate::users(users,planes);
    populate::staff(staff);
    populate::locations(locations);
}

MainMenu::~MainMenu(){
    save::users(users);
    save::planes(planes);
    save::locations(locations);
    save::staff(staff);

}

void MainMenu::show() {
    unsigned int options = 0;

    system("cmd /c cls");
    cout << "Main Menu:\n\n";
    cout << "[" << ++options << "] " << "Passenger Login\n";
    cout << "[" << ++options << "] " << "Passenger Register\n";
    cout << "[" << ++options << "] " << "Show Flights\n";
    cout << "[" << ++options << "] " << "Show Transports\n";
    cout << "[" << ++options << "] " << "Admin Login\n";
    cout << "[0] Exit\n";
}

Menu * MainMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }
    switch(option){
        case 0: return nullptr;
        case 1: return new LoginPassengerMenu();
        case 2: return new RegisterPassengerMenu();
        case 3: return new FlightMenu(false);
        case 4: return new TransportsMenu();
        case 5: return new LoginAdminMenu();
    }
    return invalidOption();
}

// --------------- Register Passenger Menu ---------------
RegisterPassengerMenu::RegisterPassengerMenu() : Menu() {}
void RegisterPassengerMenu::show() {
    system("cls");
    cout << "Information required: ID number, name, age\n";
}
Menu * RegisterPassengerMenu::getNextMenu() {
    string username, name,password;
    unsigned nif;
    unsigned age;

    cout << "name\n ";
    if(!input::get(name)){
        return invalidOption();
    }
    cout << "nif\n ";
    if(!input::get(nif) || !input::validateID(to_string(nif))){
        return invalidOption();
    }
    cout << "username\n ";;
    if(!input::get(username)){
        return invalidOption();
    }
    cout << "password\n ";
    if(!input::get(password)){
        return invalidOption();
    }
    cout << "age\n ";
    if(!input::get(age)){
        return invalidOption();
    }


    users.insert(new Passenger(name, age ,nif,username, password));
    cout << " \n You've registered with success" << endl;
    input::waitEnter();
    return nullptr;
}

//----------------- Register Staff Menu -----------------

RegisterStaffMenu::RegisterStaffMenu() : Menu() {}

void RegisterStaffMenu::show() {
    system("cls");
    cout << "Information required: ID number, name, age\n";
}
Menu * RegisterStaffMenu::getNextMenu() {

    string username, name, password;
    unsigned nif;
    unsigned age;

    cout << "name\n ";
    if (!input::get(name)) {
        return invalidOption();
    }
    cout << "nif\n ";
    if (!input::get(nif) || !input::validateID(to_string(nif))) {
        return invalidOption();
    }
    cout << "username\n ";;
    if (!input::get(username)) {
        return invalidOption();
    }
    cout << "password\n ";
    if (!input::get(password)) {
        return invalidOption();
    }
    cout << "age\n ";
    if (!input::get(age)) {
        return invalidOption();
    }


    staff.push_back(new Person(name, age, nif, username, password));
    cout << " \n You've registered with success" << endl;
    input::waitEnter();
    return nullptr;
}
// --------------- Passenger Login Menu ---------------
LoginPassengerMenu::LoginPassengerMenu() : Menu() {}
void LoginPassengerMenu::show() {
    system("cmd /c cls");
    cout << "Please login to experience the full potential of our program \n \n " << endl;

}
Menu * LoginPassengerMenu::getNextMenu() {
    bool check = true;

    string username,password;
    cout << "username \n [0] to exit \n";
    if(!input::get(username)) {
        return invalidOption();
    }

    if(username == "0"){
        return nullptr;
    }

    cout << "password\n";
    if(!input::get(password)) {
        return invalidOption();
    }


    for(auto passenger: users){

        if(passenger->getUsername() == username){
            if(passenger->getPassword()== password){
                cout << "CONGRATS YOU'RE NOW LOGGED IN " << endl;
                input::waitEnter();
                return new BookingMenu(passenger);
            }
            cout << "WRONG PASSWORD"<< endl;
            check = false;
        }
    }
    if(check)
        cout << "Username (" << username << ") does not exist in our database" << std::endl;
    input::waitEnter();
    return nullptr;
}

// --------------- Admin Login Menu ---------------
LoginAdminMenu::LoginAdminMenu() : Menu() {}
void LoginAdminMenu::show() {
    system("cmd /c cls");
    cout << "Admin login\n \n " << endl;

}
Menu * LoginAdminMenu::getNextMenu() {
    bool check = true;

    string username,password;
    cout << "[0] to exit \n username\n ";
    if(!input::get(username)) {
        return invalidOption();
    }

    if(username == "0"){
        return nullptr;
    }

    cout << "password\n";
    if(!input::get(password)) {
        return invalidOption();
    }


    for(auto admin: admins){

        if(admin->getUsername() == username){
            if(admin->getPassword()== password){
                cout << "CONGRATS YOU'RE NOW LOGGED IN " << endl;
                input::waitEnter();
                return new AdminMenu();
            }
            cout << "WRONG PASSWORD"<< endl;
            check = false;
        }
    }
    if(check){
        cout << "Username (" << username << ") does not exist in our database" << endl;
    }
    input::waitEnter();
    return nullptr;
}

// --------------- Booking Menu ---------------
BookingMenu::BookingMenu(Passenger * passenger) : passenger(passenger) {}
void BookingMenu::show() {
    system("cls");
    unsigned int option = 1;

    std::cout << "[" << option++ << "] Book Flight" << std::endl;
    std::cout << "[" << option++ << "] Cancel Flight" << std::endl;
    std::cout << "[" << option++ << "] Tickets" << std::endl;
    std::cout << "[" << option++ << "] Check-In" << std::endl;
    std::cout << "[" << option++ << "] Suitcase" << std::endl;

    std::cout << "[0] Exit" << std::endl;
}
Menu * BookingMenu::getNextMenu() {
    int option;
    if (!input::get(option))
        return invalidOption();
    if (option == 0) {
        return nullptr;
    } else {
        unsigned int id, pos;//TODO
        switch (option) {
            case 1:
                return new FlightMenu(passenger);
            case 2:
                return new CancelMenu(passenger);
            case 3:
                return new TicketsMenu(passenger);
            case 4:
                return new CheckInMenu(passenger);
            case 5:
                return new SuitcaseMenu(passenger);
        }
    }
    return invalidOption();
}


// ----------------SuitCase Menu----------------

SuitcaseMenu::SuitcaseMenu(Passenger * passenger) : passenger(passenger) {}
void SuitcaseMenu::show() {
    system("cls");
    unsigned int option = 1;

    std::cout << "[" << option++ << "] Register Suitcase" << std::endl;
    std::cout << "[" << option++ << "] Show Suitcases" << std::endl;
    std::cout << "[" << option++ << "] Update Suitcase" << std::endl;
    std::cout << "[" << option++ << "] Delete Suitcase" << std::endl;

    std::cout << "[0] Exit" << std::endl;
}
Menu * SuitcaseMenu::getNextMenu() {
    int option;
    if (!input::get(option))
        return invalidOption();
    if (option == 0) {
        return nullptr;
    } else {
        unsigned int id, pos;//TODO
        switch (option) {
            case 1:
                return new RegisterSuitcaseMenu(passenger);
            case 2:
                return new ShowSuitcasesMenu(passenger);
            case 3:
                return new UpdateSuitcasesMenu(passenger);
            case 4:
                return new DeleteSuitcaseMenu(passenger);
        }
    }
    return invalidOption();
}

// ----------------ShowSuitcases Menu -------

ShowSuitcasesMenu::ShowSuitcasesMenu(Passenger * passenger): Menu(),passenger(passenger){};

void ShowSuitcasesMenu::show() {
    system("cls");
    cout << "Your baggage registered in our system: " << endl;
}

Menu * ShowSuitcasesMenu::getNextMenu(){
    cout << "ID\t" << "Weight\t" << "\tType" << endl;
    for(auto idx: passenger->getLuggage()){
        cout << idx->getID() << "\t" << idx->getWeight() << "\t\t" << idx->getType() << endl;
    }
    input::waitEnter();
    return nullptr;
}


// --------------- Register SuitCase ---------------

RegisterSuitcaseMenu::RegisterSuitcaseMenu(Passenger * passenger): Menu(),passenger(passenger){};

void RegisterSuitcaseMenu::show(){
    system("cls");
    cout << "Here you can register your bag! " << endl;
}

Menu * RegisterSuitcaseMenu::getNextMenu(){
    float weight, width, height, length;
    string type;

    cout << "Type (Handbag or HoldSuitcase)" << endl;
    if(!input::get(type)){
        return invalidOption();
    }

    if(type != "Handbag" && type != "HoldSuitcase"){
        return invalidOption();
    }

    cout << "Weight" << endl;
    if(!input::get(weight)){
        return invalidOption();
    }
    cout << "Width" << endl;
    if(!input::get(width)){
        return invalidOption();
    }
    cout << "Height" << endl;
    if(!input::get(height)){
        return invalidOption();
    }
    cout << "Length" << endl;
    if(!input::get(length)){
        return invalidOption();
    }

    Suitcase* temp;
    if(type == "Handbag")
        temp = new Handbag(weight, width, height, length);
    else
        temp = new HoldSuitcase(weight, width, height, length);


    if(!(temp->isAllowedDimensions())){
        cout << "The suitcase exceeds the allowed dimensions!" << endl;
        return invalidOption();
    }

    passenger->addSuitcase(temp);
    input::waitEnter();
    return nullptr;

}

//---------------UPDATE SUITCASE--------------

UpdateSuitcasesMenu::UpdateSuitcasesMenu(Passenger * passenger): Menu(),passenger(passenger){};

void UpdateSuitcasesMenu::show(){
    system("cls");
    cout << "Here you can update the weight of your suitcase! " << endl;
}

Menu* UpdateSuitcasesMenu::getNextMenu() {
    unsigned id;
    float weight;

    cout << "Please enter the bag ID" << endl;
    if(!input::get(id)){
        return invalidOption();
    }

    cout << "Please enter the new weight" << endl;
    if(!input::get(weight)){
        return invalidOption();
    }

    bool result;
    try{
        result = passenger->updateSuitcase(id, weight);
    }catch (ErrorInexistentSuitcase){
        cout << "There is no suitcase with this ID! " << endl;
        input::waitEnter();
        return nullptr;
    }
    if(!result){
        cout << "Invalid weight!" << endl;
    }
    input::waitEnter();
    return nullptr;
}

//---------------DELETE SUITCASE--------------

DeleteSuitcaseMenu::DeleteSuitcaseMenu(Passenger * passenger): Menu(),passenger(passenger){};

void DeleteSuitcaseMenu::show(){
    system("cls");
    cout << "Here you can delete a suitcase. " << endl;
}

Menu* DeleteSuitcaseMenu::getNextMenu() {
    unsigned id;

    cout << "Please enter the bag ID" << endl;
    if(!input::get(id)){
        return invalidOption();
    }

    try{
        passenger->removeSuitcase(id);
    }catch (ErrorInexistentSuitcase){
        cout << "There is no suitcase with this ID! " << endl;
        input::waitEnter();
        return nullptr;
    }

    input::waitEnter();
    return nullptr;
}

// --------------- Cancel Menu ---------------
CancelMenu::CancelMenu(Passenger * passenger) : Menu(),passenger(passenger) {}
void CancelMenu::show() {
    system("cls");
    for(auto t :passenger->getAllTickets()){
        t.show();
        cout << "\n=========================================" << endl;
    }
    cout << "Which ticket do you desire to cancel? [TICKET ID]" << endl;
}

Menu * CancelMenu::getNextMenu() {
    if(passenger->getAllTickets().size() == 0){
        cout << "No tickets!" << endl;
        input::waitEnter();
        return nullptr;
    }
    int ticketID;
    if(!input::get(ticketID)){
        return invalidOption();
    }


    try{
        passenger->getTicket(ticketID);
    }
    catch (ErrorInvalidTicket){
        return invalidOption();
    }


    passenger->getTicket(ticketID).show();


    cout << "\nPRESS [1] If you wish to cancel your ticket " << endl;
    cout << "PRESS [0] TO GO TO PREVIOUS MENU" << endl;

    int option;
    if(!input::get(option))
        return invalidOption();
    if(option == 0){
        return nullptr;
    }
    else if(option == 1){

        try{
            passenger->cancelTicket(ticketID);
        }catch (ErrorInvalidTicket){
            cout << "Error!" << endl;
        }
        cout << "\nTicket canceled with success"<< endl;
        input::waitEnter();
        return nullptr;
    }


    return invalidOption();
}


// ---------------  Flight Menu ---------------
FlightMenu::FlightMenu(Passenger* passenger)  : Menu(),passenger(passenger){loggedIn=true;}

FlightMenu::FlightMenu(bool loggedIn) : Menu(),loggedIn(loggedIn){}


void FlightMenu::show() {
    system("cls");
    string origin, destination;

    cout << "Input your desired destination and origin" << endl;
    cout << "To return press 0" << endl;

}
Menu * FlightMenu::getNextMenu() {

    string origin, destination;

    cout << "From: ";
    if(!input::get(origin))
        return invalidOption();

    if(origin=="0")
        return nullptr;

    cout << endl << "To: ";
    if(!input::get(destination))
        return invalidOption();


    vector<Flight> aux;
    for(auto plane : planes) {
        vector<Flight> temp = plane->getFlight(origin, destination);
        aux.insert(aux.end(),temp.begin(),temp.end());
    }

    if(aux.size()==0){
        cout << "There are no flights available" << endl;
        input::waitEnter();
        return nullptr;
    }

    cout << "IDFlight\tDepartureDate\tDepartureTime\tDuration\tOrigin\tDestination" << endl;
    for(auto idx: aux){
        idx.show();
    }
    if(loggedIn){
        return new BuyMenu(passenger);
    }
    input::waitEnter();
    return nullptr;
}

// --------------- Buy Menu ---------------
BuyMenu::BuyMenu(Passenger* passenger): Menu(),passenger(passenger){}
void BuyMenu::show() {}

Menu * BuyMenu::getNextMenu() {

    int desiredFlightNumber,numOfTickets;
    cout << "Flight Number: ";
    if(!input::get(desiredFlightNumber)){
        return invalidOption();
    }
    Flight chosen;
    Plane planeChosen;
    for(auto plane : planes) {
        for(auto flight : plane->getFlightPlan()) {
            if (flight->getIdFlight() == desiredFlightNumber ){
                chosen = *flight;
                planeChosen = *plane;
            }
        }
    }

    cout << "Number of tickets: ";
    if(!input::get(numOfTickets)){
        return invalidOption();
    }

    for(int i=1;i <= numOfTickets; i++){
        system("cls");
        cout << "(" << i << "/" << numOfTickets << ")" << endl;
        cout << " ===========================================" << endl;

        string username, name,password,seat;
        unsigned nif;
        unsigned age;
        int type;

        cout << "type\n[0]first\n[1]executive\n[2]economic\n ";
        if(!input::get(type)){
            return invalidOption();
        }

        int availableSeats;
        switch(type){
            case 0: availableSeats = planeChosen.getNumSeatsFirst();
            case 1: availableSeats = planeChosen.getNumSeatsExecutive();
            case 2: availableSeats = planeChosen.getNumSeatsEconomic();
        }

        cout << "seat\n ---From 1 to" << availableSeats<<"-----" << endl;
        if(!input::get(seat)){
            return invalidOption();
        }

        cout << "name\n ";
        if(!input::get(name)){
            return invalidOption();
        }
        cout << "nif\n ";
        if(!input::get(nif) || !input::validateID(to_string(nif))){
            return invalidOption();
        }

        cout << "username\n ";
        if(!input::get(username)){
            return invalidOption();
        }

        cout << "password\n ";
        if(!input::get(password)){
            return invalidOption();
        }

        cout << "age\n ";
        if(!input::get(age)){
            return invalidOption();
        }

        users.insert(new Passenger(name, age ,nif,username, password));
        passenger->addTicket(*(new Ticket((TypeTicket)type,seat,chosen)));
        input::waitEnter();

    }
    cout << "THE PROCESS IS COMPLETE" << endl;
    input::waitEnter();
    return nullptr;
}

// --------------- Transports Menu ---------------
TransportsMenu:: TransportsMenu(): Menu() {}
void TransportsMenu::show() {
    system("cls");

    cout << "Here you're be able to search for the transports available at your destination"<< endl;

}

Menu * TransportsMenu::getNextMenu() {
    bool check = true;
    string typeString;
    TypeTransport type;
    float minDistance, maxDistance;
    string origin, destination;
    Time t1,t2;
    Location aux;

    cout << "\nOrigin:";
    if(!input::get(origin)){
        return invalidOption();
    }

    for(auto it : locations){
        if(it->getStr() == origin){
            aux = *it;
            check = false;
            break;
        }
    }

    if(check){
        cout << "Invalid Origin!" << endl;
        input::waitEnter();
        return nullptr;
    }

    cout << "\nMin Distance:";
    if(!input::get(minDistance)){
        return invalidOption();
    }

    cout << "\nMax Distance:";
    if(!input::get(maxDistance)){
        return invalidOption();
    }

    list<Station> closeStations =  aux.getStation(minDistance,maxDistance);
    if(closeStations.size() == 0){
        cout << "There is no station that is in this range." << endl;
        input::waitEnter();
        return nullptr;
    }

    cout << "\nType:";
    if(!input::get(typeString)){
        return invalidOption();
    }

    cout << "\nDestination:";
    if(!input::get(destination)){
        return invalidOption();
    }

    cout << "\n(Time must be in format hh:mm:second)\nFrom:";
    if(!input::get(t1)){
        return invalidOption();
    }

    cout << "Until:";
    if(!input::get(t2)){
        return invalidOption();
    }

    if(typeString == "Metro" || typeString == "metro"){
        type = metro;
    }else if(typeString == "Train" || typeString == "train"){
        type = train;
    }else if(typeString == "Bus" || typeString == "bus"){
        type = bus;
    }else{
        cout << "Invalid transport!" << endl;
        input::waitEnter();
        return nullptr;
    }
    cout << "Type\tDestination" << endl << endl;
    for(auto idx: closeStations){
        cout << "Distance: " << idx.getDistance() << endl;
        try{
            idx.getTransport(destination,type).show(t1,t2);
        }catch (ErrorInexistentTransport){
            continue;
        }
    }
    input::waitEnter();
    return nullptr;
}



// ---------------  Ticket Menu ---------------
TicketsMenu ::TicketsMenu (Passenger* passenger):Menu(), passenger(passenger) {}
void TicketsMenu ::show() {
    system("cls");
    for(auto t :passenger->getAllTickets()){
        t.show();
        cout << "\n=========================================" << endl;
    }
}

Menu * TicketsMenu ::getNextMenu() {
    input::waitEnter();
    return nullptr;
}

// --------------- Check-in Menu ---------------

CheckInMenu ::CheckInMenu(Passenger *passenger):Menu(),passenger(passenger) {}


void CheckInMenu ::show() {
    system("cls");

    cout << "Welcome to the Check In \n"<< endl;


}
Menu * CheckInMenu::getNextMenu() {
    bool check = true;

    unsigned idFlight;
    cout << "Please enter the flight id: ";
    if(!input::get(idFlight)){
        return invalidOption();
    }

    if(!passenger->validTicket(idFlight)){
        cout << "Did not buy a ticket for this flight! " << endl;
        input::waitEnter();
        return nullptr;
    }

    Plane* planeAux;
    Flight flightTemp;

    for(auto plane:planes){
        if(idFlight == plane->getIDFirstFlight()){
            try{
                plane->getFirstFlight();
            }catch (ErrorNoFlight){
                continue;
            }
            flightTemp = *plane->getFirstFlight();
            planeAux = plane;
            check = false;
            break;
        }
    }

    if(check){
        cout << "Error! Either the flight does not exist or the check in has not yet opened." << endl;
        input::waitEnter();
        return nullptr;
    }

    float extraWeight;
    for(auto ticket: passenger->getAllTickets()){
        if(ticket.getFlightID() == idFlight){
            extraWeight = checkIn.checkInPassenger(passenger, ticket);
            try{
                passenger->cancelTicket(ticket.getTicketID());
            }catch(ErrorInvalidTicket){
                cout << "Invalid Ticket!" << endl;
            }
            break;
        }
    }

    if(extraWeight <= 0){
        cout << "You don't have to pay anything extra, have a nice flight"<< endl;
    }

    else{
        cout << " You have to pay " << extraWeight* 2.5 << " euros because of your excess luggage!"<< endl;
    }

    planeAux->addPassenger(passenger);

    input::waitEnter();
    return nullptr;
}






// --------------- Admin Menu ---------------

AdminMenu ::AdminMenu():Menu() {}

void AdminMenu::show() {
    unsigned int options = 0;

    system("cls");
    cout << "Main Menu:\n\n";
    cout << "[" << ++options << "] " << "Flight\n";
    cout << "[" << ++options << "] " << "Service\n";
    cout << "[" << ++options << "] " << "Transport\n";
    cout << "[" << ++options << "] " << "Register Staff\n";
    cout << "[0] Exit\n";
}


Menu * AdminMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }

    switch(option){
        case 0: return nullptr;//TODO
        case 1: return new AdminFlightMenu();
        case 2: return new AdminServiceMenu();
        case 3: return new AdminTransportMenu();
        case 4: return new RegisterStaffMenu();

    }
    return invalidOption();
}


//-----------------ADMIN MENU------------------------



AdminFlightMenu ::AdminFlightMenu():Menu() {}

void AdminFlightMenu::show() {
    unsigned int options = 0;

    system("cls");
    cout << "Admin Flight Menu:\n\n";
    cout << "[" << ++options << "] " << "Create Flight\n";
    cout << "[" << ++options << "] " << "Edit Flight\n";
    cout << "[" << ++options << "] " << "Cancel Flight\n";
    cout << "[" << ++options << "] " << "Create Plane\n";
    cout << "[" << ++options << "] " << "Delete Plane\n";
    cout << "[" << ++options << "] " << "Show Planes\n";
    cout << "[" << ++options << "] " << "Create Transport Car\n";
    cout << "[" << ++options << "] " << "Delete Transport Car\n";
    cout << "[" << ++options << "] " << "Show Transport Car\n";
    cout << "[" << ++options << "] " << "Start Flight\n";
    cout << "[" << ++options << "] " << "Show Passengers\n";
    cout << "[" << ++options << "] " << "Show Cargo Hold\n";

    cout << "[0] Exit\n";
}


Menu * AdminFlightMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }

    switch(option){
        case 0: return nullptr;
        case 1: return new CreateFlightMenu();
        case 2: return new EditFlightMenu();
        case 3: return new CancelFlightMenu();
        case 4: return new CreatePlaneMenu();
        case 5: return new DeletePlaneMenu();
        case 6: return new ShowPlanes();
        case 7: return new CreateTransportCar();
        case 8: return new DeleteTransportCar();
        case 9: return new ShowTransportCar();
        case 10: return new StartFlightMenu();
        case 11: return new ShowPassengersMenu();
        case 12: return new ShowCargoHold();

    }
    return invalidOption();
}


AdminServiceMenu ::AdminServiceMenu():Menu() {}

void AdminServiceMenu::show() {
    unsigned int options = 0;

    system("cls");
    cout << "Admin Service Menu:\n\n";
    cout << "[" << ++options << "] " << "Create Service\n";
    cout << "[" << ++options << "] " << "Do Service\n";
    cout << "[" << ++options << "] " << "Show Service Done\n";
    cout << "[0] Exit\n";
}


Menu * AdminServiceMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }

    switch(option){
    case 0: return nullptr;
    case 1: return new CreateServiceMenu();
    case 2: return new DoServiceMenu();
    case 3: return new ShowServiceDone();
    }
    return invalidOption();
}


AdminTransportMenu ::AdminTransportMenu():Menu() {}

void AdminTransportMenu::show() {
    unsigned int options = 0;

    system("cls");
    cout << "Main Menu:\n\n";
    cout << "[" << ++options << "] " << "Create Station\n";
    cout << "[" << ++options << "] " << "Delete Station\n";
    cout << "[" << ++options << "] " << "Create Transport\n";
    cout << "[" << ++options << "] " << "Delete Transport\n";
    cout << "[" << ++options << "] " << "Create Schedule for a Transport\n";
    cout << "[" << ++options << "] " << "Delete Schedule for a Transport\n";
    cout << "[0] Exit\n";
}


Menu * AdminTransportMenu::getNextMenu() {
    int option;
    if(!input::get(option)){
        return invalidOption();
    }

    switch(option){
        case 0: return nullptr;
        case 1: return new CreateStationMenu();
        case 2: return new DeleteStationMenu();
        case 3: return new CreateTransportMenu();
        case 4: return new DeleteTransportMenu();
        case 5: return new CreateScheduleMenu();
        case 6: return new DeleteScheduleMenu();
    }
    return invalidOption();
}


// --------------- Create Flight Menu ---------------

CreateFlightMenu ::CreateFlightMenu():Menu() {}

void CreateFlightMenu ::show() {
    system("cls");
    cout << "To create a new Flight type object you'll need its number, origin, destination, departureDate and duration"<< endl;

}
Menu * CreateFlightMenu::getNextMenu() {

    if(planes.size() == 0){
        cout << "No planes are available" << endl;
        input::waitEnter();
        return nullptr;
    }

    unsigned idFlight;
    Date departureDate;
    Time departureTime;
    Time duration;
    string originString;
    string destinationString;

    cout << "idFlight\n ";
    if(!input::get(idFlight)){
        return invalidOption();
    }
    cout << "Departure Date\n ";
    if(!input::get(departureDate)){
        return invalidOption();
    }

    cout << "Departure Time\n ";
    if(!input::get(departureTime)){
        return invalidOption();
    }

    cout << "Duration\n ";
    if(!input::get(duration)){
        return invalidOption();
    }

    cout << "Origin\n ";
    if(!input::get(originString)){
        return invalidOption();
    }

    bool checkLocation = true;
    Location* origin;
    for(auto location: locations){
        if(location->getStr() == originString){
            checkLocation = false;
            origin = location;
            break;
        }
    }



    if(checkLocation){
        origin = new Location(originString);
        locations.push_back(origin);
    }

    cout << "Destination\n ";
    if(!input::get(destinationString)){
        return invalidOption();
    }

    checkLocation = true;
    Location* destination;
    for(auto location: locations){
        if(location->getStr() == destinationString){
            checkLocation = false;
            destination = location;
            break;
        }
    }

    if(checkLocation){
        destination = new Location(destinationString);
        locations.push_back(new Location(destinationString));
    }


    (*min_element(planes.begin(),planes.end(),
                  [] (const Plane* p1, const Plane* p2)
                  {
                      return p1->getNumFlights() < p2->getNumFlights();
                  }
    ))->addFlight(new Flight(idFlight,departureDate,departureTime,duration,*origin,*destination));

    input::waitEnter();
    return nullptr;

}

// --------------- Edit Flight Menu ---------------

EditFlightMenu ::EditFlightMenu():Menu() {}

void EditFlightMenu ::show() {
    system("cls");
    cout << "Change the details of a flight" << endl;
}
Menu * EditFlightMenu::getNextMenu() {
    bool check = true;
    unsigned idFlight;
    Date departureDate;
    Time departureTime;
    Time duration;
    Location origin;
    Location destination;

    cout << "idFlight\n ";
    if(!input::get(idFlight)){
        return invalidOption();
    }

    cout << "Departure Date\n ";
    if(!input::get(departureDate)){
        return invalidOption();
    }

    cout << "Departure Time\n ";
    if(!input::get(departureTime)){
        return invalidOption();
    }

    cout << "Duration\n ";
    if(!input::get(duration)){
        return invalidOption();
    }

    cout << "Origin\n ";
    if(!input::get(origin)){
        return invalidOption();
    }

    cout << "Destination\n ";
    if(!input::get(destination)){
        return invalidOption();
    }

    for(auto plane: planes){
        try{
            plane->updateFlight(idFlight, departureDate, departureTime, duration, destination, origin);
        }catch(ErrorNoFlight){
            continue;
        }
        cout << "Success!" << endl;
        input::waitEnter();
        return nullptr;
    }
    cout << "Invalid Flight!" << endl;
    input::waitEnter();
    return nullptr;
}

// --------------- Delete Flight Menu ---------------

CancelFlightMenu ::CancelFlightMenu():Menu() {}

void CancelFlightMenu ::show() {
    system("cls");


}
Menu * CancelFlightMenu::getNextMenu() {

    int number;
    cout << "Delete Flight Number\n ";
    if(!input::get(number)){
        return invalidOption();
    }


    for(auto plane : planes) {
        if(plane->removeFlight(number)){
            cout << "Flight successfully deleted" << endl;
            input::waitEnter();
            return nullptr;
        }
    }

    cout << "Flight not found" << endl;
    input::waitEnter();
    return nullptr;
}

// --------------- Create Service Menu ---------------

CreateServiceMenu ::CreateServiceMenu():Menu() {}

void CreateServiceMenu ::show() {
    system("cls");

}
Menu * CreateServiceMenu::getNextMenu() {

    int licensePlate;
    bool check = true;

    if(staff.size() == 0){
        cout << "There is no staff registered in our system yet." << endl;
        input::waitEnter();
        return nullptr;
    }

    cout << "License Plate of the plane you are requesting a service for\n ";
    if(!input::get(licensePlate)){
        return invalidOption();
    }

    cout << " ------- Specify the type of service you require -------" << endl;
    Date date;
    Time time;
    string type;
    cout << "date: ";
    if(!input::get(date)){
        return invalidOption();
    }
    cout << "time: ";
    if(!input::get(time)){
        return invalidOption();
    }
    cout << "type: ";
    if(!input::get(type)){
        return invalidOption();
    }
    Service s1;
    if(type == "Cleaning" || type == "cleaning")
        s1 = Service(*staff.at(rand() % staff.size()), date, time, cleaning);
    else if(type == "Maintenance" || type == "maintenance")
        s1= Service(*staff.at(rand() % staff.size()), date, time, maintenance);
    else{
        cout << "Error! Only cleaning and maintenance services are available." << endl;
        input::waitEnter();
        return nullptr;
    }
    for(auto plane : planes) {
        if((*plane).getLicensePlate() == licensePlate){
            plane->addService(s1);
            check = false;
        }
    }
    if(check){
        cout << "No plane that is registered in our system has this license plate." << endl;
    }
    input::waitEnter();
    return nullptr;
}

// --------------- Create Station Menu ---------------

CreateStationMenu ::CreateStationMenu():Menu() {}

void CreateStationMenu ::show() {
    system("cls");
    cout << "In this Menu you'll be creating a new Station and append it to a known location" << endl;
}

Menu * CreateStationMenu ::getNextMenu() {

    string city;
    float distance;
    unsigned id;
    cout << "City\n ";
    if(!input::get(city)){
        return invalidOption();
    }

    bool checkLocation = true;
    Location* it;
    for(auto location: locations){
        if(location->getStr() == city){
            checkLocation = false;
            it = location;
            break;
        }
    }

    if(checkLocation){
        it = new Location(city);
        locations.push_back(it);
    }

    cout << "Distance from closest airport\n ";
    if(!input::get(distance)){
        return invalidOption();
    }

    try{
        it->getStation(distance);
    }catch (ErrorInvalidStation){
        it->addStation(Station(distance));
        input::waitEnter();
        return nullptr;
    }

    cout << "There is already a station with this distance" << endl;
    input::waitEnter();
    return nullptr;
}

// --------------- Create Transport Menu ---------------

CreateTransportMenu ::CreateTransportMenu():Menu() {}

void CreateTransportMenu ::show() {
    system("cls");
    cout << "In this Menu you'll be creating a new transport" << endl;
}

Menu * CreateTransportMenu ::getNextMenu() {//TO DO

    string city,destination;
    string type;
    float distance;

    cout << "City\n ";
    if(!input::get(city)){
        return invalidOption();
    }

    cout << "Distance\n";
    if(!input::get(distance)){
        return invalidOption();
    }

    cout << "Destination\n ";
    if(!input::get(destination)){
        return invalidOption();
    }

    cout << "Type of transport\n ";
    if(!input::get(type)){
        return invalidOption();
    }
    Transport t1;
    if(type=="Metro" || type == "metro"){
        t1= Transport(destination, metro);
    }else if(type == "Bus" || type == "bus"){
        t1= Transport(destination, bus);
    }else if(type == "Train" || type == "train"){
        t1= Transport(destination, train);
    }else{
        cout << "Invalid type of transport!" << endl;
        input::waitEnter();
        return nullptr;
    }

    for(auto it: locations) {
        if(it->getStr() == city)
        {
            try {
                it->getStation(distance);
            } catch (ErrorInvalidStation) {
                cout << "Invalid station!" << endl;
               input::waitEnter();
               return nullptr;
            }
            Station aux = it->getStation(distance);
            try{
                aux.getTransport(t1);
            }catch (ErrorInexistentTransport){
                it->removeStation(distance);
                aux.addTransport(t1);
                it->addStation(aux);
                input::waitEnter();
                return nullptr;
            }
            cout << "There is already a transport with these attributes" << endl;
            input::waitEnter();
            return nullptr;
        }
    }
    cout << "Invalid origin or distance!" << endl;
    input::waitEnter();
    return nullptr;
}


// --------------- Delete Transport Menu ---------------

DeleteTransportMenu ::DeleteTransportMenu():Menu() {}

void DeleteTransportMenu ::show() {
    system("cls");

}
Menu * DeleteTransportMenu ::getNextMenu() {
    string city,destination,type;
    float distance;

    cout << "City\n ";
    if(!input::get(city)){
        return invalidOption();
    }

    cout << "Distance\n ";
    if(!input::get(distance)){
        return invalidOption();
    }

    cout << "Destination\n ";
    if(!input::get(destination)){
        return invalidOption();
    }

    cout << "Type of transport\n ";
    if(!input::get(type)){
        return invalidOption();
    }
    Transport t1;
    if(type=="Metro" || type == "metro"){
        t1= Transport(destination, metro);
    }else if(type == "Bus" || type == "bus"){
        t1= Transport(destination, bus);
    }else if(type == "Train" || type == "train"){
        t1= Transport(destination, train);
    }else{
        cout << "Invalid type of transport!" << endl;
        input::waitEnter();
        return nullptr;
    }

    for(auto it: locations) {
        if(it->getStr() == city)
        {
            try {
                it->getStation(distance);
            } catch (ErrorInvalidStation) {
                cout << "Invalid station!" << endl;
                input::waitEnter();
                return nullptr;
            }
            Station aux = it->getStation(distance);
            it->removeStation(distance);
            aux.removeTransport(t1);
            it->addStation(aux);
            input::waitEnter();
            return nullptr;
        }
    }
    cout << "Invalid origin or distance!" << endl;
    input::waitEnter();
    return nullptr;
}
// --------------- Create/Edit Schedule Menu ---------------

CreateScheduleMenu ::CreateScheduleMenu():Menu() {}

void CreateScheduleMenu ::show() {
    system("cls");
    cout << "In this Menu you'll be able to create the schedule of a specific transport" << endl;

}

Menu * CreateScheduleMenu::getNextMenu() {
    string city,destination,type;
    float distance;

    cout << "City\n ";
    if(!input::get(city)){
        return invalidOption();
    }

    cout << "Distance\n ";
    if(!input::get(distance)){
        return invalidOption();
    }

    cout << "destination\n ";
    if(!input::get(destination)){
        return invalidOption();
    }

    cout << "Type of transport\n ";
    if(!input::get(type)){
        return invalidOption();
    }
    Transport t1;
    if(type=="Metro" || type == "metro"){
        t1= Transport(destination, metro);
    }else if(type == "Bus" || type == "bus"){
        t1= Transport(destination, bus);
    }else if(type == "Train" || type == "train"){
        t1= Transport(destination, train);
    }else{
        cout << "Invalid type of transport!" << endl;
        input::waitEnter();
        return nullptr;
    }

    Time time;
    cout << "Time it stops at the station\n ";
    if(!input::get(time)){
        return invalidOption();
    }

    for(auto it: locations) {
        if(it->getStr() == city)
        {
            try {
                it->getStation(distance).getTransport(t1);
            } catch (ErrorInvalidStation) {
                cout << "Invalid station!" << endl;
                input::waitEnter();
                return nullptr;
            }catch(ErrorInexistentTransport){
                cout << "Inexistent Transport!" << endl;
                input::waitEnter();
                return nullptr;
            }
            Station aux = it->getStation(distance);
            it->removeStation(distance);
            aux.getTransport(t1).addTime(time);
            it->addStation(aux);
            input::waitEnter();
            return nullptr;
        }
    }
    cout << "Invalid origin or distance!" << endl;
    input::waitEnter();
    return nullptr;
}
// --------------- Start Flight Menu ---------------

StartFlightMenu::StartFlightMenu():Menu() {}

void StartFlightMenu::show() {
    system("cls");
    cout << "In this Menu you'll be starting the next flight" << endl;
}

Menu* StartFlightMenu::getNextMenu() {
    if(planes.size() == 0){
        cout << "There are no planes" << endl;
        input::waitEnter();
        return nullptr;
    }
    if(treadmill.getNumCarsAvailable() == 0){
        cout << "There are no available transport cars" << endl;
        input::waitEnter();
        return nullptr;
    }

    vector<Flight*> temp;
    for(auto plane:planes){
        try{
            plane->getFirstFlight();
        }catch(ErrorNoFlight){
            continue;
        }
        temp.push_back(plane->getFirstFlight());
    }


    if(temp.size() == 0){
        cout << "There are no flights" << endl;
        input::waitEnter();
        return nullptr;
    }

    Flight* flightAux = *min_element(temp.begin(),temp.end(), [] (Flight const* f1, Flight const* f2)
    {
        if(f1->getDepartureDate() == f2->getDepartureDate())
            return !(f1->getDepartureTime() < f2->getDepartureTime());
        return f1->getDepartureDate() < f2->getDepartureDate();
    });
    cout << "Start Flight with this Flight ID: " << flightAux->getIdFlight() << endl << endl;


    for(auto plane:planes){
        if(flightAux->getIdFlight() == plane->getIDFirstFlight()){
            treadmill.loadTransportPlane(flightAux->getIdFlight(), plane);
            plane->setNextFlight();
            input::waitEnter();
            return nullptr;
        }
    }
    input::waitEnter();
    return nullptr;

}

//---------------Show Passengers Menu----------
ShowPassengersMenu::ShowPassengersMenu():Menu(){}

void ShowPassengersMenu::show(){
    system("cls");
    cout << "Shows passengers who are already on a plane for a particular flight" << endl;
}

Menu* ShowPassengersMenu::getNextMenu(){
    unsigned idFlight;
    bool check = true;
    cout << "Enter the flight id" << endl;
    if(!input::get(idFlight)){
        return invalidOption();
    }

    for(auto plane: planes) {
        try {
            plane->getIDFirstFlight();
        } catch (ErrorNoFlight) {
            continue;
        }
        if (plane->getIDFirstFlight() == idFlight) {
            plane->showAllPassengers();
            check = false;
            break;
        }
    }

    if(check){
        cout << "There are no flights with this id" << endl;
    }

    input::waitEnter();
    return nullptr;

}

//---------------Show Cargo Hold Menu----------

ShowCargoHold::ShowCargoHold():Menu() {}

void ShowCargoHold::show() {
    system("cls");
    cout << "Shows the bags that are in the hold of a particular flight" << endl;
}

Menu* ShowCargoHold::getNextMenu() {
    unsigned idFlight;
    bool check = true;
    cout << "Enter the flight id" << endl;
    if(!input::get(idFlight)){
        return invalidOption();
    }


    for(auto plane: planes) {
        try {
            plane->getIDFirstFlight();
        } catch (ErrorNoFlight) {
            continue;
        }
        if (plane->getIDFirstFlight() == idFlight) {
            plane->showCargoHold();
            check = false;
            break;
        }
    }

    if(check){
        cout << "There are no flights with this id" << endl;
    }

    input::waitEnter();
    return nullptr;

}

//------------DO Service Menu-------------

DoServiceMenu::DoServiceMenu():Menu() {}

void DoServiceMenu::show(){
    system("cls");
    cout << "Orders to start a service on a particular plane" << endl;
}

Menu* DoServiceMenu::getNextMenu() {
    int licensePlate;
    bool check = true;
    cout << "Enter the license plate" << endl;
    if (!input::get(licensePlate)) {
        return invalidOption();
    }

    for(auto plane:planes){
        if(plane->getLicensePlate() == licensePlate){
            plane->doService();
            check = false;
            break;
        }
    }
    if(check){
        cout << "There are no planes with this plate" << endl;
    }

    input::waitEnter();
    return nullptr;
}


//--------------------Create Plane Menu---------------
CreatePlaneMenu::CreatePlaneMenu():Menu() {}

void CreatePlaneMenu::show() {
    system("cls");
    cout << "Create a plane" << endl;
}

Menu* CreatePlaneMenu::getNextMenu() {
    unsigned numSeatsFirst, numSeatsExecutive, numSeatsEconomic;
    int licensePlate;
    string model;

    cout << "Number of First Class Seats"<<endl;
    if (!input::get(numSeatsFirst)) {
        return invalidOption();
    }
    cout << "Number of Executive Seats"<<endl;
    if (!input::get(numSeatsExecutive)) {
        return invalidOption();
    }
    cout << "Number of Economic Seats"<<endl;
    if (!input::get(numSeatsEconomic)) {
        return invalidOption();
    }
    cout << "License plate"<<endl;
    if (!input::get(licensePlate)) {
        return invalidOption();
    }
    cout << "Model"<<endl;
    if (!input::get(model)) {
        return invalidOption();
    }

    planes.push_back(new Plane(numSeatsFirst,numSeatsExecutive,numSeatsEconomic,licensePlate,model));
    input::waitEnter();
    return nullptr;
}

//--------------------Delete Plane Menu---------------
DeletePlaneMenu::DeletePlaneMenu():Menu() {}

void DeletePlaneMenu::show() {
    system("cls");
    cout << "Delete a certain plane" << endl;
}

Menu* DeletePlaneMenu::getNextMenu() {
    int licensePlate;
    bool check = true;

    cout << "License plate"<<endl;
    if (!input::get(licensePlate)) {
        return invalidOption();
    }

    for(auto it = planes.begin(); it != planes.end(); it++){
        if((*it)->getLicensePlate() == licensePlate){
            planes.erase(it);
            check = false;
            break;
        }
    }

    if(check){
        cout << "There are no planes with this plate" << endl;
    }

    input::waitEnter();
    return nullptr;
}

//------------------SHOW PLANE----------------------

ShowPlanes::ShowPlanes():Menu() {}

void ShowPlanes::show() {
    system("cls");
    cout << "Plate\tModel"<<endl;
}

Menu* ShowPlanes::getNextMenu() {
    for(auto idx: planes){
        idx->show();
    }
    input::waitEnter();
    return nullptr;
}

//--------------------SHOW SERVICE--------------------

ShowServiceDone::ShowServiceDone():Menu() {}

void ShowServiceDone::show() {
    system("cls");
    cout << "Shows the services performed on a particular plane" << endl;
}

Menu* ShowServiceDone::getNextMenu() {
    int licensePlate;
    bool check = true;

    cout << "License plate"<<endl;
    if (!input::get(licensePlate)) {
        return invalidOption();
    }

    for(auto it = planes.begin(); it != planes.end(); it++){
        if((*it)->getLicensePlate() == licensePlate){
            (*it)->showService();
            check = false;
            break;
        }
    }

    input::waitEnter();
    return nullptr;
}

// ------------------------ DELETE Station -----------------

DeleteStationMenu::DeleteStationMenu():Menu() {}

void DeleteStationMenu::show() {
    system("cls");
    cout << "Erases a station" << endl;
}

Menu* DeleteStationMenu::getNextMenu() {
    string city;
    float distance;
    cout << "City\n ";
    if(!input::get(city)){
        return invalidOption();
    }

    bool checkLocation = true;
    Location* it;
    for(auto location: locations){
        if(location->getStr() == city){
            checkLocation = false;
            it = location;
            break;
        }
    }

    if(checkLocation){
        cout << "There is no city that is registered with this name." << endl;
        input::waitEnter();
        return nullptr;
    }

    cout << "Distance from closest airport\n ";
    if(!input::get(distance)){
        return invalidOption();
    }

    it->removeStation(distance);

    input::waitEnter();
    return nullptr;
}


//-------------------DELETE SCHEDULE MENU------------------

DeleteScheduleMenu ::DeleteScheduleMenu():Menu() {}

void DeleteScheduleMenu ::show() {
    system("cls");
    cout << "In this Menu you'll be able to delete the schedule of a specific transport" << endl;

}


Menu * DeleteScheduleMenu::getNextMenu() {
    string city,destination,type;
    float distance;

    cout << "City\n ";
    if(!input::get(city)){
        return invalidOption();
    }

    cout << "Distance\n ";
    if(!input::get(distance)){
        return invalidOption();
    }

    cout << "destination\n ";
    if(!input::get(destination)){
        return invalidOption();
    }

    cout << "Type of transport\n ";
    if(!input::get(type)){
        return invalidOption();
    }
    Transport t1;
    if(type=="Metro" || type == "metro"){
        t1= Transport(destination, metro);
    }else if(type == "Bus" || type == "bus"){
        t1= Transport(destination, bus);
    }else if(type == "Train" || type == "train"){
        t1= Transport(destination, train);
    }else{
        cout << "Invalid type of transport!" << endl;
        input::waitEnter();
        return nullptr;
    }

    Time time;
    cout << "Time it stops at the station\n ";
    if(!input::get(time)){
        return invalidOption();
    }

    for(auto it: locations) {
        if(it->getStr() == city)
        {
            try{
                it->getStation(distance).getTransport(t1);
            }catch(ErrorInexistentTransport){
                cout << "Invalid Transport!." << endl;
                input::waitEnter();
                return nullptr;
            }
            catch(ErrorInvalidStation){
                cout << "Invalid station!" << endl;
                input::waitEnter();
                return nullptr;
            }

            Station aux = it->getStation(distance);
            it->removeStation(distance);
            if(!aux.getTransport(t1).removeTime(time)){
                cout << "No transport has this time." << endl;
            }
            it->addStation(aux);
            input::waitEnter();
            return nullptr;
        }
    }
    cout << "Invalid origin or distance!" << endl;
    input::waitEnter();
    return nullptr;
}

//---------------------Transport Car---------------------

CreateTransportCar::CreateTransportCar():Menu() {}

void  CreateTransportCar::show() {
    system("cls");
    cout << "In this Menu you'll be able to create a transport car" << endl;

}

Menu * CreateTransportCar::getNextMenu() {
    unsigned numCarriages, maxNumSuitcases, maxNumStacks;

    cout << "Number of Carriages\n ";
    if(!input::get(numCarriages)){
        return invalidOption();
    }

    cout << "Maximum number of bags in a stack\n ";
    if(!input::get(maxNumSuitcases)){
        return invalidOption();
    }

    cout << "Maximum number of stacks\n ";
    if(!input::get(maxNumStacks)){
        return invalidOption();
    }

    treadmill.addTransportCart(TransportCar(numCarriages,maxNumSuitcases,maxNumStacks));

    input::waitEnter();
    return nullptr;
}

DeleteTransportCar::DeleteTransportCar():Menu() {}

void  DeleteTransportCar::show() {
    system("cls");
    cout << "In this Menu you'll be able to delete a transport car" << endl;
}

Menu * DeleteTransportCar::getNextMenu() {
    unsigned id;
    cout << "ID\n ";
    if(!input::get(id)){
        return invalidOption();
    }

    vector<TransportCar>* aux = treadmill.getCars();
    auto it = find(aux->begin(),aux->end(), TransportCar(id));

    if(it==aux->end()){
        cout << "There is no transport car with this id." << endl;
        input::waitEnter();
        return nullptr;
    }

    aux->erase(it);
    input::waitEnter();
    return nullptr;
}

ShowTransportCar::ShowTransportCar():Menu() {}

void  ShowTransportCar::show() {
    system("cls");
    cout << "In this Menu you'll be able to show all transports cars" << endl;

}

Menu * ShowTransportCar::getNextMenu() {
    treadmill.showCars();
    input::waitEnter();
    return nullptr;
}