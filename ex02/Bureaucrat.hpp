/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:34:18 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/09 12:34:20 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:

		std::string	_name;
		int			_grade;

	public:

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(std::string name, int grade);

		Bureaucrat	&operator=(const Bureaucrat &copy);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		promote(void);
		void		demote(void);
		void		signForm(AForm &form);
		void		executeForm(AForm &form);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif
