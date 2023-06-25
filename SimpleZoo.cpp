#include <iostream>
#include <vector>
#include <string>

class Animal {
private:
    std::string name;
    int age;
    std::string food;

public:
    Animal(const std::string& animalName, int animalAge, const std::string& animalFood)
        : name(animalName), age(animalAge), food(animalFood) {}

    std::string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    std::string getFood() const {
        return food;
    }
    
    void setAge(int animalAge){
        this->age = animalAge;
    }
    
    void setFood(std::string animalFood){
        this->food = animalFood;
    }

    virtual void makeSound() const = 0;
};

class Lion : public Animal {
public:
    Lion(const std::string& name, int age)
        : Animal(name, age, "Meat") {}

    void makeSound() const override {
        std::cout << "The lion roars." << std::endl;
    }
};

class Elephant : public Animal {
public:
    Elephant(const std::string& name, int age)
        : Animal(name, age, "Grass") {}

    void makeSound() const override {
        std::cout << "The elephant trumpets." << std::endl;
    }
};

class Giraffe : public Animal {
public:
    Giraffe(const std::string& name, int age)
        : Animal(name, age, "Leaves") {}

    void makeSound() const override {
        std::cout << "The giraffe bleats." << std::endl;
    }
};

class Zoo {
private:
    std::vector<Animal*> animals;

public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void removeAnimal(const std::string& animalName) {
        for (auto it = animals.begin(); it != animals.end(); ++it) {
            if ((*it)->getName() == animalName) {
                delete *it;
                animals.erase(it);
                break;
            }
        }
    }

    void listAllAnimals() const {
        std::cout << "動物清單：" << std::endl;
        for (const auto& animal : animals) {
            std::cout << "名稱：" << animal->getName() << "，年齡：" << animal->getAge() << "，食物：" << animal->getFood() << std::endl;
        }
    }

    ~Zoo() {
        for (auto animal : animals) {
            delete animal;
        }
    }
};

int main() {
    Zoo zoo;

    // 新增動物
    Animal* lion = new Lion("Lion", 5);
    zoo.addAnimal(lion);

    Animal* elephant = new Elephant("Elephant", 10);
    zoo.addAnimal(elephant);

    Animal* giraffe = new Giraffe("Giraffe", 7);
    zoo.addAnimal(giraffe);

    // 列出動物清單
    zoo.listAllAnimals();

    // 刪除動物
    zoo.removeAnimal("Elephant");

    // 列出更新後的動物清單
    zoo.listAllAnimals();

    // 呼叫動物發出聲音
    lion->makeSound();
    giraffe->makeSound();

    // 釋放記憶體
    delete lion;
    delete giraffe;

    return 0;
}
