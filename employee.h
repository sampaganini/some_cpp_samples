#ifndef employee_h
#define employee_h 
#include <string.h>

class Employee
    {
        
       public:
        string Name;
        string Position;
        int Age;  
        
        Employee(string new_name = "Unknown",string new_position = "Unknown", int new_age = 0)
        {
            Name = new_name;
            Position = new_position;
            Age = new_age;
        }
        
        ~Employee() {};
        friend ostream& operator <<(ostream& os, const Employee& emp)
        {
          return  os << emp.Name << ' '<< emp.Position << ' ' << emp.Age;
 
        }
    };
    
    
#endif /* employee.h */