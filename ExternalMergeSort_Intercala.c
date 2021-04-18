#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	FILE *a, *b, *c, *d, *e, *f, *g, *h;	 // variaveis de divisao do arquivo
	FILE *saida1, *saida2, *saida3, *saida4; // saidas dois a dois
	Endereco ea, eb, ec, ed, ee, ef, eg, eh;

	a = fopen("cep_a.dat", "r");
	b = fopen("cep_b.dat", "r");
	c = fopen("cep_c.dat", "r");
	d = fopen("cep_d.dat", "r");
	e = fopen("cep_e.dat", "r");
	f = fopen("cep_f.dat", "r");
	g = fopen("cep_g.dat", "r");
	h = fopen("cep_h.dat", "r");

	saida1 = fopen("saida1.dat", "w");
	saida2 = fopen("saida2.dat", "w");
	saida3 = fopen("saida3.dat", "w");
	saida4 = fopen("saida4.dat", "w");

	fread(&ea, sizeof(Endereco), 1, a);
	fread(&eb, sizeof(Endereco), 1, b);
	fread(&ec, sizeof(Endereco), 1, c);
	fread(&ed, sizeof(Endereco), 1, d);
	fread(&ee, sizeof(Endereco), 1, e);
	fread(&ef, sizeof(Endereco), 1, f);
	fread(&eg, sizeof(Endereco), 1, g);
	fread(&eh, sizeof(Endereco), 1, h);

	/*--------- Inicio intercalacao do primeiro e segundo oitavos ---------*/

	while (!feof(a) && !feof(b))
	{
		if (compara(&ea, &eb) < 0)
		{
			fwrite(&ea, sizeof(Endereco), 1, saida1);
			fread(&ea, sizeof(Endereco), 1, a);
		}
		else
		{
			fwrite(&eb, sizeof(Endereco), 1, saida1);
			fread(&eb, sizeof(Endereco), 1, b);
		}
	}

	while (!feof(a))
	{
		fwrite(&ea, sizeof(Endereco), 1, saida1);
		fread(&ea, sizeof(Endereco), 1, a);
	}
	while (!feof(b))
	{
		fwrite(&eb, sizeof(Endereco), 1, saida1);
		fread(&eb, sizeof(Endereco), 1, b);
	}

	fclose(a);
	fclose(b);
	fclose(saida1);

	/*--------- Fim intercalacao do primeiro e segundo oitavos ---------*/

	/*--------- Inicio intercalacao do terceiro e quarto oitavos ---------*/

	while (!feof(c) && !feof(d))
	{
		if (compara(&ec, &ed) < 0)
		{
			fwrite(&ec, sizeof(Endereco), 1, saida2);
			fread(&ec, sizeof(Endereco), 1, c);
		}
		else
		{
			fwrite(&ed, sizeof(Endereco), 1, saida2);
			fread(&ed, sizeof(Endereco), 1, d);
		}
	}

	while (!feof(c))
	{
		fwrite(&ec, sizeof(Endereco), 1, saida2);
		fread(&ec, sizeof(Endereco), 1, c);
	}
	while (!feof(d))
	{
		fwrite(&ed, sizeof(Endereco), 1, saida2);
		fread(&ed, sizeof(Endereco), 1, d);
	}

	fclose(c);
	fclose(d);
	fclose(saida2);

	/*--------- Fim intercalacao do terceiro e quarto oitavos ---------*/

	/*--------- Inicio intercalacao do quinto e sexto oitavos ---------*/

	while (!feof(e) && !feof(f))
	{
		if (compara(&ee, &ef) < 0)
		{
			fwrite(&ee, sizeof(Endereco), 1, saida3);
			fread(&ee, sizeof(Endereco), 1, e);
		}
		else
		{
			fwrite(&ef, sizeof(Endereco), 1, saida3);
			fread(&ef, sizeof(Endereco), 1, f);
		}
	}

	while (!feof(e))
	{
		fwrite(&ee, sizeof(Endereco), 1, saida3);
		fread(&ee, sizeof(Endereco), 1, e);
	}
	while (!feof(f))
	{
		fwrite(&ef, sizeof(Endereco), 1, saida3);
		fread(&ef, sizeof(Endereco), 1, f);
	}

	fclose(e);
	fclose(f);
	fclose(saida3);

	/*--------- Fim intercalacao do quinto e sexto oitavos ---------*/

	/*--------- Inicio intercalacao do setimo e oitavo oitavos ---------*/

	while (!feof(g) && !feof(h))
	{
		if (compara(&eg, &eh) < 0)
		{
			fwrite(&eg, sizeof(Endereco), 1, saida4);
			fread(&eg, sizeof(Endereco), 1, g);
		}
		else
		{
			fwrite(&eh, sizeof(Endereco), 1, saida4);
			fread(&eh, sizeof(Endereco), 1, h);
		}
	}

	while (!feof(g))
	{
		fwrite(&eg, sizeof(Endereco), 1, saida4);
		fread(&eg, sizeof(Endereco), 1, g);
	}
	while (!feof(h))
	{
		fwrite(&eh, sizeof(Endereco), 1, saida4);
		fread(&eh, sizeof(Endereco), 1, h);
	}

	fclose(g);
	fclose(h);
	fclose(saida4);

	/*--------- Fim intercalacao do setimo e oitavo oitavos ---------*/

	/*--------- Inicio intercalacao das saidas ---------*/

	FILE *saida5, *saida6;
	Endereco esaida1, esaida2, esaida3, esaida4;

	saida1 = fopen("saida1.dat", "r"); // saida1 e saida2 foram abertas outras vez pois fechei no ultimo uso
	saida2 = fopen("saida2.dat", "r");
	saida3 = fopen("saida3.dat", "r");
	saida4 = fopen("saida4.dat", "r");

	// abrindo aquivos para escrita
	saida5 = fopen("saida5.dat", "w");
	saida6 = fopen("saida6.dat", "w");

	fread(&esaida1, sizeof(Endereco), 1, saida1);
	fread(&esaida2, sizeof(Endereco), 1, saida2);
	fread(&esaida3, sizeof(Endereco), 1, saida3);
	fread(&esaida4, sizeof(Endereco), 1, saida4);

	/*--------- Inicio intercalacao da saida1 e saida2 ---------*/

	while (!feof(saida1) && !feof(saida2))
	{
		if (compara(&esaida1, &esaida2) < 0)
		{
			fwrite(&esaida1, sizeof(Endereco), 1, saida5);
			fread(&esaida1, sizeof(Endereco), 1, saida1);
		}
		else
		{
			fwrite(&esaida2, sizeof(Endereco), 1, saida5);
			fread(&esaida2, sizeof(Endereco), 1, saida2);
		}
	}

	while (!feof(saida1))
	{
		fwrite(&esaida1, sizeof(Endereco), 1, saida5);
		fread(&esaida1, sizeof(Endereco), 1, saida1);
	}
	while (!feof(saida2))
	{
		fwrite(&esaida2, sizeof(Endereco), 1, saida5);
		fread(&esaida2, sizeof(Endereco), 1, saida2);
	}

	fclose(saida5);

	/*--------- Fim intercalacao da saida1 e saida2 ---------*/

	/*--------- Inicio intercalacao da saida3 e saida4 ---------*/

	while (!feof(saida3) && !feof(saida4))
	{
		if (compara(&esaida3, &esaida4) < 0)
		{
			fwrite(&esaida3, sizeof(Endereco), 1, saida6);
			fread(&esaida3, sizeof(Endereco), 1, saida3);
		}
		else
		{
			fwrite(&esaida4, sizeof(Endereco), 1, saida6);
			fread(&esaida4, sizeof(Endereco), 1, saida4);
		}
	}

	while (!feof(saida3))
	{
		fwrite(&esaida3, sizeof(Endereco), 1, saida6);
		fread(&esaida3, sizeof(Endereco), 1, saida3);
	}
	while (!feof(saida4))
	{
		fwrite(&esaida4, sizeof(Endereco), 1, saida6);
		fread(&esaida4, sizeof(Endereco), 1, saida4);
	}

	fclose(saida6);

	/*--------- Fim intercalacao da saida3 e saida4 ---------*/

	/*--------- Inicio intercalacao da saida final ---------*/

	FILE *saidaEnd;
	Endereco esaida5, esaida6;

	saida5 = fopen("saida5.dat", "r");
	saida6 = fopen("saida6.dat", "r");

	// abrindo aquivos para escrita
	saidaEnd = fopen("saida.dat", "w");

	fread(&esaida5, sizeof(Endereco), 1, saida5);
	fread(&esaida6, sizeof(Endereco), 1, saida6);

	while (!feof(saida5) && !feof(saida6))
	{
		if (compara(&esaida5, &esaida6) < 0)
		{
			fwrite(&esaida5, sizeof(Endereco), 1, saidaEnd);
			fread(&esaida5, sizeof(Endereco), 1, saida5);
		}
		else
		{
			fwrite(&esaida6, sizeof(Endereco), 1, saidaEnd);
			fread(&esaida6, sizeof(Endereco), 1, saida6);
		}
	}

	while (!feof(saida5))
	{
		fwrite(&esaida5, sizeof(Endereco), 1, saidaEnd);
		fread(&esaida5, sizeof(Endereco), 1, saida5);
	}
	while (!feof(saida6))
	{
		fwrite(&esaida6, sizeof(Endereco), 1, saidaEnd);
		fread(&esaida6, sizeof(Endereco), 1, saida6);
	}

	fclose(saida6);
	fclose(saida5);
	fclose(saidaEnd);
}
