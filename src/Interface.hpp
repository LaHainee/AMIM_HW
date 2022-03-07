#ifndef SOLVER_H
#define SOLVER_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <vector>

#include "constants.hpp"

using namespace std;

struct Result {
    double failureProbability;           // Вероятность отказа
    double mathExpectationBusyOperators; // Математическое ожидание занятых операторов
    double operatorsLoadCoeff;           // Коэффициент загрузки операторов
    double queueExistanceProbability;    // Вероятность существования очереди
    double mathExpectationQueueLength;   // Математическое ожидание длины очереди
    double queueLoadCoeff;               // Коэффициент занятости мест в очереди
};

class Solver {
public:
    virtual void Solve() = 0;

    virtual ~Solver() {};
};

#endif