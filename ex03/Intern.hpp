/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:13:24 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/09 13:11:52 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		std::string	_known_forms[3];

	public:

		class	UnknownFormTemplate : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);

		Intern		&operator=(const Intern &copy);
		std::string	getKnownForm(int index) const;
		AForm		*makeform(std::string name, std::string target) const;
};

#endif
