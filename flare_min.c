// ./a.out X(layout length) Y(layout width) NET //X & Y must be divisible by 2. NET must be less than 10. 

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>


struct shape//L Z or I shape
{
	long x1,y1, x2,y2, x3,y3, x4,y4,select,select_prev;
	float priority;
	
};

struct shape *MAT[1000][1000];//holds the address of shapes
long NETMAT[1000][1000];

struct grid 
{
	float Tcapacity;
	struct grid_seg *GS;
};

struct grid_seg//holds how much part of a shape is in a grid
{
	float capacity;
	long mati,matj;
	struct grid_seg *nxt;
};

struct grid *GMAT[200][200];

long randum(long i, long j)
{
  	
  	long r=rand();
	r=r%j;
   	return(r+i);
}


struct grid_seg * density_find(long X, long Y, long k, long m, long n, long tr)
{
  
	long p,q,i,j;
	long arrx[X+Y],arry[X+Y],count,xx1,yy1,xx2,yy2;
	float wirelength;
	struct grid_seg *head=NULL,*ptr,*data;
	for(p=1;p<k;p++)
	{
		for(q=1;MAT[p][q]!=NULL;q++)
		{
			//points insertion on matrix
			i=0;
			xx1=MAT[p][q]->x1;
			yy1=MAT[p][q]->y1;
			xx2=MAT[p][q]->x2;
			yy2=MAT[p][q]->y2;
			if(xx1!=xx2 && yy1==yy2)
			{
				for(;xx1!=xx2;i++)
				{
					if(xx1>xx2)
						xx1--;
					if(xx1<xx2)
						xx1++;
					arrx[i]=xx1;
					arry[i]=yy1;
				}
				arrx[i]=xx1;
				arry[i]=yy1;
				i++;
			}
			else
			if(xx1==xx2 && yy1!=yy2)
			{
		
				for(;yy1!=yy2;i++)
				{
					if(yy1>yy2)
						yy1--;
					if(yy1<yy2)
						yy1++;
					arrx[i]=xx1;
					arry[i]=yy1;
				}
				arrx[i]=xx1;
				arry[i]=yy1;
				i++;
			}
	
			xx1=MAT[p][q]->x2;
			yy1=MAT[p][q]->y2;
			xx2=MAT[p][q]->x3;
			yy2=MAT[p][q]->y3;
			if(xx1!=xx2 && yy1==yy2)
			{
				for(;xx1!=xx2;i++)
				{
					if(xx1>xx2)
						xx1--;
					if(xx1<xx2)
						xx1++;
					arrx[i]=xx1;
					arry[i]=yy1;
				}
				arrx[i]=xx1;
				arry[i]=yy1;
				i++;
			}
			else
			if(xx1==xx2 && yy1!=yy2)
			{
				
				for(;yy1!=yy2;i++)
				{
					if(yy1>yy2)
						yy1--;
					if(yy1<yy2)
						yy1++;
					arrx[i]=xx1;
					arry[i]=yy1;
				}
				arrx[i]=xx1;
				arry[i]=yy1;
				i++;
			}
			
			xx1=MAT[p][q]->x3;
			yy1=MAT[p][q]->y3;
			xx2=MAT[p][q]->x4;
			yy2=MAT[p][q]->y4;
			if(xx1!=xx2 && yy1==yy2)
			{
				for(;xx1!=xx2;i++)
				{
					if(xx1>xx2)
						xx1--;
					if(xx1<xx2)
						xx1++;
					arrx[i]=xx1;
					arry[i]=yy1;
				}
				arrx[i]=xx1;
				arry[i]=yy1;
				i++;
			}
			else
			if(xx1==xx2 && yy1!=yy2)
			{
				
				for(;yy1!=yy2;i++)
				{
					if(yy1>yy2)
						yy1--;
					if(yy1<yy2)
						yy1++;
					arrx[i]=xx1;
					arry[i]=yy1;
				}
				arrx[i]=xx1;
				arry[i]=yy1;
				i++;
			}
			//points insertion on matrix end
			
			//capacity of a grid
			count=0;
			for(j=0;j<i;j++)
			{
				if(m==(arrx[j]/tr)+(arrx[j]%tr) && n==(arry[j]/tr)+(arry[j]%tr))
				{
					count++;
				}
				wirelength=count-1;
				if(m!=(arrx[0]/tr)+(arrx[0]%tr) && n!=(arry[0]/tr)+(arry[0]%tr))
				{
					wirelength+=0.5;
				}
				if(m!=(arrx[i-1]/tr)+(arrx[i-1]%tr) && n!=(arry[i-1]/tr)+(arry[i-1]%tr))
				{
					wirelength+=0.5;
				}
				if(count==0)
					wirelength=0;
				
			}
			//capacity of a grid end
			
			data=(struct grid_seg *)malloc(sizeof(struct grid_seg));
			data->capacity=wirelength;
			data->mati=p;
			data->matj=q;
			data->nxt=NULL;
			
			if(head==NULL)
			{
				head=data;
				ptr=head;
			}
			else
			{
				ptr->nxt=data;
				ptr=ptr->nxt;
			}
			
			
		}
	}
  
  
  
	return(head);
}





int check_shape(long X,long Y,long x1,long y1,long x2,long y2, long x3,long y3,long x4,long y4)
{
	long arrx[X+Y],arry[X+Y],i,j,xx1,xx2,yy1,yy2,temp=1,diff;
	i=0;
	xx1=x1;
	yy1=y1;
	xx2=x2;
	yy2=y2;
	if(xx1!=xx2 && yy1==yy2)
	{
		for(;xx1!=xx2;i++)
		{
			if(xx1>xx2)
				xx1--;
			if(xx1<xx2)
				xx1++;
			arrx[i]=xx1;
			arry[i]=yy1;
		}
		arrx[i]=xx1;
		arry[i]=yy1;
		i++;
	}
	else
	if(xx1==xx2 && yy1!=yy2)
	{
		
		for(;yy1!=yy2;i++)
		{
			if(yy1>yy2)
				yy1--;
			if(yy1<yy2)
				yy1++;
			arrx[i]=xx1;
			arry[i]=yy1;
		}
		arrx[i]=xx1;
		arry[i]=yy1;
		i++;
	}
	
	xx1=x2;
	yy1=y2;
	xx2=x3;
	yy2=y3;
	if(xx1!=xx2 && yy1==yy2)
	{
		for(;xx1!=xx2;i++)
		{
			if(xx1>xx2)
				xx1--;
			if(xx1<xx2)
				xx1++;
			arrx[i]=xx1;
			arry[i]=yy1;
		}
		arrx[i]=xx1;
		arry[i]=yy1;
		i++;
	}
	else
	if(xx1==xx2 && yy1!=yy2)
	{
		
		for(;yy1!=yy2;i++)
		{
			if(yy1>yy2)
				yy1--;
			if(yy1<yy2)
				yy1++;
			arrx[i]=xx1;
			arry[i]=yy1;
		}
		arrx[i]=xx1;
		arry[i]=yy1;
		i++;
	}
	
	xx1=x3;
	yy1=y3;
	xx2=x4;
	yy2=y4;
	if(xx1!=xx2 && yy1==yy2)
	{
		for(;xx1!=xx2;i++)
		{
			if(xx1>xx2)
				xx1--;
			if(xx1<xx2)
				xx1++;
			arrx[i]=xx1;
			arry[i]=yy1;
		}
		arrx[i]=xx1;
		arry[i]=yy1;
		i++;
	}
	else
	if(xx1==xx2 && yy1!=yy2)
	{
		
		for(;yy1!=yy2;i++)
		{
			if(yy1>yy2)
				yy1--;
			if(yy1<yy2)
				yy1++;
			arrx[i]=xx1;
			arry[i]=yy1;
		}
		arrx[i]=xx1;
		arry[i]=yy1;
		i++;
	}
	
	for(j=1;j<(i-1);j++)
	{
		if(NETMAT[arrx[j]][arry[j]]==1)
			temp=0;
	}
	return(temp);

}


void shape_find(long x1, long y1, long x2, long y2, long mati, long X, long Y)
{
	long matj=1,i,diff,temp;
	struct shape *ILZ;
	
	if(x1==x2 || y1==y2)
	{	
		ILZ=(struct shape *)malloc(sizeof(struct shape));
		ILZ->x1=x1;
		ILZ->y1=y1;
		ILZ->x2=x2;
		ILZ->y2=y2;
		ILZ->x3=x2;
		ILZ->y3=y2;
		ILZ->x4=x2;
		ILZ->y4=y2;
		ILZ->priority=1.00;//priority for I shape
		temp=check_shape(X,Y,ILZ->x1,ILZ->y1,ILZ->x2,ILZ->y2,ILZ->x3,ILZ->y3,ILZ->x4,ILZ->y4);
		if(temp==1)
		{
			MAT[mati][matj]=ILZ;
			matj++;
		}
		
		
	}
	else 
	if(x1!=x2 && y1!=y2)
	{  	
		for(i=0;(x1+i)!=x2;)//shifting vertical line
		{
			ILZ=(struct shape *)malloc(sizeof(struct shape));
			
			ILZ->x1=x1;
			ILZ->y1=y1;
			ILZ->x2=x1+i;
			ILZ->y2=y1;
			ILZ->x3=x1+i;
			ILZ->y3=y2;
			ILZ->x4=x2;
			ILZ->y4=y2;
			
			if(i==0)
				ILZ->priority=0.99;//priority for L shape
			else
				ILZ->priority=0.98;//priority for Z shape
			temp=check_shape(X,Y,ILZ->x1,ILZ->y1,ILZ->x2,ILZ->y2,ILZ->x3,ILZ->y3,ILZ->x4,ILZ->y4);
			if(temp==1)
			{
				ILZ->priority=0.00;
			}
			MAT[mati][matj]=ILZ;
			matj++;
			
			if(x1>x2)
				i--;
			if(x1<x2)
				i++;
		}
		
		for(i=0;(y1+i)!=y2;)//shifting horizontal line
		{
			ILZ=(struct shape *)malloc(sizeof(struct shape));
			
			ILZ->x1=x1;
			ILZ->y1=y1;
			ILZ->x2=x1;
			ILZ->y2=y1+i;
			ILZ->x3=x2;
			ILZ->y3=y1+i;
			ILZ->x4=x2;
			ILZ->y4=y2;
			
			temp=1;	
			temp=check_shape(X,Y,ILZ->x1,ILZ->y1,ILZ->x2,ILZ->y2,ILZ->x3,ILZ->y3,ILZ->x4,ILZ->y4);
			if(temp==0)
			{
				ILZ->priority=0.00;
			}
			else
			{
				if(i==0)
					ILZ->priority=0.99;//priority for L shape
				else
					ILZ->priority=0.98;//priority for Z shape
			
				
			}
			MAT[mati][matj]=ILZ;
			matj++;
			
			if(y1>y2)
				i--;
			if(y1<y2)
				i++;
		
		}
		
		
	}
	
	MAT[mati][matj]=NULL;
}

void net(long X,long Y,long NET,long tr)
{
	
	long ARR1[X][Y],len[NET];
	long no_of_points,i,j,valid_x,valid_y;
	long netx[NET][9],nety[NET][9];
	
	long distance,targetk,k,xd,yd,d,tempx,tempy;
	FILE *out,*prev;
	
	long no_of_gridy,no_of_gridx;
	
	//initialization
	for(i=0;i<=X;i++)
		for(j=0;j<=Y;j++)
		{	ARR1[i][j]=(-1); 
			NETMAT[i][j]=0;
		}
	
	//initialization end
	
	out=fopen("TEST_FLARE.txt","w");
	fprintf(out," X = %ld, Y = %ld, track = %ld",X,Y,tr);
	//point insertion
	fprintf(out,"\n INSERTED POINTS\n------------------------------------\n");
	srand ( time(NULL) );
	for(i=0;i<NET;i++)
	{
		while(1)
		{
			no_of_points=rand();
			no_of_points=no_of_points%5;// numeric is the upper bound of points
			if(no_of_points>1)// numeric is the lower bound of points
				break;
		}	
		len[i]=no_of_points;
		for(j=0;j<no_of_points;j++)
		{
			while(1)
			{
				valid_x=randum(1,X*Y);
				//valid_y=randum(1,Y);
				valid_y=(valid_x/X)+1;
				valid_x=(valid_x%Y)+1;
				
				if(ARR1[valid_x][valid_y]<0)//arr[x][y]<0 means it is -1 means not occupied
				{
					ARR1[valid_x][valid_y]=i+1;//net no. is inserted in the place arr[x][y]
					NETMAT[valid_x][valid_y]=1;
					break;
				}
			}
			netx[i][j]=valid_x;
			nety[i][j]=valid_y;
			
			fprintf(out," [ %ld,%ld ]",netx[i][j],nety[i][j]);
		}
		
		fprintf(out,"\n");
	}
	//point insertion end
	
	
	//sorting
	fprintf(out,"\n\n");
	fprintf(out,"\n POINTS AFTER SORTING\n------------------------------------\n");
	for(i=0;i<NET;i++)
	{
		for(j=0;(j+2)<len[i];j++)
		{
			distance=(X+Y)+2;
			targetk=0;
			for(k=j+1;k<len[i];k++)
			{
				xd=netx[i][j]-netx[i][k];
				yd=nety[i][j]-nety[i][k];
				if(xd<0)
					xd=xd*(-1);
				if(yd<0)
					yd=yd*(-1);
				d=xd+yd;
				if(d<0)
					d=d*(-1);
				if(distance > d)
				{
					distance=d;
					targetk=k;
				}
			
			}
			if(targetk>0)
			{
				tempx=netx[i][j+1];
				tempy=nety[i][j+1];
				
				netx[i][j+1]=netx[i][targetk];
				nety[i][j+1]=nety[i][targetk];

				netx[i][targetk]=tempx;
				nety[i][targetk]=tempy;
			}
		}
	}
		
	//display netx nety
	
	for(i=0;i<NET;i++)
	{
		for(j=0;j<len[i];j++)
		{
			fprintf(out," [%ld,%ld]",netx[i][j],nety[i][j]);
			
		}
		fprintf(out,"\n");
	}
	fprintf(out,"\n\n");
	//display end

	//sorting end
	
		
	//shape finding
	k=1;
	for(i=0;i<NET;i++)
	{
		for(j=0;j<(len[i]-1);j++,k++)
		{
			shape_find(netx[i][j],nety[i][j],netx[i][j+1],nety[i][j+1],k,X,Y);
			
		}
	}
	//shape finding end
	printf("\nTotal no. of subnets = %ld\n",k-1);
	
	//dispaly shape
	long c=0;
	for(i=1;i<k;i++)
	{
		for(j=1;MAT[i][j]!=NULL;j++,c++)
		{
			fprintf(out,"\nX%ld_%ld      %.2f\n-------------------------------------\n %ld %ld\n %ld %ld\n %ld %ld\n %ld %ld\n\n\n ",i,j,MAT[i][j]->priority,MAT[i][j]->x1,MAT[i][j]->y1,MAT[i][j]->x2,MAT[i][j]->y2,MAT[i][j]->x3,MAT[i][j]->y3,MAT[i][j]->x4,MAT[i][j]->y4);
		}
	}
	fprintf(out,"\n total vaiables = %ld\n\n",c);
	//display shape end
	
	//density finding
	
	no_of_gridx=X/tr;
	no_of_gridy=Y/tr;
	//struct grid *GMAT[no_of_gridx][no_of_gridy];
	
	
	for(i=1;i<=no_of_gridx;i++)
	{
		for(j=1;j<=no_of_gridy;j++)
		{
			//total density of a grid 
			if((i==1 && j==1) || (i==no_of_gridx && j==no_of_gridy) || (i==1 && j==no_of_gridy) || (i==no_of_gridx && j==1))
			{
				GMAT[i][j]=(struct grid *)malloc(sizeof(struct grid));
				GMAT[i][j]->Tcapacity=(2*tr*tr)-2*(tr*0.5);//total capacity of a inner grid & no. of track unit less in an corner edge.
			}
			else
			{
				if((i==1 && j!= 1 && j!=no_of_gridy) || (j==1 && i!= 1 && i!=no_of_gridx))
				{
					GMAT[i][j]=(struct grid *)malloc(sizeof(struct grid));
					GMAT[i][j]->Tcapacity=(2*tr*tr)-(tr*0.5);// if grid is not inner & not corner then tr track unit will less from capacity.
				}
				else
				{
					GMAT[i][j]=(struct grid *)malloc(sizeof(struct grid));
					GMAT[i][j]->Tcapacity=2*tr*tr;//if grid is inner grid then the total capacity.
				}
			}
			//total density of a grid end
			
			
			
			GMAT[i][j]->GS=density_find(X,Y,k,i,j,tr);//find the density of a shape in a grid
			
		}
	}
	
	//gaussian density
	
	float gaussMAT[no_of_gridx][no_of_gridy];
	float a=1,density;
	float sigmax=no_of_gridx,sigmay=no_of_gridy;
	
	
	for(i=(no_of_gridx/2)*(-1);i<=(no_of_gridx/2);i++)
	{
		for(j=(no_of_gridy/2)*(-1);j<=(no_of_gridy/2);j++)
		{
			density=(-0.5)*((2*i/sigmax)*(2*i/sigmax) + (2*j/sigmay)*(2*j/sigmay));
			density=a*expf( density );
			gaussMAT[i+1+(no_of_gridx/2)][j+1+(no_of_gridy/2)]=density;
	  
		}
		
	}
	//gaussian density end
	
	//density finding end
	fclose(out);
	
	//problem formulation
	struct grid_seg *ptr;
	out=fopen("prob_form_my.lp","w");
	prev=fopen("prob_form_prev.lp","w");
	
	fprintf(out,"\n\n/*expression*/\n\n");
	fprintf(prev,"\n\n/*expression*/\n\n");
	fprintf(out," max: ");
	for(i=1;i<=k;i++)
	{
		for(j=1;MAT[i][j]!=NULL;j++)
		{
			if(MAT[i][j]->priority!=0)
			{
				fprintf(out,"+ %f*X%ld_%ld ",MAT[i][j]->priority,i,j);
				fprintf(prev,"+ %f*X%ld_%ld ",MAT[i][j]->priority,i,j);
			}	
		}
	}
	fprintf(out,";\n\n\n");
	fprintf(prev,";\n\n\n");
	
	fprintf(out,"\n\n/*subject to */\n \n\n");
	fprintf(prev,"\n\n/*subject to */\n \n\n");
	for(i=1;i<k;i++)
	{
		if(MAT[i][1]!=NULL)
		{
			fprintf(out,"  con%ld:  ",i);
			fprintf(prev,"  con%ld:  ",i);
			for(j=1;MAT[i][j]!=NULL;j++)
			{
				fprintf(out,"+ X%ld_%ld ",i,j);
				fprintf(prev,"+ X%ld_%ld ",i,j);
			}
			fprintf(out," <= 1;\n\n");
			fprintf(prev," <= 1;\n\n");
		}
	}
	for(i=1;i<=no_of_gridx;i++)
	{
		for(j=1;j<=no_of_gridy;j++)
		{
			fprintf(out,"  con%ld_%ld: + 0 X1_1 ",i,j);
			fprintf(prev,"  con%ld_%ld: + 0 X1_1 ",i,j);
			ptr=GMAT[i][j]->GS;
			for(;ptr!=NULL;ptr=ptr->nxt)
			{
				if(ptr->capacity!=0)	
				{
					fprintf(out,"+ %f X%ld_%ld ",ptr->capacity,ptr->mati,ptr->matj);
					fprintf(prev,"+ %f X%ld_%ld ",ptr->capacity,ptr->mati,ptr->matj);
				}
			}
			//fprintf(out," <= %f ;\n\n",GMAT[i][j]->Tcapacity);
			fprintf(out," <= %f ;\n\n",GMAT[i][j]->Tcapacity*gaussMAT[i][j]);
			fprintf(prev," <= %f ;\n\n",GMAT[i][j]->Tcapacity);
		}
	}
	fprintf(out,"\n \n");
	fprintf(prev,"\n \n");
	
	
	fprintf(out,"\n\n/*variables*/\n\n");
	fprintf(prev,"\n\n/*variables*/\n\n");
	for(i=1;i<=k;i++)
	{
		for(j=1;MAT[i][j]!=NULL;j++)
		{
			fprintf(out,"bin X%ld_%ld;\n",i,j);
			fprintf(prev,"bin X%ld_%ld;\n",i,j);
		}
	}
	fprintf(out," ");
	fprintf(prev," ");
	fclose(out);
	fclose(prev);
	//problem formulation end
	
}


long char_to_num(char num[])
{
	long i,num1,num2;
	for(i=0,num1=0;num[i]!='\0';i++)
	{
		num2=num[i];
		num2-=48;
		num1=num1*10+num2;
		
	}
	return(num1);
}
void collectXij()
{
	char ch,s[10];
	long mati,matj,i,connect=0,disconnect=0;
	FILE *f;
	f=fopen("lp_my.txt","r");
	for(ch=fgetc(f);ch!='X';ch=fgetc(f))
	{ }
	for(;ch!=EOF;ch=fgetc(f))
	{
		if(ch=='X')
		{
			ch=fgetc(f);
			for(i=0;ch!='_';i++)
			{
				s[i]=ch;
				ch=fgetc(f);
			}
			s[i]='\0';
			mati=char_to_num(s);
			ch=fgetc(f);
			for(i=0;ch!=' ';i++)
			{
				s[i]=ch;
				ch=fgetc(f);
			}
			s[i]='\0';
			matj=char_to_num(s);
			
			
		}
				
		if(ch=='1')
		{
			MAT[mati][matj]->select=1;
			connect++;
			//printf("\n X%ld_%ld",mati,matj);
		}
		if(ch=='0')
			disconnect++;
		//printf(".");
	}
	//printf("\n");
	printf("\n my connected net = %ld\n my disconnected net = %ld",connect,disconnect);
	fclose(f);
}


void collectXij_prev()
{
	char ch,s[10];
	long mati,matj,i,connect=0,disconnect=0;
	FILE *f;
	f=fopen("lp_prev.txt","r");
	for(ch=fgetc(f);ch!='X';ch=fgetc(f))
	{ }
	for(;ch!=EOF;ch=fgetc(f))
	{
		if(ch=='X')
		{
			ch=fgetc(f);
			for(i=0;ch!='_';i++)
			{
				s[i]=ch;
				ch=fgetc(f);
			}
			s[i]='\0';
			mati=char_to_num(s);
			ch=fgetc(f);
			for(i=0;ch!=' ';i++)
			{
				s[i]=ch;
				ch=fgetc(f);
			}
			s[i]='\0';
			matj=char_to_num(s);
			
			
		}
				
		if(ch=='1')
		{
			MAT[mati][matj]->select_prev=1;
			connect++;
			//printf("\n X%ld_%ld",mati,matj);
		}
		if(ch=='0')
			disconnect++;
		//printf(".");
	}
	//printf("\n");
	printf("\n prev connected net = %ld\n prev disconnected net = %ld",connect,disconnect);
	fclose(f);
}

void flaremap(long m, long n)
{
	long i,j,mati,matj;
	float PSF[m][n],Vden[m][n],capcount,cal;
	struct grid_seg *segptr;
	char c,fc,pc;
	FILE *f;
	//vacancy density
	f=fopen("sci_my.sce","w");
	fprintf(f,"\n");
	fprintf(f,"DV=[");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			capcount=0;
			segptr=GMAT[i][j]->GS;
			
			for(;segptr!=NULL;segptr=segptr->nxt)
			{ 
				mati=segptr->mati;
				matj=segptr->matj;
				if(MAT[mati][matj]->select==1)
				{
					  capcount+=(segptr->capacity);
				}
			}
			
			Vden[i][j]=(GMAT[i][j]->Tcapacity)-capcount;
			fprintf(f,"  %f",Vden[i][j]);
		}
		if(i!=m)
			fprintf(f,";");
		
	}
	fprintf(f,"];\n\n");
	//vacancy density end
	
	
	//PSF calculation
	fprintf(f,"PSF=[");
	float a=0.25,k;
	k=(2*3.41)/500;//cheak it out
		
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cal=(-1)*(a*k*k*((m*m)+(n*n)));
			PSF[i][j]=expf(cal);
			fprintf(f," %f",PSF[i][j]);
		}
		if(i!=m)
			fprintf(f,";");
		
	}
	
	fprintf(f,"];\n\n");
	//PSF calculation end
	fprintf(f,"[F]=conv2(PSF, DV );\n");
	fprintf(f,"[F]=[F]/max([F]);\n");
	fprintf(f,"St=st_deviation([F]);\n");
	fprintf(f,"disp(St);\n");
	fclose(f);
}
void flaremap_prev(long m, long n)
{
	long i,j,mati,matj;
	float PSF[m][n],Vden[m][n],capcount,cal;
	struct grid_seg *segptr;
	char c,fc,pc;
	FILE *f;
	//vacancy density
	f=fopen("sci_prev.sce","w");
	fprintf(f,"\n");
	fprintf(f,"DV=[");
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			capcount=0;
			segptr=GMAT[i][j]->GS;
			
			for(;segptr!=NULL;segptr=segptr->nxt)
			{ 
				mati=segptr->mati;
				matj=segptr->matj;
				if(MAT[mati][matj]->select_prev==1)
				{
					  capcount+=(segptr->capacity);
				}
			}
			
			Vden[i][j]=(GMAT[i][j]->Tcapacity)-capcount;
			fprintf(f,"  %f",Vden[i][j]);
		}
		if(i!=m)
			fprintf(f,";");
		
	}
	fprintf(f,"];\n\n");
	//vacancy density end
	
	
	//PSF calculation
	fprintf(f,"PSF=[");
	float a=0.25,k;
	k=(2*3.41)/500;//cheak it out
		
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			cal=(-1)*(a*k*k*((m*m)+(n*n)));
			PSF[i][j]=expf(cal);
			fprintf(f," %f",PSF[i][j]);
		}
		if(i!=m)
			fprintf(f,";");
		
	}
	
	fprintf(f,"];\n\n");
	//PSF calculation end
	fprintf(f,"[F]=conv2(PSF, DV );\n");
	fprintf(f,"[F]=[F]/max([F]);\n");
	fprintf(f,"St=st_deviation([F]);\n");
	fprintf(f,"disp(St);\n");
	fclose(f);
}

void main(int arg,char *num[])
{
	
	long X,Y,NET,tr,m,n;
	X=char_to_num(num[1]);
	Y=char_to_num(num[2]);
	NET=char_to_num(num[3]);
	tr=char_to_num(num[4]);
	printf("\n Formulating...\n");
	net(X,Y,NET,tr);
	printf("\n Formulation complete\n");
	
	printf("\n solving by lp_solve...\n");
	
	system("lp_solve -s prob_form_my.lp > lp_my.txt");
	system("lp_solve -s prob_form_prev.lp > lp_prev.txt");
	
	printf("\n solved\n");
	
	printf("\n data gathering...\n");
	collectXij();
	collectXij_prev();
	printf("\n data gathering end\n");
	
	m=(X/tr)+(X%tr);
	n=(Y/tr)+(Y%tr);
	printf("\n calculating flare...\n");
	flaremap(m,n);
	flaremap_prev(m,n);
	printf("\n done.\n");
}
