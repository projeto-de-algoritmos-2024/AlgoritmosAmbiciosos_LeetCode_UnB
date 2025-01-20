class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Criar vetor dp com valor máximo + 1 como valor inicial
        vector<int> dp(amount + 1, amount + 1);
        
        // Caso base: para formar valor 0, precisamos de 0 moedas
        dp[0] = 0;
        
        // Para cada valor de 1 até amount
        for (int i = 1; i <= amount; i++) {
            // Para cada moeda disponível
            for (int coin : coins) {
                // Se a moeda atual for menor ou igual ao valor que queremos formar
                if (coin <= i) {
                    // Atualizamos dp[i] com o mínimo entre o valor atual
                    // e 1 + dp[i - coin]
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        // Se dp[amount] continuar com valor inicial, significa que não é possível
        // formar o valor, então retornamos -1
        return dp[amount] > amount ? -1 : dp[amount];
    }
};