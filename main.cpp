#include <bits/stdc++.h>
using namespace std;

float distanta_totala;

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < 4; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int tata[], int graf[4][4], ofstream& outputFile)
{
cout << "Muchie, drum\n";
for (int i = 1; i < 4; i++){
cout << tata[i] << " - " << i << " \t" << graf[i][tata[i]] << " \n";
distanta_totala += graf[i][tata[i]];
}
}

void primMST(int graf[4][4], ofstream& outputFile)
{
int tata[4];
int key[4];
bool mstSet[4];
for (int i = 0; i < 4; i++)
key[i] = INT_MAX, mstSet[i] = false;
key[0] = 0;
tata[0] = -1;
for (int count = 0; count < 4 - 1; count++) {
int u = minKey(key, mstSet);
mstSet[u] = true;
for (int v = 0; v < 4; v++)
if (graf[u][v] && mstSet[v] == false && graf[u][v] < key[v])
tata[v] = u, key[v] = graf[u][v];
}
printMST(tata, graf, outputFile);
}

int main()
{
   int graf[4][4] = {  {0, 301, 617, 626},
                       {301, 0, 526, 630},
                       {617, 526, 0, 235},
                       {626, 630, 235, 0}};
                       
	ofstream outputFile("rezultat.txt");
	if (outputFile.is_open()) {
    	primMST(graf, outputFile);
    	cout << "Timpul :" << ((distanta_totala * 10) / 1440) * 36 << " ore." << endl;
    	outputFile << "Distanta totala este: " << distanta_totala <<" km."<< endl;
    	outputFile << "Distanta in mile este: " << distanta_totala*0.621371192<<" mile."<<endl;
    	outputFile << "Costul transportului este " << (distanta_totala * 7.8) / 100 * 1.7 << " lire." << endl;
    	outputFile << "Costul in euro este :"<< ((distanta_totala * 7.8) / 100 * 1.7)*1.15<<" euro."<<endl;
    	outputFile << "Costul in dolari este :"<< ((distanta_totala * 7.8) / 100 * 1.7)*1.23<<" dolari."<<endl;
    	outputFile.close();
    	cout << "Rezultatele au fost exportate in fisierul rezultat.txt." << endl;
	}	
	else {
    cout << "Eroare la deschiderea fisierului." << endl;
	}
	return 0;
}