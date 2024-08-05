#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    // Create form objects with different targets
    ShrubberyCreationForm form1("office");
    ShrubberyCreationForm form2(form1);
    ShrubberyCreationForm form3;
    RobotomyRequestForm form4("lab");
    PresidentialPardonForm form5("Shelly");
    // Create bureaucrat objects with different names and grades
    Bureaucrat bureaucrat1("Alice", 140);
    Bureaucrat bureaucrat2("Bob", 50);
    Bureaucrat bureaucrat3("Charlie", 1);
    // Assign form1 to form3
    form3 = form1;
    std::cout << std::endl;

    // Print form details
    std::cout << std::endl;
    std::cout << form1 << " | target: " << form1.getTarget() << std::endl;
    std::cout << form2 << " | target: " << form2.getTarget() << std::endl;
    std::cout << form3 << " | target: " << form3.getTarget() << std::endl;
    std::cout << form4 << " | target: " << form4.getTarget() << std::endl;
    std::cout << form5 << " | target: " << form5.getTarget() << std::endl;

    // Execute and sign forms with different bureaucrats
    bureaucrat2.executeForm(form3); // Bob tries to execute form3
    bureaucrat1.signForm(form3);    // Alice signs form3
    bureaucrat1.executeForm(form3); // Alice tries to execute form3
    bureaucrat2.executeForm(form3); // Bob executes form3
    bureaucrat1.signForm(form4);    // Alice signs form4
    bureaucrat2.signForm(form4);    // Bob signs form4
    bureaucrat2.executeForm(form4); // Bob executes form4
    bureaucrat3.executeForm(form4); // Charlie executes form4
    bureaucrat2.signForm(form5);    // Bob signs form5
    bureaucrat3.executeForm(form5); // Charlie executes form5
    bureaucrat3.signForm(form5);    // Charlie signs form5
    bureaucrat3.executeForm(form5); // Charlie executes form5
    std::cout << std::endl;

    // ex03
    // Create an Intern object
    Intern intern;
    // Create forms using the intern
    AForm *shrubberyForm = intern.makeForm("ShrubberyCreationForm", "park");
    AForm *robotomyForm = intern.makeForm("RobotomyRequestForm", "gym");
    AForm *presidentialForm = intern.makeForm("PresidentialPardonForm", "Grandma");
    // Bureaucrat signs the forms
    bureaucrat3.signForm(*shrubberyForm);
    bureaucrat3.signForm(*robotomyForm);
    bureaucrat3.signForm(*presidentialForm);
    // Bureaucrat executes the forms
    bureaucrat3.executeForm(*shrubberyForm);
    bureaucrat3.executeForm(*robotomyForm);
    bureaucrat3.executeForm(*presidentialForm);
    // Clean up dynamically allocated memory
    delete shrubberyForm;
    delete robotomyForm;
    delete presidentialForm;
    std::cout << std::endl;

    return 0;
}
