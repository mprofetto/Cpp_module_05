/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:42:06 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 10:38:51 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}

Form::Form() : _name("random form"), _signed(0), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "Form " << this->_name << " created by default" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " has been destroyed" << std::endl;
}

Form::Form(const Form &copy) :
	_name(copy.getName()),
	_signed(copy.getSignature()),
	_grade_to_sign(copy.getGradeToSign()),
	_grade_to_execute(copy.getGradeToExecute())
{
	std::cout << "Form " << this->_name << " created by copy" << std::endl;
}

Form::Form(std::string name, bool signature, int grade_to_sign, int grade_to_execute) :
	_name(name),
	_signed(signature),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_sign < 1)
		throw Form::GradeTooHighException();
	if (grade_to_execute > 150)
		throw Form::GradeTooLowException();
	else if (grade_to_execute < 1)
		throw Form::GradeTooHighException();
	std::cout << "Form " << this->_name << " created by assignation" << std::endl;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSignature(void) const
{
	return (this->_signed);
}

int			Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int			Form::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "Form " << form.getName() << ":" << std::endl;
	o << "	Status: ";
	if (form.getSignature() == 1)
		o << "signed";
	else
		o << "not signed";
	o << std::endl;
	o << "Can be signed by a grade " << form.getGradeToSign() << " bureaucrat" << std::endl;
	o << "Can be executed by a grade " << form.getGradeToExecute() << " bureaucrat" << std::endl;
	return (o);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		this->_signed = 1;
}
