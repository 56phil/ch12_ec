// CH12_EX3.cpp : This file contains the 'main' function.
// Program execution begins and ends there.
// Phil Huffman

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct clown {
    string name;
    int votes;
    double pctOfTotal;
};

int sumVotes(vector<clown>&);
clown winningClown(vector<clown>&);

int main() {
    clown aClown;
    vector<clown>clownCar;
    int totalVotes(0);
    int numberOfClowns(0);

    cout << "Enter number of candidates: ";
    cin >> numberOfClowns;
    cout << endl;

    cout << "Enter candidate's name and the votes "
        << " received by the candidate." << endl;
    while (clownCar.size() < numberOfClowns) {
        cin >> aClown.name >> aClown.votes;
        aClown.pctOfTotal = 0.0;
        clownCar.emplace_back(aClown);
    }

    totalVotes = sumVotes(clownCar);

    cout << setw(13) << left << "Candidate"
        << setw(17) << "Votes Received"
        << setw(18) << "% of Total Votes"
        << endl;

    for(auto c : clownCar) {
        cout << setw(10) << left << c.name
            << setw(11) << right << c.votes
            << setw(18) << fixed << showpoint << right << setprecision(2)
            << c.pctOfTotal
            << endl;
    }

    cout << left << setw(17) << "Total" << totalVotes << endl;

    cout << left << setw(35) << "The Winner of the Election is:"
        << winningClown(clownCar).name
        << endl;
    return 0;
}

int sumVotes(vector<clown>& clownCar) {
    int sum(0);
    for(auto aClown : clownCar) {
        sum += aClown.votes;
    }

    for(auto& aClown : clownCar) {
        aClown.pctOfTotal = 100.0 * (aClown.votes / static_cast<double>(sum));
    }

    return sum;
}

clown winningClown(vector<clown>& clownCar) {
    clown winner(clownCar.front());
    for(auto aClown : clownCar) {
        if (aClown.votes > winner.votes) {
            winner = aClown;
        }
    }
    return winner;
}
