#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuá rios no sistema
{
	// inicio criação de variáveis/string
	char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
    // final criação de variáveis/string
    
    printf("digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se as strig
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das string   
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consultar()
{
   setlocale(LC_ALL, "portuguese");
   char cpf [40];
   char conteudo [200];
   
   printf("Digite o CPF a ser consultado");
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
   {
   	printf("Não foi possivel abrir o arquivo, não localizado! \n");
   }
   
   while(fgets(conteudo, 200, file) !=NULL)
   
   {
   	printf("\nEssa são as informações do usuário: ");
   	printf("%s", conteudo);
   	printf("\n\n");
   }
   
   system("pause");
   
   
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {

	  system("cls");
	
	  setlocale(LC_ALL, "portuguese"); //Definindo linguagem 
	
	  printf("\t###cartório da EBAC###\n\n"); //Inicio do menu 
  	  printf("escolha a opção desejada do menu:\n\n");
	  printf("\t1 - registrar nome\n");
	  printf("\t2 - consultar nomes\n");
	  printf("\t3 - deletar nomes\n\n");
	  printf("\t4 - sair do sistema\n\n");
	  printf("Opcão:"); //Fim do menu

      scanf("%d", &opcao); //armazenando a escolha do usuário
    
      system("cls"); //responsavel por limpar a tela
      
      
      switch(opcao)
      {
      	case 1:
      	registro(); //chamada de funções
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
	    deletar();
		break;
		
		case 4:
	    printf("obrigado por utilizar o sistema!\n");
	    return 0;
	    break;
		
		default:
		printf("essa opção não está disponivel!\n");
		system("pause");
		break;
		
	 } 
  }
}
