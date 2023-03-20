proFile: mainA3.o helperA3.o countEmployees.o fireAll.o fireOne.o loadEmpData.o lookOnFullName.o  lookOnId.o printAll.o printOne.o recruitEmployee.o sortEmployeesId.o
	gcc -Wall -std=c99 -g mainA3.o helperA3.o countEmployees.o fireAll.o fireOne.o loadEmpData.o lookOnFullName.o lookOnId.o printAll.o printOne.o recruitEmployee.o sortEmployeesId.o -o bin/proFile

mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/mainA3.c

countEmployees.o: src/countEmployees.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/countEmployees.c

fireAll.o: src/fireAll.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/fireAll.c

fireOne.o: src/fireOne.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/fireOne.c

loadEmpData.o: src/loadEmpData.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/loadEmpData.c

lookOnFullName.o: src/lookOnFullName.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/lookOnFullName.c

lookOnId.o: src/lookOnId.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/lookOnId.c

printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/printAll.c

printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/printOne.c

recruitEmployee.o: src/recruitEmployee.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/recruitEmployee.c

sortEmployeesId.o: src/sortEmployeesId.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/sortEmployeesId.c

helperA3.o: src/helperA3.c include/headerA3.h
	gcc -Wall -std=c99 -c -g src/helperA3.c

clean:
	rm *.o bin/proFile