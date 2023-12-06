/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:15:41 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 17:00:05 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char	*Intern::UnknownFormTemplate::what(void) const throw()
{
	return ("Intern doesn't know the form template asked");
}

std::string	Intern::getKnownForm(int index) const
{
	return (this->_known_forms[index]);
}

Intern::Intern()
{
	this->_known_forms[0] = "ShrubberyCreationForm";
	this->_known_forms[1] = "RobotomyRequestForm";
	this->_known_forms[2] = "PresidentialPardonForm";
	return;
}

Intern::~Intern()
{
	return;
}

Intern::Intern(const Intern &copy)
{
	this->_known_forms[0] = copy.getKnownForm(0);
	this->_known_forms[1] = copy.getKnownForm(1);
	this->_known_forms[2] = copy.getKnownForm(2);
	return;
}

AForm	*Intern::makeform(std::string name, std::string target) const
{
	AForm	*form;
	int		i;

	i = -1;
	form = NULL;
	while (++i < 3)
	{
		if (name.compare(this->_known_forms[i]) == 0)
			break;
	}
	switch(i)
	{
		case 0:
		{
			form = new ShrubberyCreationForm(target);
			break;
		}
		case 1:
		{
			form = new RobotomyRequestForm(target);
			break;
		}
		case 2:
		{
			form = new PresidentialPardonForm(target);
			break;
		}
		case 3:
			throw UnknownFormTemplate();
	}
	std::cout << "Intern create " << name << std::endl;
	return (form);
}
