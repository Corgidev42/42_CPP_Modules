#include "Rpn.hpp"

binary RPN::_binaryAccess() {
	if (_stack.size() <= 1)
		throw RPN::StackIsEmptyException();
	float right = _stack.top();
	_stack.pop();
	float left = _stack.top();
	_stack.pop();

	return binary(left, right);
}

RPN::RPN() : _str(""), _numbers(0) {}

RPN::RPN(const std::string& str) : _str(str), _numbers(0) {}

RPN::RPN(const RPN& other) : _stack(other._stack), _str(other._str), _numbers(other._numbers) {
	(void) other;
}

RPN& RPN::operator=(const RPN& other) {
	_stack = other._stack;
	_str = other._str;
	_numbers = other._numbers;
	return *this;
}

RPN::~RPN() {}

void RPN::str(const std::string& str) {
	_str = str;
}

std::string RPN::str() {
	return _str;
}

int RPN::size() {
	return _stack.size();
}


void RPN::push(float n) {
	_stack.push(n);
}

float RPN::pop() {
	if (_stack.size() == 0)
		throw RPN::StackIsEmptyException();
	float n = _stack.top();
	_stack.pop();
	return n;
}

void RPN::clear() {
	while (_stack.size() > 0)
		_stack.pop();
	_numbers = 0;
}

void RPN::_processToken(const std::string& token) {
	if (token.size() == 1 && token[0] == '+')
		sum();
	else if (token.size() == 1 && token[0] == '-')
		sub();
	else if (token.size() == 1 && token[0] == '*')
		mul();
	else if (token.size() == 1 && token[0] == '/')
		div();
	else {
		float n = std::atof(token.c_str());
		if (n == 0 && (token.size() > 1 || token[0] != '0'))
			throw RPN::InvalidTypeException();
		push(n);
	}
}

void RPN::_process() {
	size_t pos;
	while ((pos = _str.find(' ', 0)) != std::string::npos) {
		std::string token = _str.substr(0, pos);
		_processToken(token);
		_str = _str.substr(pos + 1, _str.size() - pos);
	}
	if (_str.size() > 0) {
		_processToken(_str);
		_str = "";
	}
}

void RPN::process(const std::string& str) {
	_str = str;
	_process();
}

void RPN::process() {
	_process();
}

float RPN::result() {
	if (_stack.size() == 0)
		throw RPN::StackIsEmptyException();
	if (_stack.size() > 1)
		throw RPN::InvalidResultStackException();
	return _stack.top();
}

std::ostream& operator<<(std::ostream &os, const RPN& rpn) {
	RPN copy(rpn);

	os << "[";
	while (copy.size() > 0) {
		os << copy.pop() << (copy.size() > 0 ? "," : "");
	}
	os << "]";
	return os;
}

void RPN::sum() {
	binary binary = _binaryAccess();

	_stack.push(binary.first + binary.second);
}

void RPN::sub() {
	binary binary = _binaryAccess();

	_stack.push(binary.first - binary.second);
}

void RPN::mul() {
	binary binary = _binaryAccess();

	_stack.push(binary.first * binary.second);
}

void RPN::div() {
	binary binary = _binaryAccess();

	if (binary.second == 0)
		throw RPN::DivideByZeroException();

	_stack.push(binary.first / binary.second);
}

const char* RPN::InvalidTypeException::what() const throw() {
	return "Invalid type";
}

const char* RPN::DivideByZeroException::what() const throw() {
	return "Divide by zero";
}

const char* RPN::InvalidResultStackException::what() const throw() {
	return "Invalid result stack";
}

const char* RPN::InvalidBinaryStackException::what() const throw() {
	return "Invalid binary stack";
}

const char* RPN::StackIsEmptyException::what() const throw() {
	return "Stack is empty";
}

const char* RPN::TooManyNumbersException::what() const throw() {
	return "Too many numbers in process";
}