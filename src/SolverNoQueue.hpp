#include "Interface.hpp"

class Solver_NoQueue : public Solver {
public:    
    void Solve() override {
        FILE *fout1 = fopen("../data/task1_1/FailureProbability.txt", "w");
        FILE *fout2 = fopen("../data/task1_1/MathExpectation.txt", "w");
        FILE *fout3 = fopen("../data/task1_1/OperatorsLoadCoeff.txt", "w");

        int operators = 1; // Начальное количество операторов
        double failureProbability = 1; // Начальная вероятность отказа

        while (failureProbability >= 0.01) {
            Result result = calculate(operators);

            fprintf(fout1, "%d %e\n", operators, result.failureProbability);
            fprintf(fout2, "%d %e\n", operators, result.mathExpectationBusyOperators);
            fprintf(fout3, "%d %e\n", operators, result.operatorsLoadCoeff);
            
            failureProbability = result.failureProbability;
            ++operators;
        }

        AMOUNT = operators - 1;

        fclose(fout1);
        fclose(fout2);
        fclose(fout3);
    }

    ~Solver_NoQueue() {}

private:
    Result calculate(int n) {
        vector<double> p(n);
        p[0] = 1;

        double pSum = 1;
        double mSum = 0;
        for (int i = 1; i < n + 1; ++i) {
            p[i] = p[i - 1] * P1_LAMBDA / (i * P1_MU);
            pSum += p[i];
            mSum += i * p[i];
        }

        double p0 = 1 / pSum;
        Result result = {
            .failureProbability = p[n] * p0,
            .mathExpectationBusyOperators = mSum * p0,
            .operatorsLoadCoeff = mSum * p0 / n
        };

        return result;
    }
};