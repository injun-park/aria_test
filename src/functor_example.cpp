//
// Created by ijpark on 8/21/17.
//

#include <string>
#include <Aria.h>


class CallbackContainer {
public:
    void callback1() {
        printf("CallbackContainer::callabck1()\n");
    }
    void callback2(int i) {
        printf("CallbackContainer::callabck2()\n");
    }
    void callback3(const char* str) {
        printf("CallbackContainer::callabck3()\n");
    }
};


void my_callback() {
    printf("MyCallback\n");
}

int main(int argc, char** argv) {
    CallbackContainer cb;

    ArGlobalFunctor functor(&my_callback);
    functor.invoke();


    ArFunctorC<CallbackContainer> functor0(cb, &CallbackContainer::callback1);
    functor0.invoke();

    return -1;
}

