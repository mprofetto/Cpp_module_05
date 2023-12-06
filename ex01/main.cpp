/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:47 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 10:47:08 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form	test1;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Form	test2("test form", 0, 2, 2);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Form	test3("test form", 0, -1, 2);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Form	test4("test form", 0, 2, 189);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Form	test5("test form", 0, 2, 2);
		Form	test6(test5);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Form	test7("test form", 0, 2, 2);
		Bureaucrat	bureaucrat1("Luc", 1);
		test7.beSigned(bureaucrat1);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Form	test7("test form 7", 0, 2, 2);
		Bureaucrat	bureaucrat1("Luc", 5);
		test7.beSigned(bureaucrat1);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}

	try
	{
		Form	test8("test form 8", 0, 2, 2);
		Bureaucrat	bureaucrat1("Luc", 5);
		bureaucrat1.signForm(test8);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "Exception: " << e.what() << '\n';
	}
	return (0);
}
