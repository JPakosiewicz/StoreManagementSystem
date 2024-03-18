#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Products {
private:
    static int typesOfProducts;
    int id;
    int amount;
    float price;
protected:
    string name;
    string brand;
    string system;
    string cpu;
public:
    void getProductInfo() {
        cout << "Product name: " << brand << " " << name << endl;
        cout << "Cost: " << price << " PLN" << endl;
        cout << "Amount of products: " << amount << endl;
    }

    string getProductName() {
        return brand + " " + name;
    }

    float getPrice() {
        return price;
    }

    int getAmount() {
        return amount;
    }

    void updateAmount(int _amount) {
        amount = _amount;
    }

    Products(string _name, string _brand, string _system, string _cpu, float _price, int _amount) : name(_name), brand(_brand), system(_system), cpu(_cpu), price(_price), amount(_amount) {
        id = ++typesOfProducts;
    }
};

int Products::typesOfProducts = 0;

class Computer : public Products {
private:
    string gpu;
    string memory;
    string disk;
public:
    void setPcSpec(string _gpu, string _memory, string _disk) {
        gpu = _gpu;
        memory = _memory;
        disk = _disk;
    }
    
    void getPcSpec() {
        cout << "Computer specifications: " << endl;
        cout << "* System - " << system << endl;
        cout << "* Cpu - " << cpu << endl;
        cout << "* Gpu - " << gpu << endl;
        cout << "* Memory - " << memory << endl;
        cout << "* Disk - " << disk << endl;
    }

    Computer(string _name, string _brand, string _system, string _cpu, float _price, int _amount) : Products(_name, _brand, _system, _cpu, _price, _amount) {}
};

class Laptop : public Products {
private:
    string gpu;
    string memory;
    string disk;
    string screenType;
    float screenSize;
public:
    void setLaptopSpec(string _gpu, string _memory, string _disk, string _screenType, float _screenSize) {
        gpu = _gpu;
        memory = _memory;
        disk = _disk;
        screenType = _screenType;
        screenSize = _screenSize;
    }
    
    void getLaptopSpec() {
        cout << "Computer specifications: " << endl;
        cout << "* System - " << system << endl;
        cout << "* Cpu - " << cpu << endl;
        cout << "* Gpu - " << gpu << endl;
        cout << "* Memory - " << memory << endl;
        cout << "* Disk - " << disk << endl;
        cout << "* Screen - " << screenSize << '"' << " " << screenType << endl;
    }

    Laptop(string _name, string _brand, string _system, string _cpu, float _price, int _amount) : Products(_name, _brand, _system, _cpu, _price, _amount) {}
};

class Phone : public Products {
private:
    float screenSize;
    int ramSize;
    int memorySize;
    int batterySize;
public:
    void setPhoneSpec(float _screenSize, int _ramSize, int _memorySize, int _batterySize) {
        screenSize = _screenSize;
        ramSize = _ramSize;
        memorySize = _memorySize;
        batterySize = _batterySize;
    }

    void getPhoneSpec() {
        cout << "Phone specifications: " << endl;
        cout << "* System - " << system << endl;
        cout << "* Cpu - " << cpu << endl;
        cout << "* Screen - " << screenSize << '"' << endl;
        cout << "* RAM - " << memorySize << " GB" << endl;
        cout << "* Built-in memory - " << memorySize << "GB" << endl;
        cout << "* Battery capacity - " << batterySize << " mAh" << endl;
    }

    Phone(string _name, string _brand, string _system, string _cpu, float _price, int _amount) : Products(_name, _brand, _system, _cpu, _price, _amount) {}
};

class Employee {
private:
    static int numberOfEmployees;
    int id;
    float salary;
    int amountOfDaysOff = 20;
    string name;
    string surname;
    string jobPosition;
    string email;
public:
    void getEmployeeData() {
        cout << "Employee " << id << " data:" << endl;
        cout << "Name: " << name << " " << surname << endl;
        cout << "Job position: " << jobPosition << endl;
        cout << "Employee email: " << email << endl;
        cout << "Amount of days off: " << amountOfDaysOff << " days" << endl;
    }

    void getEmployeeSlary() {
        cout << "Employee " << id << " salary: " << salary  << " PLN" << endl;
    }

    void changeEmployeeSalary(float _salary) {
        salary = _salary;
    }

    void decreaseAmountOfDaysOff(int _amount) {
        if (_amount > 0 && amountOfDaysOff - _amount > 0) {
            amountOfDaysOff -= _amount;
        }
        else {
            cout << "Wrong number" << endl;
        }
    }

    void increaseAmountOfDaysOff(int _amount) {
        if (_amount > 0) {
            amountOfDaysOff = _amount;
        }
        else {
            cout << "Number needs to be grater than 0" << endl;
        }
    }

    Employee(string _name, string _surname, string _jobPosition, string _email, float _salary) : name(_name), surname(_surname), jobPosition(_jobPosition), email(_email), salary(_salary) {
        id = ++numberOfEmployees;
    }
};

int Employee::numberOfEmployees = 0;

struct Task {
    string description;
    string assignedEmployee;
    int priority;
    int timeLeft;

    Task(string _desc, string _assignedEmp, int _priority ,  int _time) : description(_desc), assignedEmployee(_assignedEmp), timeLeft(_time) {
        if (_priority > 3) {
            _priority = 3;
        } 

        if (_priority < 1) {
            _priority = 1;
        }
        priority = _priority;
    }
};

class TaskBoard {
private:
    vector<Task> employeeTasks;

public:
    void addTask(string _desc, string _assignedEmp, int _priority, int _time) {
        employeeTasks.emplace_back(_desc, _assignedEmp, _priority, _time);
    }

    void removeTask(int index) {
        if (index >= 0 && index < employeeTasks.size()) {
            employeeTasks.erase(employeeTasks.begin() + index);
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void displayTasksByPriority() {
        sort(employeeTasks.begin(), employeeTasks.end(), [](Task& currentTask, Task& nextTask) {
            return currentTask.priority > nextTask.priority;
        });

        cout << "Tasks sorted by priority:" << endl;
        for (auto task : employeeTasks) {
            cout << "Priority: " << task.priority << ", Description: " << task.description << ", Assigned to: " << task.assignedEmployee << ", Time left: " << task.timeLeft << " days" << endl;
        }
    }

    void displayTasksByTimeLeft() {
        sort(employeeTasks.begin(), employeeTasks.end(), [](Task& currentTask, Task& nextTask) {
            return currentTask.timeLeft < nextTask.timeLeft;
        });

        cout << "Tasks sorted by time left:" << endl;
        for (auto& task : employeeTasks) {
            cout << "Time left: " << task.timeLeft << " days, Description: " << task.description << ", Assigned to: " << task.assignedEmployee << ", Priority: " << task.priority << endl;
        }
    }
};

class ShoppingCart {
private:
    vector<Products> productsInCart;
    float cartValue = 0;
public:
    void addProduct(Products product) {
        cartValue += product.getPrice();
        productsInCart.push_back(product);
    }

    void clearCart() {
        cartValue = 0;
        productsInCart.clear();
    }

    void removeProduct(int index) {
        if (index < 0 || index >= productsInCart.size()) {
            cout << "Invalid index. Product cannot be removed." << endl;
            return;
        }
        cartValue -= productsInCart[index].getPrice();
        productsInCart.erase(productsInCart.begin() + index);
    }

    float getCartValue() {
        return cartValue;
    }

    void displayCart() {
        int productIndex = 0;
        cout << "Shopping Cart:" << endl;
        for (auto product : productsInCart) {
            productIndex++;
            cout << productIndex << ") " << product.getProductName() << ": " << product.getPrice() << " PLN" << endl;;
        }

        if (productsInCart.size() == 0) {
            cout << "No products in shopping cart" << endl;
        }

        cout << "Final price: " << cartValue << " PLN" << endl;
    }
};

class UserBalance {
private:
    float balance;
public:
    float getBalance() {
        return balance;
    }

    void buy(float cartValue) {
        if (balance > cartValue) {
            balance -= cartValue;
            cout << "You bought the items" << endl;
        } else {
            cout << "Insufficient funds to buy products!" << endl;
        }
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "You deposited " << amount << " pln in to your account. Current balance: " << balance << " PLN" << endl;
        }
    }

    void withdraw(float amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn " << amount << " PLN. Current balance: " << balance << " PLN" << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    UserBalance() : balance(5000) {}
};

class Customer {
private:
    static int numberOfUsers;
    int id;
    string name;
    string password;
    string address;
    string email;
    ShoppingCart cart;
    UserBalance userBalance;
public:
    void getUserData() {
        cout << "User " << id << " data: " << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Adress: " << address << endl;
    }

    void changePassword(string previousPassword) {
        string newPassword;
        string repeatPassword;
        if (previousPassword != password) {
            cout << "Previous password is incorrect! Try again." << endl;
            return;
        }

        cout << "Insert new password: ";
        cin >> newPassword;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer after first cin
        cout << "Repeat new password: ";
        cin >> repeatPassword;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        
        while (newPassword != repeatPassword) {
            newPassword, repeatPassword = "";
            cout << "Passwords didn't match. Insert new password again: ";
            cin >> newPassword;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Repeat new password: ";
            cin >> repeatPassword;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        password = newPassword;
    }

    void addToCart(Products product) {
        cart.addProduct(product);
    }

    void clearCart() {
        cart.clearCart();
    }

    void removeProductFromCart(int index) {
        cart.removeProduct(index);
    }

    void displayCart() {
        cart.displayCart();
    }

    void showBalance() {
        cout << "Your balance: " << userBalance.getBalance() << " PLN" << endl;
    }

    void deposit(float amount) {
        userBalance.deposit(amount);
    }

    void withdraw(float amount) {
        userBalance.withdraw(amount);
    }

    void buyProducts() {
        userBalance.buy(cart.getCartValue());
    }


    Customer(string _name, string _password, string _email, string _address) : name(_name), password(_password), email(_email), address(_address) {
        ++numberOfUsers;
        id = numberOfUsers;
    }
};

int Customer::numberOfUsers = 0;


int main()
{
    Computer pc1("Pro 290 G9 SFF", "HP", "Windows 11 Pro", "Intel Core i5-13500", 2899, 200);
    pc1.setPcSpec("Intel UHD Graphics 770", "16 GB (DIMM DDR4, 3200 MHz)", "512 GB SSD PCIe");
    Computer pc2("Nitro", "Acer", "No system", "Intel Core i5-12400F", 2999, 100);
    pc1.setPcSpec("NVIDIA GeForce GTX 1660 SUPER", "16 GB (DIMM DDR4, 3200 MHz)", "512 GB SSD PCIe");
    Computer pc3("G4M3R HERO", "X-kom", "Windows 11 Home", "Intel Core i7-14700F", 8700, 50);
    pc1.setPcSpec("NVIDIA GeForce RTX 4070 Super", "32 GB (DIMM DDR5, 6000MHz)", "1000 GB SSD M.2 PCIe 4.0");

    Laptop laptop1("ThinkPad E16", "Lenovo", "Windows 11 Pro", "Intel Core i5-1335U", 4200, 1);
    laptop1.setLaptopSpec("Intel Iris Xe Graphics", "16 GB (DDR4, 3200 MHz)", "512 GB SSD M.2 PCIe", "Matte, LED, IPS", 16);
    Laptop laptop2("Extensa", "Acer", "Windows 11 Home", "Intel Core i5-1235U", 2399, 152);
    laptop2.setLaptopSpec("Intel UHD", "16 GB (DDR4, 3200 MHz)", "1000 GB SSD M.2 PCIe", "Matte, LED, IPS", 15.6);
    Laptop laptop3("Bravo 15", "MSI", "No system", "AMD Ryzen™ 7 7735HS", 4399, 34);
    laptop2.setLaptopSpec("NVIDIA GeForce RTX 4060", "16 GB (DDR5, 4800 MHz)", "1000 GB SSD M.2 PCIe", "Matte, LED, IPS", 15.6);

    Phone phone1("Galaxy S23", "Samsung", "Android 13", "Qualcomm Snapdragon 8 gen 2", 3799, 73);
    phone1.setPhoneSpec(6.1, 8, 256, 3900);
    Phone phone2("iPhone 13", "Apple", "iOS 15", "Apple A15 Bionic", 2649, 10);
    phone1.setPhoneSpec(6.1, 8, 256, 3227);
    Phone phone3("Redmi Note 12", "Xiaomi", "Android 13", "Qualcomm Snapdragon 685", 649, 123);
    phone1.setPhoneSpec(6.67, 4, 128, 5000);

    pc1.getProductInfo();
    cout << endl;
    pc1.getPcSpec();

    cout << endl;

    laptop1.getProductInfo();
    cout << endl;
    laptop1.getLaptopSpec();

    cout << endl;

    phone1.getProductInfo();
    cout << endl;
    phone1.getPhoneSpec();

    cout << endl;

    Employee employee1("John", "Doe", "Manager", "johndoe@gmail.com", 8590);
    Employee employee2("Alice", "Smith", "Cashier", "alice123@gmail.com", 4200);
    Employee employee3("Bob", "Johnson", "Technician", "johnsonb@gmail.com", 6130);

    employee1.getEmployeeData();
    employee1.getEmployeeSlary();
    cout << endl;

    employee2.getEmployeeData();
    employee2.getEmployeeSlary();
    cout << endl;

    employee3.getEmployeeData();
    employee3.getEmployeeSlary();
    cout << endl;

    Customer customer1("Michael Wilson", "password123", "john@gmail.com", "123 Main St");
    customer1.getUserData();
    customer1.addToCart(phone1);
    customer1.addToCart(laptop2);
    customer1.displayCart();
    customer1.deposit(10000);
    customer1.buyProducts();
    customer1.changePassword("wrongPassword");

    cout << endl;

    Customer customer2("Jennifer Brown", "abc123", "jennifer@gmail.com", "456 Elm St");
    customer2.getUserData();
    customer2.addToCart(pc1);
    customer2.addToCart(phone3);
    customer2.displayCart();
    customer2.withdraw(3000);
    customer2.buyProducts();
    customer2.changePassword("abc123");

    TaskBoard tb1;
    tb1.addTask("Organize products on shelves", "Alice Smith", 2, 6);
    tb1.addTask("Fix broken piece of technology", "Bob Johnson", 0, 2);
    tb1.addTask("Restock products", "John Doe", 4, 4);
    tb1.displayTasksByTimeLeft();

    cout << endl;

    tb1.removeTask(2);
    tb1.displayTasksByPriority();

    cout << endl;

    return 0;
}