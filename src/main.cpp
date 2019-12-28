#include <iostream>
#include <future>
#include <chrono>

#include <emscripten.h>
#include <emscripten/bind.h>

std::future<std::string> futureWork;

void doWork() {
    std::cout << "Welcome WASM!" << std::endl;
    std::cout << "Main thread=" << std::this_thread::get_id() << std::endl;
   
    futureWork = std::async(std::launch::async, [](){
        std::cout << "Worker thread=" << std::this_thread::get_id() << std::endl;

        int x = 0;
        while (x < 50)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            std::cout << "sleep for 200ms : count: " << x << std::endl;
            x++;
        }

        return std::string("hello from defered\n");
    });
}

std::string getWorkResult() {
    return futureWork.get();
}

EMSCRIPTEN_BINDINGS(module) {
	emscripten::function("doWork", &doWork);
    emscripten::function("getWorkResult", &getWorkResult);
}