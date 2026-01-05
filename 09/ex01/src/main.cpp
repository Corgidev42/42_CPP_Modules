#include "Rpn.hpp"
#include <iostream>
#include <exception>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cerr << "Invalid input, need RPN string" << std::endl;
		return 1;
	}

	RPN rpn_args(argv[1]);
	try {
		rpn_args.process();
		std::cout << rpn_args.result() << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// std::cout << "==== RPN ====" << std::endl;
	// RPN rpn;
	// RPN rpnA(rpn);
	// rpnA.str("1 2 +");
	// std::cout << rpnA.str() << std::endl;
	// rpn = rpnA;
	// rpn.str("");
	// try {
	// 	rpn.process("1 2 + 3 *");
	// 	std::cout << rpn.result() << std::endl;
	// } catch (std::exception& e) { 
	// 	std::cerr << e.what() << std::endl;
	// }
	// rpn.clear();
	// std::cout << rpn << std::endl;

	// std::cout << std::endl << "==== RPN1 ====" << std::endl;
	// RPN rpn1("2 4 6 * +");
	// try {
	// 	rpn1.process();
	// 	std::cout << rpn1.result() << std::endl;
	// } catch (std::exception& e) { 
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << std::endl << "==== RPN2 ====" << std::endl;
	// RPN rpn2;
	// try {
	// 	rpn2.push(25.0f);
	// 	rpn2.push(12.0f);

	// 	rpn2.sum();

	// 	rpn2.push(9.0f);
	// 	rpn2.sub();

	// 	rpn2.push(3.0f);
	// 	rpn2.push(1.0f);
	// 	std::cout << rpn2 << std::endl;

	// 	rpn2.mul();
	// 	rpn2.div();

	// 	std::cout << rpn2 << std::endl;
	// 	std::cout << rpn2.result() << std::endl;
	// 	std::cout << rpn2.pop() << std::endl;
	// } catch (std::exception& e) { 
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << std::endl << "==== RPN3 ====" << std::endl;
	// RPN rpn3;
	// try {
	// 	rpn3.process("4 1");
	// 	rpn3.process("3 + *");
	// 	rpn3.process("2 /");
	// 	std::cout << rpn3 << std::endl;
	// 	std::cout << rpn3.result() << std::endl;
	// } catch (std::exception& e) { 
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << std::endl << "==== RPN4 ====" << std::endl;
	// RPN rpn4;
	// try {
	// 	// Not a number
	// 	rpn4.process("1 adidas 2 +");
	// } catch (std::exception& e) { std::cerr << e.what() << std::endl;}
	// try {
	// 	// Dividing by 0
	// 	rpn4.clear();
	// 	rpn4.process("3 0 /");
	// } catch (std::exception& e) { std::cerr << e.what() << std::endl;}
	// try {
	// 	// 2 args in stack -> impossible
	// 	rpn4.clear();
	// 	rpn4.process("0 3");
	// 	std::cout << rpn4.result() << std::endl;
	// } catch (std::exception& e) { std::cerr << e.what() << std::endl;}
	// try {
	// 	// Not enough args in stack during binary operation
	// 	rpn4.clear();
	// 	rpn4.process("0 +");
	// 	rpn4.clear();
	// } catch (std::exception& e) { std::cerr << e.what() << std::endl;}
	// try {
	// 	// Too many numbers in process
	// 	rpn4.clear();
	// 	rpn4.process("0");
	// 	for (int i = 0; i < MAX_NUMBERS; i++)
	// 		rpn4.process("1 +");
	// } catch (std::exception& e) { std::cerr << e.what() << std::endl;}

	
	// std::cout << std::endl << "==== RPN5 ====" << std::endl;
	// RPN rpn5;

	// try {
	// 	rpn5.process("7 9 5 4 3 2 1 8 0 + - * / + - * /");
	// 	std::cout << rpn5.result() << std::endl;
	// 	rpn5.clear();

	// 	rpn5.process("8 9 * 9 - 9 - 9 - 4 - 1 +");
	// 	std::cout << rpn5.result() << std::endl;
	// 	rpn5.clear();

	// 	rpn5.process("7 7 * 7 -");
	// 	std::cout << rpn5.result() << std::endl;
	// 	rpn5.clear();

	// 	rpn5.process("1 2 * 2 / 2 * 2 4 - +");
	// 	std::cout << rpn5.result() << std::endl;
	// 	rpn5.clear();

	// 	rpn5.process("(1 + 1)");
	// 	std::cout << rpn5.result() << std::endl;
	// } catch (std::exception& e) { 
	// 	std::cerr << e.what() << std::endl;
	// }
	return 0;
}