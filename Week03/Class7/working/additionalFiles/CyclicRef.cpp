#include <iostream>
#include <memory>
#include <string>

class Person
{
private:
	std::string m_name;
	std::weak_ptr<Person> m_partner; 

public:

	Person(const std::string &name): m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Person()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Person> &p1, std::shared_ptr<Person> &p2)
	{
        bool retValue = true;
		if (!p1 || !p2){
			retValue = false;
        }else{
            p1->m_partner = p2;
            p2->m_partner = p1;

            std::cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';
        }

		return retValue;
	}
};

int main()
{
	std::shared_ptr<Person> lucy = std::make_shared<Person>("Lucy"); // create a Person named "Lucy"
	std::shared_ptr<Person> ricky = std::make_shared<Person>("Ricky"); // create a Person named "Ricky"

	partnerUp(lucy, ricky); // Make "Lucy" point to "Ricky" and vice-versa

	return EXIT_SUCCESS;
}