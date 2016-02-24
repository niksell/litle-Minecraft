

game : main.cpp Display.o View.o ColorCube.o Cube.o MouseCamera.o Move.o Player.o Light.o Utils.h
	g++ -o game Display.o View.o ColorCube.o Cube.o MouseCamera.o Move.o Player.o Light.o main.cpp -lGL -lGLU -lglut 

Display.o : Display.cpp Display.h Utils.h
	g++ -c Display.cpp -lGL -lGLU -lglut

View.o : View.cpp View.h Utils.h
	g++ -c View.cpp 

ColorCube.o : ColorCube.cpp ColorCube.h Utils.h
	g++ -c ColorCube.cpp -lGL -lGLU -lglut 

Cube.o : Cube.cpp ColorCube.cpp Cube.h Utils.h ColorCube.h
	g++ -c Cube.cpp ColorCube.cpp  -lGL -lGLU -lglut 

MouseCamera.o : MouseCamera.cpp MouseCamera.h Utils.h
	g++ -c MouseCamera.cpp 

Move.o : Move.cpp Move.h Cube.h Utils.h
	g++ -c Move.cpp 

Player.o : Player.cpp Player.h Cube.h Utils.h
	g++ -c Player.cpp 

Light.o : Light.cpp Utils.h Light.h
	g++ -c Light.cpp -lGL -lGLU -lglut



clean:
	rm -rf *o game


