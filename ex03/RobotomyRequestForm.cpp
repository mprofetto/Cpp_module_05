/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:23:28 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/13 10:40:23 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 0, 72, 45)
{
	srand((unsigned int)time(NULL));
	this->_target = "random target";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 0, 72, 45),
	_target(target)
{
	srand((unsigned int)time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
	AForm(copy.getName(), copy.getSignature(), copy.getGradeToSign(), copy.getGradeToExecute()),
	_target(copy.getTarget())
{
	srand((unsigned int)time(NULL));
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const AForm &copy)
{
	throw AForm::AssignationForbidden();
	(void) copy;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat &bureaucrat) const
{
	static int rand_nbr = 0;

	if (this->getSignature() == 0)
		throw AForm::UnsignedFormException();
	else if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Brrrr! Brrrr! Brrrr!" << std::endl;
		rand_nbr += std::rand();
		if (rand_nbr % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getTarget() << "robotomy has failed" << std::endl;
	}
}
