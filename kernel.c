void printStringVideo(char* str, int color);
void DrawLine(int x1,int y1,int x2,int y2,int color);

void main(){
	int i = 1, j = 50;
	char current = 0;
	char* gameLabel = "EMA Games";
	char game[3];
	game[0] = 'j';
	game[1] = 'a';
	game[2] = 0;  
	setVideoMode();
	moveCursor(4, 1);
	printStringVideo(game, 0x4);
	DrawLine(20, 10, 100, 100, 0xF);
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
