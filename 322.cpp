class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Ordenamos as moedas em ordem decrescente
        sort(coins.begin(), coins.end(), greater<int>());
        
        int totalCoins = 0;
        int remainingAmount = amount;
        
        // Para cada moeda, começando da maior
        for (int coin : coins) {
            // Se a moeda for maior que o valor restante, pula
            if (coin > remainingAmount) continue;
            
            // Calcula quantas vezes podemos usar esta moeda
            int numCoins = remainingAmount / coin;
            totalCoins += numCoins;
            remainingAmount -= numCoins * coin;
            
            // Se já formamos o valor total, retorna
            if (remainingAmount == 0) {
                return totalCoins;
            }
        }
        
        // Se ainda sobrou valor para formar, não é possível
        return remainingAmount > 0 ? -1 : totalCoins;
    }
};