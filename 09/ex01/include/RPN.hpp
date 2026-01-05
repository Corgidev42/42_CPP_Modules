#pragma once

#include <string>
#include <stack>
#include <ostream>
#include <stdexcept>
#include <cstdlib>

typedef std::pair<float, float> binary;

#ifndef MAX_NUMBERS
	#define MAX_NUMBERS 9
#endif

class RPN {
private:
	std::stack<float> _stack;
	std::string _str;
	int _numbers;

	void _processToken(const std::string& token);
	binary _binaryAccess();
	void _process();
public:
	RPN();
	RPN(const std::string& str);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void str(const std::string& str);
	std::string str();

	int size();

	void push(float n);
	float pop();

	void clear();

	void process(const std::string& str);
	void process();
	float result();

	friend std::ostream& operator<<(std::ostream &os, const RPN& rpn);

	void sum();
	void sub();
	void mul();
	void div();

	class InvalidTypeException : public std::exception {
		public:
			const char* what() const throw();
	};

	class DivideByZeroException : public std::exception {
		public:
			const char* what() const throw();
	};

	class InvalidResultStackException : public std::exception {
		public:
			const char* what() const throw();
	};

	class InvalidBinaryStackException : public std::exception {
		public:
			const char* what() const throw();
	};

	class StackIsEmptyException : public std::exception {
		public:
			const char* what() const throw();
	};

	class TooManyNumbersException : public std::exception {
		public:
			const char* what() const throw();
	};
};