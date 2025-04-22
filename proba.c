#include <stdio.h>

double fatorial(int x){

    double valor = 1;

    for (int i = x; i > 1; i--)
    {
        valor *= i;       
    }
    return valor;
}

double combinacao(int n ,int x){
    double resultado;

    resultado = (fatorial(n)/(fatorial(n-x)*fatorial(x)));

    return resultado;
}

double potencia(double x, int p) {
    double resultado = 1.0;

    for (int i = 0; i < p; i++) {
        resultado *= x;
    }
    return resultado;
}

double distribuicaoBinomial(int n, int x, double por1, double por2){
    double resultado;

    resultado = combinacao(n, x) * potencia(por1, x) * potencia(por2, (n - x));

    return resultado;
}

double distribuicaoBinomialAcumulada(int n, int p, int tipo, double por1, double por2){
    double resultado = 0;

    if (tipo == 1)
    {
        for (int i = p; i <= n; i++)
    {
        double valor = distribuicaoBinomial(n,i,por1,por2);
        resultado += valor;
        printf("%.4lf\n",valor);
    }
    }else{
        for (int i = p; i >= 0; i--)
    {
        double valor = distribuicaoBinomial(n,i,por1,por2);
        resultado += valor;
        printf("%.4lf\n",valor);
    }
    }
    return resultado;
}


int main(){
    
    int x,n,escolha1 = 0, tipo, escolha = 1;
    double por1, por2;

    while (1)
    {
        printf("Escolha o tipo de distribuição binomial digite os seguintes valores:\n");
        printf("1 para distribuição binomial indivual ou 2 para distribuição binomial acumulada\n");
        printf("Caso não queria utilizar o programa digite 0\n");
        scanf("%d", &escolha1);

        if (escolha1 == 1)
        {
            escolha = 1;
            while (escolha)
            {
                printf("Digite o valor de n: \n");
                scanf("%d",&n);

                printf("Digite o valor de x: \n");
                scanf("%d",&x);
            
                printf("Digite a porcentagem de sucesso(ex: 80 para 80%%): \n");
                scanf("%lf",&por1);

                por1 = por1/100;

                por2 = 1 - por1;

                printf("%.4lf\n",distribuicaoBinomial(n,x,por1,por2));

                printf("Se deseja encerrar o calculo de distribuição binomial invidual digite 0\nCaso queria realizar outra conta digite 1.\n");
                scanf("%d", &escolha);

            }
        }else if (escolha1 == 2)
        {
            escolha = 1;
            while (escolha)
            {
                printf("Digite o valo de n: \n");
                scanf("%d",&n);

                printf("Digite o valor de P(x)\n");
                scanf("%d", &x);
            
                printf("Digite a porcentagem de sucesso: \n");
                scanf("%lf",&por1);

                printf("Digite 1 para crescente(igual e maior que P(x)) ou 2 para descrecente(igual e menor que P(x))\n");
                scanf("%d", &tipo);

                while (escolha)
                {
                    if (tipo == 1 || tipo == 2)
                    {
                        por1 = por1 / 100;
                        por2 = 1 - por1;

                        printf("%.4lf\n",distribuicaoBinomialAcumulada(n,x,tipo,por1,por2));

                        printf("Se deseja encerrar o calculo de distribuição binomial acumulada digite 0\nCaso queria realizar outra conta digite 1.\n");
                        scanf("%d", &escolha);

                        if (escolha == 1)
                        {
                            break;
                        }
                        
                        
                    }else if (escolha == 1)
                    {
                        printf("\nDigite um valor válido no tipo de distribuição!!\n");
                        continue;
                    }
                    else
                    {
                        break;
                    }
                    
                }
            }
        }else if (escolha1 == 0)
        {
            printf("Programa finalizado");
            break;
        }else
        {
            printf("Digite um valor válido!!!");
            continue;
        }
        
    }

    return 0;
}

