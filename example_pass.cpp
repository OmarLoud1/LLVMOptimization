#include "AST.h"
#include <iostream>
#include <map>

// pair <pointer, bool>-pointer-pointer - body
void ExamplePass(ModuleAST* TheModule) {

  //fprintf(stderr, "This Module has %lu externs and %lu functions!\n\n", TheModule->Externs.size(), TheModule->Functions.size());

  
  for (auto const& x : TheModule->Functions){
  
      fprintf (stderr, "%s %p  \n", x.first.c_str(), x.second.first.get());
      FunctionAST* func = x.second.first.get();
      ForExprAST* forloop;
      ExprAST* exp = func->Body.get();

      if(typeid(exp)== typeid(forloop)){
        exp = (ForExprAST*) exp;
        forloop = (ForExprAST*) exp;
        ExprAST* body1 = forloop->Body.get();
      }
      fprintf (stderr, "%s %s  \n", func, exp);
      fprintf (stderr, "%d  \n", TheModule->getFunctionProto(x.first.c_str())->isOperator()); 

      //std::pair<std::unique_ptr<FunctionAST>, bool> pair1;
      //pair1 = TheModule->Functions.find(x.first);
      //fprintf (stderr, "%s  \n", pair1.first);
      //fprintf (stderr, "%s  \n", pair1.second.c_str());    
    }
}
