class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int fim = INT_MIN, contador = 0; // inicializa o fim como o menor inteiro possível em C++ e o contador como 0

        // faz a ordenação dos intervalos em ordem crescente pelo término
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // compara os intervalos pelo valor de término
        });

        // percorrer cada intervalo ordenado
        for (const auto& intervalo : intervals) {
            int inicio = intervalo[0], termino = intervalo[1]; // define início e término do intervalo atual
            if (inicio >= fim) { // se o início do intervalo atual não sobrepõe o intervalo anterior
                fim = termino; // atualiza o valor do fim para o término do intervalo atual
            } else {
                contador++; // incrementa o contador se houver sobreposição
            }
        }

        return contador; // retorna o número de intervalos removidos

    }
};
