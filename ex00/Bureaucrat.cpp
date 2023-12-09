/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:47:57 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/09 12:33:38 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
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

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy.getGrade();
	this->_name = copy.getName();
	return (*this);
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (o);
}
