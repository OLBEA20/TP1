#include<stdio.h>
#include<stdlib.h>
struct pgcdReturn{
	int nbOfIteration;
	int pgcd;
};

void pgcdFB(int m, int n,pgcdReturn *pgcdR){
	int nbOfIteration = 1;

	if(n == 0){
		pgcdR->nbOfIteration = nbOfIteration;
		pgcdR->pgcd = m;
		return;
	}
	else {
		int t = n;
		while(m%t != 0 || n%t != 0){
			t = t-1;
			nbOfIteration++;
		}
		pgcdR->nbOfIteration = nbOfIteration;
		pgcdR->pgcd = t;
		return;	

	}
}

void Euclide(int m, int n, pgcdReturn *pgcdR){
	int nbOfIteration = 1;
	
	int r = 0;
	while(n > 0){
		r = m%n;
		m = n;
		n = r;
		nbOfIteration++;
	}

	pgcdR->nbOfIteration = nbOfIteration;
	pgcdR->pgcd = m;
	return;
}

int FibNonRec(int n){
	if(n == 0){
		return 0;
	}

	int u = 0;
	int v = 1;

	for(int i = 2; i <= n; i++){
		v = v + u;
		u = v - u;
	}
	
	return v;
}

int main(int arg, char *argc[]){
	printf("HelloWorld!\n");
	
	pgcdReturn *pgcdR;
	pgcdR = (pgcdReturn*)malloc(sizeof(pgcdReturn));

	pgcdReturn *pgcdR2;
	pgcdR2 = (pgcdReturn*)malloc(sizeof(pgcdReturn));

	printf("|i--F(i+1)--F(i)--PGCD--pgcdFB--Euclide|\n");

	for(int i = 0; i < 40; i++){
		int fiboPlusUn = FibNonRec(i + 1);
		int fibo = FibNonRec(i);
		
		pgcdFB(fiboPlusUn, fibo, pgcdR);
		Euclide(fiboPlusUn, fibo, pgcdR2);

		printf("%i   %i       %i       %i       %i       %i\n", 
				i + 1, 
				fiboPlusUn, 
				fibo,
				pgcdR->pgcd,
				pgcdR->nbOfIteration,
				pgcdR2->nbOfIteration);
	}
}


