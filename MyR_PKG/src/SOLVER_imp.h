#ifndef SOLVER_IMP_H
#define SOLVER_IMP_H

#include "SOLVER.h"


template < int ORDER >
void SOLVER_Base<ORDER>::apply(){
 
  
  // Create a dummy solution 
  for(int i=0; i < 5 ;i++)
    _solution.push_back(i);

  	Rprintf("I'm apply \n");

  	//print solution 
    std::string saving_filename = "IM_APPLY.txt";
    printer::SaveSTDvector(saving_filename, _solution);


}// 




#endif
