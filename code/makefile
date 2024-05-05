myprogram : main.o Person.o Shop.o Goods.o Factor.o Request.o
	g++ -std=c++98  -o myprogram main.o Person.o Shop.o Goods.o Factor.o Request.o

  main.o : main.cpp Person.h Shop.h Goods.h Request.h Factor.h
			g++ -std=c++98 -c main.cpp

	Person.o : Person.cpp Person.h
			g++ -std=c++98 -c Person.cpp

	Goods.o : Goods.cpp Goods.h Person.h
			 g++ -std=c++98 -c Goods.cpp

	Shop.o : Shop.cpp Shop.h Person.h Goods.h
			 g++ -std=c++98 -c Shop.cpp

	Factor.o : Factor.cpp Factor.h Person.h Goods.h
		 		g++ -std=c++98 -c Factor.cpp

	Request.o : Request.cpp Request.h Person.h
				g++ -std=c++98 -c Request.cpp
