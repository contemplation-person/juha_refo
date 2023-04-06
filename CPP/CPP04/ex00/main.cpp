#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;
    
    std::cout << "---------------" << std::endl;
    const WrongAnimal* Wrongmeta = new WrongAnimal();
    const WrongAnimal* t = new WrongCat();
    Wrongmeta->makeSound();
    t->makeSound();
    return 0;
}
