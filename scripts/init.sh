# Создание необходимых директорий
if [[ ! -d ../images ]]
then
    cd .. &&
    mkdir images && cd images &&
    mkdir task1_1 task1_2 task1_3 task1_4 task2_1 &&
    mkdir task1_2/queue task1_2/operators
fi
if [[ ! -d ../data ]]
then 
    cd .. &&
    mkdir data && cd data &&
    mkdir task1_1 task1_2 task1_3 task1_4 task2_1
fi