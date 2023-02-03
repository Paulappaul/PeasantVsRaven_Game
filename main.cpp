#include "directory.hpp"
#include "directory.cpp"

int main(){
Character* p1 = new Character;
startUp(p1);
mainMenu(p1);
cleanup();
delete p1;
return 0;
}