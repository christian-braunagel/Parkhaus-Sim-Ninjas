/*mit diesem File können wir fürs implementieren die einzelnen Funktionen unserer Files einmal testen.
Ruft im richtigen Block einfach die Funktionen auf die ihr testen wollt und lasst euch den return 
ausprinten.*/

#include "../include/queue.h"
#include "../include/vehicle.h"
#include "../include/parkhaus.h"
#include "../include/statistics.h"
#include "../include/sim_parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * @brief Unit tests for the functions in queue.c
 * 
 * This function tests the following functions:
 * - init_queue
 * - enqueue
 * - dequeue
 * - free_queue
 * 
 */
void queue_test(){
    //init_queue test
    queue *my_queue = init_queue();
    assert(my_queue != NULL);
    
    //enqueue test
    assert(enqueue(my_queue, 1, 5, 1) == 0);
    assert(enqueue(my_queue, -100, 5, -1) == -1);   //test invalid input parameters, should return -1
    my_queue = NULL;                                 //reset the queue for the next test
    assert(enqueue(my_queue, 2, 3, 3) == -1);       //test for invalid queue pointer

    //dequeue test
    assert(dequeue(my_queue) == NULL);              //test for NULL queue pointer, should return NULL
    my_queue = init_queue();
    assert(dequeue(my_queue) == NULL);              //test for empty queue, should return NULL
    enqueue(my_queue, 1, 5, 1);
    assert(dequeue(my_queue)->vehicle_id == 1);     //test for correct dequeue

    //print_queue test will not be tested here because it only prints the queue and does not return any value, so we would have to check the output manually, which is not ideal for automated testing. (Was manualy tested and works as expected)

    //test freeing the queue
    assert(free_queue(&my_queue) == 0);             //test for successful freeing
    assert(my_queue == NULL);                       //check if the original queue pointer is set to NULL
    my_queue = NULL;
    assert(free_queue(&my_queue) == -1);            //test for invalid queue pointer, should return -1
}

void parkhaus_test(){

}

void updateStats_test(){
    stats test_stats = {0};

    updateStats (&test_stats, 4, 3, 3, 18, 0, 25, 46);

    assert(test_stats.max_wait_time == 0);
    assert(test_stats.max_length_queue == 18);
    assert(test_stats.sum_cars_in == 3);
    aasert(test_stats.sum_cars_out == 3);
    assert(test_stats.sum_parkhaus_auslastung == 4);
    assert(test_stats.sum_wait_time == 0);
    assert(test_stats.sum_length_queue == 18);

    updateStats(&test_stats, 14, 55, 2, 5, 4, 33, 0);

    assert(test_stats.max_wait_time == 4);
    assert(test_stats.max_length_queue == 18);
    assert(test_stats.sum_cars_in == 58);
    aasert(test_stats.sum_cars_out == 5);
    assert(test_stats.sum_parkhaus_auslastung == 18);
    assert(test_stats.sum_wait_time == 4);
    assert(test_stats.sum_length_queue == 23);
}

void printfinalStats_test (){
    
}

void sim_parameters_test(){

}
int main(){
    queue_test();
    //parkhaus_test();
    //statistics_test();
    //sim_parameters_test();
}