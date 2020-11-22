#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <conio2.h>
#include <string.h>
#include <locale.h>
#include <time.h>

struct listaVendedores{
	int CodigoVendedor;
	char NomeVendedor[30];
	int QuantidadeDeItensVendidos;
	float TotalDePedidos;
	float TotalDeComissao;
}
vendedor[3];

struct listaProdutos{
	int CodigoProduto;
	char DescricaoProduto[30];
	float PrecoUnitario;
}
produto[15];

void salvarDataNoArquivo(){
	struct tm *data_hora_atual;
	time_t segundos;
	time(&segundos);    
	data_hora_atual = localtime(&segundos);  

	FILE* arquivo = fopen("pedidos.txt", "a");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo vendas.txt.\n");
        getch();
        exit(0);
    }

	fprintf(arquivo, "\n\tData e hora do pedido: %d/", data_hora_atual->tm_mday);
	fprintf(arquivo, "%d/",data_hora_atual->tm_mon+1);
	fprintf(arquivo, "%d",data_hora_atual->tm_year+1900);
	
	fprintf(arquivo, " - %d:",data_hora_atual->tm_hour);   
	fprintf(arquivo, "%d:",data_hora_atual->tm_min);
	fprintf(arquivo, "%2d\n",data_hora_atual->tm_sec);
  
	fclose(arquivo);
}

void carregarVendedores(){
	vendedor[0].CodigoVendedor = 1;
	vendedor[1].CodigoVendedor = 2;
	vendedor[2].CodigoVendedor = 3;
	
	strcpy(vendedor[0].NomeVendedor, "JOSE ANTONIO MATEUS");
	strcpy(vendedor[1].NomeVendedor, "MARIA HELENA");
	strcpy(vendedor[2].NomeVendedor, "MARCIA ANTONIETA");
	
	FILE* arquivo = fopen("vendas.txt", "r");
	if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo vendas.txt.\n");
        getch();
        exit(0);
    }
	int i = 0;
	for(i = 0; i < 3; i++){
		fscanf(arquivo,"%d %f %f\n", &vendedor[i].QuantidadeDeItensVendidos, &vendedor[i].TotalDePedidos, &vendedor[i].TotalDeComissao);
	}

	fclose(arquivo);
}

cadastrarValoresNoArquivo(){
	FILE* arquivo = fopen("vendas.txt", "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo vendas.txt.\n");
        getch();
        exit(0);
    }
	int i = 0;
	for(i = 0; i < 3; i++){
    	fprintf(arquivo, "%d %.2f %.2f\n", vendedor[i].QuantidadeDeItensVendidos, vendedor[i].TotalDePedidos, vendedor[i].TotalDeComissao);
    }
    fclose(arquivo);
}

void carregarProdutos(){
	int i = 0;
	for(i = 0; i < 15; i++){
	 	produto[i].CodigoProduto = i+1;
	}
	strcpy(produto[0].DescricaoProduto, "CADEIRA BRANCA");
	strcpy(produto[1].DescricaoProduto, "CADEIRA PRETA");
	strcpy(produto[2].DescricaoProduto, "MESA DE VIDRO 2x2");
	strcpy(produto[3].DescricaoProduto, "MESA DE VIDRO 2x4");
	strcpy(produto[4].DescricaoProduto, "MESA DE MADEIRA 2x2");
	strcpy(produto[5].DescricaoProduto, "MESA DE MADEIRA 2x4");
	strcpy(produto[6].DescricaoProduto, "GUARDA ROUPAS INFANTIL");
	strcpy(produto[7].DescricaoProduto, "GUARDA ROUPAS CASAL");
	strcpy(produto[8].DescricaoProduto, "CRIADO MUDO");
	strcpy(produto[9].DescricaoProduto, "ARMARIO DE COZINHA");
	strcpy(produto[10].DescricaoProduto, "BALCAO DE COZINHA");
	strcpy(produto[11].DescricaoProduto, "RACK PARA TV");
	strcpy(produto[12].DescricaoProduto, "CAMA DE SOLTEIRO");
	strcpy(produto[13].DescricaoProduto, "CAMA DE CASAL");
	strcpy(produto[14].DescricaoProduto, "SOFA 2 + 3 LUGARES");
	
	produto[0].PrecoUnitario = 25.00;
	produto[1].PrecoUnitario = 28.90;
	produto[2].PrecoUnitario = 390.90;
	produto[3].PrecoUnitario = 490.90;
	produto[4].PrecoUnitario = 259.90;
	produto[5].PrecoUnitario = 359.90;
	produto[6].PrecoUnitario = 450.00;
	produto[7].PrecoUnitario = 699.00;
	produto[8].PrecoUnitario = 125.90;
	produto[9].PrecoUnitario = 109.90;
	produto[10].PrecoUnitario = 256.00;
	produto[11].PrecoUnitario = 189.90;
	produto[12].PrecoUnitario = 220.00;
	produto[13].PrecoUnitario = 399.00;
	produto[14].PrecoUnitario = 799.50;
}

int retornarCampeaoDeVendas(){
	if(vendedor[0].TotalDePedidos > vendedor[1].TotalDePedidos && vendedor[0].TotalDePedidos > vendedor[2].TotalDePedidos){
		return 0;
	} else if(vendedor[1].TotalDePedidos > vendedor[0].TotalDePedidos && vendedor[1].TotalDePedidos > vendedor[2].TotalDePedidos){
		return 1;
	} else{
		return 2;
	}
}

float calcularComissao(int quantidadeItensVendidos){
	if(quantidadeItensVendidos < 10){
		return 0.12;
	} else if(quantidadeItensVendidos >= 11 && quantidadeItensVendidos <= 29){
		return 0.17;
	} else if(quantidadeItensVendidos >= 30 && quantidadeItensVendidos <= 44){
		return 0.22;
	} else{
		return 0.27;
	}
}

void cabecalho(){
	clrscr();
	puts("MÓVEIS DOBOM - FÁBRICA DE MÓVEIS");
}

void exibirListaDeVendedores(){
	int i = 0;
	clrscr();
	cabecalho();
	printf("\nLISTA DE VENDEDORES\n\n");
	printf("Cód Vendedor \t Nome Vendedor\n\n");
	for(i = 0; i < 3; i++){
	printf("%d \t\t %s\n", vendedor[i].CodigoVendedor, vendedor[i].NomeVendedor);
	}
	printf("\n\nAperte qualquer tecla para voltar ao menu principal.\nOu aperte 'ESC' para sair.");
	char opcao = getch();
	switch(opcao){
		case 27:
			exit(0);
			break;
		default:
		menuPrincipal();
		break;
	}
}

void exibirListaDeProdutos(){
	int i = 0;
	clrscr();
	cabecalho();
	printf("\nLISTA DE PRODUTOS\n\n");
	printf("Cód Produto \t Descrição Produto \t\t Preço unitário\n\n");
	for(i = 0; i < 15; i++){
	printf("%-2d \t\t %-22s \t %3.2f\n", produto[i].CodigoProduto, produto[i].DescricaoProduto, produto[i].PrecoUnitario);
	}
	printf("\n\nAperte qualquer tecla para voltar ao menu principal.\nOu aperte 'ESC' para sair.");
	char opcao = getch();
	switch(opcao){
		case 27:
			exit(0);
			break;
		default:
		menuPrincipal();
		break;
	}
}

encerrarPedido(codigoVendedor, y){
	gotoxy(1, y-1);
	printf("                                                                                ");
	
	gotoxy(1, y);
	printf("Total de itens do pedido: %d", vendedor[codigoVendedor].QuantidadeDeItensVendidos);
	
	gotoxy(1, y+2);
	printf("Valor total do pedido: R$%.2f", vendedor[codigoVendedor].TotalDePedidos);
	
	float porcentagemComissao = calcularComissao(vendedor[codigoVendedor].QuantidadeDeItensVendidos);
	vendedor[codigoVendedor].TotalDeComissao = ((1+porcentagemComissao)*vendedor[codigoVendedor].TotalDePedidos);
	
	gotoxy(1, y+4);
	printf("Percentual de comissão: %.2f%%", porcentagemComissao*100);
	
	cadastrarValoresNoArquivo();
	
	gotoxy(1, y+6);
	char continuar;
		printf("\nDeseja digitar um novo pedido (S/N)? ");
		continuar = getche();
		getch();
		switch(continuar){
			case 's':
			case 'S':
				emissaoDePedidos();
				break;
			case 'n':
			case 'N':
				printf("\nPressione qualquer tecla para voltar ao menu, ou pressione 'ESC' para sair.");
				char sair = getch();
				fflush(stdin);
				switch(sair){
					case 27:
						exit(0);
						break;
					default:
						menuPrincipal();
						break;
				}
				break;
		}
}

inserirProduto(int codigoVendedor, int y){
	int codigoProduto = 0;
	gotoxy(1, y);
	scanf("%d", &codigoProduto);
	
	if(codigoProduto == 0){
		encerrarPedido(codigoVendedor, y+1);
	}
	if(codigoProduto > 0 && codigoProduto <= 15){
	gotoxy(11, y);
	printf("%s", produto[codigoProduto-1].DescricaoProduto);

	gotoxy(36, y);
	printf("%.2f", produto[codigoProduto-1].PrecoUnitario);
	
	int quantidadeProduto = 0;
	gotoxy(53, y);
	scanf("%d", &quantidadeProduto);
	vendedor[codigoVendedor].QuantidadeDeItensVendidos += quantidadeProduto;
	
	float valorTotalProduto = quantidadeProduto*produto[codigoProduto-1].PrecoUnitario;
	gotoxy(69, y);
	printf("%.2f", valorTotalProduto);
	vendedor[codigoVendedor].TotalDePedidos += valorTotalProduto;
	
	salvarDataNoArquivo();
	
	FILE* arquivo = fopen("pedidos.txt", "a");
    if(arquivo == NULL) {
        printf("Erro ao abrir o pedidos.txt.\n");
        getch();
		exit(0);
    }

    fprintf(arquivo, "Cod Vendedor | Nome Vendedor       | Cod Prod | Descr Prod             | Preco Unit R$ | Qtd Vendida | Total R$\n");
    fprintf(arquivo, "%-2d           | %-19s | %-9d| %-22s | %-6.2f        | %-2d          | %-4.2f\n", codigoVendedor+1, vendedor[codigoVendedor].NomeVendedor, codigoProduto, produto[codigoProduto-1].DescricaoProduto, produto[codigoProduto-1].PrecoUnitario, quantidadeProduto, valorTotalProduto);
    fclose(arquivo);

	} else{
		printf("Opção inválida. Pressione qualquer tecla para tentar novamente.");
		getch();
		gotoxy(1, y);
		printf("\t\t\t\t\t\t\t\t");
		gotoxy(1, y+1);
		printf("\t\t\t\t\t\t\t\t");
		inserirProduto(codigoVendedor, y);
	}
}

void emissaoDePedidos(){
	clrscr();
	cabecalho();
	printf("\nEMISSÃO DE PEDIDOS\n\n");
	
	printf("\n\nCÓDIGO DO VENDEDOR: ");
	int codigoVendedor = 0;
	scanf("%d", &codigoVendedor);
	if(codigoVendedor < 0 || codigoVendedor > 3){
		gotoxy(1, 7);
		printf("Opção inválida. Pressione qualquer tecla para tentar novamente.");
		getch();
		emissaoDePedidos();
	} else{
		gotoxy(22, 7);
		printf(" - %s", vendedor[codigoVendedor-1].NomeVendedor);
	}
	printf("\n\nCod Prod  Descr Prod               Preco Unit R$    Qtd Vendida     Total R$\n\n");
	int y = 11;
	
	while(1){
		inserirProduto(codigoVendedor-1, y);
		y+=2;
	}
}

totalizacaoDePedidos(){
	clrscr();
	cabecalho();
	printf("\nEMISSÃO DE PEDIDOS\n\n");
	
	printf("TOTAIS POR VENDEDOR:\n\n");
	printf("\t\t\tQtd de itens    Total dos Pedidos     Total Comissão\n\n");
	int i = 0;
	int quantidadeDeVendasTotal = 0;
	float valorDePedidosTotal = 0;
	float comissaoTotal = 0;
	for(i = 0; i < 3; i++){
	printf("%d %-20s \t%d \t\tR$%-16.2f    R$%.2f\n\n", vendedor[i].CodigoVendedor, vendedor[i].NomeVendedor, vendedor[i].QuantidadeDeItensVendidos, vendedor[i].TotalDePedidos, vendedor[i].TotalDeComissao);
	quantidadeDeVendasTotal += vendedor[i].QuantidadeDeItensVendidos;
	valorDePedidosTotal += vendedor[i].TotalDePedidos;
	comissaoTotal += vendedor[i].TotalDeComissao;
	}
	printf("TOTAIS DA FÁBRICA \t%d \t\tR$%-16.2f    R$%.2f\n\n\n\n", quantidadeDeVendasTotal, valorDePedidosTotal, comissaoTotal);
	printf("CAMPEÃO DE VENDAS\n\n");
	
	int campeaoDeVendas = retornarCampeaoDeVendas();
	
	printf("VENDEDOR: %d %s\n\n", vendedor[campeaoDeVendas].CodigoVendedor, vendedor[campeaoDeVendas].NomeVendedor);
	
	printf("VALOR DA COMISSÃO COM BONUS: R$%.2f", vendedor[campeaoDeVendas].TotalDeComissao+1200);
	
	printf("\n\nAperte qualquer tecla para voltar ao menu principal.\nOu aperte 'ESC' para sair.");
	char opcao = getch();
	switch(opcao){
		case 27:
			exit(0);
			break;
		default:
		menuPrincipal();
		break;
	}
}

exibirLogDePedidos(){
	clrscr();
	cabecalho();
	printf("\nLOG DE PEDIDOS\n\n");
	char info[200];
	FILE* arquivo = fopen("pedidos.txt", "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo vendas.txt.\n");
        getch();
        exit(0);
    }

	while((fgets(info, sizeof(info), arquivo))!=NULL )
   		printf("%s", info);
  
	fclose(arquivo);
}

void menuPrincipal(){
	clrscr();
	cabecalho();
	system("color 07");
	puts("MENU PRINCIPAL");
	puts("--------------");
	puts("Selecione uma opção:");
	puts("1 - EMISSÃO DE PEDIDOS");
	puts("2 - TOTALIZAÇÃO DE PEDIDOS");
	puts("3 - EXIBIR LISTA DE PRODUTOS");
	puts("4 - EXIBIR LISTA DE VENDEDORES");
	puts("5 - EXIBIR LOG DE PEDIDOS");
	puts("Q - SAIR");
	
	printf("\nOpção: ");
	char opcao;
	scanf("%c", &opcao);
	switch(opcao){
		case '1':
			emissaoDePedidos();
			break;
		case '2':
			totalizacaoDePedidos();
			break;
		case '3':
			exibirListaDeProdutos();
			break;
		case '4':
			exibirListaDeVendedores();
			break;
		case '5':
			exibirLogDePedidos();
			break;
		case 'q':
		case 'Q':
			exit(0);
			break;
		default:
			printf("\nOpção inválida. Aperte qualquer tecla para tentar novamente.");
			getch();
			fflush(stdin);
			menuPrincipal();
			break;
	}
}

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	carregarVendedores();
	carregarProdutos();
	menuPrincipal();
	return 0;
}
