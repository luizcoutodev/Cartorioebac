#include <stdio.h> //biblioteca de comunica�ao 
#include <stdlib.h> //aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto de regi�o
#include <string.h> //biblioteca respons�vel por strings.
#include <windows.h>

int registro() //fun��o respons�vel por cadastrar usu�rios no sistema.
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	char cpf[40];
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Voc� escolheu o registro de nomes\n\n");
	printf("Digite o cpf a ser registrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);
	
	FILE *file; //criou o arquivo obs: FILE em caps � a FUN��O.
	file = fopen(arquivo, "w"); //criou um arquivo com nome do cpf. obs: W - WRITE / A - ATUALIZ / D - DELETE / R - LER
	fprintf(file,"CPF:");
	fprintf(file, cpf);
	fclose(file);
	
	file = fopen(arquivo, "a"); //PULANDO A LINHA E INSERINDO "NOME:" ANTES DO DADO PARA APRENSENTAR MELHOR NA CONSULTA
	fprintf(file,"\nNome:");
	fclose(file);
	
	printf("Digite o nome: "); 
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //inserindo o nome dentro do banco de dados.
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //PULANDO A LINHA E INSERINDO "SOBRENOME" ANTES DO DADO PARA APRENSENTAR MELHOR NA CONSULTA
	fprintf(file,"\nSobrenome:");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //PULANDO A LINHA E INSERINDO "CARGO:" ANTES DO DADO PARA APRENSENTAR MELHOR NA CONSULTA
	fprintf(file,"\nCargo:");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");	
}

int consulta() //Criando a fun��o consulta.
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char dados[200];
	int repeticao=0;
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // LENDO O ARQUIVO COM MESMO NOME DE CPF
	
	if (file == NULL )
	{
		printf("Usu�rio n�o localizado");
	}
	
	while(fgets(dados, 200,file) != NULL)
	{
		if (repeticao==0) //setando para que n�o apare�a a mensagem repetidas vezes.
		{
			printf("\nEssas s�o as informa��es do cpf requisitado:\n");
		}
		repeticao++;
		printf("%s", dados);

	}
	fclose(file);
	printf("\n");
	system("pause");
}

int deletar() //criando a fun��o deletar.
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	char cpf[40];
	int decisao=0;
		
	printf("Digite o CPF a ser deletado:");
	scanf("%s",cpf);
	printf("Tem certeza que deseja deletar %s ?\n",cpf);
	printf("Pressione 1 para Sim e 2 para N�o:");
	scanf("%d", &decisao);
	printf("_________________________________________\n\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //arquivo aberto para leitura antes do switchcase, pois dentro ocorre erro.
	
	switch(decisao)		//criando op��o de escolha caso o usu�rio mude de ideia.
	{	
		case 1:
			if(file == NULL)
			{
				printf("\nN�o foi poss�vel deletar, o usu�rio n�o foi encontrado no sistema.\n");
			} else 
			{
				fclose(file);	//fechando o arquivo antes de deletar, para que n�o ocorra erros de arquivo aberto.
				remove(cpf);
				printf("\nUsu�rio foi deletado com sucesso\n");
			}
		break;
		
		case 2:
			printf("\nRetornando ao menu inicial..\n");
		break;
		
		default:
			printf("\n ERRO: Op��o n�o encontrada\n");
		break;
	}
	system("pause");
	
}
	
	

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	int opcao=0; //definindo vari�vel op��o
	int laco=1; //variavel la�o criada, para o loop do menu.
	char senhaDigitada[30];
	char usuario[30];
	char senha[30];
	char conteudoArquivo[30]; //Senha que est� salva dentro do arquivo txt usu�rio.
	
	printf("### Cart�rio da EBAC ### \n \tBem vindo \n\n");
	printf("Digite seu nome de usu�rio:"); //Verificando se o usu�rio j� encontra-se no sistema.
	scanf("%s", usuario); 
	
	FILE *file; //verificando se o arquivo do usu�rio ja encontra-se criado.
	file = fopen(usuario,"r"); 
	
	if (file == NULL) { //caso n�o esteja criado � aberto o registro de contas.
		fclose(file);
		printf("\n� necess�rio criar uma conta antes que possa prosseguir.");
		system("pause");
		printf("\nDigite o nome de usu�rio desejado (at� 30 caracteres):");
		scanf("%s", usuario);
		
		FILE *file;
		file = fopen(usuario,"w"); //criando arquivo com nome de usu�rio.
		printf("\nDigite a senha desejada:");
		scanf("%s", senhaDigitada);
		fprintf(file, senhaDigitada); // salvando a senha dentro do arquivo do usu�rio.
		fclose(file);
		
		printf("\nConta criada, abra o programa novamente.");
		system ("pause");
		
		
	} else {
	
		printf("\nDigite a senha:");
		scanf ("%s", senha); //FAZER A SENHA COPIAR O CONTEUDO DO TXT E COMPARAR PARA VER SE S�O IGUAIS. 
		
		FILE *file;
		file = fopen(usuario, "r");
		
		while(fgets(conteudoArquivo, 30,file) != NULL){
		}	
		
			
		if (strcmp(senha, conteudoArquivo) == 0){ //comparado para ver se as duas strings s�o iguais, retorna 0 se forem iguais.
			printf("\nLogin com sucesso, acessando sistema..");
			system("pause");
			for(laco=1; laco=1;) //iniciada repeti��o do menu
			{	
				system("cls");
		
				setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
				printf("### Cart�rio da EBAC ### \n \tBem vindo \n\n"); //in�cio menu
				printf ("Escolha a op��o desejada: \n\n");
				printf ("\t 1 - Registrar nomes\n"); 
				printf("\t 2 - Consultar nomes\n");
				printf ("\t 3 - Deletar nomes \n");
				printf ("\t 4 - Sair do sistema \n\n\n"); //fim do menu
	
				printf("Digite a op��o:");
				scanf("%d", &opcao);	//armazenando a escolha do usu�rio.
	
				system("cls");
	
				switch(opcao) //escolha de op��o do usu�rio
				{
					case 1:	
					registro();
					break;
			
					case 2:
					consulta();
					break;
			
					case 3:
					deletar();
					break;
			
					case 4:
					printf("**************************************** \n");
					printf("Obrigado por usar nosso sistema. At� logo! \n");
					printf("****************************************");
					return 0;
					break;
			
					default:
					printf("\n Essa op��o n�o est� dispon�vel. \n");
					system("pause");
					break;
				}
			} 
		} else {
			printf("\nSenha incorreta, encerrando o programa.");
			system("pause");
		
		}
	}
}
