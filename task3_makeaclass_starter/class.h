// Blank header file
#include <string>
class student {
    private:
        std::string state;
        std::string name;  
        int age;
    public:
        /// constructor
        student();
        student(std::string name, std::string state, int age);
        /// method to get name, state, and age, respectively
        std::string getName();
        std::string getState();
        int getAge();
        /// set
        void setName(std::string name);
        void setState(std::string state);
        void setAge(int age);
        ~student();
};