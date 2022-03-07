#include "../src/SolverNoQueue.hpp"
#include "../src/SolverLimitedQueue.hpp"
#include "../src/SolverEndlessQueue.hpp"
#include "../src/SolverLeavingQueue.hpp"
#include "../src/SolverMachines.hpp"

void ClientCode(Solver *solver) {
    solver->Solve();
}

int main() {
    Solver_NoQueue *solver_noQueue = new Solver_NoQueue;
    ClientCode(solver_noQueue);

    Solver_LimitedQueue *solver_limitedQueue = new Solver_LimitedQueue;
    ClientCode(solver_limitedQueue);

    Solver_EndlessQueue *solver_endlessQueue = new Solver_EndlessQueue;
    ClientCode(solver_endlessQueue);

    Solver_LeaveQueue *solver_leaveQueue = new Solver_LeaveQueue;
    ClientCode(solver_leaveQueue);

    Solver_Machines *solver_machines = new Solver_Machines;
    ClientCode(solver_machines);

    delete solver_noQueue;
    delete solver_limitedQueue;
    delete solver_endlessQueue;
    delete solver_leaveQueue;
    delete solver_machines;

    return 0;
}