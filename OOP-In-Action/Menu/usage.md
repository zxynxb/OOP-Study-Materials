
### Menu

A handy Menu class for prompting the user to choose from options within the menu.

**pre-req:**

- c++ cli g++ or clang
- c++ 17 or plus compiler

**Props:**

- Not need to write ungodly switch and if-else statements.
- Intuitive APIS and high code readability.
- Easy to customize and handle errors. 

![demo](https://github.com/LGUCC/OOP-Study-Materials/assets/78583049/77b615c3-c095-4a8e-bd66-e7aa4ecec384)

### Usage

```cpp
#include "./menu.hpp"

inline void say(const char* msg) { std::cout << msg; }

int main()
{
  say("\nChoose your favorite cat breed :-) \n");
  Menu menu;
  
  // attach options
  menu
  .attach({"Scottish Fold", [](){ say("Cool! i also love them!!"); }})
  .attach({"Persian", [](){ say("Hmm! They are so cute"); }})
  .attach({"Ragdoll", [](){ say("I love their blue eyes"); }})
  .attach({"I don't Like Cats", [](){ say("Oooh! How can you not like cats? They're adorable!"); }})
  .attach_default([](){ say("Never Mind :-) \n"); });
  
  // native APIS 😊
  std::cout << menu;
  say(">> "); std::cin >> menu;

  // handle on not found
  if(!menu.found()) {
    say("choose correct option to exit \n");
    main();
  } 

  return EXIT_SUCCESS;
}

```

### Customization

I make menu class in such a way so anyone can customize it easily and add their functionality on the top of it.

**Customize Console Output:**

By Default, it shows `1 - your_string`. if someone like to customize default behavior then you need to provide your custom output adaptor here is how you could implement it.

```cpp
class CatMenuAdaptor : public OutputAdapter<const int&, const std::string&> {
public:
  void out(std::ostream& out, const int& idx, const std::string& option) override {
    out << option << " ~ " << (idx + 1) << "\n";
  }
};

// in main before cout attach this as following
auto outputAdapter = new CatMenuAdaptor();
menu.attach_adapter(new CatMenuAdaptor());
```


![demo custom output](https://github.com/LGUCC/OOP-Study-Materials/assets/78583049/4c2e1d2f-8b1c-43f0-b96a-493d4b5a0d04)

### 🧪 Test

to run test run following in your terminal,

```bash
$ g++ test.cpp -o test
$ test
```

---

Happy Coding ♥

Credit: [Zain ul din](https://github.com/Zain-ul-din)
