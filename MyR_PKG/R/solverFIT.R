#' Spatial generalize linear model with differential regularization
#'
solver.fit = function(order = NULL,
	fam=c("binomial", "probit","cloglog", "exponential", "gamma", "poisson"),
	scale.param = NULL )
{

    bigsol = NULL
    print('C++ Code Execution')
    
    ##  parameters check 
    if(is.null(order))
    {
        order<- 1
    }
    if(is.null(scale.param))
    {
        scale.param<- 0.5
    }
  
    storage.mode(order) <-"integer"
    storage.mode(scale.param) <- "double"
    storage.mode(fam) <- "character"

    ## Call C++ function
    bigsol <- .Call("solver_fit", order, fam, scale.param, PACKAGE = "MyPKG")

    return(bigsol)

  }
