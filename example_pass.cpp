#include "AST.h"
#include <iostream>
#include <map>

// pair <pointer, bool>-pointer-pointer - body
void ExamplePass(ModuleAST* TheModule) {

  //fprintf(stderr, "This Module has %lu externs and %lu functions!\n\n", TheModule->Externs.size(), TheModule->Functions.size());

  
  for (auto const& x : TheModule->Functions){
  
    //fprintf (stderr, "%s %p  \n", x.first.c_str(), x.second.first.get());
    FunctionAST* func = x.second.first.get();
    ForExprAST* forloop;
    ExprAST* exp = func->Body.get();
    //print(exp);
    ForExprAST* forExpr = dynamic_cast<ForExprAST*>(exp);

    //if(typeid(exp)== typeid(forloop)){
    if(forExpr) {
      exp = (ForExprAST*) exp;
      forloop = (ForExprAST*) exp;
      ExprAST* body1 = forloop->Body.get();
      fprintf(stderr, "something %p \n", body1);
      
      fprintf(stderr, " %s \n", forloop->Start.get()->codegen()->getNameOrAsOperand().c_str() );
      fprintf(stderr, " %s \n", forloop->End.get()->codegen()->getNameOrAsOperand().c_str() );


    }
    


    //fprintf (stderr, "%s %s  \n", func, exp);
    //fprintf (stderr, "%d  \n", TheModule->getFunctionProto(x.first.c_str())->isOperator());

  }
}
