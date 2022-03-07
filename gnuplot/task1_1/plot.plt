set terminal png
set title sprintf("Вероятность отказа")
set xlabel "Количество операторов"
set output "../../images/task1_1/Вероятность отказа.png"
plot "../../data/task1_1/FailureProbability.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Мат. ожидание числа занятых операторов")
set xlabel "Количество операторов"
set output "../../images/task1_1/Математическое ожидание числа занятых операторов.png"
plot "../../data/task1_1/MathExpectation.txt" using 1:2 notitle with lp

set terminal png
set title sprintf("Коэффициент загрузки операторов")
set xlabel "Количество операторов"
set output "../../images/task1_1/Коэффициент загрузки операторов.png"
plot "../../data/task1_1/OperatorsLoadCoeff.txt" using 1:2 notitle with lp
