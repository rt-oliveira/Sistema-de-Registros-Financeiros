#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

void CriarArquivoDeProfile();
void LerRegistroDoArquivo(NO_REGISTRO*,FILE*);
void EscreverRegistrosNoArquivo(PROFILE*);

#endif
