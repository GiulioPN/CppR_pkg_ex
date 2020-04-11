# SIM_BERNOULLI with right mesh type

.rs.restartR()
rm(list=ls())


#################################
## Gam fem fit BERNOULLI TEST ##
################################


# LOAD library ----------------------------------------
library(MyPKG)


output_CPP<- MyPKG::solver.fit(1, "binomial", 1)


