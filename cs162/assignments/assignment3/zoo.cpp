#include "./zoo.h"
#include "./animal.h"
#include "./sea_lion.h"
#include "./tiger.h"
#include "./black_bear.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


Zoo::Zoo(){
    set_month(12);
    set_year(1999);
    set_zoo_name("Zoo");
    set_food_price(80);
    set_food_mod(0);
    set_bank(100000);
    set_num_animals(0);
    set_num_sea_lions(0);
    set_num_tigers(0);
    set_num_black_bears(0);
    sea_lion_pen = new Sea_lion[num_sea_lions];
    tiger_pen = new Tiger[num_tigers];
    black_bear_pen = new Black_bear[num_black_bears];
}

Zoo::~Zoo(){
    delete [] sea_lion_pen;
    delete [] tiger_pen;
    delete [] black_bear_pen;
}

int Zoo::get_month(){
    return month;
}

int Zoo::get_year(){
    return year;
}

string Zoo::get_zoo_name(){
    return zoo_name;
}

int Zoo::get_food_price(){
    return food_price;
}

int Zoo::get_food_mod(){
    return food_mod;
}

int Zoo::get_bank(){
    return bank;
}

int Zoo::get_num_animals(){
    return num_animals;
}

int Zoo::get_num_sea_lions(){
    return num_sea_lions;
}

int Zoo::get_num_tigers(){
    return num_tigers;
}

int Zoo::get_num_black_bears(){
    return num_black_bears;
}

void Zoo::set_month(int new_month){
    month = new_month;
}

void Zoo::set_year(int new_year){
    year = new_year;
}

void Zoo::set_zoo_name(string new_zoo_name){
    zoo_name = new_zoo_name;
}

void Zoo::set_food_price(int new_food_price){
    food_price = new_food_price;
}

void Zoo::set_food_mod(int new_food_mod){
    food_mod = new_food_mod;
}

void Zoo::set_bank(int new_bank){
    bank = new_bank;
}

void Zoo::set_num_animals(int new_num_animals){
    num_animals = new_num_animals;
}

void Zoo::set_num_sea_lions(int new_num_sea_lions){
    num_sea_lions = new_num_sea_lions;
}

void Zoo::set_num_tigers(int new_num_tigers){
    num_tigers = new_num_tigers;
}

void Zoo::set_num_black_bears(int new_num_black_bears){
    num_black_bears = new_num_black_bears;
}

void Zoo::add_sea_lion(int num_new_sea_lions, int new_sea_lions_age){
    for(int i = 0; i < num_new_sea_lions; i++){
        num_sea_lions += 1;
        num_animals += 1;
        Sea_lion* temp = new Sea_lion[num_sea_lions];
        for(int j = 0; j < num_sea_lions - 1; j++)
            temp[j] = sea_lion_pen[j];
        Sea_lion new_sea_lion(new_sea_lions_age);
        temp[num_sea_lions - 1] = new_sea_lion;
        delete [] sea_lion_pen;
        sea_lion_pen = new Sea_lion[num_sea_lions];
        for(int j = 0; j < num_sea_lions; j++)
            sea_lion_pen[j] = temp[j];
        delete [] temp;
    }
}

void Zoo::add_tiger(int num_new_tigers, int new_tigers_age){
    for(int i = 0; i < num_new_tigers; i++){
        num_tigers += 1; 
        num_animals += 1;
        Tiger* temp = new Tiger[num_tigers];
        for(int j = 0; j < num_tigers - 1; j++)
            temp[j] = tiger_pen[j];
        Tiger new_tiger(new_tigers_age);
        temp[num_tigers - 1] = new_tiger;
        delete [] tiger_pen;
        tiger_pen = new Tiger[num_tigers];
        for(int j = 0; j < num_tigers; j++)
            tiger_pen[j] = temp[j];
        delete [] temp;
    }
}

void Zoo::add_black_bear(int num_new_black_bears, int new_black_bears_age){
    for(int i = 0; i < num_new_black_bears; i++){
        num_black_bears += 1; 
        num_animals += 1;
        Black_bear* temp = new Black_bear[num_black_bears];
        for(int j = 0; j < num_black_bears - 1; j++)
            temp[j] = black_bear_pen[j];
        Black_bear new_black_bear(new_black_bears_age);
        temp[num_black_bears - 1] = new_black_bear;
        delete [] black_bear_pen;
        black_bear_pen = new Black_bear[num_black_bears];
        for(int j = 0; j < num_black_bears; j++)
            black_bear_pen[j] = temp[j];
        delete [] temp;
    }
}

void Zoo::remove_sea_lion(int index){
    num_sea_lions -= 1;
    num_animals -= 1;
    Sea_lion* temp = new Sea_lion[num_sea_lions];
    for(int i = 0; i < num_sea_lions; i++){
        if(i < index)
            temp[i] = sea_lion_pen[i];
        else
            temp[i] = sea_lion_pen[i + 1];
    }
    delete [] sea_lion_pen;
    sea_lion_pen = new Sea_lion[num_sea_lions];
    for(int i = 0; i < num_sea_lions; i++)
        sea_lion_pen[i] = temp[i];
    delete [] temp;
}

void Zoo::remove_tiger(int index){
    num_tigers -= 1;
    num_animals -= 1;
    Tiger* temp = new Tiger[num_tigers];
    for(int i = 0; i < num_tigers; i++){
        if(i < index)
            temp[i] = tiger_pen[i];
        else
            temp[i] = tiger_pen[i + 1];
    }
    delete [] tiger_pen;
    tiger_pen = new Tiger[num_tigers];
    for(int i = 0; i < num_tigers; i++)
        tiger_pen[i] = temp[i];
    delete [] temp;
}

void Zoo::remove_black_bear(int index){
    num_black_bears -= 1;
    num_animals -= 1;
    Black_bear* temp = new Black_bear[num_black_bears];
    for(int i = 0; i < num_black_bears; i++){
        if(i < index)
            temp[i] = black_bear_pen[i];
        else
            temp[i] = black_bear_pen[i + 1];
    }
    delete [] black_bear_pen;
    black_bear_pen = new Black_bear[num_black_bears];
    for(int i = 0; i < num_black_bears; i++)
        black_bear_pen[i] = temp[i];
    delete [] temp;
}

void Zoo::one_month_passes(){
    cout << " • Onto the next month ! ... (1 to continue) : ";
    if(get_month() < 12)
        set_month(get_month() + 1);
    else{
        set_month(1);
        set_year(get_year() + 1);
    }
    for(int i = 0; i < get_num_sea_lions(); i++)
        sea_lion_pen[i].set_age(sea_lion_pen[i].get_age() + 1);
    for(int i = 0; i < get_num_tigers(); i++)
        tiger_pen[i].set_age(tiger_pen[i].get_age() + 1);
    for(int i = 0; i < get_num_black_bears(); i++)
        black_bear_pen[i].set_age(black_bear_pen[i].get_age() + 1);
    cin >> trash;
}

void Zoo::determine_event(){
    int num = gen_rand_num(0, 7 + get_food_mod());
    if(num > 5 && get_num_animals() > 0)
        sickness();
    else if(num > 3 && get_num_animals() > 0)
        birth();
    else if(num > 1 && get_num_animals() > 0)
        attendance_boom();
    else{
        cout << " • Nothing exciting this month... (1 to continue) : ";
        cin >> trash;
        cout << endl;
    }
}

int Zoo::generate_money(){
    int revenue = 0;
    for(int i = 0; i < get_num_sea_lions(); i++){
        if(sea_lion_pen[i].get_age() > 6)
            revenue += sea_lion_pen[i].get_revenue();
        else
            revenue += sea_lion_pen[i].get_revenue() * 2;
    }
    for(int i = 0; i < get_num_tigers(); i++){
        if(sea_lion_pen[i].get_age() > 6)
            revenue += tiger_pen[i].get_revenue();
        else
            revenue += tiger_pen[i].get_revenue() * 2;
    }
    for(int i = 0; i < get_num_black_bears(); i++){
        if(sea_lion_pen[i].get_age() > 6)
            revenue += black_bear_pen[i].get_revenue();
        else
            revenue += black_bear_pen[i].get_revenue() * 2;
    }
    set_bank(get_bank() + revenue);
    reset_boom();
    return revenue;
}

void Zoo::buy_animals(){
    int animal_type;
    int animal_amount;
    cout << " • What kind of animal will you buy? (sea lion - 1 | tiger - 2 | black bear - 3) : ";
    cin >> animal_type;
    print_game();
    cout << " • How many will you buy? (0 to 2) : ";
    cin >> animal_amount;
    if(animal_amount > 2)
        animal_amount = 2;
    if(animal_type == 1){
        add_sea_lion(animal_amount, 48);
        set_bank(get_bank() - 800 * animal_amount);
    }else if(animal_type == 2){
        add_tiger(animal_amount, 48);
        set_bank(get_bank() - 10000 * animal_amount);
    }else{
        add_black_bear(animal_amount, 48);
        set_bank(get_bank() - 5000 * animal_amount);
    }
}

void Zoo::buy_food(){
    int food_amount = 0;
    int choice;
    for(int i = 0; i < get_num_sea_lions(); i++)
        food_amount += 1;
    for(int i = 0; i < get_num_tigers(); i++)
        food_amount += 5;
    for(int i = 0; i < get_num_black_bears(); i++)
        food_amount += 3;
    cout << " • You need to buy " << food_amount << " food this month. What type will you buy? (1 - cheap | 2 - regular | 3 - supreme) : ";
    cin >> choice;
    if(choice == 1){
        set_bank(get_bank() - (food_amount * get_food_price() / 2));
        set_food_mod(1);
    }else if(choice == 2){
        set_bank(get_bank() - (food_amount * get_food_price()));
        set_food_mod(0);
    }else{
        set_bank(get_bank() - (food_amount * get_food_price() * 2));
        set_food_mod(-1);
    }
    set_food_price(gen_rand_num(get_food_price() * 0.8, get_food_price() * 1.2));
}

bool Zoo::keep_playing(){
    if(get_bank() >= 0){
        int choice;
        cout << " • Go to the next month? (1 - yes | not 1 - no) : ";
        cin >> choice;
        if(choice == 1)
            return true;
    }
    return false;
}

void Zoo::sickness(){
    cout << " • EVENT: Sick | ";
    int pen_num;
    int pen_index;
    while(true){
        pen_num = gen_rand_num(0, 2);
        if(pen_num == 0 && get_num_sea_lions() > 0){
            pen_index = gen_rand_num(0, get_num_sea_lions() - 1);
            if(sea_lion_pen[pen_index].get_age() < 6){
                cout << "A baby sea lion is sick it will cost you $800 for treatment... (1 to continue) : ";
                cin >> trash;
                if(get_bank() >= 800){
                    set_bank(get_bank() - 800);
                    print_game();
                    cout << "You saved it! ... (1 to continue) : ";
                }else{
                    remove_sea_lion(pen_index);
                    print_game();
                    cout << "It died :( ... (1 to continue) : ";
                }
            }else{
                cout << "A sea lion is sick it will cost you $400 for treatment... (1 to continue) : ";
                cin >> trash;
                if(get_bank() >= 400){
                    set_bank(get_bank() - 400);
                    print_game();
                    cout << "You saved it! ... (1 to continue) : ";
                }else{
                    remove_sea_lion(pen_index);
                    print_game();
                    cout << "It died :( ... (1 to continue) : ";
                }
            }
            break;
        }else if(pen_num == 1 && get_num_tigers() > 0){
            pen_index = gen_rand_num(0, get_num_tigers() - 1);
            if(tiger_pen[pen_index].get_age() < 6){
                cout << "A baby tiger is sick it will cost you $10000 for treatment... (1 to continue) : ";
                cin >> trash;
                if(get_bank() >= 10000){
                    set_bank(get_bank() - 10000);
                    print_game();
                    cout << " • You saved it! ... (1 to continue) : ";
                }else{
                    remove_tiger(pen_index);
                    print_game();
                    cout << " • It died :( ... (1 to continue) : ";
                }
            }else{
                cout << "A tiger is sick it will cost you $5000 for treatment... (1 to continue) : ";
                cin >> trash;
                if(get_bank() >= 5000){
                    set_bank(get_bank() - 5000);
                    print_game();
                    cout << " • You saved it! ... (1 to continue) : ";
                }else{
                    remove_tiger(pen_index);
                    print_game();
                    cout << " • It died :( ... (1 to continue) : ";
                }
            }
            break;
        }else if(pen_num == 2 && get_num_black_bears() > 0){
            pen_index = gen_rand_num(0, get_num_black_bears() - 1);
            if(black_bear_pen[pen_index].get_age() < 6){
                cout << "A baby black_bear is sick it will cost you $5000 for treatment... (1 to continue) : ";
                cin >> trash;
                if(get_bank() >= 5000){
                    set_bank(get_bank() - 5000);
                    print_game();
                    cout << " • You saved it! ... (1 to continue) : ";
                }else{
                    remove_black_bear(pen_index);
                    print_game();
                    cout << " • It died :( ... (1 to continue) : ";
                }
            }else{
                cout << "A black_bear is sick it will cost you $2500 for treatment... (1 to continue) : ";
                cin >> trash;
                if(get_bank() >= 2500){
                    set_bank(get_bank() - 2500);
                    print_game();
                    cout << " • You saved it! ... (1 to continue) : ";
                }else{
                    remove_black_bear(pen_index);
                    print_game();
                    cout << " • It died :( ... (1 to continue) : ";
                }
            }
            break;
        }
    }
    cin >> trash;
    cout << endl;
}

void Zoo::birth(){
    cout << " • EVENT: Birth | ";
    int pen_num = gen_rand_num(0, 2);
    while(pen_num < 7){
        if((pen_num == 0 || pen_num == 3) && get_num_sea_lions() > 0){
            for(int i = 0; i < get_num_sea_lions(); i++)
                if(sea_lion_pen[i].get_age() > 47){
                    cout << "A baby sea lion was born! ... (1 to continue) : ";
                    add_sea_lion(1, 0);
                    pen_num = 7;
                    break;
                }
        }else if((pen_num == 1 || pen_num == 4) && get_num_tigers() > 0){
            for(int i = 0; i < get_num_tigers(); i++)
                if(tiger_pen[i].get_age() > 47){
                    cout << "Three baby tigers were born! ... (1 to continue) : ";
                    add_tiger(3, 0);
                    pen_num = 7;
                    break;
                }
        }else if((pen_num == 2 || pen_num == 5) && get_num_black_bears() > 0){
            for(int i = 0; i < get_num_black_bears(); i++)
                if(black_bear_pen[i].get_age() > 47){
                    cout << "Two baby black bears were born! ... (1 to continue) : ";
                    add_black_bear(2, 0);
                    pen_num = 7;
                    break;
                }
        }else if(pen_num == 6)
            cout << " • Your animals are too young for this... (1 to continue) : ";
        pen_num++;
    }
    cin >> trash;
    cout << endl;
}

void Zoo::attendance_boom(){
    for(int i = 0; i < get_num_sea_lions(); i ++)
        sea_lion_pen[i].set_revenue(160 + gen_rand_num(150, 400));
    cout << "EVENT: Boom | Your sea lions are loving the attention and will attract more guest! ... (1 to continue) : ";
    cin >> trash;
    cout << endl;
}

void Zoo::reset_boom(){
    for(int i = 0; i < get_num_sea_lions(); i ++)
        sea_lion_pen[i].set_revenue(160);
}

int Zoo::gen_rand_num(int lower_bound, int upper_bound){
    srand(time(NULL));
    return rand() % (upper_bound + 1 - lower_bound) + lower_bound;
}

string Zoo::print_zoo_name(){
    string str;
    int spaces = 36 - get_zoo_name().length();
    for(int i = 0; i < spaces / 2; i++)
        str += " ";
    str += get_zoo_name();
    for(int i = 0; i < spaces / 2; i++)
        str += " ";
    if(spaces % 2 == 1)
        str += " ";
    return str;
}

string Zoo::print_month(){
    int num = get_month();
    if(num == 1)
        return "January  ";
    else if(num == 2)
        return "February ";
    else if(num == 3)
        return "March    ";
    else if(num == 4)
        return "April    ";
    else if(num == 5)
        return "May      ";
    else if(num == 6)
        return "June     ";
    else if(num == 7)
        return "July     ";
    else if(num == 8)
        return "August   ";
    else if(num == 9)
        return "September";
    else if(num == 10)
        return "October  ";
    else if(num == 11)
        return "November ";
    else if(num == 12)
        return "December ";
    else
        return "Unknown  ";
}

string Zoo::print_n_sea_lions(){
    string str;
    int digits;
    if(get_num_sea_lions() - 10 < 0)
        str += "  ";
    else if(get_num_sea_lions() - 100 < 0)
        str += " ";
    return str;
}

string Zoo::print_n_tigers(){
    string str;
    int digits;
    if(get_num_tigers() - 10 < 0)
        str += "  ";
    else if(get_num_tigers() - 100 < 0)
        str += " ";
    return str;
}

string Zoo::print_n_black_bears(){
    string str;
    int digits;
    if(get_num_black_bears() - 10 < 0)
        str += "  ";
    else if(get_num_black_bears() - 100 < 0)
        str += " ";
    return str;
}

string Zoo::print_bank(){
    string str;
    if(get_bank() - 10 < 0)
        str += "      ";
    else if(get_bank() - 100 < 0)
        str += "     ";
    else if(get_bank() - 1000 < 0)
        str += "    ";
    else if(get_bank() - 10000 < 0)
        str += "   ";
    else if(get_bank() - 100000 < 0)
        str += "  ";
    else if(get_bank() - 1000000 < 0)
        str += " ";
    str += "$";
    return str;
}

string Zoo::print_food_price(){
    string str;
    if(get_food_price() - 10 < 0)
        str += "      ";
    else if(get_food_price() - 100 < 0)
        str += "     ";
    else if(get_food_price() - 1000 < 0)
        str += "    ";
    else if(get_food_price() - 10000 < 0)
        str += "   ";
    else if(get_food_price() - 100000 < 0)
        str += "  ";
    else if(get_food_price() - 1000000 < 0)
        str += " ";
    str += "$";
    return str;
}


void Zoo::print_open(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nKeep me out of your terminal please!\n\n\n\n\n\n\n\n\t╔════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "\t║ <><><> WELCOME TO THE VERY BEST TEXT BASED ZOO TYCOON GAME EVER <><><> ║" << endl;
    cout << "\t╠════════════════════════════════════════════════════════════════════════╣" << endl;
    cout << "\t║           <>    ᶘ ᵒᴥᵒ}    <>    (≡*ᴥ*)    <>    ʕ •ᴥ•ʔ    <>           ║" << endl;
    cout << "\t║               Sea Lions         Tigers        Black Bears              ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║          These are the three animals you can buy for your zoo          ║" << endl;
    cout << "\t║         Each species has their pros and cons, but all are cute         ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║                    Now let's get started, shall we?                    ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║         First you must pick a name for your zoo(36 chars max)          ║" << endl;
    cout << "\t║  (warning:the best zoo tycoon game ever does not have error handling)  ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t╚════════════════════════════════════════════════════════════════════════╝\n\n" << endl;
    cout << " • What is the name of your new zoo? (no spaces) : ";
}

void Zoo::print_game(){
    cout << "\n\n\n\n\n\n\n\n\n\t╔════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "\t║                  " << print_zoo_name() << "                  ║" << endl;
    cout << "\t╠═════════════════╦══════════════════╦═════════════════╦═════════════════╣" << endl;
    cout << "\t║   DATE:         ║   ᶘ ᵒᴥᵒ} - " << print_n_sea_lions() << get_num_sea_lions() << "   ║   Bank:         ║  Food Price:    ║" << endl;
    cout << "\t║    " << print_month() << "    ║   (≡*ᴥ*) - " << print_n_tigers() << get_num_tigers() << "   ║    " << print_bank() << get_bank() << "     ║    " << print_food_price() << get_food_price() << "     ║" << endl;
    cout << "\t║    " << get_year() << "         ║   ʕ •ᴥ•ʔ - " << print_n_black_bears() << get_num_black_bears() << "   ║                 ║                 ║" << endl;
    cout << "\t╠═════════════════╩════════╦═════════╩════════════╦════╩═════════════════╣" << endl;
    cout << "\t║         -Events-         ║    -Animal Cost-     ║    -Food Prices-     ║" << endl;
    cout << "\t║ Birth:   one animal      ║  Sea Lion:   $800    ║ Cheap:  1/2 Cost     ║" << endl;
    cout << "\t║          gives birth     ║                      ║       2x Sick Chance ║" << endl;
    cout << "\t║ Sick:    one animal      ║  Tiger:      $10000  ║ Regular: 1x Cost     ║" << endl;
    cout << "\t║          gets sick       ║                      ║       1x Sick Chance ║" << endl;
    cout << "\t║ Boom:    attendance booms║  Black Bear: $5000   ║ Supreme: 2x Cost     ║" << endl;
    cout << "\t║ Nothing: nothing         ║                      ║      1/2 Sick Chance ║" << endl;
    cout << "\t╚══════════════════════════╩══════════════════════╩══════════════════════╝\n\n" << endl;
}

void Zoo::print_close(){
    cout << "\n\n\n\n\n\n\n\n\n\t╔════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << "\t║                  " << print_zoo_name() << "                  ║" << endl;
    cout << "\t╠═════════════════╦══════════════════╦═════════════════╦═════════════════╣" << endl;
    cout << "\t║   DATE:         ║   ᶘ ᵒᴥᵒ} - " << print_n_sea_lions() << get_num_sea_lions() << "   ║   Bank:         ║  Food Price:    ║" << endl;
    cout << "\t║    " << print_month() << "    ║   (≡*ᴥ*) - " << print_n_tigers() << get_num_tigers() << "   ║    " << print_bank() << get_bank() << "     ║    " << print_food_price() << get_food_price() << "     ║" << endl;
    cout << "\t║    " << get_year() << "         ║   ʕ •ᴥ•ʔ - " << print_n_black_bears() << get_num_black_bears() << "   ║                 ║                 ║" << endl;
    cout << "\t╠═════════════════╩══════════════════╩═════════════════╩═════════════════╣" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║                          THANKS FOR PLAYING!                           ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t║                                                                        ║" << endl;
    cout << "\t╚════════════════════════════════════════════════════════════════════════╝\n\n" << endl;
}