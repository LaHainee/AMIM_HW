#include "Interface.hpp"

class Solver_EndlessQueue : public Solver {
public:
    void Solve() override {
        FILE *fout1 = fopen("../data/task1_3/MathExpectation.txt", "w");
        FILE *fout2 = fopen("../data/task1_3/OperatorsLoadCoeff.txt", "w");
        FILE *fout3 = fopen("../data/task1_3/QueueExistanceProbability.txt", "w");
        FILE *fout4 = fopen("../data/task1_3/MathExpectationQueueLength.txt", "w");

        for (int operators = 1; operators <= AMOUNT; ++operators) {
            CalculateResult result = calculate(operators);
            if (result.valid) {
                fprintf(fout1, "%d %e\n", operators, result.data.mathExpectationBusyOperators);
                fprintf(fout2, "%d %e\n", operators, result.data.operatorsLoadCoeff);
                fprintf(fout3, "%d %e\n", operators, result.data.queueExistanceProbability);
                fprintf(fout4, "%d %e\n", operators, result.data.mathExpectationQueueLength);
            }
        }

        fclose(fout1);
        fclose(fout2);
        fclose(fout3);
        fclose(fout4);
    }

private:
    struct CalculateResult {
        Result data;
        bool valid;
    };

    CalculateResult calculate(int n) {
        CalculateResult result;
        vector<double> p(n);
        p[0] = 1;

        double pSum = 1;
        double mSum = 0;
        double noQueueSum = 1; // вероятность без очереди
        for (int i = 1; i < n + 1; ++i) {
            p[i] = p[i - 1] * P1_LAMBDA / (i * P1_MU);
            pSum += p[i];
            noQueueSum += p[i];
            mSum += i * p[i];
        }

        double a = P1_LAMBDA / (n * P1_MU);
        if (a >= 1) {
            result.valid = false;
            return result;
        }

        double progression = a / (1 - a);
        pSum += p[n] * progression;
        mSum += n * p[n] * progression;
        
        double p0 = 1 / pSum;

        Result data = {
            .mathExpectationBusyOperators = mSum * p0,
            .operatorsLoadCoeff = mSum * p0 / n,
            .queueExistanceProbability = p0 * p[n] * progression,
            .mathExpectationQueueLength = p0 * p[n] * progression / (1 - a)
        };

        result.data = data;
        result.valid = true;
        return result;
    }
};