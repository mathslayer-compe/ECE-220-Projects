#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>





sp_tuples * load_tuples(char* input_file)
{

    int row, col;
    double val;

    FILE* file=fopen(input_file, "r");

    // checking if file is empty
    if (file == NULL) {
        printf("File cannot open");
        return NULL;
    }

    // reading row and column size of array
    fscanf(file, "%d %d", &row,&col);
    sp_tuples * matrix=malloc(sizeof(sp_tuples));
    matrix->m=row;
    matrix->n=col;
    matrix->nz=0;
    matrix->tuples_head=NULL;

    // reading through all values of the file until it reaches end
    while (feof(file) == 0) {
        fscanf(file, "%d, %d, %lf\n", &row, &col, &val);
        set_tuples(matrix, row, col, val);
    }

    fclose(file);
    //set the tuples by calling set_tuples
    return matrix;
}



double gv_tuples(sp_tuples * mat_t,int row,int col)

{
    sp_tuples_node * pointer= mat_t->tuples_head;
    while(pointer!=NULL){
        if((pointer->row==row)&&(pointer->col==col)){
            return pointer->value;
        }
        pointer=pointer->next;
    }
    return 0;
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
    if(value==0){
        sp_tuples_node * pointer=mat_t->tuples_head;
        if((pointer->row==row)&&(pointer->col==col)){
            free(pointer);
            mat_t->nz--;
            mat_t->tuples_head=NULL;
        }
        while(pointer!=NULL){
            if(pointer->next==NULL){
                break;
            }
            if((pointer->next->row==row)&&(pointer->next->col==col)){
                sp_tuples_node * temp_ptr=pointer->next;
                pointer->next=temp_ptr->next;
                free(temp_ptr);
                mat_t->nz--;
            }
            pointer=pointer->next;
        }
        return;
    }
    mat_t->nz++;
    sp_tuples_node * ptr=malloc(sizeof(sp_tuples_node));
    ptr->row=row;
    ptr->col=col;
    ptr->value=value;
    sp_tuples_node* pointer=mat_t->tuples_head;
    if(pointer==NULL){
        mat_t->tuples_head=ptr;
        ptr->next=NULL;
        return;
    }
    while(pointer!=NULL){
        if((pointer->row==row)&&(pointer->col==col)){
            pointer->value=value;
            free(pointer);
            mat_t->nz--;
            return;
        }
        if(pointer->next==NULL){
            ptr->next=pointer->next;
            pointer->next=ptr;
            return;
        }
        pointer=pointer->next;
    }
}



void save_tuples(char * file_name, sp_tuples * mat_t)
{

	FILE* file=fopen(file_name, "w"); //instructions sound like this file should be overwrriten but might be read?
    fprintf(file, "%d %d\n", mat_t->m,mat_t->n);
    sp_tuples_node * pointer=mat_t->tuples_head;
    while(pointer!=NULL){
        fprintf(file, "%d %d %lf\n",pointer->row, pointer->col, pointer->value);
        pointer=pointer->next;
    }
    fclose(file);
    return;


}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB){

	sp_tuples * matC=malloc(sizeof(sp_tuples));
    matC->m=matA->m;
    matC->n=matA->n;
    matC->nz=0;
    sp_tuples_node * pointer_a=matA->tuples_head;
    while(pointer_a!=NULL){
        set_tuples(matC,pointer_a->row, pointer_a->col, pointer_a->value);
        pointer_a=pointer_a->next;
    }
    sp_tuples_node * pointer_b=matB->tuples_head;
    double valC=gv_tuples(matC, pointer_b->row, pointer_b->col);
    while(pointer_b!=NULL){
        set_tuples(matC, pointer_b->row, pointer_b->col, valC+pointer_b->value);
        pointer_b=pointer_b->next;
    }
    return matC;


}






	
void destroy_tuples(sp_tuples * mat_t){
    sp_tuples_node * head_ptr= mat_t->tuples_head;
    sp_tuples_node * ptr=NULL;
    while(head_ptr!=NULL){
        ptr=head_ptr->next;
        free(head_ptr);
        head_ptr=ptr;
    }
    free(mat_t);
    return;
    
}  






