#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP solver_fit(SEXP, SEXP, SEXP);


static const R_CallMethodDef CallEntries[] = {
    {"solver_fit",                      (DL_FUNC) &solver_fit,                       3},
    {NULL, NULL, 0}
};

void R_init_fdaPDE(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
