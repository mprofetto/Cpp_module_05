/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:33:44 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/04 16:19:13 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	test1;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test2("Luc", 151);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test3("Luc", -1);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test4("Luc", 3);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test5("Sylvie", 3);
		Bureaucrat	test6(test5);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test7("Pierre", 5);
		test7.promote();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test8("Didier", 5);
		test8.demote();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test9("Jeanne", 1);
		test9.promote();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Bureaucrat	test10("Louise", 150);
		test10.demote();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	Bureaucrat	test11;
	std::cout << test11 << std::endl;

	return (0);
}
