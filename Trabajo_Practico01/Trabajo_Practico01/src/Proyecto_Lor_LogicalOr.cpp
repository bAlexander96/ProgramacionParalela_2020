/*
 ============================================================================
 Name        : Proyecto_Lor_LogicalOr.c
 Author      : Alexander
 Version     :
 Copyright   : Your copyright notice
 Description : Calculate Pi in MPI
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(size != 4)
    {
        printf("Contara con 4 procesos.\n");

    }

    int root_rank = 0;

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    bool my_value = (my_rank == 3);
    bool reduction_result = false;
    MPI_Reduce(&my_value, &reduction_result, 1, MPI_C_BOOL, MPI_LOR, root_rank, MPI_COMM_WORLD);

    if(my_rank == root_rank)
    {
        printf("El lógico final es %s.\n", reduction_result ? "true" : "false");
    }

    MPI_Finalize();

    return EXIT_SUCCESS;
}
