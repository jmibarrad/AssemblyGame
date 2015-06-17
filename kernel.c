void printStringVideo(char* str, int color);
void DrawLine(int x,int y,int x2,int y2,int color);
void DrawRect(int x,int y,int x2,int y2,int color);
void drawFillRect(int x,int y,int x2,int y2,int color);
void gameOver();
void gameStart();
void runnerGame();
void drawObstacule(int x,int y,int color);
void drawSun(int x,int y,int color);
void drawCloud(int x,int y,int color);
void moveCar(int x,int y,int color);
void drawMaze();
void drawHorizontalRect(int x, int y,int color);
void printInt(int value, int color);

void main(){
	int i = 32, j = 120;
	
	char* gameLabel = "EMA Games";
	//beep();
	setVideoMode();
	moveCursor(15, 1);
	DrawRect(27, 40, 185, 279, 0xE);
	printStringVideo("EMA", 0x4F);
	printStringVideo(" Games", 0x5F);
	
	printInt(getPixel(i+1, j), 15);
	printInt(getPixel(0, 0), 15);
	printInt(12, 15);
	//gameOver();
	gameStart();
	//runnerGame();
}

void gameStart()
{
	int i = 32, j = 105, pixel = 0,pixel2=0;
	char current = 0;
	drawMaze(11);
	putPixel(i, j, 0xF);
	putPixel(i+1, j, 0xF);
	putPixel(i, j+1, 0xF);
	putPixel(i+1, j+1, 0xF);
	while(1){
		current = readChar();
		if(current== 's'){
			i++;
			pixel = getPixel(i, j+1);
			pixel2 = getPixel(i+1, j+1);
			if(pixel != 0x0 && pixel2 !=0x0)
				gameOver();
			putPixel(i-1, j, 0x0);
			putPixel(i-1, j+1, 0x0);
			
			putPixel(i, j, 0xF);
			putPixel(i+1, j, 0xF);
			putPixel(i, j+1, 0xF);
			putPixel(i+1, j+1, 0xF);
		}else if(current == 'w'){
			i--;
			pixel = getPixel(i, j);
			pixel2 = getPixel(i+1, j);
			if(pixel != 0x0 && pixel2!=0x0)
				gameOver();
			putPixel(i+2, j, 0x0);
			putPixel(i+2, j+1, 0x0);
			
			putPixel(i, j, 0xF);
			putPixel(i+1, j, 0xF);
			putPixel(i, j+1, 0xF);
			putPixel(i+1, j+1, 0xF);
		}else if(current== 'd'){
			j++;
			pixel = getPixel(i+1, j);
			pixel2 = getPixel(i+1, j+1);
			if(pixel != 0x0 && pixel2!=0x0)
				gameOver();
			putPixel(i, j-1, 0x0);
			putPixel(i+1, j-1, 0x0);
			
			putPixel(i, j, 0xF);
			putPixel(i+1, j, 0xF);
			putPixel(i, j+1, 0xF);
			putPixel(i+1, j+1, 0xF);
		}else if(current == 'a'){
			j--;
			pixel = getPixel(i, j);
			pixel2 = getPixel(i, j+1);
			if(pixel != 0x0 && pixel !=0x0)
				gameOver();
			putPixel(i, j+2, 0x0);
			putPixel(i+1, j+2, 0x0);
			
			putPixel(i, j, 0xF);
			putPixel(i+1, j, 0xF);
			putPixel(i, j+1, 0xF);
			putPixel(i+1, j+1, 0xF);
		}
	}
}

void moveCar(int x,int y,int color)
{
	drawObstacule(x,y,color);
	drawFillRect(x,y+17,8,1,11);
}

void drawSun(int x,int y,int color)
{
	drawFillRect(x,y+3, 5,14, color);
	drawFillRect(x+5,y, 10,20, color);
	drawFillRect(x+15,y+3, 5,14, color);
}

void drawCloud(int x,int y,int color)
{
	drawFillRect(x,y+3, 5,24, color);
	drawFillRect(x+5,y, 10,30, color);
	drawFillRect(x+15,y+3, 5,24, color);
}

void drawObstacule(int x,int y,int c)
{	
	drawFillRect(x,y, 1,6, 11);
	drawFillRect(x,y+6, 1,8, c);
	drawFillRect(x,y+14, 1,3, 11);
	
	drawFillRect(x+1,y, 2,6, 11);
	drawFillRect(x+1,y+6, 2,1, c);
	drawFillRect(x+1,y+7, 2,2, 15);
	drawFillRect(x+1,y+9, 2,1, c);
	drawFillRect(x+1,y+10, 2,2, 15);
	drawFillRect(x+1,y+12, 2,2, c);
	drawFillRect(x+1,y+14, 2,3, 11);
	
	drawFillRect(x+3,y, 1,9, c);
	drawFillRect(x+3,y+9, 1,5, c);
	drawFillRect(x+3,y+14, 1,3, c);
	
	drawFillRect(x+4,y, 2,2, 14);
	drawFillRect(x+4,y+2, 2,7, c);
	drawFillRect(x+4,y+9, 2,5, c);
	drawFillRect(x+4,y+14, 2,3, c);
	
	
	drawFillRect(x+6,y, 2,9, c);
	drawFillRect(x+6,y+9, 2,5, c);
	drawFillRect(x+6,y+14, 2,3, c);
	
	drawFillRect(x+7,y, 1,4, c);
	drawFillRect(x+7,y+4, 1,3, 0);
	drawFillRect(x+7,y+7, 1,4, c);
	drawFillRect(x+7,y+11, 1,3, 0);
	drawFillRect(x+7,y+14, 1,3, c);
	
	drawFillRect(x+8,y, 1,4, 11);
	drawFillRect(x+8,y+4, 1,3, 0);
	drawFillRect(x+8,y+7, 1,4, 11);
	drawFillRect(x+8,y+11, 1,3, 0);
	drawFillRect(x+8,y+14, 1,3, 11);
	
}

void runnerGame()
{
	int i = 138, j = 70,k, pixel = 0,pixel2=0, car1X=160, car2X=220;
	char current = 0;
	drawFillRect(28,41, 120, 238, 11);
	drawFillRect(140,41, 45, 238, 0xA);
	putPixel(i, j, 6);
	putPixel(i+1, j, 6);
	putPixel(i, j+1, 6);
	putPixel(i+1, j+1,6);
	moveCar(131,car2X,9);
	moveCar(131,car1X,8);
	drawSun(40,50,14);
	drawCloud(30,170,15);
	drawCloud(40,100,15);
	drawCloud(70,250,15);
	while(1){
		current = readChar();
		if(current == 0x20){
			for(k=0;k<25;k++)
			{
				i--;
				pixel = getPixel(i, j);
				pixel2 = getPixel(i+1, j);
				if(pixel != 11 && pixel2!=11)
					gameOver();
				putPixel(i+2, j, 11);
				putPixel(i+2, j+1, 11);
			
				putPixel(i, j, 6);
				putPixel(i+1, j, 6);
				putPixel(i, j+1, 6);
				putPixel(i+1, j+1, 6);
				moveCar(131,car1X,8);
				car1X-=1;
				delay();
			}
			for(k=0;k<25;k++)
			{
				i++;
				pixel = getPixel(i, j+1);
				pixel2 = getPixel(i+1, j+1);
				if(pixel != 11 && pixel2 !=11)
					gameOver();
				putPixel(i-1, j, 11);
				putPixel(i-1, j+1, 11);
			
				putPixel(i, j, 6);
				putPixel(i+1, j, 6);
				putPixel(i, j+1, 6);
				putPixel(i+1, j+1, 6);
				moveCar(131,car2X,9);
				car2X-=1;
				delay();
			}
		}else 
		{
			drawObstacule(131,car1X,8);
			delay();
			car1X-=2;
			drawObstacule(131,car2X,9);
			car2X-=2;
			delay();
		}
	}
}

void movingObstacules(){

}

void printStringVideo(char* str, int color){
	int i;	
	for(i=0; str[i] != '\0'; i++)
		printCharVGA(str[i], color);
}

void DrawLine(int x1,int y1,int x2,int y2,int color)
{
    int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;
	dx=x2-x1;      /* the horizontal distance of the line */
	dy=y2-y1;      /* the vertical distance of the line */
	if(dx<0){  
		dxabs=dx*-1;
		sdx=-1;
	}else{
		dxabs=dx;
		sdx=1;
	}
	if(dy<0){
	    dyabs=dy*-1;
	    sdy=-1;
	}else{
		dyabs=dy;
		sdy=1;
	}	
	  
	  
	  x=dyabs>>1;
	  y=dxabs>>1;
	  px=x1;
	  py=y1;
	  
	  if (dxabs>=dyabs) /* the line is more horizontal than vertical */
	  {
		for(i=0;i<dxabs;i++)
		{
		  y+=dyabs;
		  if (y>=dxabs)
		  {
		    y-=dxabs;
		    py+=sdy;
		  }
		  px+=sdx;
		  putPixel(px,py,color);
		}
	  }
	  else /* the line is more vertical than horizontal */
	  {
		for(i=0;i<dyabs;i++)
		{
		  x+=dxabs;
		  if (x>=dyabs)
		  {
		    x-=dyabs;
		    px+=sdx;
		  }
		  py+=sdy;
		  putPixel(px,py,color);
		}
	  }
}

void DrawRect(int x1,int y1 ,int x2 ,int y2,int color)
{
	DrawLine(x1,y1,x2,y1,color);
	DrawLine(x2,y1,x2,y2,color);
	DrawLine(x1,y1,x1,y2,color);
	DrawLine(x1,y2,x2,y2,color);
}

void gameOver(){
	int i, j, k = 199, h = 319;
	for(i = 0; i < 200; i++, k--)
		for(j = 0; j < 320; j++, h--)
			DrawRect(i, j, k, h, 0x4);
}

void drawFillRect(int x, int y, int width, int height, int color){
	int i, j;
	for(i = x; i<x + width; i++)
		for(j = y; j < y + height; j++)
			putPixel(i, j, color);
}

void drawMaze(int color){
	int width = 5;

	//           y1  x1 width height color
	drawFillRect(45, 61, width, 218, color);
	drawFillRect(45, 61, 20, width, color);
	drawFillRect(75, 61, width, 15, color);
	drawFillRect(65, 71,15, width, color);
}

void printInt(int value,int color)
{
	if(value!=0){
		int digits=1;
		while(value>=digits)
			digits=digits*10;
		
		digits=digits/10;
		while(digits!=1)
		{
			printCharVGA((value/digits)+48,color);
			value=value-(value/digits)*digits;
			digits=digits/10;
		}
		printCharVGA((value/digits)+48,color);
	}else
		printCharVGA(value+48,color);
}
