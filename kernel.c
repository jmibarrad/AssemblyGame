void printStringVideo(char* str, int color);
void DrawLine(int x,int y,int x2,int y2,int color);
void DrawRect(int x,int y,int x2,int y2,int color);
void drawFillRect(int x,int y,int x2,int y2,int color);
void gameOver();
void drawMaze();


void main(){
	int i = 1, j = 50;
	char current = 0;
	char* gameLabel = "EMA Games";
	beep();
	setVideoMode();
	moveCursor(15, 1);
	printStringVideo("EMA", 0x4F);
	printStringVideo(" Games", 0x5F);
	drawMaze();
	//gameOver();
	while(1){
		current = readChar();
		if(current== 's'){
			i++;
			putPixel(i-1, j, 0x0);
			putPixel(i, j, 0xF);
		}else if(current == 'w'){
			i--;
			putPixel(i+1, j, 0x0);
			putPixel(i, j, 0xF);
		}else if(current== 'd'){
			j++;
			putPixel(i, j-1, 0x0);
			putPixel(i, j, 0xF);
		}else if(current == 'a'){
			j--;
			putPixel(i, j+1, 0x0);
			putPixel(i, j, 0xf);
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

void DrawRect(int x1,int y1,int x2,int y2,int color)
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

void drawFillRect(int x, int y, int x2, int y2, int color){
	int i, j;
	for(i = x; i<x2; i++)
		for(j = y; j < y2; j++)
			putPixel(i, j, color);
}

void drawMaze(){
	//           x1  y1 x2  y2
	DrawRect(27, 40, 185, 279, 0xE);
	drawFillRect(28, 47, 50, 50, 0xF);
	drawFillRect(50, 47, 53, 60, 0xF);
	//drawFillRect(60, 41, 63, 100, 0xF);
	//drawFillRect(80, 45, 83, 67, 0xF);
	//drawFillRect(100, 41, 103, 80, 0xF);
	//drawFillRect(28, 80, 50, 83, 0xF);
	//drawFillRect(50, 35, 53, 100, 0xF);
	//drawFillRect(80, 4, 83, 45, 0xF);
	
}
