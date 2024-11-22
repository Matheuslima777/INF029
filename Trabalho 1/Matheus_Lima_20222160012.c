
// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Matheus Lima de Jesus
//  email: Matheuxlima77@gmail.com
//  Matrícula:20222160012
//  Semestre:2024.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

//retirar todos os printf() antes da entrega

#include <stdio.h>
#include "Matheus_Lima_20222160012.h" // Substitua pelo seu arquivo de header renomeado
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <wchar.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i; 

  for (i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){ 
    sDia[i] = '\0'; 
  }else {
    dq.valido = 0;
    return dq;
  }  


  int j = i + 1; //anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){ 
    sMes[i] = '\0';  
  }else {
    dq.valido = 0;
    return dq;
  }


  j = j + 1; 
  i = 0;

  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){ 
    sAno[i] = '\0';  
  }else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dq.valido = 1;

  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){
  int datavalida;
  //quebra a string data em strings sDia, sMes, sAno
  DataQuebrada dataQuebrada = quebraData(data);

  if (dataQuebrada.valido == 0) {
      return 0;
  } else if((dataQuebrada.iMes == 2) 
        && (dataQuebrada.iDia == 29) 
        && !(dataQuebrada.iAno % 4 == 0 
          || dataQuebrada.iAno % 400 == 0) 
        && (dataQuebrada.iAno % 100 != 0)) {
          return 0;
  } else if ((dataQuebrada.iMes == 1
        ||dataQuebrada.iMes == 3
        ||dataQuebrada.iMes == 5
        ||dataQuebrada.iMes == 7
        ||dataQuebrada.iMes == 8
        ||dataQuebrada.iMes == 10
        ||dataQuebrada.iMes == 12) 
      && (dataQuebrada.iDia < 1 || dataQuebrada.iDia > 31) ){
        return 0;
  } else if((dataQuebrada.iMes == 4
        ||dataQuebrada.iMes == 6 
        ||dataQuebrada.iMes == 9
        ||dataQuebrada.iMes == 11) 
      && (dataQuebrada.iDia < 1 || dataQuebrada.iDia > 30)){
      return 0;
    } 

  if(dataQuebrada.iMes < 1 || dataQuebrada.iMes > 12 ){
      return 0;
    }
  return 1;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  DataQuebrada dataInicial, dataFinal;
    //calcule os dados e armazene nas tres variaveis a seguir
    DiasMesesAnos dma;
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    dma.qtdAnos = 0;
    dataInicial = quebraData(datainicial);
    dataFinal = quebraData(datafinal);

  int mesesNegativos = 0; //caso a subtracao resulte em um numero negativo
    int anosNegativos = 0; //caso a subtracao resulte em um numero negativo
    int meses_com_31_dias[7] = {1,3,5,7,8,10,12};
  int ano_bissexto_dataInicial = 0;
  int ano_bissexto_dataFinal = 0;
  int i = 0;

    //verifica se os dias ou os meses sao validos
    if((dataInicial.iDia < 1 || dataInicial.iDia > 31)
    ||(dataInicial.iMes < 1 || dataInicial.iMes > 12)){ 
        dma.retorno = 2;
        return dma;
    } else if((dataFinal.iDia < 1 || dataFinal.iDia > 31)
        ||(dataFinal.iMes < 1 || dataFinal.iMes > 12)){
        dma.retorno = 3;
        return dma;
    } else if(!(dataInicial.iAno % 4 == 0 || dataInicial.iAno % 400 == 0) 
        && dataInicial.iDia == 29){
        dma.retorno = 2;
        return dma;
    }else if(dataInicial.iAno%4 == 0 || dataInicial.iAno%400 == 0) {
    ano_bissexto_dataInicial = 1;
  } else if(!(dataFinal.iAno%4 == 0 || dataFinal.iAno%400 == 0)
        && dataFinal.iDia ==29){
            dma.retorno = 3;
            return dma;
    }else if(dataFinal.iAno%4 == 0 || dataFinal.iAno%400 == 0){
    ano_bissexto_dataFinal = 1;
  } 

    //calculo da diferença de dias
    if(dataInicial.iDia < dataFinal.iDia){
        dma.qtdDias = dataFinal.iDia - dataInicial.iDia;
    } else if(dataInicial.iDia == dataFinal.iDia){
        dma.qtdDias = 0;
    } else if(dataInicial.iDia>dataFinal.iDia){
        for(i = 0; i < 8; i++){
            if(dataInicial.iMes == meses_com_31_dias[i]){
                dma.qtdDias = 31 - (dataInicial.iDia - dataFinal.iDia);
                mesesNegativos--;
            }
        }
            if(dataInicial.iMes == 2 
        && (ano_bissexto_dataInicial == 0 && ano_bissexto_dataFinal == 0)){
                dma.qtdDias = 28 - (dataInicial.iDia - dataFinal.iDia);
                mesesNegativos--;
            }
            else if(dataInicial.iMes == 2 
          && (ano_bissexto_dataInicial == 1 || ano_bissexto_dataFinal == 1)){
                dma.qtdDias = 29 - (dataInicial.iDia - dataFinal.iDia);
                mesesNegativos--;
            }
        if(dma.qtdDias == 0){
            dma.qtdDias = 30 - (dataInicial.iDia - dataFinal.iDia);
            mesesNegativos--;
        }
        if(ano_bissexto_dataInicial == 1 && ano_bissexto_dataFinal == 0) dma.qtdDias-=1;
    }

    //calcula diferença de meses
    if(dataInicial.iMes < dataFinal.iMes){
        dma.qtdMeses = dataFinal.iMes - dataInicial.iMes;
    }
    if(dataInicial.iMes == dataFinal.iMes){
        dma.qtdMeses = 0;
    }
    if(dataInicial.iMes>dataFinal.iMes){
        dma.qtdMeses-= 12 - (dataInicial.iMes - dataFinal.iMes);
        dma.qtdAnos-=1;
    }

    //calcula diferença de anos
    if(dataInicial.iAno < dataFinal.iAno){
        dma.qtdAnos = dataFinal.iAno - dataInicial.iAno;
    }
    if(dataInicial.iAno == dataFinal.iAno){
        dma.qtdAnos = 0;
    }
    if(dataInicial.iAno > dataFinal.iAno){
        dma.qtdAnos -= dataInicial.iAno - dataFinal.iAno;
    }

    //verifica se a data final eh maior do que a inicial
    if(dma.qtdDias < 0 
    || dma.qtdMeses < 0 
    || dma.qtdAnos <0){
        dma.retorno = 4;
        return dma; 
    }
    //verifique se a data final nao eh menor que a data inicial

      //calcule a distancia entre as datas
        dma.qtdMeses += mesesNegativos;
      //se tudo der certo
      dma.retorno = 1;
      return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

int q3(char texto[], char c, int isCaseSensitive){
  int qtdOcorrencias = 0;
  char copiaTexto[250]; 
  strcpy(copiaTexto, texto);
  char copiaC = c;

  if (!isCaseSensitive){
    int i = 0;
    for (; copiaTexto[i] != '\0'; i++){ 
      copiaTexto[i] = toupper(copiaTexto[i]);
    }
    copiaC = toupper(c);

    for (int i = 0; copiaTexto[i] != '\0'; i++){ 
      if (copiaC == copiaTexto[i]) {
        qtdOcorrencias++;
      }
    }	
  } else{
    for (int i = 0; texto[i] != '\0'; i++){ 
      if (c == texto[i]) {
        qtdOcorrencias++;
      }
    }	
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char strTexto[], char strBusca[], int posicoes[30]){
    // setlocale(LC_ALL, "");
  // int qtdOcorrencias = 0;

  // wchar_t copia_strTexto[250];
    // wchar_t copia_strBusca[50];

    // mbstowcs(copia_strTexto, strTexto, 250);
    // mbstowcs(copia_strBusca, strBusca, 50);

  // int i, j;
    // // for (i = 0; strTexto[i] != '\0'; i++){
    // //     if (strTexto[j] != -61) {
    // //         copia_strTexto[j] = strTexto[i];
    // //         j++;
    // //     }
    // // }

  // int tam_copia_strTexto = wcslen(copia_strTexto);
  // int tam_copia_strBusca = wcslen(copia_strBusca);

  // 	for (int i = 0; i <= tam_copia_strTexto - tam_copia_strBusca; i++) {
  // 		int j, k;
  // 		// Verificando se a substring de tam_strTexto a partir da posição i é igual a tam_strBusca
  // 		for (j = 0; j < tam_copia_strBusca; j++) {
  // 			if (strTexto[i + j] != strBusca[j]) {
  // 				break; // Se os caracteres não coincidirem, sai do loop interno
  // 			}
  // 		}
  // 		if (j == tam_copia_strBusca) {
  // 			posicoes[qtdOcorrencias * 2] = i+1; // Armazena a posição inicial da palavra
    //         	posicoes[qtdOcorrencias * 2 + 1] = i + 1 + tam_copia_strBusca - 1; // Armazena a posição final da palavra
  // 			qtdOcorrencias++; // Se todos os caracteres de tam_numBusca_S foram encontrados, incrementa qtdOcorrencias
  // 		} 
    // }
  // return qtdOcorrencias;


  int qtdOcorrencias = 0;
  int i, j, k = 0;
  int decrementar = 0;
  int contadorLetras;
  int tamanhoBusca = strlen(strBusca); //guarda o tamanho da string

  char copia_strTexto[250];
    char copia_strBusca[50];

  strncpy(copia_strTexto, strTexto, 250);
    strncpy(copia_strBusca, strBusca, 50);

    for(i = 0; copia_strTexto[i] !='\0'; i++){
        j = 0;
        contadorLetras = 0;

    if(copia_strTexto[i] <- 61){ 
      decrementar--;//decrementa quando encontra -61
        } 
        if(copia_strTexto[i] == copia_strBusca[j]){
            for(j = 1; copia_strBusca[j] != '\0'; j++){
                if(copia_strBusca[j] != copia_strTexto[i + j]){ 
                    contadorLetras++; //incrementa somente se a palavra buscada foi encontrada 
                }
            }
            if(contadorLetras == 0){
                posicoes[k] = i + 1 + decrementar; //posicao inicial da palavra encontrada
                posicoes[k+1] = i + tamanhoBusca + decrementar; //posicao final da palavra encontrada
                k += 2;
                qtdOcorrencias++;
                i += 1;
            }
        }
    }
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){

  //refazer pois nao deve usar string
  // char num_S[6];
    // sprintf(num_S, "%d\n", num);
  // char numInvertido_S[6];

    // int tam = strlen(num_S)-1;
  // int j = tam-1;
  // int i = 0;

    // for (; i < tam; i++){ 
  // 	numInvertido_S[j] = num_S[i];
  // 	j--;
  // }

  // if(i > 0){
  // 	numInvertido_S[i] = '\0';
  // }

  // int numInvertido_I = atoi(numInvertido_S);

  // return numInvertido_I;

    int numInvertido = 0;

    while (num > 0) {
        int digito = num % 10;
        numInvertido = numInvertido * 10 + digito;
        num /= 10;
    }

    return numInvertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){

    int qtdOcorrencias = 0;

    int tamanhoNum1 = 0;
    int tamanhoNum2 = 0;
    int tempNum1 = numerobase;
    int tempNum2 = numerobusca;

    while (tempNum1 > 0) {
        tamanhoNum1++;
        tempNum1 /= 10;
    }
    while (tempNum2 > 0) {
        tamanhoNum2++;
        tempNum2 /= 10;
    }

    int arrayNum1[tamanhoNum1];
    int arrayNum2[tamanhoNum2];

    for (int i = tamanhoNum1 - 1; i >= 0; i--) {
        arrayNum1[i] = numerobase % 10;
        numerobase /= 10;
    }

    for (int i = tamanhoNum2 - 1; i >= 0; i--) {
        arrayNum2[i] = numerobusca % 10;
        numerobusca /= 10;
    }

    for (int i = 0; i < tamanhoNum1 - tamanhoNum2; i++) {
        int j;
        for (j = 0; j < tamanhoNum2; j++) {
            if (arrayNum1[i + j] != arrayNum2[j]) {
                break;
            }
        }
        if (j == tamanhoNum2) {
            qtdOcorrencias++;
        }
    } 
    return qtdOcorrencias;
}