class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // cria um vetor de pares onde cada par representa o tempo de plantio e crescimento
        vector<pair<int, int>> seeds;
        for (int i = 0; i < plantTime.size(); ++i) {
            seeds.emplace_back(plantTime[i], growTime[i]);
        }

        // ordena o vetor de pares com base no tempo de crescimento em ordem decrescente (adaptado para minimizar o tempo  de conclusão em vez de atrasos em relação a prazos igual no algoritmo do universitário (minimize lateness))
        sort(seeds.begin(), seeds.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second; // comparar pelo segundo elemento (growTime)
        });

        int tempoPlantio = 0; // tempo total de plantio até o momento
        int maxFlorescimento = 0; // dia máximo de florescimento

        // iterar sobre cada semente no vetor ordenado
        for (const auto& seed : seeds) {
            int plantTime = seed.first; // tempo de plantio da semente atual
            int growTime = seed.second; // tempo de crescimento da semente atual

            tempoPlantio += plantTime; // atualiza o tempo total de plantio

            // calcula o dia de florescimento e atualizar o valor máximo
            maxFlorescimento = max(maxFlorescimento, tempoPlantio + growTime);
        }

        return maxFlorescimento; // retorna o dia mais cedo em que todas as flores florescerão
    }
};
