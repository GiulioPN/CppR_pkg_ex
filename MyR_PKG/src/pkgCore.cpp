#define R_VERSION_

#include "pkgCore.h"

#include "SOLVER.h"
#include "SOLVERfactory.h"
#include "printer.h"


template<int ORDER >
SEXP skeleton( std::string family, SEXP RscaleParam)
{


	double scaleParam = REAL(RscaleParam)[0];

//traditional: IT WORKS 
/*
	Rprintf("I'm before apply \n");
	SOLVER_Bernoulli<ORDER> solver(scaleParam);
	solver.apply();
	Rprintf("I'm before apply \n");
	const std::vector<double>& solution = solver.getSolution();
*/

// Factory: THIS IS THE PROBLEM IN mac OS Catalina, but in UBUNTU works
   	
   	Rprintf("I'm before apply factory \n");
  	
  	std::unique_ptr<SOLVER_Base< ORDER >> fsolver = SOLVERfactory< ORDER >::createSOLVERsolver(family, scaleParam);
  	fsolver->apply();
  	// end of problem
  	const std::vector<double>& solution = fsolver->getSolution();
 	Rprintf("I'm after apply factory \n");
 	
 	//print solution
    std::string saving_filename = "IM_SKELETON.txt";
    printer::SaveSTDvector(saving_filename, solution);


	//Copy result in R memory
	SEXP result = R_NilValue;
 	result = PROTECT(Rf_allocVector(VECSXP, 1));
	
	SET_VECTOR_ELT(result, 0, Rf_allocVector(REALSXP, solution.size()));

  	//return solution
	double *rans = REAL(VECTOR_ELT(result, 0));
	for(int i = 0; i < solution.size(); i++)
	{
			rans[i] = solution[i];
	}

	UNPROTECT(1);

	return(result);
}



extern "C" {

  SEXP solver_fit(SEXP Rorder, SEXP Rfamily, SEXP RscaleParam)
{
    //Set input data: can I re-use this fdapde class? FPCA actually implement it's own class for the datastructure
	

	int ORDER = INTEGER(Rorder)[0];

  	std::string family = CHAR(STRING_ELT(Rfamily,0));
  	
  	if(ORDER==1)
	   return (skeleton< 1 >(family, RscaleParam));
	else 
    	return(R_NilValue);
}


}
