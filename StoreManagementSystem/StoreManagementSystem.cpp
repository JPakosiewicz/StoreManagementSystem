#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cassert>

using namespace std;

/*******************************************************
Class: Products
Description: Represents a product with basic information.
Fields:
 * typesOfProducts (static int) - Static field to keep track of the total number of products available in store.
 * id (int) - Represents the unique identifier of the product.
 * name (string) - Stores the name of the product.
 * brand (string) - Stores the brand of the product.
 * system (string) - Stores the system information of the product.
 * cpu (string) - Stores the CPU information of the product.
 * price (int) - Stores the price of the product.
 * amount (int) - Stores the quantity of the product available.
Methods:
 * getProductInfo() - Retrieves the detailed information about the product including its name, price, and quantity.
 * getProductName() - Retrieves the full name of the product including its brand and name.
 * getPrice() - Retrieves the price of the product.
 * getAmount() - Retrieves the available quantity of the product.
 * updateAmount(int _amount) - Updates the quantity of the product available.
Constructor:
 * Products(string _name, string _brand, string _system, string _cpu, float _price, int _amount)
*******************************************************/
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
    string getProductInfo() {
        stringstream ss;
        ss << "Product name: " << brand << " " << name << endl;
        ss << "Cost: " << price << " PLN" << endl;
        ss << "Amount of products: " << amount << endl;
        return ss.str();
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

/*******************************************************
Class: Computer
Description: Represents a computer product with additional specifications.
Fields:
 * gpu (string) - Stores the GPU information of the computer.
 * memory (string) - Stores the memory information of the computer.
 * disk (string) - Stores the disk information of the computer.
Methods:
 * setPcSpec(string _gpu, string _memory, string _disk) - Sets the specifications of the computer including GPU, memory, and disk.
 * getPcSpec() - Retrieves the detailed specifications of the computer including system, CPU, GPU, memory, and disk.
Constructor:
 * Computer(string _name, string _brand, string _system, string _cpu, float _price, int _amount)
*******************************************************/
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
    
    string getPcSpec() {
        stringstream ss;
        ss << "Computer specifications: " << endl;
        ss << "* System - " << system << endl;
        ss << "* Cpu - " << cpu << endl;
        ss << "* Gpu - " << gpu << endl;
        ss << "* Memory - " << memory << endl;
        ss << "* Disk - " << disk << endl;
        return ss.str();
    }

    Computer(string _name, string _brand, string _system, string _cpu, float _price, int _amount) : Products(_name, _brand, _system, _cpu, _price, _amount) {}
};


/*******************************************************
Class: Laptop
Description: Represents a laptop product with additional specifications.
Fields:
 * gpu (string) - Stores the GPU information of the laptop.
 * memory (string) - Stores the memory information of the laptop.
 * disk (string) - Stores the disk information of the laptop.
 * screenType (string) - Stores the type of screen of the laptop.
 * screenSize (float) - Stores the size of the screen of the laptop.
Methods:
 * setLaptopSpec(string _gpu, string _memory, string _disk, string _screenType, float _screenSize) - Sets the specifications of the laptop including GPU, memory, disk, screen type, and screen size.
 * getLaptopSpec() - Retrieves the detailed specifications of the laptop including system, CPU, GPU, memory, disk, screen type, and screen size.
Constructor:
 * Laptop(string _name, string _brand, string _system, string _cpu, float _price, int _amount)
*******************************************************/
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
    
    string getLaptopSpec() {
        stringstream ss;
        ss << "Computer specifications: " << endl;
        ss << "* System - " << system << endl;
        ss << "* Cpu - " << cpu << endl;
        ss << "* Gpu - " << gpu << endl;
        ss << "* Memory - " << memory << endl;
        ss << "* Disk - " << disk << endl;
        ss << "* Screen - " << screenSize << '"' << " " << screenType << endl;
        return ss.str();
    }

    Laptop(string _name, string _brand, string _system, string _cpu, float _price, int _amount) : Products(_name, _brand, _system, _cpu, _price, _amount) {}
};

/*******************************************************
Class: Phone
Description: Represents a phone product with additional specifications.
Fields:
 * screenSize (float) - Stores the size of the phone screen.
 * ramSize (int) - Stores the RAM size of the phone.
 * memorySize (int) - Stores the built-in memory size of the phone.
 * batterySize (int) - Stores the battery capacity of the phone.
Methods:
 * setPhoneSpec(float _screenSize, int _ramSize, int _memorySize, int _batterySize) - Sets the specifications of the phone including screen size, RAM size, built-in memory size, and battery capacity.
 * getPhoneSpec() - Retrieves the detailed specifications of the phone including system, CPU, screen size, RAM size, built-in memory size, and battery capacity.
Constructor:
 * Phone(string _name, string _brand, string _system, string _cpu, float _price, int _amount)
*******************************************************/
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

    string getPhoneSpec() {
        stringstream ss;
        ss << "Phone specifications: " << endl;
        ss << "* System - " << system << endl;
        ss << "* Cpu - " << cpu << endl;
        ss << "* Screen - " << screenSize << '"' << endl;
        ss << "* RAM - " << memorySize << " GB" << endl;
        ss << "* Built-in memory - " << memorySize << "GB" << endl;
        ss << "* Battery capacity - " << batterySize << " mAh" << endl;
        return ss.str();
    }

    Phone(string _name, string _brand, string _system, string _cpu, float _price, int _amount) : Products(_name, _brand, _system, _cpu, _price, _amount) {}
};

/*******************************************************
Class: Employee
Description: Represents an employee with basic personal and employment information.
Fields:
 * numberOfEmployees (static int) - Static field to keep track of the total number of employees.
 * id (int) - Represents the unique identifier of the employee.
 * salary (float) - Stores the salary of the employee.
 * amountOfDaysOff (int) - Stores the remaining days off for the employee (default value is 20 days).
 * name (string) - Stores the first name of the employee.
 * surname (string) - Stores the last name of the employee.
 * jobPosition (string) - Stores the job position of the employee.
 * email (string) - Stores the email address of the employee.
Methods:
 * getBasicData() - Retrieves the basic personal and employment data of the employee, including name, surname, and job position.
 * getEmployeeData() - Retrieves detailed information about the employee, including name, surname, job position, email, and remaining days off.
 * getEmployeeSlary() - Retrieves the salary of the employee.
 * changeEmployeeSalary(float _salary) - Updates the salary of the employee.
 * decreaseAmountOfDaysOff(int _amount) - Decreases the remaining days off for the employee by the specified amount.
 * increaseAmountOfDaysOff(int _amount) - Increases the remaining days off for the employee by the specified amount.
Constructor:
 * Employee(string _name, string _surname, string _jobPosition, string _email, float _salary)
*******************************************************/
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
    string getBasicData() {
        return name + " " + surname + " - " + jobPosition;
    }

    string getEmployeeData() {
        stringstream ss;
        ss << "Employee " << id << " data:" << endl;
        ss << "Name: " << name << " " << surname << endl;
        ss << "Job position: " << jobPosition << endl;
        ss << "Employee email: " << email << endl;
        ss << "Amount of days off: " << amountOfDaysOff << " days" << endl;
        return ss.str();
    }

    string getEmployeeSlary() {
        stringstream ss;
        ss << "Employee salary: " << salary << " PLN" << endl;
        return ss.str();
    }

    void changeEmployeeSalary(float _salary) {
        salary = _salary;
    }

    bool decreaseAmountOfDaysOff(int _amount) {
        if (_amount > 0 && amountOfDaysOff - _amount >= 0) {
            amountOfDaysOff -= _amount;
            return true;
        }
        cout << "Wrong number" << endl;
        return false;
    }

    bool increaseAmountOfDaysOff(int _amount) {
        if (_amount > 0) {
            amountOfDaysOff += _amount;
            return true;
        }
        cout << "Number needs to be grater than 0" << endl;
        return false;
    }

    Employee(string _name, string _surname, string _jobPosition, string _email, float _salary) : name(_name), surname(_surname), jobPosition(_jobPosition), email(_email), salary(_salary) {
        id = numberOfEmployees++;
    }
};

int Employee::numberOfEmployees = 0;

/*******************************************************
Struct: Task
Description: Represents a task assigned to an employee.
Fields:
 * id (int) - Unique identifier of the task.
 * description (string) - Stores the description of the task.
 * assignedEmployee (string) - Stores the name of the employee assigned to the task.
 * priority (int) - The priority level of the task (1 - lowest, 3 - highest).
 * timeLeft (int) - The remaining time to complete the task in days.
Constructor:
 * Task(string _desc, string _assignedEmp, int _priority, int _time)
*******************************************************/
struct Task {
    static int nextId;
    int id;
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
        id = nextId++;
    }
};

int Task::nextId = 1;

/*******************************************************
Class: TaskBoard
Description: Represents a task board containing tasks assigned to employees.
Fields:
 * employeeTasks (vector<Task>) - Vector storing Task objects representing the tasks on the task board.
Methods:
 * getTasksIds() - Retrieves the IDs of all tasks currently on the task board.
 * addTask(string _desc, string _assignedEmp, int _priority, int _time) - Adds a new task to the task board with the specified description, assigned employee, priority, and time.
 * removeTask(int taskId) - Removes the task with the specified ID from the task board.
 * displayTasksByPriority() - Displays the tasks on the task board sorted by priority, showing ID, priority, description, assigned employee, and time left for each task.
 * displayTasksByTimeLeft() - Displays the tasks on the task board sorted by time left, showing ID, time left, description, assigned employee, and priority for each task.
*******************************************************/
class TaskBoard {
private:
    vector<Task> employeeTasks;
public:
    vector<int> getTasksIds() {
        vector<int> currentTaskIds;
        for (auto task : employeeTasks) {
            currentTaskIds.push_back(task.id);
        }
        return currentTaskIds;
    }

    void addTask(string _desc, string _assignedEmp, int _priority, int _time) {
        employeeTasks.emplace_back(_desc, _assignedEmp, _priority, _time);
    }

    void removeTask(int taskId) {
        auto taskToDelete = remove_if(employeeTasks.begin(), employeeTasks.end(),
            [taskId](const Task& task) {
                return task.id == taskId;
            });
        
        if (taskToDelete != employeeTasks.end()) {
            employeeTasks.erase(taskToDelete, employeeTasks.end());
        }
    }

    string displayTasksByPriority() {
        sort(employeeTasks.begin(), employeeTasks.end(), [](Task& currentTask, Task& nextTask) {
            return currentTask.priority > nextTask.priority;
        });

        stringstream ss;
        for (auto task : employeeTasks) {
            ss << "ID: " << task.id << ", Priority: " << task.priority << ", Description: " << task.description << ", Assigned to: " << task.assignedEmployee << ", Time left: " << task.timeLeft << " days" << endl;
        }
        return ss.str();
    }

    string displayTasksByTimeLeft() {
        sort(employeeTasks.begin(), employeeTasks.end(), [](Task& currentTask, Task& nextTask) {
            return currentTask.timeLeft < nextTask.timeLeft;
        });

        stringstream ss;
        for (auto task : employeeTasks) {
            ss << "ID: " << task.id << ", Time left: " << task.timeLeft << " days, Description: " << task.description << ", Assigned to: " << task.assignedEmployee << ", Priority: " << task.priority << endl;
        }
        return ss.str();
    }
};


/*******************************************************
Class: ShoppingCart
Description: Represents a shopping cart containing products.
Fields:
 * productsInCart (vector<Products>) - Vector storing Products objects representing the products in the shopping cart.
 * numberOfItems (int) - stores the total number of items in the shopping cart.
 * cartValue (float) - stores the total value of the items in the shopping cart.
Methods:
 * addProduct(Products product) - Adds a product to the shopping cart, updating the number of items and cart value accordingly.
 * clearCart() - Clears all products from the shopping cart and resets the number of items and cart value.
 * removeProduct(int index) - Removes a product from the shopping cart at the specified index, updating the number of items and cart value accordingly.
 * getNumberOfItems() - Retrieves the total number of items in the shopping cart.
 * getCartValue() - Retrieves the total value of the items in the shopping cart.
 * displayCart() - Displays the contents of the shopping cart, including the product names and prices, as well as the final price.
 * decreaseAmountOfProductsInCart() - Decreases the amount of every product in the cart by one
*******************************************************/
class ShoppingCart {
private:
    vector<Products*> productsInCart;
    int numberOfItems = 0;
    float cartValue = 0;
public:
    bool addProduct(Products* product) {
        if (product->getAmount() > 0) {
            numberOfItems++;
            cartValue += product->getPrice();
            productsInCart.push_back(product);
            return true;
        } else {
            return false;
        }
    }

    void clearCart() {
        numberOfItems = 0;
        cartValue = 0;
        productsInCart.clear();
    }

    void removeProduct(int index) {
        if (index < 0 || index >= productsInCart.size()) {
            cout << "Invalid index. Product cannot be removed." << endl;
            return;
        }
        numberOfItems--;
        cartValue -= productsInCart[index]->getPrice();
        productsInCart.erase(productsInCart.begin() + index);
    }

    int getNumberOfItems() {
        return numberOfItems;
    }

    float getCartValue() {
        return cartValue;
    }

    string displayCart() {
        stringstream ss;
        int productIndex = 0;
        ss << "Shopping Cart:" << endl;
        for (auto product : productsInCart) {
            productIndex++;
            ss << productIndex << ") " << product->getProductName() << ": " << product->getPrice() << " PLN" << endl;;
        }

        if (productsInCart.size() == 0) {
            ss << "No products in shopping cart" << endl;
        }

        ss << "Final price: " << cartValue << " PLN" << endl;
        return ss.str();
    }

    void decreaseAmountOfProductsInCart() {
        for (auto& product : productsInCart) {
            product->updateAmount(product->getAmount() - 1);
        }
    }
};

/*******************************************************
Class: UserBalance
Description: Represents the balance of a user's account.
Fields:
 * balance (float) - stores the current balance of the user's account.
Methods:
 * getBalance() - Retrieves the current balance of the user's account.
 * buy(float cartValue) - Deducts the specified cart value from the user's balance if sufficient funds are available and returns a message indicating the success or failure of the transaction.
 * deposit(float amount) - Adds the specified amount to the user's balance if the amount is positive and returns a message confirming the deposit.
 * withdraw(float amount) - Subtracts the specified amount from the user's balance if sufficient funds are available and returns a message indicating the success or failure of the withdrawal.
*******************************************************/
class UserBalance {
private:
    float balance;
public:
    float getBalance() {
        return balance;
    }

    string buy(float cartValue) {
        stringstream ss;
        if (balance > cartValue) {
            balance -= cartValue;
            ss << "You bought the items" << endl;
        } else {
            ss << "Insufficient funds to buy products!" << endl;
        }
        return ss.str();
    }

    string deposit(float amount) {
        stringstream ss;
        if (amount > 0) {
            balance += amount;
            ss << "You deposited " << amount << " PLN in to your account." << endl;
        }
        return ss.str();
    }

    string withdraw(float amount) {
        stringstream ss;
        if (balance >= amount) {
            balance -= amount;
            ss << "Withdrawn " << amount << " PLN."<< endl;
        } else {
            ss << "Insufficient funds!" << endl;
        }
        return ss.str();
    }

    UserBalance() : balance(5000) {}
};

/*******************************************************
Class: Customer
Description: Represents a customer with an account for purchasing products.
Fields:
 * numberOfUsers (static int) - Static field to keep track of the total number of customers in the system.
 * id (int) - Unique identifier of the customer.
 * name (string) - Stores the name of the customer.
 * password (string) - Stores the password of the customer.
 * address (string) - Stores the address of the customer.
 * email (string) - Stores the email address of the customer.
 * cart (ShoppingCart) - Object representing the shopping cart of the customer.
 * userBalance (UserBalance) - Object representing the balance of the customer's account.
Methods:
 * getUserName() - Retrieves the name of the customer.
 * getUserPassword() - Retrieves the password of the customer.
 * getUserData() - Retrieves and displays the basic information of the customer.
 * changePassword(string previousPassword) - Allows the customer to change their password after verifying their previous password.
 * addToCart(Products product) - Adds a product to the customer's shopping cart.
 * clearCart() - Clears all items from the customer's shopping cart.
 * removeProductFromCart(int index) - Removes a product from the customer's shopping cart based on the specified index.
 * getNumberOfItemsInCart() - Retrieves the number of items in the customer's shopping cart.
 * displayCart() - Retrieves and displays the contents of the customer's shopping cart.
 * showBalance() - Retrieves and displays the current balance of the customer's account.
 * deposit(float amount) - Deposits the specified amount into the customer's account balance.
 * withdraw(float amount) - Withdraws the specified amount from the customer's account balance.
 * buyProducts() - Processes the purchase of items in the customer's shopping cart if sufficient funds are available and clears the cart upon successful purchase.
Constructor:
 * Customer(string _name, string _password, string _email, string _address)
*******************************************************/
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
    string getUserName() {
        return name;
    }

    string getUserPassword() {
        return password;
    }

    string getUserData() {
        stringstream ss;
        ss << "User data: " << endl;
        ss << "Name: " << name << endl;
        ss << "Email: " << email << endl;
        ss << "Adress: " << address << endl;
        return ss.str();
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
        system("cls");
        cout << "Password has been changed!" << endl;
    }

    bool addToCart(Products* product) {
        return cart.addProduct(product);
    }

    void clearCart() {
        cart.clearCart();
    }

    void removeProductFromCart(int index) {
        cart.removeProduct(index);
    }

    int getNumberOfItemsInCart() {
        return cart.getNumberOfItems();
    }

    string displayCart() {
        return cart.displayCart();
    }

    string showBalance() {
        stringstream ss;
        ss << "Your balance: " << userBalance.getBalance() << " PLN" << endl;
        return ss.str();
    }

    string deposit(float amount) {
        return userBalance.deposit(amount);
    }

    string withdraw(float amount) {
        return userBalance.withdraw(amount);
    }

    bool buyProducts() {
        if (userBalance.buy(cart.getCartValue()) == "You bought the items\n") {
            cart.decreaseAmountOfProductsInCart();
            cart.clearCart();
            return true;
        }
        return false;
    }


    Customer(string _name, string _password, string _email, string _address) : name(_name), password(_password), email(_email), address(_address) {
        ++numberOfUsers;
        id = numberOfUsers;
    }
};

int Customer::numberOfUsers = 0;

/*******************************************************
 Function name: userChoiceVerify
 Input parameters: 
 * userChoice (int) - a variable storing the user's selection
 * listOfChoices (vector<int>) - vector containing all possible options
 * clearConsole (bool) - a logical variable that determines whether the console will be cleared (set to true by default)
 Return value: userChoice (int) - returns the choice of the user which is included in the list of possible choices
 Information: 
 A function that checks whether the user has selected one of the possible options marked as numbers. 
 If the user has selected the wrong number, he or she is forced to choose one of the possible options. 
 Only when an option from the list is selected, the selection value is returned.
*******************************************************/
int userChoiceVerify(int userChoice, vector<int> listOfChoices, bool clearConsole = true) {
    bool validChoice = find(listOfChoices.begin(), listOfChoices.end(), userChoice) != listOfChoices.end();

    while (!validChoice) {
        cout << "Wrong number. Choose a number from the list." << endl;
        cout << "Your choice: ";
        cin >> userChoice;

        validChoice = find(listOfChoices.begin(), listOfChoices.end(), userChoice) != listOfChoices.end();
    }

    if (clearConsole) {
        system("cls");
    }
    return userChoice;
}

// Tests declaration
void testProductsClass();
void testComputerClass();
void testLaptopClass();
void testPhoneClass();
void testEmployeeClass();
void testTaskBoardClass();
void testShoppingCart();
void testUserBalance();
void testCustomerClass();

int main()
{
    // Tests callout
    testProductsClass();
    testComputerClass();
    testLaptopClass();
    testPhoneClass();
    testEmployeeClass();
    testTaskBoardClass();
    testShoppingCart();
    testUserBalance();
    testCustomerClass();

    // Creating objects of class Computer and setting their specifications
    Computer pc1("Pro 290 G9 SFF", "HP", "Windows 11 Pro", "Intel Core i5-13500", 2899, 200);
    pc1.setPcSpec("Intel UHD Graphics 770", "16 GB (DIMM DDR4, 3200 MHz)", "512 GB SSD PCIe");
    Computer pc2("Nitro", "Acer", "No system", "Intel Core i5-12400F", 2999, 100);
    pc2.setPcSpec("NVIDIA GeForce GTX 1660 SUPER", "16 GB (DIMM DDR4, 3200 MHz)", "512 GB SSD PCIe");
    Computer pc3("G4M3R HERO", "X-kom", "Windows 11 Home", "Intel Core i7-14700F", 8700, 50);
    pc3.setPcSpec("NVIDIA GeForce RTX 4070 Super", "32 GB (DIMM DDR5, 6000MHz)", "1000 GB SSD M.2 PCIe 4.0");

    // Creating objects of class Laptop and setting their specifications
    Laptop laptop1("ThinkPad E16", "Lenovo", "Windows 11 Pro", "Intel Core i5-1335U", 4200, 1);
    laptop1.setLaptopSpec("Intel Iris Xe Graphics", "16 GB (DDR4, 3200 MHz)", "512 GB SSD M.2 PCIe", "Matte, LED, IPS", 16);
    Laptop laptop2("Extensa", "Acer", "Windows 11 Home", "Intel Core i5-1235U", 2399, 152);
    laptop2.setLaptopSpec("Intel UHD", "16 GB (DDR4, 3200 MHz)", "1000 GB SSD M.2 PCIe", "Matte, LED, IPS", 15.6);
    Laptop laptop3("Bravo 15", "MSI", "No system", "AMD Ryzen 7 7735HS", 4399, 34);
    laptop3.setLaptopSpec("NVIDIA GeForce RTX 4060", "16 GB (DDR5, 4800 MHz)", "1000 GB SSD M.2 PCIe", "Matte, LED, IPS", 15.6);

    // Creating objects of class Phone and setting their specifications
    Phone phone1("Galaxy S23", "Samsung", "Android 13", "Qualcomm Snapdragon 8 gen 2", 3799, 73);
    phone1.setPhoneSpec(6.1, 8, 256, 3900);
    Phone phone2("iPhone 13", "Apple", "iOS 15", "Apple A15 Bionic", 2649, 10);
    phone2.setPhoneSpec(6.1, 8, 256, 3227);
    Phone phone3("Redmi Note 12", "Xiaomi", "Android 13", "Qualcomm Snapdragon 685", 649, 123);
    phone3.setPhoneSpec(6.67, 4, 128, 5000);

    // Creating employees that work in the store
    Employee employee1("John", "Doe", "Manager", "johndoe@gmail.com", 8590);
    Employee employee2("Alice", "Smith", "Cashier", "alice123@gmail.com", 4200);
    Employee employee3("Bob", "Johnson", "Technician", "johnsonb@gmail.com", 6130);

    // Creating company task board and adding tasks to it
    TaskBoard companyTaskBoard;
    companyTaskBoard.addTask("Organize products on shelves", "Alice Smith", 2, 6);
    companyTaskBoard.addTask("Fix broken piece of technology", "Bob Johnson", 0, 2);
    companyTaskBoard.addTask("Restock products", "John Doe", 4, 4);

    // Creating list of customers and creating 2 exemplary customers
    vector <Customer> customerList;
    customerList.emplace_back("Michael Wilson", "password123", "john@gmail.com", "123 Main St");
    customerList.emplace_back("Jennifer Brown", "abc123", "jennifer@gmail.com", "456 Elm St");

    // Initializing variables for program control flow
    bool isTheProgramWorking = true; // while this variable is true the program runs
    int userChoice = 0; // variable storing current user choice
    int previousUserChoice = 0; // varibale storing previous user choice
    vector <Products*> productsReference = { &pc1, &pc2, &pc3, &laptop1, &laptop2, &laptop3, &phone1, &phone2, &phone3 }; // vector that stores pointers to Products objects

    int userAccount = -1; // while value -1 user is logged off / when the value is different from -1, the user is logged in
    bool productsListActive = false; // variable responsible for displaying the view of product list
    bool userBalanceActive = false; // variable responsible for displaying the view of user balance
    bool userShoppingCartActive = false; // variable responsible for displaying the view of shopping cart

    Employee* choosenEmployee = nullptr; // pointer to choosen employee
    bool employeeListActive = false; // variable responsible for displaying the view of employee list
    bool taskBoardActive = false; // variable responsible for displaying the view of task board
    bool currentTaskBoardViewByPriority = true; // a variable that determines how tasks are displayed on the board

    // Prompting the user to choose the application interface
    cout << "Hello! Choose application interface: (1) Customer interface, (2) Manager interface" << endl;
    cout << "Your choice: ";
    cin >> userChoice;
    userChoice = userChoiceVerify(userChoice, { 1, 2 }); // Validating user input

    // Customer interface
    if (userChoice == 1) {
        while (isTheProgramWorking) {
            // Main menu
            cout << "Welcome customer! What would you like to do?" << endl;
            
            // List of options if user is logged off
            if (userAccount == -1) {
                cout << "1) Show list of products" << endl;
                cout << "2) Log in" << endl;
                cout << "3) Create account" << endl;
                cout << "4) Exit" << endl;
                cin >> userChoice;
                userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4 });
            }

            // List of options if user is logged in
            if (userAccount != -1) {
                cout << "1) Show list of products" << endl;
                cout << "2) Show user data" << endl;
                cout << "3) Show shopping cart" << endl;
                cout << "4) Show my balance" << endl;
                cout << "5) Change password" << endl;
                cout << "6) Log off" << endl;
                cout << "7) Exit" << endl;
                cin >> userChoice;
                userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4, 5, 6, 7});
            }

            // Displays products list
            if(userChoice == 1) {
                productsListActive = true;
                while (productsListActive) {
                    cout << "<Products list>" << endl;
                    cout << endl;
                    cout << "Computers:" << endl;
                    cout << "[1] " << pc1.getProductName() << " - " << pc1.getPrice() << " PLN (" << pc1.getAmount() << " pieces left)" << endl;
                    cout << "[2] " << pc2.getProductName() << " - " << pc2.getPrice() << " PLN (" << pc2.getAmount() << " pieces left)" << endl;
                    cout << "[3] " << pc3.getProductName() << " - " << pc3.getPrice() << " PLN (" << pc3.getAmount() << " pieces left)" << endl;
                    cout << endl;
                    cout << "Laptops:" << endl;
                    cout << "[4] " << laptop1.getProductName() << " - " << laptop1.getPrice() << " PLN (" << laptop1.getAmount() << " pieces left)" << endl;
                    cout << "[5] " << laptop2.getProductName() << " - " << laptop2.getPrice() << " PLN (" << laptop2.getAmount() << " pieces left)" << endl;
                    cout << "[6] " << laptop3.getProductName() << " - " << laptop3.getPrice() << " PLN (" << laptop3.getAmount() << " pieces left)" << endl;
                    cout << endl;
                    cout << "Phones:" << endl;
                    cout << "[7] " << phone1.getProductName() << " - " << phone1.getPrice() << " PLN (" << phone1.getAmount() << " pieces left)" << endl;
                    cout << "[8] " << phone2.getProductName() << " - " << phone2.getPrice() << " PLN (" << phone2.getAmount() << " pieces left)" << endl;
                    cout << "[9] " << phone3.getProductName() << " - " << phone3.getPrice() << " PLN (" << phone3.getAmount() << " pieces left)" << endl;
                    cout << "--------------------------------------------------" << endl;

                    // Product list menu
                    cout << "What do you want to do?" << endl;
                    cout << "1) Add a product to your shopping cart" << endl;
                    cout << "2) Show product details" << endl;
                    cout << "3) Exit list of products" << endl;
                    cin >> userChoice;
                    userChoice = userChoiceVerify(userChoice, { 1, 2, 3 }, false);

                    // User adds product to their shopping cart
                    if (userChoice == 1) {
                        if (userAccount != -1) {
                            // Adding product to user cart (by product index)
                            cout << "Choose the product you want to add to your shopping cart: ";
                            cin >> userChoice;
                            userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4, 5, 6, 7 ,8, 9 }, false);
                            system("cls");

                            if (customerList[userAccount].addToCart(productsReference[userChoice - 1])) {
                                cout << "Product has been added to your cart" << endl << endl;
                            } else {
                                cout << "Sorry, the product is out of stock." << endl << endl;
                            }
                            userChoice = 0;
                        } else {
                            // Logged off user can't add product to their cart
                            system("cls");
                            cout << "Log in to add products to shopping cart!" << endl << endl;
                            userChoice = 0;
                        }
                    }

                    // User inspects product (shows choosen products specification)
                    if (userChoice == 2) {
                        cout << "Choose the product you want to inspect: ";
                        cin >> userChoice;
                        userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4, 5, 6, 7 ,8, 9 }, false);
                        system("cls");
                        switch (userChoice) {
                        case 1:
                            cout << pc1.getProductInfo() << endl;
                            cout << pc1.getPcSpec() << endl;
                            break;
                        case 2:
                            cout << pc2.getProductInfo() << endl;
                            cout << pc2.getPcSpec() << endl;
                            break;
                        case 3:
                            cout << pc3.getProductInfo() << endl;
                            cout << pc3.getPcSpec() << endl;
                            break;
                        case 4:
                            cout << laptop1.getProductInfo() << endl;
                            cout << laptop1.getLaptopSpec() << endl;
                            break;
                        case 5:
                            cout << laptop2.getProductInfo() << endl;
                            cout << laptop2.getLaptopSpec() << endl;
                            break;
                        case 6:
                            cout << laptop3.getProductInfo() << endl;
                            cout << laptop3.getLaptopSpec() << endl;
                            break;
                        case 7:
                            cout << phone1.getProductInfo() << endl;
                            cout << phone1.getPhoneSpec() << endl;
                            break;
                        case 8:
                            cout << phone2.getProductInfo() << endl;
                            cout << phone2.getPhoneSpec() << endl;
                            break;
                        case 9:
                            cout << phone3.getProductInfo() << endl;
                            cout << phone3.getPhoneSpec() << endl;
                            break;
                        }
                        userChoice = 0;
                    }

                    // User exits product list
                    if (userChoice == 3) {
                        productsListActive = false;
                        system("cls");
                        userChoice = 0;
                    }
                }
            }
            
            // <==== User logged off options ====>
            
            // Log in
            if(userChoice == 2 && userAccount == -1) {
                bool loggedIn = false;
                int userAccountIndex = 0;
                string userLogin;
                string userPass;

                cout << "Enter your name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, userLogin);

                cout << "Enter your password: ";
                cin >> userPass;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");

                // Checks if user provided correct data
                for (int i = 0; i < customerList.size(); i++) {
                    if (userLogin == customerList[i].getUserName() && userPass == customerList[i].getUserPassword()) {
                        loggedIn = true;
                    }
                    userAccountIndex = i;
                }

                // Log in failure
                if (!loggedIn) {
                    cout << "Your name or password didn't match. Try again." << endl << endl;
                }

                // Log in successful
                if (loggedIn) {
                    userAccount = userAccountIndex;
                    cout << "You're logged in as " << userLogin << endl << endl;
                }
                userChoice = 0;
            }

            // Creating new customer account
            if (userChoice == 3 && userAccount == -1) {
                string userName;
                string userPassword;
                string userMail;
                string userAdress;

                cout << "Enter your full name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, userName);

                cout << "Enter your account password: ";
                cin >> userPassword;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter your mail: ";
                cin >> userMail;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter your adress: ";
                cin >> userAdress;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                system("cls");

                customerList.emplace_back(userName, userPassword, userMail, userAdress);
                cout << "Your account has been created!" << endl << endl;
            }

            // Exit program
            if (userChoice == 4 && userAccount == -1) {
                isTheProgramWorking = false;
            }

            // <==== User logged in options ====>

            // Display user data
            if (userChoice == 2 && userAccount != -1) {
                cout << customerList[userAccount].getUserData() << endl << endl;
            }

            // Display customer shopping cart
            if (userChoice == 3 && userAccount != -1) {
                userShoppingCartActive = true;
                while (userShoppingCartActive) {
                    cout << customerList[userAccount].displayCart() << endl << endl;
                    cout << "What would you like to do:" << endl;
                    cout << "1) Remove product from cart" << endl;
                    cout << "2) Remove all products from cart" << endl;
                    cout << "3) Buy products" << endl;
                    cout << "4) Exit shopping cart" << endl;
                    cin >> userChoice;
                    userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4 }, false);

                    // User removes product from their cart (by index)
                    if (userChoice == 1) {

                        if (customerList[userAccount].getNumberOfItemsInCart() == 0) {
                            system("cls");
                            cout << "Your shopping cart is empty." << endl << endl;
                        }

                        if (customerList[userAccount].getNumberOfItemsInCart() != 0) {
                            cout << "Choose the number of product you would like to remove: ";
                            cin >> userChoice;

                            vector <int> rangeOfItemsInCart;
                            for (int i = 1; i <= customerList[userAccount].getNumberOfItemsInCart(); i++) {
                                rangeOfItemsInCart.push_back(i);
                            }

                            userChoice = userChoiceVerify(userChoice, rangeOfItemsInCart, false);
                            customerList[userAccount].removeProductFromCart(userChoice - 1);
                            system("cls");
                            cout << "Product has been removed" << endl << endl;
                            userChoice = 0;
                        }
                    }

                    // User removes all products from their cart
                    if (userChoice == 2) {

                        if (customerList[userAccount].getNumberOfItemsInCart() == 0) {
                            system("cls");
                            cout << "Your shopping cart is empty." << endl << endl;
                        }

                        if (customerList[userAccount].getNumberOfItemsInCart() != 0) {
                            customerList[userAccount].clearCart();
                            system("cls");
                            cout << "All products have been removed from your shopping cart." << endl << endl;
                        }
                    }

                    // User attempts to buy products (if there is enough funds on user balance the process will be successful)
                    if (userChoice == 3) {
                        system("cls");
                        if (customerList[userAccount].getNumberOfItemsInCart() != 0) {
                            if (customerList[userAccount].buyProducts()) {
                                cout << "Products bought" << endl << endl;
                            }
                            else {
                                cout << "Insufficient funds!" << endl << endl;
                            }
                        } else {
                            cout << "Your shopping cart is empty." << endl << endl;
                        }
                    }

                    // User exits shopping cart view
                    if (userChoice == 4) {
                        system("cls");
                        userShoppingCartActive = false;
                        userChoice = 0;
                    }
                }
            }

            // Display user balance 
            if (userChoice == 4 && userAccount != -1) {
                userBalanceActive = true;
                while (userBalanceActive) {
                    cout << customerList[userAccount].showBalance() << endl << endl;
                    cout << "What would you like to do:" << endl;
                    cout << "1) Deposit money into my account" << endl;
                    cout << "2) Withdraw money from my account" << endl;
                    cout << "3) Exit balance view" << endl;
                    cin >> userChoice;
                    userChoice = userChoiceVerify(userChoice, { 1, 2, 3 }, false);

                    // User deposits choosen amount of money into their account
                    if (userChoice == 1) {
                        int userAmount;
                        cout << "Enter the amount of money you want to deposit:";
                        cin >> userAmount;

                        while (userAmount < 0) {
                            cout << "Number should be greater than 0. Insert the number again:";
                            cin >> userAmount;
                        }

                        system("cls");

                        cout << customerList[userAccount].deposit(userAmount) << endl << endl;
                    }

                    // User withdraws choosen amount of money from their account
                    if (userChoice == 2) {
                        int userAmount;
                        cout << "Enter the amount of money you want to withdraw:";
                        cin >> userAmount;

                        while (userAmount < 0) {
                            cout << "Number should be greater than 0. Insert the number again:";
                            cin >> userAmount;
                        }

                        system("cls");

                        cout << customerList[userAccount].withdraw(userAmount) << endl << endl;
                    }

                    // User exits balance view
                    if (userChoice == 3) {
                        system("cls");
                        userBalanceActive = false;
                        userChoice = 0;
                    }
                }
            }

            // Change current customer account password
            if (userChoice == 5 && userAccount != -1) {
                string previousUserPassword;
                cout << "Enter your previous password: ";
                cin >> previousUserPassword;
                customerList[userAccount].changePassword(previousUserPassword);
                cout << endl;
            }

            // Log off 
            if (userChoice == 6 && userAccount != -1) {
                userAccount = -1;
                cout << "You are now logged off" << endl << endl;
            }

            // Exit program
            if (userChoice == 7 && userAccount != -1) {
                isTheProgramWorking = false;
            }
        }
    }

    // Manager interface
    if (userChoice == 2) {
        while (isTheProgramWorking) {
            // Main menu
            cout << "Welcome into manager interface. Choose what would you like to do:" << endl;
            cout << "1) Show list of employees" << endl;
            cout << "2) Show task board" << endl;
            cout << "3) Show list of products" << endl;
            cout << "4) Exit" << endl;
            cin >> userChoice;
            userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4 });

            // Display list of employees
            if (userChoice == 1) {
                employeeListActive = true;
                while (employeeListActive) {
                    cout << "<List of employees>" << endl;
                    cout << "[1] " << employee1.getBasicData() << endl;
                    cout << "[2] " << employee2.getBasicData() << endl;
                    cout << "[3] " << employee3.getBasicData() << endl;
                    cout << endl;
                    cout << "What would you like to do?" << endl;
                    cout << "1) Show employee details" << endl;
                    cout << "2) Change employee salary" << endl;
                    cout << "3) Change number of employee days off" << endl;
                    cout << "4) Exit" << endl;
                    cin >> userChoice;
                    userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4 }, false);
                    previousUserChoice = userChoice;

                    // User provides employee id (activates when user chooses option 1, 2 or 3)
                    if (userChoice == 1 || userChoice == 2 || userChoice == 3) {
                        cout << "Choose the employee id: ";
                        cin >> userChoice;
                        userChoice = userChoiceVerify(userChoice, { 1, 2, 3 });
                        switch (userChoice) {
                        case 1:
                            choosenEmployee = &employee1;
                            break;
                        case 2:
                            choosenEmployee = &employee2;
                            break;
                        case 3:
                            choosenEmployee = &employee3;
                            break;
                        }
                        userChoice = previousUserChoice;
                    }

                    // Display choosen employee details
                    if (userChoice == 1) {
                        system("cls");
                        cout << choosenEmployee->getEmployeeData();
                        cout << choosenEmployee->getEmployeeSlary() << endl << endl;
                        userChoice = 0;
                    }

                    // User changes choosen employee salary
                    if (userChoice == 2) {
                        int amount;
                        cout << "Insert the amount: ";
                        cin >> amount;

                        while (amount < 0) {
                            cout << "Number should be greater then 0. Insert the number again: ";
                            cin >> amount;
                        }

                        system("cls");
                        choosenEmployee->changeEmployeeSalary(amount);
                        userChoice = 0;
                    }

                    // User changes the amount of days off for the choosen employee ( positive number -> add number of days / negative number -> subtract number of days)
                    if (userChoice == 3) {
                        int amount;
                        cout << "Insert the amount of days you want to change (negative numbers decreases / positive numbers increases): ";
                        cin >> amount;
                        system("cls");

                        if (amount > 0) {
                            if (choosenEmployee->increaseAmountOfDaysOff(amount)) {
                                cout << "Number of employee days off has been increased by " << amount << " days." << endl << endl;
                            }
                        }

                        if (amount < 0) {
                            amount *= -1;
                            if (choosenEmployee->decreaseAmountOfDaysOff(amount)) {
                                cout << "Number of employee days off has been decreased by " << amount << " days." << endl << endl;
                            }
                        }
                        
                        userChoice = 0;
                    }

                    // User exits employee list view
                    if (userChoice == 4) {
                        userChoice = 0;
                        employeeListActive = false;
                        system("cls");
                    }
                }
            }

            // Display task board
            if (userChoice == 2) {
                taskBoardActive = true;
                while (taskBoardActive) {
                    // Displays task board by priority of the tasks
                    if (currentTaskBoardViewByPriority) {
                        cout << "<Task Board - displayed by priority>" << endl;
                        cout << companyTaskBoard.displayTasksByPriority() << endl;
                    }
                    
                    // Displays task board by the tasks time left 
                    if (!currentTaskBoardViewByPriority) {
                        cout << "<Task Board - displayed by time left>" << endl;
                        cout << companyTaskBoard.displayTasksByTimeLeft() << endl;
                    }

                    cout << endl;
                    cout << "What would you like to do?" << endl;
                    cout << "1) Add task to the board" << endl;
                    cout << "2) Remove task from the board" << endl;

                    // This option shows when user have choosen to display tasks by priority
                    if (currentTaskBoardViewByPriority) {
                        cout << "3) Display task board by time left" << endl;
                    }

                    // This option shows when user have choosen to display tasks by time left
                    if (!currentTaskBoardViewByPriority) {
                        cout << "3) Display task board by priority" << endl;
                    }
                    
                    cout << "4) Exit" << endl;
                    cin >> userChoice;
                    userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4 }, false);

                    // User adds task to task board
                    if (userChoice == 1) {
                        string newTaskDesc;
                        string newTaskAssignedEmployee;
                        int newTaskPriority;
                        int newTaskTime;

                        cout << "Enter task description: ";
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        getline(cin, newTaskDesc);

                        cout << "Enter name of the employee you want to assign to this task: ";
                        getline(cin, newTaskAssignedEmployee);

                        cout << "Enter priority of this task (1 / 2 / 3): ";
                        cin >> newTaskPriority;

                        cout << "Enter how many days are left until the end of the task: ";
                        cin >> newTaskTime;
                        
                        companyTaskBoard.addTask(newTaskDesc, newTaskAssignedEmployee, newTaskPriority, newTaskTime);
                        system("cls");
                        cout << "Task has been added" << endl << endl;
                        userChoice = 0;
                    }

                    // User removes task from task board (by id)
                    if (userChoice == 2) {
                        cout << "Choose the id of the task you want to remove: ";
                        cin >> userChoice;
                        userChoice = userChoiceVerify(userChoice, companyTaskBoard.getTasksIds());

                        companyTaskBoard.removeTask(userChoice);
                        cout << "Task has been deleted" << endl << endl;
                        userChoice = 0;
                    }

                    // User changes the method of display
                    if (userChoice == 3) {
                        currentTaskBoardViewByPriority = !currentTaskBoardViewByPriority;
                        system("cls");
                    }

                    // User exits task board view
                    if (userChoice == 4) {
                        taskBoardActive = false;
                        userChoice = 0;
                        system("cls");
                    }
                }
            }

            // Display product list
            if (userChoice == 3) {
                productsListActive = true;
                while (productsListActive) {
                    cout << "<Products list>" << endl;
                    cout << endl;
                    cout << "Computers:" << endl;
                    cout << "[1] " << pc1.getProductName() << " - " << pc1.getPrice() << " PLN (" << pc1.getAmount() << " pieces left)" << endl;
                    cout << "[2] " << pc2.getProductName() << " - " << pc2.getPrice() << " PLN (" << pc2.getAmount() << " pieces left)" << endl;
                    cout << "[3] " << pc3.getProductName() << " - " << pc3.getPrice() << " PLN (" << pc3.getAmount() << " pieces left)" << endl;
                    cout << endl;
                    cout << "Laptops:" << endl;
                    cout << "[4] " << laptop1.getProductName() << " - " << laptop1.getPrice() << " PLN (" << laptop1.getAmount() << " pieces left)" << endl;
                    cout << "[5] " << laptop2.getProductName() << " - " << laptop2.getPrice() << " PLN (" << laptop2.getAmount() << " pieces left)" << endl;
                    cout << "[6] " << laptop3.getProductName() << " - " << laptop3.getPrice() << " PLN (" << laptop3.getAmount() << " pieces left)" << endl;
                    cout << endl;
                    cout << "Phones:" << endl;
                    cout << "[7] " << phone1.getProductName() << " - " << phone1.getPrice() << " PLN (" << phone1.getAmount() << " pieces left)" << endl;
                    cout << "[8] " << phone2.getProductName() << " - " << phone2.getPrice() << " PLN (" << phone2.getAmount() << " pieces left)" << endl;
                    cout << "[9] " << phone3.getProductName() << " - " << phone3.getPrice() << " PLN (" << phone3.getAmount() << " pieces left)" << endl;
                    cout << "--------------------------------------------------" << endl;

                    cout << "What would you like to do?" << endl;
                    cout << "1) Change product amount" << endl;
                    cout << "2) Change product specification" << endl;
                    cout << "3) Exit" << endl;
                    cin >> userChoice;
                    userChoice = userChoiceVerify(userChoice, { 1, 2 ,3 }, false);
                    previousUserChoice = userChoice;

                    // User exits product list view
                    if (userChoice == 3) {
                        system("cls");
                        productsListActive = false;
                        userChoice = 0;
                    }

                    // User provides the index of the product (activates when user chooses option 1 or 2)
                    if (previousUserChoice == 1 || previousUserChoice == 2) {
                        cout << "Choose the product: ";
                        cin >> userChoice;
                        userChoice = userChoiceVerify(userChoice, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
                    }

                    // User changes choosen product specifications
                    if (previousUserChoice == 2) {
                        string newGpu;
                        string newMemory;
                        string newDisk;
                        string newScreenType;
                        float newScreenSize;
                        int newRamSize;
                        int newMemorySize;
                        int newBatterySize;

                        // Computer 
                        if (userChoice >= 1 && userChoice <= 3) {
                            cout << "Insert computer GPU: ";
                            cin >> newGpu;
                            cout << "Insert computer memory: ";
                            cin >> newMemory;
                            cout << "Insert computer disk: ";
                            cin >> newDisk;
                        }

                        // Laptop
                        if (userChoice >= 4 && userChoice <= 6) {
                            cout << "Insert laptop GPU: ";
                            cin >> newGpu;
                            cout << "Insert laptop memory: ";
                            cin >> newMemory;
                            cout << "Insert laptop disk: ";
                            cin >> newDisk;
                            cout << "Insert laptop screen type: ";
                            cin >> newScreenType;
                            cout << "Insert laptop screen size: ";
                            cin >> newScreenSize;
                        }

                        // Phone
                        if (userChoice >= 7 && userChoice <= 9) {
                            cout << "Insert phone screen size: ";
                            cin >> newScreenSize;
                            cout << "Insert phone RAM size: ";
                            cin >> newRamSize;
                            cout << "Insert phone memory size: ";
                            cin >> newMemorySize;
                            cout << "Insert phone battery capacity: ";
                            cin >> newBatterySize;
                        }

                        system("cls");
                        cout << "Product specifications updated" << endl << endl;

                        // Display modified product specification
                        switch (userChoice) {
                        case 1:
                            pc1.setPcSpec(newGpu, newMemory, newDisk);
                            cout << pc1.getPcSpec() << endl;
                            break;
                        case 2:
                            pc2.setPcSpec(newGpu, newMemory, newDisk);
                            cout << pc2.getPcSpec() << endl;
                            break;
                        case 3:
                            pc3.setPcSpec(newGpu, newMemory, newDisk);
                            cout << pc3.getPcSpec() << endl;
                            break;
                        case 4:
                            laptop1.setLaptopSpec(newGpu, newMemory, newDisk, newScreenType, newScreenSize);
                            cout << laptop1.getLaptopSpec() << endl;
                            break;
                        case 5:
                            laptop2.setLaptopSpec(newGpu, newMemory, newDisk, newScreenType, newScreenSize);
                            cout << laptop2.getLaptopSpec() << endl;
                            break;
                        case 6:
                            laptop3.setLaptopSpec(newGpu, newMemory, newDisk, newScreenType, newScreenSize);
                            cout << laptop3.getLaptopSpec() << endl;
                            break;
                        case 7:
                            phone1.setPhoneSpec(newScreenSize, newRamSize, newMemorySize, newBatterySize);
                            cout << phone1.getPhoneSpec() << endl;
                            break;
                        case 8:
                            phone2.setPhoneSpec(newScreenSize, newRamSize, newMemorySize, newBatterySize);
                            cout << phone2.getPhoneSpec() << endl;
                            break;
                        case 9:
                            phone3.setPhoneSpec(newScreenSize, newRamSize, newMemorySize, newBatterySize);
                            cout << phone3.getPhoneSpec() << endl;
                            break;
                        }
                        userChoice = 0;
                    }

                    // User changes the amount of available products
                    if (previousUserChoice == 1) {
                        int amount = 0;
                        cout << "Insert the new amount of product: ";
                        cin >> amount;

                        while (amount < 0) {
                            cout << "Number should be grater or equal to 0. Insert the amount again: ";
                            cin >> amount;
                        }

                        productsReference[userChoice - 1]->updateAmount(amount);
                        
                        system("cls");
                        cout << "Product amount updated" << endl << endl;
                        userChoice = 0;
                    }
                }
            }
            
            // Exit program
            if (userChoice == 4) {
                isTheProgramWorking = false;
            }
        }
    }

    return 0;
}

// <======================== Tests ========================>
void testProductsClass() {
    {
        // Create a test instance of the Products class
        Products productTest("Keyboard", "Logitech", "None", "None", 120, 20);

        // Check if the product name is correctly formatted
        assert(productTest.getProductName() == "Logitech Keyboard");
        
        // Check if the price and amount of products are correct
        assert(productTest.getPrice() == 120);
        assert(productTest.getAmount() == 20);
        
        // Update the amount of products and verify
        productTest.updateAmount(60);
        assert(productTest.getAmount() == 60);

        // Verify the product information string
        assert(productTest.getProductInfo() == "Product name: Logitech Keyboard\nCost: 120 PLN\nAmount of products: 60\n");
    }
    //cout << "Product class valid" << endl;
    //cout << endl;
}

void testComputerClass() {
    {
        // Create a test instance of the Computer class
        Computer computerTest("Pro 290 G9 SFF", "HP", "Windows 11 Pro", "Intel Core i5-13500", 2899, 200);
        computerTest.setPcSpec("Intel UHD Graphics 770", "16 GB (DIMM DDR4, 3200 MHz)", "512 GB SSD PCIe");

        // Verify various attributes and specifications
        assert(computerTest.getProductName() == "HP Pro 290 G9 SFF");
        assert(computerTest.getPrice() == 2899);
        assert(computerTest.getAmount() == 200);
        assert(computerTest.getProductInfo() == "Product name: HP Pro 290 G9 SFF\nCost: 2899 PLN\nAmount of products: 200\n");
        assert(computerTest.getPcSpec() == "Computer specifications: \n* System - Windows 11 Pro\n* Cpu - Intel Core i5-13500\n* Gpu - Intel UHD Graphics 770\n* Memory - 16 GB (DIMM DDR4, 3200 MHz)\n* Disk - 512 GB SSD PCIe\n");
    }
    //cout << "Computer class valid" << endl;
    //cout << endl;
}

void testLaptopClass() {
    {
        // Create a test instance of the Laptop class
        Laptop laptopTest("ThinkPad E16", "Lenovo", "Windows 11 Pro", "Intel Core i5-1335U", 4200, 1);
        laptopTest.setLaptopSpec("Intel Iris Xe Graphics", "16 GB (DDR4, 3200 MHz)", "512 GB SSD M.2 PCIe", "Matte, LED, IPS", 16);

        // Verify various attributes and specifications
        assert(laptopTest.getProductName() == "Lenovo ThinkPad E16");
        assert(laptopTest.getPrice() == 4200);
        assert(laptopTest.getAmount() == 1);
        assert(laptopTest.getProductInfo() == "Product name: Lenovo ThinkPad E16\nCost: 4200 PLN\nAmount of products: 1\n");
        assert(laptopTest.getLaptopSpec() == "Computer specifications: \n* System - Windows 11 Pro\n* Cpu - Intel Core i5-1335U\n* Gpu - Intel Iris Xe Graphics\n* Memory - 16 GB (DDR4, 3200 MHz)\n* Disk - 512 GB SSD M.2 PCIe\n* Screen - 16\" Matte, LED, IPS\n");
    }
    //cout << "Laptop class valid" << endl;
    //cout << endl;
}

void testPhoneClass() {
    {
        // Create a test instance of the Phone class
        Phone phoneTest("Galaxy S23", "Samsung", "Android 13", "Qualcomm Snapdragon 8 gen 2", 3799, 73);
        phoneTest.setPhoneSpec(6.1, 8, 256, 3900);

        // Verify various attributes and specifications
        assert(phoneTest.getProductName() == "Samsung Galaxy S23");
        assert(phoneTest.getPrice() == 3799);
        assert(phoneTest.getAmount() == 73);
        assert(phoneTest.getProductInfo() == "Product name: Samsung Galaxy S23\nCost: 3799 PLN\nAmount of products: 73\n");
        assert(phoneTest.getPhoneSpec() == "Phone specifications: \n* System - Android 13\n* Cpu - Qualcomm Snapdragon 8 gen 2\n* Screen - 6.1\"\n* RAM - 256 GB\n* Built-in memory - 256GB\n* Battery capacity - 3900 mAh\n");
    }
    //cout << "Phone class valid" << endl;
    //cout << endl;
}

void testEmployeeClass() {
    {
        // Create a test instance of the Employee class
        Employee employeeTest("John", "Doe", "Manager", "johndoe@gmail.com", 5000);
        
        // Verify employee data and salary
        assert(employeeTest.getEmployeeData() == "Employee 0 data:\nName: John Doe\nJob position: Manager\nEmployee email: johndoe@gmail.com\nAmount of days off: 20 days\n");
        assert(employeeTest.getEmployeeSlary() == "Employee salary: 5000 PLN\n");
        
        // Change employee salary and verify
        employeeTest.changeEmployeeSalary(6000);
        assert(employeeTest.getEmployeeSlary() == "Employee salary: 6000 PLN\n");

        // Decrease amount of days off and verify
        employeeTest.decreaseAmountOfDaysOff(5);
        assert(employeeTest.getEmployeeData() == "Employee 0 data:\nName: John Doe\nJob position: Manager\nEmployee email: johndoe@gmail.com\nAmount of days off: 15 days\n");

        // Increase amount of days off and verify
        employeeTest.increaseAmountOfDaysOff(10);
        assert(employeeTest.getEmployeeData() == "Employee 0 data:\nName: John Doe\nJob position: Manager\nEmployee email: johndoe@gmail.com\nAmount of days off: 25 days\n");
    }
    //cout << "Employee class valid" << endl;
    //cout << endl;
}

void testTaskBoardClass() {
    {
        // Create a test instance of the TaskBoard class
        TaskBoard taskBoardTest;

        // Add tasks to the task board
        taskBoardTest.addTask("Fix PC", "John Doe", 2, 5);
        taskBoardTest.addTask("Clean floor", "Jane Smith", 3, 3);
        taskBoardTest.addTask("Organize documents", "Alice Johnson", 1, 7);

        // Display tasks by priority and verify
        string tasksByPriority = taskBoardTest.displayTasksByPriority();
        assert(tasksByPriority == "ID: 2, Priority: 3, Description: Clean floor, Assigned to: Jane Smith, Time left: 3 days\nID: 1, Priority: 2, Description: Fix PC, Assigned to: John Doe, Time left: 5 days\nID: 3, Priority: 1, Description: Organize documents, Assigned to: Alice Johnson, Time left: 7 days\n");

        // Display tasks by time left and verify
        string tasksByTimeLeft = taskBoardTest.displayTasksByTimeLeft();
        assert(tasksByTimeLeft == "ID: 2, Time left: 3 days, Description: Clean floor, Assigned to: Jane Smith, Priority: 3\nID: 1, Time left: 5 days, Description: Fix PC, Assigned to: John Doe, Priority: 2\nID: 3, Time left: 7 days, Description: Organize documents, Assigned to: Alice Johnson, Priority: 1\n");

        // Remove a task and verify
        taskBoardTest.removeTask(1);
        tasksByPriority = taskBoardTest.displayTasksByPriority();
        assert(tasksByPriority == "ID: 2, Priority: 3, Description: Clean floor, Assigned to: Jane Smith, Time left: 3 days\nID: 3, Priority: 1, Description: Organize documents, Assigned to: Alice Johnson, Time left: 7 days\n");

        // Reset the task ID counter
        Task::nextId = 1;
    }
    //cout << "TaskBoard class valid" << endl;
    //cout << endl;
}

void testShoppingCart() {
    {
        // Create test products
        Products product1("Keyboard", "Razer", "Windows", "AMD", 99.99, 1);
        Products product2("Mouse", "Logitech", "Windows", "Intel", 49.99, 2);

        // Create a test instance of the ShoppingCart class
        ShoppingCart cartTest;

        // Add products to the shopping cart and verify the total price
        cartTest.addProduct(&product1);
        cartTest.addProduct(&product2);
        assert(abs(cartTest.getCartValue() - (99.99 + 49.99)) < 0.01);

        // Verify the display of the shopping cart
        string expectedCartDisplay = "Shopping Cart:\n1) Razer Keyboard: 99.99 PLN\n2) Logitech Mouse: 49.99 PLN\nFinal price: 149.98 PLN\n";
        assert(cartTest.displayCart() == expectedCartDisplay);

        // Remove a product from the shopping cart and verify the total price
        cartTest.removeProduct(0);
        assert(abs(cartTest.getCartValue() - 49.99) < 0.01);
    }
    //cout << "ShoppingCart class valid" << endl;
    //cout << endl;
}

void testUserBalance() {
    {
        // Create a test instance of the UserBalance class
        UserBalance balanceTest;

        // Deposit funds and verify balance
        balanceTest.deposit(1000);
        assert(balanceTest.getBalance() == 6000); // 5000 + 1000

        // Withdraw funds and verify balance
        balanceTest.withdraw(2000);
        assert(balanceTest.getBalance() == 4000); // 6000 - 2000

        // Buy products and verify result
        assert(balanceTest.buy(1000) == "You bought the items\n");

        // Try to buy products with insufficient funds and verify result
        assert(balanceTest.buy(5000) == "Insufficient funds to buy products!\n");
    }
    //cout << "UserBalance class valid" << endl;
    //cout << endl;
}

void testCustomerClass() {
    {
        // Create a test instance of the Customer class
        Customer customerTest("John Doe", "password123", "john@example.com", "123 Main Street");

        // Verify user data
        assert(customerTest.getUserData() == "User data: \nName: John Doe\nEmail: john@example.com\nAdress: 123 Main Street\n");

        // Create test products
        Products product1("Keyboard", "Logitech", "None", "None", 120, 1);
        Products product2("Mouse", "Logitech", "None", "None", 50, 1);
        
        // Add products to the shopping cart and verify display
        customerTest.addToCart(&product1);
        customerTest.addToCart(&product2);
        assert(customerTest.displayCart() == "Shopping Cart:\n1) Logitech Keyboard: 120 PLN\n2) Logitech Mouse: 50 PLN\nFinal price: 170 PLN\n");

        // Clear the shopping cart and verify display
        customerTest.clearCart();
        assert(customerTest.displayCart() == "Shopping Cart:\nNo products in shopping cart\nFinal price: 0 PLN\n");

        // Deposit funds and verify balance
        customerTest.deposit(1000);
        assert(customerTest.showBalance() == "Your balance: 6000 PLN\n");

        // Withdraw funds and verify balance
        customerTest.withdraw(500);
        assert(customerTest.showBalance() == "Your balance: 5500 PLN\n");

        // Add products to the shopping cart and buy, then verify balance
        customerTest.addToCart(&product1);
        assert(customerTest.buyProducts() == true);
        assert(customerTest.showBalance() == "Your balance: 5380 PLN\n");

        // Add products to the shopping cart, remove one, and verify display
        customerTest.addToCart(&product2);
        customerTest.removeProductFromCart(0);
        assert(customerTest.displayCart() == "Shopping Cart:\nNo products in shopping cart\nFinal price: 0 PLN\n");
    }
    //cout << "Customer class valid" << endl;
    //cout << endl;
}