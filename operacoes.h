#ifndef OPERACOES_H
#define OPERACOES_H

#include <stdio.h>
#include <stdlib.h>
#include "userIO.h"
#include "fileIO.h"
#include "dao.h"

void ListarRegistros(PROFILE*);
void AdicionarRegistro(PROFILE*,int*);
void EditarRegistro(PROFILE*);
void RemoverRegistro(PROFILE*);
void Sair(PROFILE*);

#endif
