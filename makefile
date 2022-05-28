HGU_FoodRating: functions.o main.o
	gcc functions.o main.o -o HGU_FoodRating
functions.o: functions.c
	gcc functions.c -c -o functions.o
main.o: main.c
	gcc main.c -c -o main.o
