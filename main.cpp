/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference and don't change the return type either.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(double val, const char* any) : value(val), name(any)  {}   //1
    double value;//2
    std::string name;//3
};

struct Comparison                                //4
{
    T* compare(T& a, T& b) //5
    {
        if ( a.value < b.value ) return &a;
        if ( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float doughnuts { 10 }, days { 12 };
    float doughnutsConsumed(float& totalDoughnuts)      //12
    {   
        std::cout << "uu's doughnut count: " << this->doughnuts << std::endl;
        this->doughnuts = totalDoughnuts;
        std::cout << "uu's updated doughnut count: " << this->doughnuts << std::endl;

        while( std::abs(this->days - this->doughnuts) > 0.001f )
        {
            this->doughnuts += 0.2f;
        }
        std::cout << "uu's updated Days value: " << this->days << std::endl;
        return this->days * this->doughnuts;
    }
};

struct UpdateDoughnutCount
{
    static float tallyDoughnuts(U* that, float& updatedDoughnutCount )        //10
    {
        if (that == nullptr) return 0.0f;
        
        std::cout << "U's doughnut count: " << that->doughnuts << std::endl;
        that->doughnuts = updatedDoughnutCount;
        std::cout << "U's updated doughnut count: " << that->doughnuts << std::endl;

        while( std::abs(that->days - that->doughnuts) > 0.001f )
        {
            that->doughnuts += 0.02f;
        }
        std::cout << "U's updated Days value: " << that->days << std::endl;
        return that->days * that->doughnuts;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T first(3.4, "name1");                         //6
    T second(4.5, "name2" );                       //6
    
    Comparison f;                                  //7
    auto* smaller = f.compare(first, second);      //8

    if (smaller != nullptr)
    {
        std::cout << "the smaller one is " << smaller->name << std::endl; //9
    }
    else
    {
        std::cout << "both of the arguments were of the same value " << std::endl;
    }
    
    U u;
    float updatedValue = 5.0f;
    std::cout << "[static func] u's multiplied values: " << UpdateDoughnutCount::tallyDoughnuts(&u, updatedValue) << std::endl;                  //11
    
    U uu;
    std::cout << "[member func] uu's multiplied values: " << uu.doughnutsConsumed( updatedValue ) << std::endl;
}
