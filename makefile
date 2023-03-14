proFile: mainA3.o helperA3.o countEmployees.o fireAll.o fireOne.o loadEmpData.o lookOnFullName.o lookOnFullName.o lookOnId.o printAll.o recruitEmployee.o sortEmployeesId.o
	gcc -Wall -std=c99 mainA3.o helperA3.o countEmployees.o fireAll.o fireOne.o loadEmpData.o lookOnFullName.o lookOnFullName.o lookOnId.o printAll.o recruitEmployee.o sortEmployeesId.o -o bin/proFile

mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/mainA3.c

countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -Wall -std=c99 -c src/countEmployees.c

fireAll.o: src/fireAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/fireAll.c

fireOne.o: src/fireOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/fireOne.c

loadEmpData.o: src/loadEmpData.c include/headerA3.h
	gcc -Wall -std=c99 -c src/loadEmpData.c

lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookOnFullName.c

lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookOnId.c

printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printAll.c

printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printOne.c

recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -Wall -std=c99 -c src/recruitEmployee.c

sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/sortEmployeesId.c

helperA3.o: src/helperA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/helperA3.c

clean:
	rm *.o bin/proFile