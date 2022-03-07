set terminal png
set title sprintf("Мат. ожидание числа простаивающих станков")
set xlabel "Количество наладчиков"
set output "../../images/task2_1/Математическое ожидание простаивающих станков.png"
plot "../../data/task2_1/MathExpectationNotWorking.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Мат. ожидание станков в очереди на обслуживание")
set xlabel "Количество наладчиков"
set output "../../images/task2_1/Математическое ожидание станков ожидающих обслуживания.png"
plot "../../data/task2_1/MathExpectationInQueue.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Вероятность образования очереди на обслуживание")
set xlabel "Количество наладчиков"
set output "../../images/task2_1/Вероятность образования очереди на обслуживание.png"
plot "../../data/task2_1/QueueExistanceProbability.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Мат. ожидание числа занятых наладчиков")
set xlabel "Количество наладчиков"
set output "../../images/task2_1/Математическое ожидание числа занятых наладчиков.png"
plot "../../data/task2_1/MathExpectationBusy.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Коэффициент занятости наладчиков")
set xlabel "Количество наладчиков"
set output "../../images/task2_1/Коэффициент занятости наладчиков.png"
plot "../../data/task2_1/QueueLoadCoeff.txt" using 1:2 notitle with lp