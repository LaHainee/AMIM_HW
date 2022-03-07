#include "Interface.hpp"

class Solver_LeaveQueue : public Solver {
public:
    void Solve() {
        FILE *fout1 = fopen("../data/task1_4/MathExpectation.txt", "w");
        FILE *fout2 = fopen("../data/task1_4/OperatorsLoadCoeff.txt", "w");
        FILE *fout3 = fopen("../data/task1_4/QueueExistanceProbability.txt", "w");
        FILE *fout4 = fopen("../data/task1_4/MathExpectationQueueLength.txt", "w");
    
        for (int operators = 1; operators <= AMOUNT; ++operators) {
            Result result = calculate(operators);

            fprintf(fout1, "%d %e\n", operators, result.mathExpectationBusyOperators);
            fprintf(fout2, "%d %e\n", operators, result.operatorsLoadCoeff);
            fprintf(fout3, "%d %e\n", operators, result.queueExistanceProbability);
            fprintf(fout4, "%d %e\n", operators, result.mathExpectationQueueLength);
        }


        fclose(fout1);
        fclose(fout2);
        fclose(fout3);
        fclose(fout4);  
    }

private:
    Result calculate(int n) {
        vector<double> pTemp(n);
        
        pTemp[0] = 1;
        for (int i = 1; i < n + 1; ++i) {
            pTemp[i] = pTemp[i - 1] * P1_LAMBDA / (i * P1_MU);
        }

        int q = 1;
        double pPrev = pTemp[n];
        double pCurr = pTemp[n] * P1_LAMBDA / (n * P1_MU + P1_NU);
        while (pCurr - pPrev) {
            ++q;
            pPrev = pCurr;
            pCurr = pPrev * P1_LAMBDA / (n * P1_MU + q * P1_NU);
        }

        vector<double> p(n + q);
        p[0] = 1;
        
        double pSum = 1;
        double mSum =0;
        double noQueueSum = 1;
        double queueLengthSum = 1;
        for (int i = 1; i < n + 1; ++i) {
            p[i] = p[i - 1] * P1_LAMBDA / (i * P1_MU);
            pSum += p[i];
            noQueueSum += p[i];
            mSum += i * p[i];
        }
        for (int i = n + 1; i < n + q + 1; ++i) {
            p[i] = p[i - 1] * P1_LAMBDA / (n * P1_MU + (i - n) * P1_NU);
            pSum += p[i];
            mSum += n * p[i];
            queueLengthSum += (i - n) * p[i];
        }

        double p0 = 1 / pSum;
        Result result = {
            .mathExpectationBusyOperators = mSum * p0,
            .operatorsLoadCoeff = mSum * p0 / n,
            .queueExistanceProbability = 1 - noQueueSum * p0,
            .mathExpectationQueueLength = queueLengthSum * p0
        };

        return result;
    }
};