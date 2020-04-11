#ifndef __SOLVERAFACTORY_HPP__
#define __SOLVERAFACTORY_HPP__

#include "pkgCore.h"
#include "SOLVER.h"
#include <cassert>

#include <memory>


template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}


//! A Factory class
template < int ORDER>
class SOLVERfactory
{
	public:
	~SOLVERfactory()=default;
		
	//! A method that takes as parameter a string and builds a pointer to the right object for the data distribution
	static std::unique_ptr<SOLVER_Base< ORDER >> createSOLVERsolver(const std::string &family, double& scaleParam){

		if(family=="binomial"){
		    return make_unique<SOLVER_Bernoulli<ORDER>>(scaleParam);
		}else if(family=="poisson"){
		    return make_unique<SOLVER_Poisson< ORDER >>(scaleParam);
		}
		return std::unique_ptr<SOLVER_Base< ORDER >>(nullptr);
	}

};


#endif
