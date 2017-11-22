#include <iostream>
#include "Tokenizer.h"
using namespace std;

int main() {
Tokenizer tokenizer;
while(true) {
 tokenizer.reset();
 tokenizer.prompt();
 if(cin.peek() == NEWLINE) {
  cout << "Exiting.. " << endl;
  return 0;
}
 while (tokenizer.type()!=ERR && tokenizer.type()!=END){
  tokenizer.next();
  switch(tokenizer.type()) {
   case NUM:
    cout << "Number: " << tokenizer.num_read() <<endl;
    break;
   case OP:
    cout << "Operator: " << tokenizer.op_read() <<endl;
    break;
   case END:
    if(tokenizer.lpn_counter() != tokenizer.rpn_counter()) {
     cout << "Error: Mismatched parenthesis" << endl;
    }
    cout << "End of input." <<endl;
    break;
   case ERR:
    cout << "An error has been encountered" <<endl;
    return 0;
  }
 }
 cin.ignore();
}
 return 0;
}
