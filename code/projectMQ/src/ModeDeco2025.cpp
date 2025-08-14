// // https://mp.weixin.qq.com/s?src=11&timestamp=1740029914&ver=5823&signature=L4l7MrE5*1Ag0qFEjxO6zTvnp*NRYbbjPqeQxBUQzo-pTIedqsA2E5q9ax9yLE4oU9R6RDh1RL5p1CQnfE-1mkdRjTHP3*ZSh6wGhdGWxMIwv9IBQsUkCO3pTLSS-qyB&new=1
// //  装饰器模式，让代码从“继承地狱”跃升为“动态叠Buff大师”——你的对象，无限可能！ 🎭🚀

// //     技术深度总结：

// //     🧠 模式本质：通过组合和委托实现运行时扩展，取代编译时继承

// //     ⚙️ C++ 特性：智能指针、移动语义、模板元编程强化实现

// //     🛡️ 防御式编程：通过接口规范和类型系统约束装饰器行为

// //     🚀 性能权衡：灵活性 vs 性能，通过Benchmark决策关键路径
// #include <stdio.h>
// #include <string>
// #include <iostream>
// #include <memory>
// using namespace std;

// class Coffee
// {

// public:
//     virtual ~Coffee() = default;

//     virtual string getDesc() const = 0;

//     virtual double cost() const = 0;
// };

// class SimpleCoffee : public Coffee
// {

// public:
//     string getDesc() const override { return "普通咖啡"; }

//     double cost() const override { return 10.0; }
// };

// class CoffeeDecorator : public Coffee
// {

// public:
//     explicit CoffeeDecorator(unique_ptr<Coffee> coffee)

//         : coffee_(move(coffee))
//     {
//     }

//     string getDesc() const override
//     {

//         return coffee_->getDesc(); // 委托给被装饰对象
//     }

//     double cost() const override
//     {

//         return coffee_->cost();
//     }

// protected:
//     unique_ptr<Coffee> coffee_;
// };

// // 加牛奶装饰器

// class MilkDecorator : public CoffeeDecorator
// {

// public:
//     using CoffeeDecorator::CoffeeDecorator;

//     string getDesc() const override
//     {

//         return coffee_->getDesc() + "+牛奶";
//     }

//     double cost() const override
//     {

//         return coffee_->cost() + 2.0;
//     }
// };

// // 加糖装饰器

// class SugarDecorator : public CoffeeDecorator
// {

// public:
//     using CoffeeDecorator::CoffeeDecorator;

//     string getDesc() const override
//     {

//         return coffee_->getDesc() + "+糖";
//     }

//     double cost() const override
//     {

//         return coffee_->cost() + 1.0;
//     }
// };

// int main(int argc, char const *argv[])
// {
//     /* code */
//     // 创建基础咖啡

//     auto coffee = make_unique<SimpleCoffee>();

//     // 动态叠加装饰（顺序自由！）

//     coffee = make_unique<MilkDecorator>(move(coffee));

//     coffee = make_unique<SugarDecorator>(move(coffee));

//     cout << coffee->getDesc(); // 输出："普通咖啡+牛奶+糖"

//     cout << coffee->cost(); // 输出：13.0

//     return 0;
// }

// Explanation:

//     Component Interface (Text): This is the base interface that defines the render() method, which is implemented by both the concrete component and the decorators.

//     Concrete Component (PlainText): This is the basic implementation of the Text interface. It simply returns the plain text content.

//     Decorator Base Class (TextDecorator): This is the base class for all decorators. It holds a reference to a Text object and delegates the render() method to it.

//     Concrete Decorators (BoldText, ItalicText, UnderlineText): These classes add additional behavior (like bold, italic, and underline) to the text by wrapping the render() method of the Text object they hold.

//     Client Code (main): The client code creates a PlainText object and then decorates it with BoldText, ItalicText, and UnderlineText. Finally, it calls the render() method to get the decorated text.

// Also look this: https://www.jb51.net/article/137305.htm

#include <iostream>
#include <string>

// Component Interface
class Text
{
public:
    virtual ~Text() = default;
    virtual std::string render() const = 0;
};

// Concrete Component
class PlainText : public Text
{
private:
    std::string content;

public:
    explicit PlainText(const std::string &content) : content(content) {}
    std::string render() const override
    {
        return content;
    }
};

// Decorator Base Class
class TextDecorator : public Text
{
protected:
    Text *text;

public:
    explicit TextDecorator(Text *text) : text(text) {}
    virtual ~TextDecorator()
    {
        delete text;
    }
};

// Concrete Decorator: Bold
class BoldText : public TextDecorator
{
public:
    explicit BoldText(Text *text) : TextDecorator(text) {}
    std::string render() const override
    {
        return "<b>" + text->render() + "</b>";
    }
};

// Concrete Decorator: Italic
class ItalicText : public TextDecorator
{
public:
    explicit ItalicText(Text *text) : TextDecorator(text) {}
    std::string render() const override
    {
        return "<i>" + text->render() + "</i>";
    }
};

// Concrete Decorator: Underline
class UnderlineText : public TextDecorator
{
public:
    explicit UnderlineText(Text *text) : TextDecorator(text) {}
    std::string render() const override
    {
        return "<u>" + text->render() + "</u>";
    }
};

int main()
{
    // Create a plain text
    Text *text = new PlainText("Hello, World!");

    // Decorate the text with bold, italic, and underline
    text = new BoldText(text);
    text = new ItalicText(text);
    text = new UnderlineText(text);

    // Render the decorated text
    std::cout << text->render() << std::endl;

    // Clean up
    delete text;

    return 0;
}