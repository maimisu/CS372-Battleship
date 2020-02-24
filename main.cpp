#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <time.h>
#include <SFML/Graphics.hpp>


int size = 51;
sf::Sprite sp[2]; //figures

int board[10][10] =
{
    -6, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

std::string toBoard(sf::Vector2f p){
    std::string s = "";
    s += char(p.x/size+99);
    s += char(7-p.y/size+49);
    return s;
}

/*sf::Vector2f coord(char a, char b){
    int x = int(a) - 97;
    int y = 7-int(b)+ 49;
    return sf::Vector2f(x*size,y*size);
}*/

/*void letMove(std::string str){
    sf::Vector2f oldPos = coord(str[0],str[1]);
    sf::Vector2f newPos = coord(str[2],str[3]);
    for(int i = 0;i<2;i++){
        if (sp[i].getPosition() == newPos) {
            sp[i].setPosition(-50,-50);
        }
    }
    for(int i = 0;i<2;i++){
        if (sp[i].getPosition() == newPos) {
            sp[i].setPosition(newPos);
        }
    }

}*/

void loadPosition(){
int k=0;
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
        int n = board[i][j];
        if (!n){
            continue;
        }
        int x = abs(n) - 1;
        int y = n>0?1:0;
        sp[k].setTextureRect(sf::IntRect(size*x,size*y,size,size));
        sp[k].setPosition(size*j,size*i);
        k++;
    }
}
}

/*void initialize_board(int array1[10][10])
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			array1[x][y] = occupied;
		}
	}
}*/
int main(){
	sf::RenderWindow window(sf::VideoMode(650,650), "BattleShip");
	sf::Texture t1,t2;
	t1.loadFromFile("images/Singularboat.png");
	t2.loadFromFile("images/battleshipBoard2.jpg");
	sf::Sprite s(t1);
	sf::Sprite sBoard(t2);

	for(int i = 0; i <2; i++){
        sp[i].setTexture(t1);
	}

	loadPosition();

	bool isMove = false;
	float dx = 0, dy = 0;
	sf::Vector2f oldPos, newPos;
	std::string str;
	int n = 0;

	while (window.isOpen()){
        sf::Vector2i pos = sf::Mouse::getPosition(window);
	    sf::Event e;
	    while(window.pollEvent(e)){
	        if (e.type == sf::Event::Closed)
	            window.close();

            if (e.type == sf::Event::MouseButtonPressed)
                if(e.key.code == sf::Mouse::Left)
                    for(int i=0;i<2;i++)
                        if(s.getGlobalBounds().contains(pos.x,pos.y)){
                        isMove = true; n = i;
                        dx = pos.x - sp[i].getPosition().x;
                        dy = pos.y - sp[i].getPosition().y;
                        oldPos = sp[i].getPosition();
                        }

            if(e.type == sf::Event::MouseButtonReleased)
                if(e.key.code == sf::Mouse::Left){
                    isMove = false;
                    sf::Vector2f p = sp[n].getPosition() + sf::Vector2f(size/2,size/2);
                    newPos = sf::Vector2f(size*int(p.x/size),size*int(p.y/size));
                    //str = toBoard(oldPos)+ toBoard(newPos);
                    //letMove(str);
                    std::cout<<size*int(p.x/size)<< " and " << size*int(p.y/size) << std::endl;
                    sp[n].setPosition(newPos);
                }
            }

            if(isMove)sp[n].setPosition(pos.x-dx,pos.y-dy);
            window.clear();
            window.draw(sBoard);
            for(int i=0;i<2;i++){
            window.draw(sp[i]);
            }
            window.display();
	    }
    //initialize_board(board);
	//print_board(board);

	return 0;
}
