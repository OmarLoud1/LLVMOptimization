#include "AST.h"
#include <iostream>
#include <map>
#include <vector>
#include "llvm/IR/Value.h"

// pair <pointer, bool>-pointer-pointer - body

std::vector<double> findloopheader(ForExprAST* forloop) {
  std::vector<double> header;
    //if(typeid(exp)== typeid(forloop)){
    if(forloop) {
      ExprAST* body1 = forloop->Body.get();
/*
      BinaryExprAST* body2 = dynamic_cast<BinaryExprAST*>(body1);
        if(body2){
          NumberExprAST* bodyvalueleft = dynamic_cast<NumberExprAST*>(body2->LHS.get());
          NumberExprAST* bodyvalueright = dynamic_cast<NumberExprAST*>(body2->RHS.get());
          if(bodyvalueright && bodyvalueleft) {
            printf(" this is supposed to be 1: %f \n  this is supposed to be 2: %f \n ",bodyvalueleft->Val, bodyvalueright->Val);

          }
        }

 */
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

  //fprintf(stderr, "This Module has %lu externs and %lu functions!\n\n", TheModule->Externs.size(), TheModule->Functions.size());

  
  for (auto const& x : TheModule->Functions){
  
    //fprintf (stderr, "%s %p  \n", x.first.c_str(), x.second.first.get());
    FunctionAST* func = x.second.first.get();
    ForExprAST* forloop;
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

       // new binary expression op colon RHS body1 LHS body 2
       // forloop1 replace body 
       // completely remove forloop 2
       // draw a syntax treee

       printf("helloworld");
     }
    }
    

    //if(typeid(exp)== typeid(forloop)){
    





      //fprintf(stderr, "something %p \n", body1);
      
      //BinaryExprAST* rhs = static_cast<BinaryExprAST*>(forExpr->End);
      
      //BinaryExprAST* end = static_cast<BinaryExprAST*>(rhs->LHS.get());
      
      //auto start_loop = static_cast<ConstantFP *>(forExpr->Start.get());
      
     // auto end_loop = static_cast<BinaryExprAST>(forExpr->End->RHS.get());
      // printf("Start Loop: %f", start_loop->getValueAPF().convertToDouble());

     // printf("End Loop: %f", end);
    }
  


    //fprintf (stderr, "%s %s  \n", func, exp);
    //fprintf (stderr, "%d  \n", TheModule->getFunctionProto(x.first.c_str())->isOperator());

  }

/* 
if(forExpr) {
      exp = (ForExprAST*) exp;
      forloop = (ForExprAST*) exp;
      ExprAST* body1 = forloop->Body.get();

      BinaryExprAST* body2 = dynamic_cast<BinaryExprAST*>(body1);
        if(body2){
          NumberExprAST* bodyvalueleft = dynamic_cast<NumberExprAST*>(body2->LHS.get());
          NumberExprAST* bodyvalueright = dynamic_cast<NumberExprAST*>(body2->RHS.get());
          if(bodyvalueright && bodyvalueleft) {
            printf(" this is supposed to be 1: %f \n  this is supposed to be 2: %f \n ",bodyvalueleft->Val, bodyvalueright->Val);

          }
        }
        NumberExprAST* step = dynamic_cast<NumberExprAST*>(forloop->Step.get());
        if(step){
          printf(" this is 1: %f \n",step->Val);
        }

        NumberExprAST* start = dynamic_cast<NumberExprAST*>(forloop->Start.get());
        BinaryExprAST* end = dynamic_cast<BinaryExprAST*>(forloop->End.get());
        if(end){
          VariableExprAST* valueright = dynamic_cast<VariableExprAST*>(end->RHS.get());
          if(valueright ) {
            printf(" this is supposed to be n: %s \n ", valueright->Name.c_str());
          }
        }
*/