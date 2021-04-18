#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int compara(const void *e1, const void *e2)
{
	return strncmp(((Endereco *)e1)->cep, ((Endereco *)e2)->cep, 8);
}

int main(int argc, char **argv)
{
	FILE *f, *saida;
	Endereco *e;
	long posicao, qtd, oitavo1;

	/*--------- inicio divisao do primeiro oitavo ---------*/

	f = fopen("cep.dat", "r");
	fseek(f, 0, SEEK_END);
	posicao = ftell(f);
	qtd = posicao / sizeof(Endereco);
	oitavo1 = qtd / 8;
	e = (Endereco *)malloc(oitavo1 * sizeof(Endereco)); // aloca o primeira oitavo do arquivo na memoria
	rewind(f);
	printf("---Primeiro Oitavo---\n");
	if (fread(e, sizeof(Endereco), oitavo1, f) == oitavo1)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo1, sizeof(Endereco), compara);
	printf("Ordenado o primeiro oitavo = OK\n");
	saida = fopen("cep_a.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo1, saida);
	fclose(saida);
	printf("Escrito o primeiro oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do primeiro oitavo ---------*/

	/*--------- inicio divisao do segundo oitavo ---------*/

	long oitavo2, qtd2;
	qtd2 = qtd - oitavo1;
	oitavo2 = qtd2 / 7;

	printf("---Segundo Oitavo---\n");
	e = (Endereco *)malloc((oitavo2 * sizeof(Endereco)));
	if (fread(e, sizeof(Endereco), oitavo2, f) == oitavo2)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo2, sizeof(Endereco), compara);
	printf("Ordenado o segundo oitavo = OK\n");
	saida = fopen("cep_b.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo2, saida);
	fclose(saida);
	printf("Escrito o segundo oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do segundo oitavo ---------*/

	/*--------- inicio divisao do terceiro oitavo ---------*/

	long oitavo3, qtd3;
	qtd3 = qtd2 - oitavo2;
	oitavo3 = qtd3 / 6;
	printf("---Terceiro Oitavo---\n");
	e = (Endereco *)malloc((oitavo3 * sizeof(Endereco)));
	if (fread(e, sizeof(Endereco), oitavo3, f) == oitavo3)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo3, sizeof(Endereco), compara);
	printf("Ordenado o terceiro oitavo = OK\n");
	saida = fopen("cep_c.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo3, saida);
	fclose(saida);
	printf("Escrito o terceiro oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do terceiro oitavo ---------*/

	/*--------- inicio divisao do quarto oitavo ---------*/

	long oitavo4, qtd4;
	qtd4 = qtd3 - oitavo3;
	oitavo4 = qtd4 / 5;
	printf("---Quarto Oitavo---\n");
	e = (Endereco *)malloc((oitavo4 * sizeof(Endereco)));
	if (fread(e, sizeof(Endereco), oitavo4, f) == oitavo4)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo4, sizeof(Endereco), compara);
	printf("Ordenado o quarto oitavo = OK\n");
	saida = fopen("cep_d.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo4, saida);
	fclose(saida);
	printf("Escrito o quarto oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do quarto oitavo ---------*/

	/*--------- inicio divisao do quinto oitavo ---------*/

	long oitavo5, qtd5;
	qtd5 = qtd4 - oitavo4;
	oitavo5 = qtd5 / 4;
	printf("---Quinto Oitavo---\n");
	e = (Endereco *)malloc((oitavo5 * sizeof(Endereco)));
	if (fread(e, sizeof(Endereco), oitavo5, f) == oitavo5)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo5, sizeof(Endereco), compara);
	printf("Ordenado o quinto oitavo = OK\n");
	saida = fopen("cep_e.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo5, saida);
	fclose(saida);
	printf("Escrito o quinto oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do quinto oitavo ---------*/

	/*--------- inicio divisao do sexto oitavo ---------*/

	long oitavo6, qtd6;
	qtd6 = qtd5 - oitavo5;
	oitavo6 = qtd6 / 3;
	printf("---Sexto Oitavo---\n");
	e = (Endereco *)malloc((oitavo6 * sizeof(Endereco)));
	if (fread(e, sizeof(Endereco), oitavo6, f) == oitavo6)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo6, sizeof(Endereco), compara);
	printf("Ordenado o sexto oitavo = OK\n");
	saida = fopen("cep_f.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo6, saida);
	fclose(saida);
	printf("Escrito o sexto oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do sexto oitavo ---------*/

	/*--------- inicio divisao do sétimo oitavo ---------*/

	long oitavo7, qtd7;
	qtd7 = qtd6 - oitavo6;
	oitavo7 = qtd7 / 2;
	printf("---Sétimo Oitavo---\n");
	e = (Endereco *)malloc((oitavo7 * sizeof(Endereco)));
	if (fread(e, sizeof(Endereco), oitavo7, f) == oitavo7)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo7, sizeof(Endereco), compara);
	printf("Ordenado o sétimo oitavo = OK\n");
	saida = fopen("cep_g.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo7, saida);
	fclose(saida);
	printf("Escrito o sétimo oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do sétimo oitavo ---------*/

	/*--------- inicio divisao do oitavo oitavo ---------*/

	long oitavo8, qtd8;
	qtd8 = qtd7 - oitavo7;
	oitavo8 = qtd8 / 2;
	printf("---Oitavo Oitavo---\n");
	e = (Endereco *)malloc((oitavo8 * sizeof(Endereco)));
	if (fread(e, sizeof(Endereco), oitavo8, f) == oitavo8)
	{
		printf("Lido = OK\n");
	}
	qsort(e, oitavo8, sizeof(Endereco), compara);
	printf("Ordenado o oitavo oitavo = OK\n");
	saida = fopen("cep_h.dat", "w");
	fwrite(e, sizeof(Endereco), oitavo8, saida);
	fclose(saida);
	printf("Escrito o oitavo oitavo = OK\n");
	free(e);

	/*---------fim divisao e escrita do oitavo oitavo ---------*/

	fclose(f);
	return 0;
}
