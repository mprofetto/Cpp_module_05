/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:12:47 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 16:56:56 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Intern	random_intern;
	AForm	*form;
	std::cout << std::endl << "All working, Intern make ShrubberyCreationForm" << std::endl;

	try
	{
		form = random_intern.makeform("ShrubberyCreationForm", "Luc");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Bad name" << std::endl;

	try
	{
		form = random_intern.makeform("lqwkdnqwkln", "Luc");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
