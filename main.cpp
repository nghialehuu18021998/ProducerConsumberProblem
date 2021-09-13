//
//  main.cpp
//  ProducerConsumer
//
//  Created by Nghia Le on 10/9/21.
//

#include <iostream>
#include <thread>

using namespace std;

void printThread(int n, string str) {
    cout << str + " " << n << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int buckets[10];
    
    for(int i = 0; i < 10; i++) {
        int num = rand();
        buckets[i] = num;
        
        cout << "10 random numbers for array buckets are : " << buckets[i] << endl;
    }
    
    for (int i = 0; i < 5; i++) {
            thread t(printThread, buckets[i], "Producer thread contains number: ");
            t.join();
    }

    for (int j = 5; j < 10; j++) {
        thread t(printThread, buckets[j], "Consumer thread contains number: ");
        t.join();
    }
    
    return 0;
}
