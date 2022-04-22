#include "AST.h"
#include <iostream>
#include <map>
#include <vector>
#include "llvm/IR/Value.h"

// pair <pointer, bool>-pointer-pointer - body

std::vector<double> findloopheader(ForExprAST* forloop) {
  std::vector<double> header;

    if(forloop) {
      ExprAST* body1 = forloop->Body.get();

        NumberExprAST* step = dynamic_cast<NumberExprAST*>(forloop->Step.get());
        if(step){
          header.push_back(step->Val);
          printf(" this is 1: %f \n",step->Val);
        }else{
          // implement checking for non existent steps
        }

        NumberExprAST* start = dynamic_cast<NumberExprAST*>(forloop->Start.get());
        if(start){
          header.push_back(start->Val);
          printf(" this is 1: %f \n",start->Val);
        }else{
          // implement checking for non existent steps
        }
        BinaryExprAST* end = dynamic_cast<BinaryExprAST*>(forloop->End.get());
        if(end){
          //VariableExprAST* valueright = dynamic_cast<VariableExprAST*>(end->RHS.get());
        NumberExprAST* valueright = dynamic_cast<NumberExprAST*>(end->RHS.get());
          if(valueright) {
            printf(" this is supposed to be n: %f \n ", valueright->Val);
            header.push_back(valueright->Val);
          }
        }
    }
    return header;
}

void ExamplePass(ModuleAST* TheModule) {

  for (auto const& x : TheModule->Functions){
    if(!x.second.second) continue;

    FunctionAST* func = x.second.first.get();
    BinaryExprAST* exp = dynamic_cast<BinaryExprAST*>(func->Body.get());

    ForExprAST* valueright = dynamic_cast<ForExprAST*>(exp->RHS.get());
    ForExprAST* valueleft = dynamic_cast<ForExprAST*>(exp->LHS.get());

    std::vector<double> headerfor1 = findloopheader(valueleft);
    std::vector<double> headerfor2 = findloopheader(valueright);

    if(headerfor1.size()== 3 && headerfor2.size() == 3){
    
      bool same = true;
     for(int i = 0; i < 3; i++){
       if(headerfor1.at(i) != headerfor2.at(i)) {
          same = false;
          printf("%f %f \n", headerfor1.at(i), headerfor2.at(i));
          break;
       }
     }  
     if(same){

      printf("The for loops are the same");

      BinaryExprAST* newExpression = new BinaryExprAST(':', nullptr, nullptr);

      newExpression->RHS.swap(valueright->Body);
      newExpression->LHS.swap(valueleft->Body);

      valueleft->Body.reset(newExpression);

      func->Body.swap(exp->LHS);

       // new binary expression op colon RHS body1 LHS body 2
       // forloop1 replace body 
       // completely remove forloop 2
       // draw a syntax treee
  
     }
     else{
       printf("the loops are not the same");
     }
    }
    }
  }

