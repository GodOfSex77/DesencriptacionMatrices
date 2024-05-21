#include<iostream>

using namespace std;

int MatrizTraspuesta(int matriz2[], int Iteracion[2], int size){
	int iterador = 0;
	
	int Matriz[3][size / 3];
	
	for(int i = 0; i < 3; i++){
		iterador = i;
		for(int j = 0; j < size / 3; j++){
			Matriz[i][j] = matriz2[iterador];
			iterador += 3;
		}
	}
	
	return Matriz[Iteracion[0]][Iteracion[1]];
}

int MatrizTraspuesta1(int llave[][3])
{
	int n1 = llave[0][0], n2 = llave[0][1], n3 = llave[0][2];
	int n4 = llave[1][0], n5 = llave[1][1], n6 = llave[1][2]; 
	int n7 = llave[2][0], n8 = llave[2][1], n9 = llave[2][2];
    llave[0][0] = n1, llave[0][1] = n4, llave[0][2] = n7, llave[1][0] = n2, llave[1][1] = n5, llave[1][2] = n8, llave[2][0] = n3, llave[2][1] = n6, llave[2][2] = n9;

	return llave[3][3];
}

int AdjuntaLlave(int llave[][3], int llave2[][3])
{	
	llave2[0][0]=(llave[1][1]*llave[2][2])-(llave[2][1]*llave[1][2]);
	llave2[0][1]=((llave[1][0]*llave[2][2])-(llave[2][0]*llave[1][2]))*(-1);
	llave2[0][2]=(llave[1][0]*llave[2][1])-(llave[2][0]*llave[1][1]);
	llave2[1][0]=((llave[0][1]*llave[2][2])-(llave[2][1]*llave[0][2]))*(-1);
	llave2[1][1]=(llave[0][0]*llave[2][2])-(llave[2][0]*llave[0][2]);
	llave2[1][2]=((llave[0][0]*llave[2][1])-(llave[2][0]*llave[0][1]))*(-1);
	llave2[2][0]=(llave[0][1]*llave[1][2])-(llave[1][1]*llave[0][2]);
	llave2[2][1]=((llave[0][0]*llave[1][2])-(llave[1][0]*llave[0][2]))*(-1);
	llave2[2][2]=(llave[0][0]*llave[1][1])-(llave[1][0]*llave[0][1]);

	return llave2[3][3];
}

int MatrizLlaveDeterminante(int determinante, int llave[][3], int llaveDet[][3])
{
	
	for(int i=0; i<5; i++) // 5 filas
	{
		for(int j=0; j<3; j++) // 3 columnas
		{
			if(i<3) // usa las 3 filas principales de la matriz llave para organizarla
			{
				llaveDet[i][j]=llave[i][j];
			}
			else
			{
				llaveDet[i][j]=llave[i-8][j-9];
				cout<<llaveDet[i][j]<<", ";
			}
			
		}
	}
int n[3], n1=1, n2=0, n3=1;
for(int i=0; i<5; i++)
{
	cout<<i<<endl;
	n2=i;
	n1=1;
	n3=1;

	for (int s=0; s<3; s++) 
	{
    	n[s] = 0;
	}

	if(i<3)
	for(int j=0; j<3; j++)
	{
			n[j]=llaveDet[n2][j];
			n1*=n[j];
			n2+=1;
			if(j==2)
			{
				cout<<n1<<", ";
			}
	}
	cout<<endl;
	if(i==2)
	{
		break;
	}
}

for(int i=0; i<5; i++)
{
	cout<<i<<"lol"<<endl;
	n2=i;
	n1=1;

	for (int s=0; s<3; s++) 
	{
    	n[i] = 0;
	}

	for(int j=2; j>=0; j--)
	{
			n[j]=llaveDet[i][j]; // el vector de 3 posiciones almacena la
			n1*=n[j];
			i+=1;
			cout<<n1<<", ";
			if(j==0)
			{
			cout<<n1<<", ";
			}
	}
	cout<<endl;
	if(i==2)
	{
		break;
	}
}

	return determinante;
}

int main(){
	
	string mensaje;
	char Abecedario[27] = {'A','B','C','D','E','F','G','H','I','J','K',	'L','M',
	'N','O','P','Q','R','S','T','U','V','W','X','Y','Z','_'};
	int llave[3][3], llave2[3][3], determinante, llaveDet[3][3];
	cout<<"Ingrese la frase encriptada"<<endl;
	cin>> mensaje;
	char Mensaje[mensaje.length()];
	int Matriz[3][mensaje.length() / 3], matriz2[mensaje.length()];
	
	cout<<"Ingrese la matriz llave"<<endl;
	
	int w=mensaje.length();
	for(int i = 0; i < w; i++)
	{
		Mensaje[i] = mensaje[i];
		
		for(int j = 0; j < 27; j++){
			if(Mensaje[i] == Abecedario[j]){
				matriz2[i] = j;
			}
		}
	}

	for(int i=0; i<3; i++)
	{
		for(int s=0; s<3; s++)
		{
			cin>>llave[i][s];
		}
	}

	cout<<endl<<endl;
	cout<<"Matriz encriptada numerica: "<<endl;

	int iteracion[2];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < w / 3; j++){
			iteracion[0] = i;
			iteracion[1] = j;

			Matriz[i][j] = MatrizTraspuesta(matriz2, iteracion, mensaje.length());
            cout<<Matriz[i][j]<<", ";			
		}
        cout<<endl;
        
	}

    cout<<endl<<endl;

	cout<<"Matriz llave: "<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<llave[i][j]<<",";
		}
		cout<<endl;
	}

	cout<<endl<<endl;

	//Determinante
	MatrizLlaveDeterminante(determinante, llave, llaveDet);

	MatrizTraspuesta1(llave);
	cout<<"Matriz Llave Traspuesta: "<<endl;
	for (int i = 0; i < 3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<llave[i][j]<<", ";
		}
		cout<<endl;
	}

	cout<<endl<<endl;

    AdjuntaLlave(llave, llave2);
	cout<<"Matriz llave Adjunta*Traspuesta: "<<endl;
	for (int i = 0; i < 3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<llave2[i][j]<<", ";
		}
		cout<<endl;
	}

	cout<<endl<<endl;

	//Matriz llave adj*tras/D
}