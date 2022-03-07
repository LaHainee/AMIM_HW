CPP_STANDARD=c++11

# Запуск приложения. Запускается скрипт для создания пустых папок (если они отсутствуют), затем запускается main
run:
	{ \
	cd scripts; \
	sh init.sh; \
	cd ../cmd; \
	g++ -std=${CPP_STANDARD} main.cpp && ./a.out; \
	}

# Создание графиков
run-gnuplot:
	{ \
	cd scripts; \
	sh init.sh; \
	sh gnuplot.sh; \
	}

# Создание пустых папок (images, data)
init:
	{ \
	cd scripts; \
	sh init.sh; \
	}

# Сборка приложения
build:
	{ \
	cd scripts; \
	sh init.sh; \
	cd ../cmd; \
	g++ -std=${CPP_STANDARD} main.cpp; \
	}

clear:
	{ \
	rm -rf data; \
	rm -rf images; \
	}