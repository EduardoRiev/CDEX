#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
	int dia, mes, ano;
};

struct {
    char nome[50];
    char telefone[20];
		int idade, codigo;
		struct Data dataNascimento;
} agenda[200];

int main(){
  struct agenda;
  int op, i = 0, alt;
  char pcr[20];
	double qtdContato;
  int codigoContato;
	char apc[50];
  do{
    printf("\nMenu de Opcoes");
    printf("\n1 - Cadastrar ");
    printf("\n2 - Quantidade de Contatos");
    printf("\n3 - Filtrar");
		printf("\n4 - Remover");
    printf("\n5 - Listar");
		printf("\n0 - Sair");
    printf("\n\nDigite sua opcao: ");
    scanf("%d", &op);
    switch(op){
      case 1:
				printf("Informe nome: ");
				scanf("%s", agenda[i].nome);
				printf("Informe telefone: ");
				scanf("%s", agenda[i].telefone);
				printf("Informe idade: ");
				scanf("%d", &agenda[i].idade);
				printf("Informe Nascimento: ");
				scanf("%d/%d/%d", &agenda[i].dataNascimento.dia, &agenda[i].dataNascimento.mes, &agenda[i].dataNascimento.ano);
				i++;
				qtdContato++;
      break;

      case 2:
      printf("\n---------------------------------\n");
      printf("Sua agenda possui: %.f contato(s)", qtdContato);
			printf("\nO percentual ocupado na agenda e: %.2f%%", (qtdContato*100) / 200);
      printf("\n---------------------------------\n");
      break;

      case 3:
      printf("\n1 - Buscar por telefone");
		  printf("\n2 - Buscar por nome");
      printf("\n\nDigite sua opcao: ");
      scanf("%d", &op);
      
      switch(op){
			case 1:
			printf("\nDigite o telefone para achar o contato: ");    
			scanf("%s", pcr);
			for(int i=0;i<qtdContato;i++){
				if(pcr == agenda[i].telefone){
					printf("Nome: %s \nTelefone: %s \nIdade: %d \nNascimento: %d/%d/%d", agenda[i].nome, agenda[i].telefone, agenda[i].idade ,agenda[i].dataNascimento.dia,agenda[i].dataNascimento.mes, agenda[i].dataNascimento.ano); 			
          break;		
					}
          else{
            printf("\nContato não encontrado\n");
            break;
          }
			}			
			break;

			case 2:
			printf("\nDigite o nome para achar o contato: ");
			scanf("%s", apc);
			for(int i=0;i<qtdContato;i++){
					if(apc == agenda[i].nome){
						printf("\nNome: %s \nTelefone: %s \nIdade: %d \nNascimento: %d/%d/%d", agenda[i].nome,agenda[i].telefone, agenda[i].idade, agenda[i].dataNascimento.dia, agenda[i].dataNascimento.mes, agenda[i].dataNascimento.ano); 
            break;
					}
          else{
            printf("Contato não encontrado\n");
            break;
          }
			}
			break;
      } while(op != 0);
      break;

			case 4:
			printf("\nDigite o codigo da conta para remover: ");
      scanf("%i", &codigoContato);
      for(int i = 0; i < qtdContato; i++) {
        if(agenda[i].codigo == codigoContato) {
          break;
        }
      }
        while(i < qtdContato-1) {
          agenda[i] = agenda[i + 1];
        }
        qtdContato--;
			break;

      case 5:
        for(i=0;i < qtdContato;i++){
        printf("\n---------------------------------\n");
				printf("Nome: %s", agenda[i].nome);
				printf("\nTelefone: %s", agenda[i].telefone);
				printf("\nIdade: %d", agenda[i].idade);
				printf("\nNascimento: %d/%d/%d", agenda[i].dataNascimento.dia, agenda[i].dataNascimento.mes, agenda[i].dataNascimento.ano);
				printf("\n---------------------------------\n");
      }
			break;		
    } 
  } while(op != 0);
  return 0;
}
