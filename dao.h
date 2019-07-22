#ifndef DAO_H
#define DAO_H

#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"

void InserirRegistroFinanceiroAoProfile(PROFILE*,NO_REGISTRO*,int);
NO_REGISTRO* BuscarRegistro(PROFILE*,int);
void Remover(PROFILE*,NO_REGISTRO*);

#endif
