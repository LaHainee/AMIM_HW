#include "Interface.hpp"

class Solver_Machines : public Solver {
public:    
    struct MachinesResult {
        double failureProbability;              // Вероятность отказа
        double mathExpectationNotWorking;       // Математическое ожидание не работающих станков
        double mathExpectationInQueue;          // Математическое ожидание станков ждущих обслуживания
        double queueExistanceProbability;       // Вероятность существования очереди
        double mathExpectationBusy;             // Математическое ожидание занятого числа наладчиков
        double loadCoeff;                       // Коэффициент загрузки наладчиков
    };

    void Solve() override {
        FILE *fout1 = fopen("../data/task2_1/MathExpectationNotWorking.txt", "w");
        FILE *fout2 = fopen("../data/task2_1/MathExpectationInQueue.txt", "w");
        FILE *fout3 = fopen("../data/task2_1/QueueExistanceProbability.txt", "w");
        FILE *fout4 = fopen("../data/task2_1/MathExpectationBusy.txt", "w");
        FILE *fout5 = fopen("../data/task2_1/QueueLoadCoeff.txt", "w");

        for (int machines = 1; machines <= P2_N; ++machines) {
            MachinesResult result = calculate(machines);
            
            fprintf(fout1, "%d %e\n", machines, result.mathExpectationNotWorking);
            fprintf(fout2, "%d %e\n", machines, result.mathExpectationInQueue);
            fprintf(fout3, "%d %e\n", machines, result.queueExistanceProbability);
            fprintf(fout4, "%d %e\n", machines, result.mathExpectationBusy);
            fprintf(fout5, "%d %e\n", machines, result.loadCoeff);
        }

        fclose(fout1);
        fclose(fout2);
        fclose(fout3);
        fclose(fout4);
        fclose(fout5);
    }

private:
    MachinesResult calculate(int n) {
        vector<double> p(P2_N);
        p[0] = 1;

        double pSum = 1;
        double mSum = 0;
        double sumNotWorking = 0;
        double sumQueue = 1;
        double sumQueueLength = 0;
        
        int amount = P2_N;        
        for (int i = 1; i < n + 1; ++i) {
            p[i] = p[i - 1] * amount * P2_LAMBDA / (i * P2_MU);
            pSum += p[i];
            mSum += i * p[i];
            sumNotWorking += i * p[i];
            sumQueue += p[i];
            --amount;
        }

        for (int i = n + 1; i < P2_N + 1; ++i) {
            p[i] = p[i - 1] * amount * P2_LAMBDA / (n * P2_MU);
            pSum += p[i];
            mSum += n * p[i];
            sumNotWorking += i * p[i];
            sumQueueLength += (i - n) * p[i];
            --amount;
        }

        double p0 = 1 / pSum;

        MachinesResult result = {
            .failureProbability = p[P2_N] * p0,
            .mathExpectationNotWorking = sumNotWorking * p0,
            .mathExpectationInQueue = sumQueueLength * p0,
            .queueExistanceProbability = 1 - (sumQueue * p0),
            .mathExpectationBusy = mSum * p0,
            .loadCoeff = mSum * p0 / n
        };

        return result;
    }
};