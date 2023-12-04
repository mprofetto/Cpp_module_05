/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:47:57 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/04 17:09:42 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade cannot be smaller than 150");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade cannot be higher than 1");
}

Bureaucrat::Bureaucrat() : _name("random bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat \"" << this->_name << "\" with grade of " << this->_grade << " has been created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat \"" << this->_name << "\" with grade of " << this->_grade << " has been destroyed" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat \"" << this->_name << "\" has been created by copy. His grade is " << this->_grade << "." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(150)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
	std::cout << "Bureaucrat \"" << this->_name << "\" has been created by assignation. His grade is " << this->_grade << "." << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int			Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void		Bureaucrat::promote(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
	std::cout << "Bureaucrat " << this->_name << " has been promoted to grade " << this->_grade << "." << std::endl;
}

void		Bureaucrat::demote(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
	std::cout << "Bureaucrat " << this->_name << " has been demoted to grade " << this->_grade << "." << std::endl;
}

void		Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't signe " << form.getName() << " because ";
		std::cerr << e.what() << '\n';
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (o);
}
