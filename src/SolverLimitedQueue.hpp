#include "Interface.hpp"

class Solver_LimitedQueue : public Solver {
public:    
    void Solve() override {
        FILE *fout1 = fopen("../data/task1_2/FailureProbability.txt", "w");
        FILE *fout2 = fopen("../data/task1_2/MathExpectation.txt", "w");
        FILE *fout3 = fopen("../data/task1_2/OperatorsLoadCoeff.txt", "w");
        FILE *fout4 = fopen("../data/task1_2/QueueExistanceProbability.txt", "w");
        FILE *fout5 = fopen("../data/task1_2/MathExpectationQueueLength.txt", "w");
        FILE *fout6 = fopen("../data/task1_2/QueueLoadCoeff.txt", "w");

        int part = 1;
        for (int operators = 1; operators <= AMOUNT; ++operators) {
            for (int queueSize = 1; queueSize <= AMOUNT; ++queueSize) {
                Result result = calculate(operators, queueSize);
                fprintf(fout1, "%d %d %d %e\n", part, operators, queueSize, result.failureProbability);
                fprintf(fout2, "%d %d %d %e\n", part, operators, queueSize, result.mathExpectationBusyOperators);
                fprintf(fout3, "%d %d %d %e\n", part, operators, queueSize, result.operatorsLoadCoeff);
                fprintf(fout4, "%d %d %d %e\n", part, operators, queueSize, result.queueExistanceProbability);
                fprintf(fout5, "%d %d %d %e\n", part, operators, queueSize, result.mathExpectationQueueLength);
                fprintf(fout6, "%d %d %d %e\n", part, operators, queueSize, result.queueLoadCoeff);
            }
        }

        part = 2;
        for (int queueSize = 1; queueSize <= AMOUNT; ++queueSize) {
            for (int operators = 1; operators <= AMOUNT; ++operators) {
                Result result = calculate(operators, queueSize);
                fprintf(fout1, "%d %d %d %e\n", part, operators, queueSize, result.failureProbability);
                fprintf(fout2, "%d %d %d %e\n", part, operators, queueSize, result.mathExpectationBusyOperators);
                fprintf(fout3, "%d %d %d %e\n", part, operators, queueSize, result.operatorsLoadCoeff);
                fprintf(fout4, "%d %d %d %e\n", part, operators, queueSize, result.queueExistanceProbability);
                fprintf(fout5, "%d %d %d %e\n", part, operators, queueSize, result.mathExpectationQueueLength);
                fprintf(fout6, "%d %d %d %e\n", part, operators, queueSize, result.queueLoadCoeff);
            }
        }

        fclose(fout1);
        fclose(fout2);
        fclose(fout3);
        fclose(fout4);
        fclose(fout5);
        fclose(fout6);
    }

private:
    Result calculate(int n, int q) {
        vector<double> p(n + q);
        p[0] = 1;

        double pSum = 1;
        double mSum = 0;
        double noQueueSum = 1; // вероятность без очереди
        double queueLengthSum = 1; // математическое ожидание длины очереди
        for (int i = 1; i < n + 1; ++i) {
            p[i] = p[i - 1] * P1_LAMBDA / (i * P1_MU);
            pSum += p[i];
            mSum += i * p[i];
            noQueueSum += p[i];
        }
        for (int i = n + 1; i < n + q + 1; ++i) {
            p[i] = p[i - 1] * P1_LAMBDA / (n * P1_MU);
            pSum += p[i];
            mSum += n * p[i];
            queueLengthSum += (i - n) * p[i];
        }

        double p0 = 1 / pSum;

        Result result = {
            .failureProbability = p[n + q] * p0,
            .mathExpectationBusyOperators = mSum * p0,
            .operatorsLoadCoeff = mSum * p0 / n,
            .queueExistanceProbability = 1 - noQueueSum * p0,
            .mathExpectationQueueLength = queueLengthSum * p0,
            .queueLoadCoeff = queueLengthSum * p0 / q
        };

        return result;
    }
};