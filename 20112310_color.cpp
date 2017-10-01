#include<iostream>
using namespace std;
void divide(int **paper, int lowcol);
int result[2]={0,0};//white, red
int main(){
	int lowcol;
	cin>>lowcol;
	int* paper[lowcol];
	for(int i=0; i<lowcol; i++){
		paper[i]=new int[lowcol];
	}
	for(int i=0; i<lowcol; i++){
		for(int j=0; j<lowcol; j++){
			cin>>paper[i][j];
		}
	}
	divide(paper, lowcol);
	cout<<result[0]<<endl;
	cout<<result[1]<<endl;
}

void divide(int **paper, int lowcol){
	int half=lowcol/2;
	int * one[half];//lefttop
	int * two[half];//righttop
	int * three[half];//leftbottom
	int * four[half];//rightbottom
	for(int i=0; i<half; i++){
		one[i]=new int[half];
		two[i]=new int[half];
		three[i]=new int[half];
		four[i]=new int[half];
	}
	for(int i=0; i<half; i++){
		for(int j=0; j<half; j++){
			one[i][j]=paper[i][j];
			two[i][j]=paper[i][half+j];
			three[i][j]=paper[half+i][j];
			four[i][j]=paper[half+i][half+j];
		}
	}
	if(half==1){
		result[one[0][0]]++;
		result[two[0][0]]++;
		result[three[0][0]]++;
		result[four[0][0]]++;
	}
	else{
		bool oneone=true, twotwo=true, threethree=true, fourfour=true;
		for(int i=0; i<half; i++){
			for(int j=0; j<half; j++){
				if(one[0][0]!=one[i][j])
					oneone=false;
				if(two[0][0]!=two[i][j])
					twotwo=false;
				if(three[0][0]!=three[i][j])
					threethree=false;
				if(four[0][0]!=four[i][j])
					fourfour=false;
			}
		}
		if(oneone)
			result[one[0][0]]++;
		else
			divide(one, half);

		if(twotwo)
			result[two[0][0]]++;
		else
			divide(two, half);

		if(threethree)
			result[three[0][0]]++;
		else
			divide(three, half);

		if(fourfour)
			result[four[0][0]]++;
		else
			divide(four, half);
	}

	/*for(int i=0; i<half; i++){
          for(int j=0; j<half; j++){
              cout<<one[i][j]<<" ";
          }
          cout<<endl;
      }

	for(int i=0; i<half; i++){
            for(int j=0; j<half; j++){
                cout<<two[i][j]<<" ";
            }
            cout<<endl;
        }
	for(int i=0; i<half; i++){
            for(int j=0; j<half; j++){
                cout<<three[i][j]<<" ";
            }
            cout<<endl;
        }
	for(int i=0; i<half; i++){
            for(int j=0; j<half; j++){
                cout<<four[i][j]<<" ";
            }
            cout<<endl;
        }*/
	

}


