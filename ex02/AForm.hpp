#pragma once

#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _status;
		const unsigned int _grade_sign;
		const unsigned int _grade_execute;
		void beSigned(void);

	public:
		AForm(const std::string& name,
				const unsigned int grade_sign,
				const unsigned int grade_execute);
		virtual ~AForm();
		const std::string& getName(void) const;
		bool getStatus(void) const;
		unsigned int getGradeSign(void) const;
		unsigned int getGradeExecute(void) const;
		void beSigned(Bureaucrat& b);
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

		class FormError : public std::exception {
			private:
				std::string _message;
			public:
				FormError(std::string message);
				const char* what() const throw();
				virtual ~FormError() throw();
		};
};


std::ostream& operator<<(std::ostream& os, const AForm& f);