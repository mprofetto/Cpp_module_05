/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:49:25 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 14:52:23 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 0, 25, 5)
{
	this->_target = "random target";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 0, 25, 5),
	_target(target)
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
	AForm(copy.getName(), copy.getSignature(), copy.getGradeToSign(), copy.getGradeToExecute()),
	_target(copy.getTarget())
{
	;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat &bureaucrat) const
{
	if (this->getSignature() == 0)
		throw AForm::UnsignedFormException();
	else if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
