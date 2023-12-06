/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:32:49 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 13:15:18 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 0, 145, 137)
{
	this->_target = "random target";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 0, 145, 137),
	_target(target)
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy.getName(), copy.getSignature(), copy.getGradeToSign(), copy.getGradeToExecute()),
	_target(copy.getTarget())
{
	;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	writeAsciiTree(std::ofstream &o)
{
	o << "       _-_"        << std::endl;
	o << "    /~~   ~~\\"    << std::endl;
	o << " /~~         ~~\\" << std::endl;
	o << "{               }" << std::endl;
	o << " \\  _-     -_  /" << std::endl;
	o << "   ~  \\\\ //  ~"  << std::endl;
	o << "_- -   | | _- _"   << std::endl;
	o << "  _ -  | |   -_"   << std::endl;
	o << "      // \\\\"     << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const
{
	std::ofstream	new_file;

	if (this->getSignature() == 0)
		throw AForm::UnsignedFormException();
	else if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		new_file.open(this->getTarget() + "_shrubbery", std::ofstream::out);
		writeAsciiTree(new_file);
		writeAsciiTree(new_file);
		writeAsciiTree(new_file);
		new_file.close();
	}
}
