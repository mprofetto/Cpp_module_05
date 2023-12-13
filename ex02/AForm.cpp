/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:42:06 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/13 10:47:36 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}

const char	*AForm::UnsignedFormException::what(void) const throw()
{
	return ("Form has not been approved");
}

const char	*AForm::AssignationForbidden::what(void) const throw()
{
	return ("Form cannot be modified in any way, they can be signed or executed. That's it.");
}

AForm::AForm() : _name("random Form"), _signed(0), _grade_to_sign(150), _grade_to_execute(150)
{
	std::cout << "Form " << this->getName() << " created by default" << std::endl;
}


AForm::AForm(const AForm &copy) :
	_name(copy.getName()),
	_signed(copy.getSignature()),
	_grade_to_sign(copy.getGradeToSign()),
	_grade_to_execute(copy.getGradeToExecute())
{
	std::cout << "Form " << this->getName() << " created by copy" << std::endl;
}

AForm::AForm(std::string name, bool signature, int grade_to_sign, int grade_to_execute) :
	_name(name),
	_signed(signature),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_sign < 1)
		throw AForm::GradeTooHighException();
	if (grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	else if (grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	std::cout << "Form " << this->getName() << " created" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form " << this->getName() << " has been destroyed" << std::endl;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSignature(void) const
{
	return (this->_signed);
}

int			AForm::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int			AForm::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

AForm	&AForm::operator=(const AForm &copy)
{
	throw AssignationForbidden();
	(void) copy;
}

std::ostream	&operator<<(std::ostream &o, const AForm &AForm)
{
	o << "Form " << AForm.getName() << ":" << std::endl;
	o << "	Status: ";
	if (AForm.getSignature() == 1)
		o << "signed";
	else
		o << "not signed";
	o << std::endl;
	o << "Can be signed by a grade " << AForm.getGradeToSign() << " bureaucrat" << std::endl;
	o << "Can be executed by a grade " << AForm.getGradeToExecute() << " bureaucrat" << std::endl;
	return (o);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_signed = 1;
}
