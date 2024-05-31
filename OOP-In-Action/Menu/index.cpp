#include "./menu.hpp"

inline void say(const char* msg) { std::cout << msg; }

int main()
{
  say("\nChoose your favorite cat breed :-)\n");
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


