/*#include <iostream>		
#include <string>
#include <vector> // vector
using namespace std;

struct User {
	string name;
	int score;
};

struct UserManager {
	vector<User*> userlist;
};


int main() {
	

	User userdata[3] = {
		{"이만수" , 10},
		{"이철민" , 20},
		{"김종혁" , 50}
	};
	int size = 3;

	UserManager* pum = new UserManager;

	for (int i = 0; i < size; i++) {
		pum->userlist.push_back(new User);
		pum->userlist[i]->name = userdata[i].name;
		pum->userlist[i]->score = userdata[i].score;
	}
	
	for (int i = 0; i < pum->userlist.size(); i++) {
		cout << pum->userlist[i]->name << " : ";
		cout << pum->userlist[i]->score << endl;
	}


	// 메모리해제
	for (int i = 0; i < pum->userlist.size(); i++) {
		delete pum->userlist[i];
	}
	delete[] pum;

	return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ABS(x) (((x) < 0) ? -(x) : (x))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define NUM_EXAMPLES 100

typedef struct Example
{
    float size;
    float price;
}Example;

Example *ex_list;

float th0, th1;

float getLinHypo(const float x)
{
    return th0 + th1 * x;
}

float getMeanSquareError(){
    float error_sum = 0.0f;
    for(int i = 0; i < NUM_EXAMPLES; ++i){
        const float error = ex_list[i].price
        - getLinHypo(ex_list[i].size);

        error_sum += error*error;
    }
    return error_sum / (float)NUM_EXAMPLES * 0.5f;
}

void updateOneGDStep(const float alpha){
    float dJ_dth0 = 0.0f, dJ_dth1 = 0.0f;

    for(int i = 0; i < NUM_EXAMPLES; ++i){
        const float h_minus_y = getLinHypo(ex_list[i].size)
        - ex_list[i].price;

        const float dh_dth0 = 1.0f;
        const float dh_dth1 = ex_list[i].size;

        dJ_dth0 += h_minus_y * dh_dth0;
        dJ_dth1 += h_minus_y * dh_dth1;
    }
    th0 -= alpha * dJ_dth0 / (float)NUM_EXAMPLES;
    th1 -= alpha * dJ_dth1 / (float)NUM_EXAMPLES;

}

int main(){
    //initialize examples
    ex_list = (Example*)malloc(sizeof(Example)*NUM_EXAMPLES);

    // input example from a data file
    FILE *ifp = fopen("d:/size_price_samples.txt","r");

    for(int i = 0; i < NUM_EXAMPLES; ++i){
        float size_input, price_input;
        fscanf(ifp,"%f %f", &size_input, &price_input);

        ex_list[i].size = size_input;
        ex_list[i].price = price_input;

        // check if file input is correct
        printf("%f %f\n",size_input,price_input);
    }

    fclose(ifp); // not to overwrite input file

    // find min max of input data
    float size_min = (float)1e8, size_max = -(float)1e8;
    float price_min = (float)1e8, price_max = -(float)1e8;

    for(int i = 0; i < NUM_EXAMPLES; ++i){
        size_min = MIN(size_min, ex_list[i].size);
        size_max = MAX(size_max, ex_list[i].size);

        price_min = MIN(price_min, ex_list[i].price);
        price_max = MAX(price_max, ex_list[i].price);
    }

    assert(size_max != size_min);
    assert(price_max != price_min);

    // feature scaling
    float size_scale = 1.0f / (size_max - size_min);
    float price_scale = 1.0f / (price_max - price_min);
    for(int i = 0; i < NUM_EXAMPLES; ++i){
        ex_list[i].size -= size_min;
        ex_list[i].size *= size_scale;
        ex_list[i].price -= price_min;
        ex_list[i].price *= price_scale;
    }

    // initialize hypothesis
    th0 = 0.0f;
    th1 = 0.0f;

    // gradient descent for faster optimization
    float MSE_prev = 1e8;
    float th0_prev = th0;
    float th1_prev = th1;

    int i;
    for(i = 0; i < 100; ++i){
        updateOneGDStep(1.0f);

        const float MSE = getMeanSquareError();
        const float MSE_de = MSE * (price_max - price_min) * (price_max - price_min);
        const float th0_de = (th0 - th1 * size_min * size_scale + price_min * price_scale) / price_scale;
        const float th1_de = th1 * size_scale / price_scale;

        printf("J( %.1f, %1f) = %f \n", th0_de, th1_de, MSE_de);

        if(ABS(MSE_prev) <= ABS(MSE)){
            // restore onestep
            th0 = th0_prev;
            th1 = th1_prev;

            break;
        }

        // back up variables
        MSE_prev = MSE;
        th0_prev = th0;
        th1_prev = th1;
    }

    printf("Iteration = %d \n", i);

    // print the results of the hypothesis
    FILE *fp = fopen("d:/hypothesis.txt","w");

    if(fp == NULL){
        printf("Cannot open file for writing");
    }

    for(int size = 0; size < 140; ++size){
        const float size = ((float)size - size_min) * size_scale;
        const float price_fs = getLinHypo(size) * (price_max - price_min) + price_min;
        fprintf(fp, "%.1f %.lf\n", (float)size, price_fs);
    }

    fclose(fp);
    free(ex_list);
    return 0;
}