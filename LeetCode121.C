/*
Problem Definition:
Given an array prices[] of stock prices, where prices[i] is the price on day i.
You can buy once and sell once later.
Objective: Maximize profit (sell price - buy price).
If no profit is possible → return 0.

Key:
Track the lowest price so far (mini) — best day to buy.
For each day, calculate potential profit if sold today.
Update the maximum profit seen so far.

Algorithm Steps:
Initialize:
mini = prices[0]
maxProfit = 0

Loop through each price:
profit = current price - mini
If profit > maxProfit, update maxProfit
If current price < mini, update mini

Return maxProfit
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int mini = prices[0];
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        int profit = prices[i] - mini;
        if (profit > maxProfit)
            maxProfit = profit;
        if (prices[i] < mini)
            mini = prices[i];
    }
    return maxProfit;
}
