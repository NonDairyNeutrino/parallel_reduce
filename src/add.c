#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

float add_many(int num_count, float* num_vector) {
    float sum = 0.;

    for(int i = 0; i < num_count; i++) {
        sum += num_vector[i];
    }
    return sum;
}

// parallel implementation
struct Adder {
    int   id;
    float a;
    float b;
    float sum;
};

void* add(void* adder_void){
    // printf("Adding on thread %lu\n", pthread_self());
    struct Adder* adder = (struct Adder*)adder_void;
    (adder -> sum) = (adder -> a) + (adder -> b);
    printf("Thread %lu executing adder %d\n", pthread_self(), adder -> id);
	return NULL;
}

float add_many_pthread(int num_count, float* num_vector) {
    pthread_t main_thread_id = pthread_self();
    if(num_count != 1){
        int thread_count = num_count % 2 == 0 ? num_count / 2 : (num_count - 1) / 2;
        int adder_count  = thread_count; // purely for clarity
        printf("Launching %d threads.\n", thread_count);
        pthread_t threads[thread_count];

        // initialize Adders
        struct Adder adders[adder_count];
        // TODO: if num_count is odd, don't create the last adder
        for(int i = 0; i < (num_count % 2 == 0 ? num_count : num_count - 1); i = i + 2){
            int  id = i/2;
            float a = num_vector[i];
            float b = num_vector[i+1];
            adders[i/2] = (struct Adder){id, a, b, 0};
            printf("Adder %d created with: a = %f, b = %f\n", adders[i/2].id, adders[i/2].a, adders[i/2].b);
        }

        // create threads to evaluate adding
        for(int i = 0; i < thread_count; i++) {
            pthread_create(&threads[i], NULL, add, (void*)&adders[i]);
        }

        // sync/join all threads
        for(int i = 0; i < thread_count; i++){
            pthread_join(threads[i], NULL); 
        }
        printf("%d threads joined.\n", thread_count);

        // if there are an odd number of arguments
        // pad sums on the right with the final number
        float sums[num_count % 2 == 0 ? adder_count : adder_count + 1];
        for(int i = 0; i < adder_count; i++){
            sums[i] = adders[i].sum;
        }
        if(num_count % 2 != 0){
            sums[adder_count] = num_vector[num_count - 1];
            // printf("%f\n", sums[adder_count]);
        }

        return add_many_pthread(num_count % 2 == 0 ? thread_count : thread_count + 1, sums);
    } else {
        return num_vector[0];
    }
}

