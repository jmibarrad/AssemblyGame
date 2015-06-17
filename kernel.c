void printStringVideo(char* str, int color);
void DrawLine(int x,int y,int x2,int y2,int color);
void DrawRect(int x,int y,int x2,int y2,int color);
void drawFillRect(int x,int y,int x2,int y2,int color);
void gameOver();
void drawMaze();
void printInt(int value, int color);
void gameStart(int color);

void main(){
	int i = 32, j = 120, pixel = 0;
	char current = 0;
	char* gameLabel = "EMA Games";
	beep();
	setVideoMode();
	moveCursor(15, 1);
	printStringVideo("EMA", 0x4F);
	printStringVideo(" Games", 0x5F);
	drawMaze(0xF);

	gameStart(0x3);
}

void gameStart(int color)
{
	int i = 32, j = 120, pixel = 0,pixel2=0;
	char current = 0;
	putPixel(i, j, color);
	putPixel(i+1, j, color);
	putPixel(i, j+1, color);
	putPixel(i+1, j+1, color);
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
			
			putPixel(i, j, color);
			putPixel(i+1, j, color);
			putPixel(i, j+1, color);
			putPixel(i+1, j+1, color);
		}else if(current == 'w'){
			i--;
			pixel = getPixel(i, j);
			pixel2 = getPixel(i+1, j);
			if(pixel != 0x0 && pixel2!=0x0)
				gameOver();
			putPixel(i+2, j, 0x0);
			putPixel(i+2, j+1, 0x0);
			
			putPixel(i, j, color);
			putPixel(i+1, j, color);
			putPixel(i, j+1, color);
			putPixel(i+1, j+1, color);
		}else if(current== 'd'){
			j++;
			pixel = getPixel(i+1, j);
			pixel2 = getPixel(i+1, j+1);
			if(pixel != 0x0 && pixel2!=0x0)
				gameOver();
			putPixel(i, j-1, 0x0);
			putPixel(i+1, j-1, 0x0);
			
			putPixel(i, j, color);
			putPixel(i+1, j, color);
			putPixel(i, j+1, color);
			putPixel(i+1, j+1, color);
		}else if(current == 'a'){
			j--;
			pixel = getPixel(i, j);
			pixel2 = getPixel(i, j+1);
			if(pixel != 0x0 && pixel !=0x0)
				gameOver();
			putPixel(i, j+2, 0x0);
			putPixel(i+1, j+2, 0x0);
			
			putPixel(i, j, color);
			putPixel(i+1, j, color);
			putPixel(i, j+1, color);
			putPixel(i+1, j+1, color);
		}
	}
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
	int width = 5, i = 44, j = 0;
	DrawRect(27, 40, 185, 279, 0xE);
	//           x1  y1 width height color
	drawFillRect(28, 52, 22, width, color);
	drawFillRect(50, 52, width, 50, color);	
	drawFillRect(36, 47, width, width, color);
	drawFillRect(28, 64, 11,width, color);
	drawFillRect(39, 64, width, 15, color);
	drawFillRect(28, 140, 12, width, color);
	drawFillRect(39, 126, width, 19, color);
	drawFillRect(39, 90, width, 27, color);
	drawFillRect(44, 112, 30, width, color);
	drawFillRect(28, 145, 3, width, 0xA); //Start
	drawFillRect(28, 150, 30, width, color);
	drawFillRect(50, 140, width, 15, color);
	drawFillRect(50, 117, width, 16, color);
	drawFillRect(35, 170, 20, width, color);
	drawFillRect(70, 45, width, 62, color);
	drawFillRect(70, 130, width, 68, color);
	drawFillRect(70, 210, width, 65, color);
	for( ; j < 16; i+=15, j++)
		drawFillRect(80, i, 30, width, color);
	drawFillRect(110, 41, width, 113, color);
	drawFillRect(110, 164, width, 116, color);	
	drawFillRect(35, 197, 40, width, color);
	drawFillRect(35, 202, width, 71, color);
	drawFillRect(37, 268, 10, width, color);	
	drawFillRect(50, 259, 20, width, color);
	drawFillRect(50, 228, width, 31, color);
	drawFillRect(50, 210, width, 11, color);
	drawFillRect(60, 200, width, 9, color);
	drawFillRect(60, 217, width, 35, color);
	//drawFillRect(60, 217, width, 35, color);
}


void printInt(int value,int color)
{
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
}
