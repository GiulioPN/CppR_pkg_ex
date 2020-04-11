#ifndef _PRINTER_HPP_
#define _PRINTER_HPP_

#include "pkgCore.h"

#include <fstream>
#include <string>
#include <iomanip>

/*
	Utility for debugging: print .txt 
	
*/

class printer{
public:


static void SaveSTDvector(std::string& name_txt, const std::vector<double> & vect){
   	const int size = vect.size();
	
	//set your output debug directory
	std::string directory = "/Users/giuliopn/Desktop/Example_R/Rscript/debugging_output/";
	name_txt = directory + name_txt;

	std::ofstream File(name_txt);
	if(File.is_open()){
		for(int k=0; k<size; k++){
				File<< std::scientific <<vect[k]<<'\n';
		}
	}
	File.close();
}


};

#endif
