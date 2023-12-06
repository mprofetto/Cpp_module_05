/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:47 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 16:45:54 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << std::endl << "All working, ShrubberyCreationForm execute himself" << std::endl;

	try
	{
		ShrubberyCreationForm	test1("Luc");
		Bureaucrat				bureaucrat1("Robert", 5);
		test1.beSigned(bureaucrat1);
		test1.execute(bureaucrat1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "All working, bureaucrat execute ShrubberyCreationForm" << std::endl;

	try
	{
		ShrubberyCreationForm	test1("Roger");
		Bureaucrat				bureaucrat1("Albert", 5);
		test1.beSigned(bureaucrat1);
		bureaucrat1.executeForm(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout <<  std::endl << "Unsigned ShrubberyCreationForm try to execute himself" << std::endl;

	try
	{
		ShrubberyCreationForm	test1("Sylvie");
		Bureaucrat				bureaucrat1("Nathalie", 5);
		test1.execute(bureaucrat1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout <<  std::endl << "Bureaucrat try to execute unsigned ShrubberyCreationForm" << std::endl;

	try
	{
		ShrubberyCreationForm	test1("Géraldine");
		Bureaucrat				bureaucrat1("Joséphine", 5);
		bureaucrat1.executeForm(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout <<  std::endl << "ShrubberyCreationForm try to execute himself by to low bureaucrat" << std::endl;

	try
	{
		ShrubberyCreationForm	test1("Eric");
		Bureaucrat				bureaucrat1("Erac", 150);
		Bureaucrat				bureaucrat2("José", 1);
		test1.beSigned(bureaucrat2);
		test1.execute(bureaucrat1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout <<  std::endl << "Bureaucrat try to execute too high ShrubberyCreationForm" << std::endl;

	try
	{
		ShrubberyCreationForm	test1("Riri");
		Bureaucrat				bureaucrat1("Fifi", 150);
		Bureaucrat				bureaucrat2("Loulou", 1);
		test1.beSigned(bureaucrat2);
		bureaucrat1.executeForm(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "All working, Robotomy form execute himself" << std::endl;

	try
	{
		RobotomyRequestForm	test1("Luc");
		Bureaucrat				bureaucrat1("Robert", 5);
		test1.beSigned(bureaucrat1);
		test1.execute(bureaucrat1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "All working, Bureaucrat execute RobotomyRequestForm" << std::endl;

	try
	{
		RobotomyRequestForm	test1("Luc");
		Bureaucrat			bureaucrat1("Robert", 5);
		test1.beSigned(bureaucrat1);
		bureaucrat1.executeForm(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "All working, Bureaucrat execute PresidentialPardonForm" << std::endl;

	try
	{
		PresidentialPardonForm	test1("Luc");
		Bureaucrat			bureaucrat1("Robert", 5);
		test1.beSigned(bureaucrat1);
		bureaucrat1.executeForm(test1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
