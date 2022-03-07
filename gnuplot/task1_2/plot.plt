set terminal png
set title sprintf("Вероятность отказа")
set xlabel "Мест в очереди"
set output "../../images/task1_2/operators/Вероятность отказа.png"
plot for [op=1:15:2] "../../data/task1_2/FailureProbability.txt" using ($1 == 1 ? $3:1/0):($2 == op ? $4:1/0) title "Операторы: ".op with lp linecolor op

set terminal png
set title sprintf("Мат. ожидание числа занятых операторов")
set xlabel "Мест в очереди"
set output "../../images/task1_2/operators/Математическое ожидание числа занятых операторов.png"
plot for [op=1:15:2] "../../data/task1_2/MathExpectation.txt" using ($1 == 1 ? $3:1/0):($2 == op ? $4:1/0) title "Операторы: ".op with lp linecolor op

set terminal png
set title sprintf("Коэффициент загрузки операторов")
set xlabel "Мест в очереди"
set output "../../images/task1_2/operators/Коэффициент загрузки операторов.png"
plot for [op=1:15:2] "../../data/task1_2/OperatorsLoadCoeff.txt" using ($1 == 1 ? $3:1/0):($2 == op ? $4:1/0) title "Операторы: ".op with lp linecolor op

set terminal png
set title sprintf("Вероятность наличия очереди")
set xlabel "Мест в очереди"
set output "../../images/task1_2/operators/Вероятность наличия очереди.png"
plot for [op=1:15:2] "../../data/task1_2/QueueExistanceProbability.txt" using ($1 == 1 ? $3:1/0):($2 == op ? $4:1/0) title "Операторы: ".op with lp linecolor op

set terminal png
set title sprintf("Мат. ожидание длины очереди")
set xlabel "Мест в очереди"
set output "../../images/task1_2/operators/Математическое ожидание длины очереди.png"
plot for [op=1:15:2] "../../data/task1_2/MathExpectationQueueLength.txt" using ($1 == 1 ? $3:1/0):($2 == op ? $4:1/0) title "Операторы: ".op with lp linecolor op

set terminal png
set title sprintf("Коэффициент занятости мест в очереди")
set xlabel "Мест в очереди"
set output "../../images/task1_2/operators/Коэффициент занятости мест в очереди.png"
plot for [op=1:15:2] "../../data/task1_2/QueueLoadCoeff.txt" using ($1 == 1 ? $3:1/0):($2 == op ? $4:1/0) title "Операторы: ".op with lp linecolor op



set terminal png
set title sprintf("Вероятность отказа")
set xlabel "Число операторов"
set output "../../images/task1_2/queue/Вероятность отказа.png"
plot for [qu=1:15:2] "../../data/task1_2/FailureProbability.txt" using ($1 == 2 ? $2:1/0):($3 == qu ? $4:1/0) title "Queue=".qu with lp linecolor qu

set terminal png
set title sprintf("Мат. ожидание числа занятых операторов")
set xlabel "Число операторов"
set output "../../images/task1_2/queue/Математическое ожидание числа занятых операторов.png"
plot for [qu=1:15:2] "../../data/task1_2/MathExpectation.txt" using ($1 == 2 ? $2:1/0):($3 == qu ? $4:1/0) title "Queue=".qu with lp linecolor qu

set terminal png
set title sprintf("Коэффициент загрузки операторов")
set xlabel "Число операторов"
set output "../../images/task1_2/queue/Коэффициент загрузки операторов.png"
plot for [qu=1:15:2] "../../data/task1_2/OperatorsLoadCoeff.txt" using ($1 == 2 ? $2:1/0):($3 == qu ? $4:1/0) title "Queue=".qu with lp linecolor qu

set terminal png
set title sprintf("Вероятность наличия очереди")
set xlabel "Число операторов"
set output "../../images/task1_2/queue/Вероятность наличия очереди.png"
plot for [qu=1:15:2] "../../data/task1_2/QueueExistanceProbability.txt" using ($1 == 2 ? $2:1/0):($3 == qu ? $4:1/0) title "Queue=".qu with lp linecolor qu

set terminal png
set title sprintf("Мат. ожидание длины очереди")
set xlabel "Число операторов"
set output "../../images/task1_2/queue/Математическое ожидание длины очереди.png"
plot for [qu=1:15:2] "../../data/task1_2/MathExpectationQueueLength.txt" using ($1 == 2 ? $2:1/0):($3 == qu ? $4:1/0) title "Queue=".qu with lp linecolor qu

set terminal png
set title sprintf("Коэффициент занятости мест в очереди")
set xlabel "Число операторов"
set output "../../images/task1_2/queue/Коэффициент занятости мест в очереди.png"
plot for [qu=1:15:2] "../../data/task1_2/QueueLoadCoeff.txt" using ($1 == 2 ? $2:1/0):($3 == qu ? $4:1/0) title "Queue=".qu with lp linecolor qu