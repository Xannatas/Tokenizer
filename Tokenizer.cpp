/* Tokenizer class
Comments, Schueller:  Sat Apr  1 16:04:40 PDT 2017
    1)  Accessor functions (e.g. num_read, op_read):	1/1
    2)  next():						2/2
    3)  op_code():					1/1
    4)  eat_spaces():					0.75/1
	- not catching leading spaces, i.e. spaces at the beginning of the
	expression, ok on subsequent spaces, also failing on spaces at the
	end of the input.
    5)  Repetitive prompt, exits on empty response:	1/1
    6)  Robust, handles bad input:			0.75/1
	- when bad input encountered should return to prompt not exit
	completely.
    7)  Reports tokens and types:			1/1
    8)  Handles '-' correctly:				1/1
    9)  Above and beyond (with comment):		1/1

        GRADE:  9.5/10

Comments and modifications made by me in the body of the program are marked
by a //SCHUELAW.  You are encouraged to search through your graded program
for the "SCHUELAW" string for those comments/changes.

Other Comments: Nice job!

*/
#include "Tokenizer.h"
#include <iostream>

// Allison Collier , Isaiah Banta

/* The above and beyond in this homework is adding an exponent operator as well as a factorial operator which will also set us up for the next homework assignment when we implement these operators in the stack for the computation. We also added two function lpn_counter() and rpn_counter() that return the number of left and right parenthesis respectively. This was used to add a feature where the program detects if there are mismatched parenthesis in the input and then exits*/ 



using namespace std;

Tokenizer::Tokenizer() {
 token_type = NUM;
 end = false;
 unary_minus = true;
 lpn_count = 0;
 rpn_count = 0;
}

void Tokenizer::prompt() const {
 cout << "Enter infix expressions: ";
}

void Tokenizer::next() {
 eat_spaces();
 char temp;
 temp = char(cin.peek());
 if (temp==NEWLINE) {
  end = true;
  token_type = END;
  unary_minus = true;
}
 else if (('0'<=temp && '9'>=temp) || temp == '.') {
  token_type = NUM;
  cin >> num;
  unary_minus = false;
 }
 else {
  token_type=OP;
  switch(temp) {
   case ADD_CHAR:
    unary_minus = true;
    op = ADD;
    break;
   case MLT_CHAR:
    unary_minus = true;
    op = MLT;
    break;
   case DIV_CHAR:
    unary_minus = true;
    op = DIV;
    break;
   case LPN_CHAR:
    unary_minus = true;
    op = LPN;
    lpn_count += 1;
    break;
   case RPN_CHAR:
    unary_minus = false;
    op = RPN;
    rpn_count += 1;
    break;
   case PWR_CHAR:
    unary_minus = true;
    op = PWR;
    break;
   case FCT_CHAR:
    unary_minus = false;
    op = FCT;
    break;
   case MOD_CHAR:
    unary_minus = true;
    op = MOD;
    break;

   case SUB_CHAR:
    if(unary_minus == true) {
     op = UNM;
    }
    else {
     op = SUB;
     unary_minus = true;
    }
    break;
   default:
    token_type = ERR;
    break;
  }
  cin.get();
 }
}
 
int Tokenizer::type() const {
 return token_type;
}

double Tokenizer::num_read() const{
 return num;
}

int Tokenizer::op_read() const{
 return op;
}

int Tokenizer::lpn_counter(){
 return lpn_count;
}

int Tokenizer::rpn_counter(){
 return rpn_count;
}
 
void Tokenizer::eat_spaces() const{
 if (char(cin.peek()) == SPC) {cin.ignore();}
}

void Tokenizer::reset() {
 end = false;
 token_type = NUM;
 unary_minus = true;
 rpn_count = 0;
 lpn_count = 0;
}

bool Tokenizer::end_of_stream() const{
 return end;
}
