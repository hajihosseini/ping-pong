#include<iostream>
#include"SDL/SDL.h"
#include<SDL/SDL_gfxPrimitives.h>
using namespace std;
SDL_Event event;
int main(){
        //PingPong
        SDL_Surface*screen =SDL_SetVideoMode(1200,700,32,0);

        int x=0,y=0,dx=1,dy=1,y1=200,y2=350,vx=0,vy=0,y3=200,y4=350;
        int score1=0,score2=0,running=1;

        boxRGBA(screen,0,y1,30,y2,100,132,219,255);
        boxRGBA(screen,1170,y3,1200,y4,100,132,219,255);

        while(running==1){
        if (SDL_PollEvent(&event)){
                if (event.type == SDL_QUIT)
                        return 0;
                if (event.type == SDL_KEYDOWN){
                         if (event.key.keysym.sym == SDLK_UP){
                                vx =50; 
                                boxRGBA(screen,1170,y4-vx,1200,y4,0,0,0,255);
                                if(y3-vx <= 0 || y4-vx <= 150){
                                        y3=0;
                                        y4=150;
                                        boxRGBA(screen,1170,y3,1200,y4,100,132,219,255);
                                }
                                else{
                                        boxRGBA(screen,1170,y3-vx,1200,y4-vx,100,132,219,255);
                                
                                y4 = y4-vx;
                                y3 = y3-vx;
                        }
                        }
			  if(event.key.keysym.sym == SDLK_DOWN){
                               vx =50;
                               boxRGBA(screen,1170,y3,1200,y3+vx,0,0,0,255);
                               if(y4+vx >= 700 || y3+vx >= 550){
                                        y3=550;
                                        y4=700;
                                        boxRGBA(screen,1170,y3,1200,y4,100,132,219,255);
                                }
                                else{
                                        boxRGBA(screen,1170,y3+vx,1200,y4+vx,100,132,219,255);
                                        y4 = y4+vx;
                                        y3 = y3+vx;
                                     }
                                }


                         if (event.key.keysym.sym == SDLK_w){
                                vy =50;
                                boxRGBA(screen,0,y2-vy,30,y2,0,0,0,255);
                                if(y1-vy <= 0 || y2-vy <= 150){
                                        y1=0;
                                        y2=150;
                                        boxRGBA(screen,0,y1,30,y2,100,132,219,255);
                                }
                                else{
                                        boxRGBA(screen,0,y1-vy,30,y2-vy,100,132,219,255);
                                         y2 = y2-vy;
                                         y1 = y1-vy;
                                 }}

		         if(event.key.keysym.sym == SDLK_s){
                                vy =50;
                                boxRGBA(screen,0,y1,30,y1+vy,0,0,0,255);
                                if(y2+vy >= 700 || y1+vy >= 550){
                                        y1=550;
                                        y2=700;
                                        boxRGBA(screen,0,y1,30,y2,100,132,219,255);
                                }
                                else{
                                        boxRGBA(screen,0,y1+vy,30,y2+vy,100,132,219,255);
                                         y2 = y2+vy;
                                         y1 = y1+vy;
                                }
                                }
                        }}

                filledEllipseRGBA(screen,x,y,10,10,0,0,0,255);
                x += dx;
                y += dy;
                filledEllipseRGBA(screen,x,y,10,10,200,100,70,255);

		   if(x==0 || x==1200)
                        dx *= -1;

                if (y==0 || y==700)
                        dy *= -1;

                if(x<=40 && y>=y1-10 && y<=y2+10)
                        dx *= -1;

                if(x>0 && x<30 && y>=y1-10 && y<=y2+10 )
                        dy *= -1;

                if(x>=1160  && y>=y3-10 && y<=y4+10)
                        dx *= -1;

                if(x>1170 && x<1200 && y>=y3-10 && y<=y4+10)
                        dy *= -1;

                if(x==0 && (y<y1-10 || y>y2+10)){
                        score2 += 1;
                        cout << "score2= " << score2 << endl;
                        if(score2 == 11){
                                cout << "player2 is winner" << endl;
                                running = 0;
                        }}
                if(x==1200 && (y<y3-10 || y>y4+10)){
                        score1 += 1;
                        cout << "score1= " << score1 <<endl;
                        if(score1 == 11){
                                cout << "player1 is winner "<<endl;
                                running = 0;
                        }}
                                SDL_Flip(screen);
                SDL_Delay(1);
        }
                cout <<"score1= " <<score1 <<endl <<"score2= "<< score2 << endl;
                SDL_Delay(5000);
                return 1;
}


