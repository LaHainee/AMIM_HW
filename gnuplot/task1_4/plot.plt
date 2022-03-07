set terminal png
set title sprintf("Мат. ожидание числа занятых операторов")
set xlabel "Количество операторов"
set output "../../images/task1_4/Математическое ожидание числа занятых операторов.png"
plot "../../data/task1_4/MathExpectation.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Коэффициент загрузки операторов")
set xlabel "Количество операторов"
set output "../../images/task1_4/Коэффициент загрузки операторов.png"
plot "../../data/task1_4/OperatorsLoadCoeff.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Вероятность наличия очереди")
set xlabel "Количество операторов"
set output "../../images/task1_4/Вероятность наличия очереди.png"
plot "../../data/task1_4/QueueExistanceProbability.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Мат. ожидание длины очереди")
set xlabel "Количество операторов"
set output "../../images/task1_4/Математическое ожидание длины очереди.png"
plot "../../data/task1_4/MathExpectationQueueLength.txt" using 1:2 notitle with lp
