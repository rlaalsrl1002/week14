#include <iostream>
#include "queueIntList.h"

void playGame(Queue& player1, Queue& player2, int rounds) {
    int player1Score = 0;
    int player2Score = 0;

    int player1PrevCard = 0;
    int player2PrevCard = 0;

    for (int i = 1; i <= rounds; ++i) {
        int player1Card = player1.showFront();
        player1.dequeue();
        int player2Card = player2.showFront();
        player2.dequeue();

        int player1DuelNumber = (i == 1) ? player1Card : player1Card + (player1Card - player1PrevCard) - 1;
        int player2DuelNumber = (i == 1) ? player2Card : player2Card + (player2Card - player2PrevCard) - 1;

        std::cout << "Round" << i << " - ";
        if (player1DuelNumber > player2DuelNumber) {
            std::cout << "P1 win!\n";
            player1Score++;
        } else if (player1DuelNumber < player2DuelNumber) {
            std::cout << "P2 win!\n";
            player2Score++;
        } else {
            std::cout << "Draw!\n";
        }

        player1PrevCard = player1Card;
        player2PrevCard = player2Card;
    }

    std::cout << "Final - ";
    if (player1Score > player2Score) {
        std::cout << "P1 win!\n";
    } else if (player1Score < player2Score) {
        std::cout << "P2 win!\n";
    } else {
        std::cout << "Draw!\n";
    }
}

int main() {
    int numCards;
    std::cin >> numCards;

    Queue player1, player2;
    int card;

    for (int i = 0; i < numCards; ++i) {
        std::cin >> card;
        player1.enqueue(card);
    }

    for (int i = 0; i < numCards; ++i) {
        std::cin >> card;
        player2.enqueue(card);
    }

    playGame(player1, player2, numCards);

    return 0;
}
