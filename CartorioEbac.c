#include <stdio.h> //biblioteca de comunicaçao 
#include <stdlib.h> //alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto de região
#include <string.h> //biblioteca responsável por strings.
#include <windows.h>

int registro() //função responsável por cadastrar usuários no sistema.
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	char cpf[40];
	char arquivo[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Você escolheu o registro de nomes\n\n");
	printf("Digite o cpf a ser registrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);
	
	FILE *file; //criou o arquivo obs: FILE em caps é a FUNÇÃO.
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

int consulta() //Criando a função consulta.
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
		printf("Usuário não localizado");
	}
	
	while(fgets(dados, 200,file) != NULL)
	{
		if (repeticao==0) //setando para que não apareça a mensagem repetidas vezes.
		{
			printf("\nEssas são as informações do cpf requisitado:\n");
		}
		repeticao++;
		printf("%s", dados);

	}
	fclose(file);
	printf("\n");
	system("pause");
}

int deletar() //criando a função deletar.
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	char cpf[40];
	int decisao=0;
		
	printf("Digite o CPF a ser deletado:");
	scanf("%s",cpf);
	printf("Tem certeza que deseja deletar %s ?\n",cpf);
	printf("Pressione 1 para Sim e 2 para Não:");
	scanf("%d", &decisao);
	printf("_________________________________________\n\n");
	
	FILE *file;
	file = fopen(cpf,"r"); //arquivo aberto para leitura antes do switchcase, pois dentro ocorre erro.
	
	switch(decisao)		//criando opção de escolha caso o usuário mude de ideia.
	{	
		case 1:
			if(file == NULL)
			{
				printf("\nNão foi possível deletar, o usuário não foi encontrado no sistema.\n");
			} else 
			{
				fclose(file);	//fechando o arquivo antes de deletar, para que não ocorra erros de arquivo aberto.
				remove(cpf);
				printf("\nUsuário foi deletado com sucesso\n");
			}
		break;
		
		case 2:
			printf("\nRetornando ao menu inicial..\n");
		break;
		
		default:
			printf("\n ERRO: Opção não encontrada\n");
		break;
	}
	system("pause");
	
}
	
	

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	int opcao=0; //definindo variável opção
	int laco=1; //variavel laço criada, para o loop do menu.
	char senhaDigitada[30];
	char usuario[30];
	char senha[30];
	char conteudoArquivo[30]; //Senha que está salva dentro do arquivo txt usuário.
	
	printf("### Cartório da EBAC ### \n \tBem vindo \n\n");
	printf("Digite seu nome de usuário:"); //Verificando se o usuário já encontra-se no sistema.
	scanf("%s", usuario); 
	
	FILE *file; //verificando se o arquivo do usuário ja encontra-se criado.
	file = fopen(usuario,"r"); 
	
	if (file == NULL) { //caso não esteja criado é aberto o registro de contas.
		fclose(file);
		printf("\nÉ necessário criar uma conta antes que possa prosseguir.");
		system("pause");
		printf("\nDigite o nome de usuário desejado (até 30 caracteres):");
		scanf("%s", usuario);
		
		FILE *file;
		file = fopen(usuario,"w"); //criando arquivo com nome de usuário.
		printf("\nDigite a senha desejada:");
		scanf("%s", senhaDigitada);
		fprintf(file, senhaDigitada); // salvando a senha dentro do arquivo do usuário.
		fclose(file);
		
		printf("\nConta criada, abra o programa novamente.");
		system ("pause");
		
		
	} else {
	
		printf("\nDigite a senha:");
		scanf ("%s", senha); //FAZER A SENHA COPIAR O CONTEUDO DO TXT E COMPARAR PARA VER SE SÃO IGUAIS. 
		
		FILE *file;
		file = fopen(usuario, "r");
		
		while(fgets(conteudoArquivo, 30,file) != NULL){
		}	
		
			
		if (strcmp(senha, conteudoArquivo) == 0){ //comparado para ver se as duas strings são iguais, retorna 0 se forem iguais.
			printf("\nLogin com sucesso, acessando sistema..");
			system("pause");
			for(laco=1; laco=1;) //iniciada repetição do menu
			{	
				system("cls");
		
				setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
				printf("### Cartório da EBAC ### \n \tBem vindo \n\n"); //início menu
				printf ("Escolha a opção desejada: \n\n");
				printf ("\t 1 - Registrar nomes\n"); 
				printf("\t 2 - Consultar nomes\n");
				printf ("\t 3 - Deletar nomes \n");
				printf ("\t 4 - Sair do sistema \n\n\n"); //fim do menu
	
				printf("Digite a opção:");
				scanf("%d", &opcao);	//armazenando a escolha do usuário.
	
				system("cls");
	
				switch(opcao) //escolha de opção do usuário
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
					printf("Obrigado por usar nosso sistema. Até logo! \n");
					printf("****************************************");
					return 0;
					break;
			
					default:
					printf("\n Essa opção não está disponível. \n");
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
