#include "directory.hpp"


Plant::Plant(){

std::cout << "Base Constructor Plant intialized" << std::endl;

}
Plant::~Plant(){

std::cout << "Base Deconstructor Plant intialized" << std::endl;

}

fruit::fruit(){


}

fruit::~fruit(){


}

void fruit::description(){

std::cout << "A fruit is a type of food that is produced by a flowering plant, typically sweet, juicy and containing seeds or a pit. \
Examples include apples, oranges, berries, bananas, grapes, and mangoes. Fruits are a great source of dietary fiber, vitamins, and minerals.\
 They also contain antioxidants and phytochemicals that can help protect against chronic diseases, such as heart disease and cancer.\n" << std::endl;

}

vegetable::vegetable(){

        std::cout << "vegetable constructor created! \n";

}

vegetable::~vegetable(){


std::cout << "Vegetable Deconstructor called!" << std::endl;

}

void vegetable::description(){

std::cout << "A vegetable is a type of food that is typically savory and comes from the root, stem, leaf, or flower of a plant. \
Vegetables are a good source of vitamins, minerals, and dietary fiber, and they are low in calories. Examples of vegetables include carrots, \
tomatoes, broccoli, cauliflower, kale, and spinach. Vegetables are known to have many health benefits such as reducing risk of chronic diseases, \
supporting digestion and weight management.\n"<< std::endl;

}


void vegetable::vegetable_List(){

std::cout << "Here are some examples of vegetables: lettuce, spinach, kale, collard greens, Swiss chard, arugula, mustard greens, beet greens,\
 turnip greens, radicchio, escarole, endive, dandelion greens, bok choy, cabbage, broccoli rabe, cilantro, and parsley are packed with essential\
  vitamins and minerals and are a great addition to any diet." << std::endl;

}

leafyVegetable::leafyVegetable(){

}

leafyVegetable::~leafyVegetable(){


}

void leafyVegetable::description(){

    std::cout << "A leafy vegetable is a type of vegetable that is primarily composed of leaves, such as lettuce, spinach, and kale. \
    Leafy vegetables are low in calories and high in vitamins, minerals and dietary fiber. They also contain antioxidants and phytochemicals \
    that can help protect against chronic diseases, such as heart disease and cancer.\n" << std::endl;
}

rootVegetable::rootVegetable(){



}

rootVegetable::~rootVegetable(){



}

void rootVegetable::vegetable_List(){

std::cout << "Here are some examples of root vegetables: carrots, beets, potatoes, sweet potatoes, turnips, parsnips, rutabagas, and radishes " << std::endl;

}

void rootVegetable::description(){

    std::cout << "A root vegetable is a type of vegetable that is grown underground, such as carrots, beets, and potatoes. Root vegetables are a \
     good source of carbohydrates, and they are often used as a staple food in many cultures. They also contain vitamins and minerals such as potassium,\
      iron, and vitamin C.\n" << std::endl;

}

//Character Class definition


void Character::setUsername(){
    std::cout << "Please enter your username\n";
    std::cin >> Username;
}
std::string Character::getUsername(){
    return Username;
}
void Character::setPassword(){
    std::cout << "Please enter your password! \n";
    std::cin >>Password;

}
std::string Character::getPassword(){
    return Password;
}
void Character::addItem(std::string item){
    bag.push_back(item);
}



//main menu


void mainMenu(Character* p1){ 
    char choice;

    if(p1->returnPoints() < 1){std::cout << "GAME OVER!" << std::endl;} else if(p1->returnPoints() > 3){std::cout << "GAME WON!" << std::endl;}else{

    std::cout << "What would you like to do " << p1->getUsername() << "?" << std::endl;
    std::cout << "(A) Frolock through the fields seeking fruit and vegetables\n(B) Learn about Plants\n(C) Learn about Vegetables\n(D) Learn about Fruit\n(E) Look in your Basket\n ";
    std::cin >> choice;
    switch (choice)
    {
    case 'A':
        produce_encounter(p1);
        break;
    case 'C':
        if(vegetablebool == false){
        vegetable* veggie = new vegetable;
        veggie->description();
        my_vector.push_back(veggie);
        vegetablebool = true;
        break;}

        else if(leafyVegbool == false || rootVegbool == false){
            
            std::cout << "You've already learned about Vegetables! Would you like to learn about leafy or root vegetables?\nEnter: Y/N \n";
            std::cin >> choice;

            switch (choice){
                case 'Y':
                leafyVegetable* leaf = new leafyVegetable;
                rootVegetable* root = new rootVegetable;
                leaf->description();
                root->description();
                my_vector.push_back(leaf);
                my_vector.push_back(root);
                leafyVegbool = true;
                rootVegbool = true;
                break;
             }
        }
        else{
            std::cout << "Looks like you've learned all there is to know about the greens!" << std::endl;
        }
        break;

    case 'D':
        if(fruitbool == false){
            fruit* citrus = new fruit;
            citrus->description();
            my_vector.push_back(citrus);
            fruitbool = true;
        }
    break;
    case 'E':
        p1->printItems();
    case 'B':


    default:
        break;
    }

    mainMenu(p1);
}
}

   /*// Find requires the lvalue to be auto, because it returns a dynamic value. We scan between the first element and the last, if it does not find the item
   we are seeking to remove, it returns an iterator following the last element of the vector (.end()) the if statement checks if item to be deleted is anything 
   but this element and then deletes the value*/



std::string coinToss(bool coinCheck){
    float coin = distribution(generator);
    std::cout << "Chance of Head: " << chance_of_head << std::endl;
    std::cout << coin;
    if (coin < chance_of_head) {
        if(coinCheck == false){ //False means we are playing a raven game, true mean we want an honest random head or tails.
        chance_of_head += 0.1;  // increases cahnce of losing. 
        return "True";}
        else{return "True";} //regular heads vs tails chances...
    } else {
        //chance_of_head -= 0.1; // decrease chance of getting tails, legacy code from previous idea...
        return "False"; // chance of tails remains constant
    }
}

void Character::printItems(){

for (auto it = begin(bag); it != end(bag); ++it) {
    std::cout <<"item: "<< *it << std::endl;
}
}

void Character::removeItem(const std::string deleteItem){
   auto item_to_be_deleted = std::find(bag.begin(), bag.end(), deleteItem); 
   if(item_to_be_deleted != bag.end()){
      bag.erase(item_to_be_deleted);
      std::cout << "item removed" << std::endl;
   }else{
      std::cout << "error found" << std::endl;
   }
}

int Character::returnPoints(){
    return points;
}
void Character::addPoints(){
    points++;
}
void Character::deductPoints(){
    points--;
} 

/*RANDOM LOGIC GOES HERE, IMPROVE INTO SINGLE FUNCTION?*/

std::string Character::vectorsize(){
   std::cout << bag.size() << std::endl;
   
   std::string ravenC = bag.at(ravenChoice(bag.size())); // grabs a random item out the bag, stores what was stolen in a string
   return ravenC;
}


int ravenChoice(int vectorsize){ // generates a number between 0 and and total size of the bag

  std::uniform_real_distribution<float> vectordistribution(0, vectorsize);
  return (int)vectordistribution(generator);

}

std::string RandomVeg(){

    int coin = enumdistribution(generator);
    return produce[coin];

}

void RandomNumber(){

 while (generatedNumbers.size() < 3) { // while loop until we have three random numbers
        int number = random(generator);
        if (generatedNumbers.count(number) == 0) { // count returns 0 if the number is not found in the set 
            generatedNumbers.insert(number); // we instert the number not found by count
            RavenList.push_back(number);
        }
}
}


void produce_encounter(Character* p1){

    int coin = enumdistribution(generator);
    int coin2 = (int)distribution(generator);

    /*We Flip a coin to determine if we encountred anything in the fields. If we do we flip another coin to determine if we encounter a Raven. The
    Chances of our encountering a Raven increases every time we call coinToss*/
    std::cout << "Cointoss2 = " << coin2 << std::endl;
    if (coin2 == 0) // 50%
    {   
    std::cout << "You found a " << produce[coin] << "!" << std::endl;
    p1->addItem(produce[coin]);
    if(coinToss(false) == "True"){ 
        ravenEncounter(p1);
    }else{mainMenu(p1);} // %50 ++ so that the next time we roll our chances of encountering a raven increase

    }else{std::cout << "you did not find anything in the fields \n"; 
          mainMenu(p1);
    }
    

}

void wrongAnswer(){

std::cout << "As the Raven flew off with the peasant's produce, The peasant would shake their head and chuckle at the ravens' antics, for they understood the birds' nature and their fondness for mischief. They felt a sense of camaraderie with the birds, for they too were creatures of the earth, bound by the same instincts and passions that drove all living things.\n\nAnd so, as the peasant harvested the fruits and vegetables of the fields, the ravens would keep them company, cawing and playing and reminding them of the beauty and magic of the world. The peasant felt a deep connection to the birds, for they too were part of the great cycle of life, and they understood the importance of preserving the delicate balance of the earth.\n" << std::endl;

}

void rightAnswer(){
    std::cout << "The Raven returned the Peasants produce and with a heart full of wonder and joy, the peasant continued their labor, and the ravens continued their play, and together they created a symphony of life in the fields, a celebration of the beauty and magic of the world.\n" <<std::endl;
}

/*MAIN GAME OPERATIONS*/

void ravenEncounter(Character* p1){
   
    std::string theStolen = p1->vectorsize(); // what they stole
    std::string option1 = RandomVeg();
    std::string option2  = RandomVeg();
    char choice;

if(intro == false){
    std::cout << "The peasant was not alone in their labor, for the fields were also home to a mischievous flock of ravens. These birds were a constant presence, flitting from one tree to another, cawing and calling to one another in a language that was both mysterious and alluring.\n\nThe peasant was often amused by the ravens, for they were playful creatures, always eager to play tricks and games on the unwary. They would swoop down to steal a freshly picked vegetable or juicy fruit, only to drop it at the last moment if the peasant entertained their games and watch as the peasant scrambled to retrieve it.\n"<<std::endl;
    intro = true;
}

    std::cout << "You've encountered a raven" << std::endl;
    std::cout << "Raven: Caw, caw! Greetings, farmer. It seems I have taken some of your produce." << std::endl;
    std::cout << p1->getUsername()  << ": [Surprised] What?! You stole from me? Give it back, you thieving bird!" << std::endl;
    std::cout << "Me: Caw, caw! Not so fast, farmer. I will only return your produce if you can guess what it is I have taken." <<std::endl;
    std::cout << p1->getUsername()  << ": [Thinks for a moment] Alright, I'll play along." << std::endl;

    RandomNumber(); // randomizes the output below: 

    std::cout << "DEBUG: THE STOLEN: " << theStolen << "The distraction: " << option1 << option2 << std::endl;
    std::cout << "Raven: [Pauses dramatically] Caw... caw..." << std::endl;
    std::cout << "Raven: What do you think I have taken?" << std::endl;

    std::vector<std::string>* test = new std::vector<std::string>; // a solution 

    for(int i =0; i < 3; i++){ // the Raven's list
        if(RavenList.at(i) == 1){
            std::cout << theStolen << std::endl;
            std::cout << RavenList.at(i) << std::endl;
            test->push_back(theStolen);
        }
        else if(RavenList.at(i) == 2){
            std::cout << option1 << std::endl;
            std::cout << RavenList.at(i) << std::endl;
            test->push_back(option1);
            
        }else{std::cout << option2 << std::endl; std::cout << RavenList.at(i) << std::endl;
        test->push_back(option2);
        } 
    }

    for(int x =0; x < 3; x++){
        if (x == 0)
        {
            std::cout << "(A) ";
        }else if(x == 1){
            std::cout << "(B) ";
        }else{std::cout << "(C) ";}
        
        std::cout << x << " " << test->at(x) << "\n";
    }

    std::cout << "Raven: What do you think I've stolen" << std::endl;

    std::cin >> choice;
    switch (choice)
    {
    case 'A':
        if (test->at(0) != theStolen){
            std::cout << "Raven: Caw! Caw! Wrong Answer Peasant! ";
            wrongAnswer();
            p1->deductPoints();
        }else{std::cout << "Right Answer!\n"; rightAnswer(); p1->addPoints();}
        break;

     case 'B':
        if (test->at(1) != theStolen){
              std::cout << "Raven: Caw! Caw! Wrong Answer Peasant! ";
              p1->deductPoints();
              wrongAnswer();
        }else{std::cout << "Right Answer!\n"; rightAnswer(); p1->addPoints();}
        break;   

    case 'C':
        if (test->at(2) != theStolen){
              std::cout << "Raven: Caw! Caw! Wrong Answer Peasant! ";
              p1->deductPoints();
              wrongAnswer();
        }else{std::cout << "Right Answer!\n"; rightAnswer(); p1->addPoints();}
        break;      

    default:
        std::cout << "Error";
        break;
    }


delete test;
}


void cleanup(){

std::cout << "cleanup begun \n";
std::cout << "VECTOR SIZE = " << my_vector.size();
if(my_vector.size() > 0){
for(int i = 0; i < my_vector.size(); i++){
    std::cout << my_vector.at(i);
    delete my_vector.at(i);}
                        }else{std::cout << "cleanup not intialized!"<<std::endl;}
}

void startUp(Character* p1){
    std::cout << "Welcome to a day in the life of a Peasant in Feudal Germany!\n";
    p1->setUsername();
    p1->setPassword();
    std::cout << "Your username is: " << p1->getUsername() << std::endl;
    std::cout << "Your password is: " << p1->getPassword() << std::endl;

    std::cout << "The peasant " << p1->getUsername() << " trudged through the fields, their calloused hands grasping a crude basket woven from reeds. The morning dew still clung to the verdant earth, and the sun had yet to reach its zenith. The peasant was ordered by their lord to harvest the bountiful fruits and vegetables that flourished in these fertile lands, a task that was both a burden and a blessing.\n\nThe peasant was a mere vessel of the divine will, a humble servant of the lord who ruled over these lands with a firm hand and a righteous heart. The peasant understood their place in the great scheme of things, and they accepted the hardships of their life with stoic resolve.\n\nYet, despite their humble station, the peasant was a romantic soul, yearning for the transcendent beauty of the world. They saw the world through the lens of German idealism, where the beauty of nature was a manifestation of the divine and the human spirit could soar to heights unimagined.\n\n\
As the peasant walked through the fields, they were awed by the majesty of the earth, and they felt a deep connection to the life that flourished all around them. They saw the delicate petals of the wildflowers, the lush leaves of the vegetables, and the ripening fruits hanging from the branches of the trees, and they felt a sense of wonder and awe that was almost spiritual in its intensity.\n\nWith a heart full of reverence and gratitude, the peasant began their labor, filling their basket with the fruits and vegetables of the earth, and harvesting the bounty of the land with a `tender touch and a quiet sense of purpose.\n" << std::endl;
}