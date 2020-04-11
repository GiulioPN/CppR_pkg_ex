#ifndef _SOLVER_H
#define _SOLVER_H

#include <cmath>
#include <math.h>
#include "pkgCore.h"

#include "printer.h"


template <int ORDER>
class SOLVER_Base {

  protected:

  // a simple member 
  double scale_param_; 
  //solution member class
  std::vector<double> _solution; 

  virtual double link(const double& mu) = 0; // g(.)


  public:

    // Constructor
  SOLVER_Base(double sparam): scale_param_(sparam){
      Rprintf("Hello I'm SOLVER_Base constructor \n");
  };
    
  virtual ~SOLVER_Base(){};
  
  // solver method in order to build up the solution 
   void apply();

   // get member 
   inline std::vector<double> const & getSolution() const{return _solution;}
   
};

// Derived classes:

// Bernoulli
template < int ORDER >
class SOLVER_Bernoulli : public SOLVER_Base < ORDER > {

  protected:
    inline double link(const double& mu){ return log(mu/(1 - mu)); }

  public:

    SOLVER_Bernoulli( double sparam):
      SOLVER_Base<ORDER>(sparam){};
};


// Poisson
template <int ORDER>
    class SOLVER_Poisson : public SOLVER_Base < ORDER> {

    protected:

      inline double link(const double& mu){ return log(mu); }

    public:

    SOLVER_Poisson( double sparam):
      SOLVER_Base< ORDER>( sparam ){};

};



#include "SOLVER_imp.h"

#endif
