
This is a little R pkg example that include a `C++` code.    
In the `Rscript/` folder there is the call to the R function that call C++ files.

#### BUILDING AND INSTALL R PKG
- ```$ R CMD build MyPKG ``` in order to build the R pakage
- ```$ R CMD INSTALL MyPKG_0.1.tar.gz``` to install the pakage 

#### REMOVE R PKG

- ```$ R CMD remove MyPKG```


#### File Descrpition 

* `/R/solverFIT.R` here it is definited the external R function called ```solver.fit()```
* `/src/` c++ directory 

* `/src/Makevars` makefile where we can definie the library
* `/src/.cpp` file dove viene definito la funzione ggm_ma


#### Functions Descrpition 
* `solver.fit()` the R function called in the Rscript/test.R script
