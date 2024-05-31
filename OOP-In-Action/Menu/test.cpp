/*
  Auto Test Runner for Menu
*/

#include <iostream>
#include <cassert>
#include <sstream>

#include "./menu.hpp"

template<class... T>
std::string build_args(T... argv) {
  std::stringstream ss;
  (([&](auto arg){ ss << arg << " "; }(argv)),...);
  return ss.str();
}

int main(int argc, char* argv[]) {

  if(argc == 1) {
    // fork current process using system call
    system(build_args(argv[0], 1, 2, 4).c_str());
  } else {
    int selected_opt = -1;
    Menu menu;
    menu
    .attach({ "a", [&](){ selected_opt = 1;} })
    .attach({ "b", [&](){ selected_opt = 2;} })
    .attach({ "c", [&](){ selected_opt = 3;} })
    .attach_default( [&](){ selected_opt = 4;});
    
    std::stringstream rs;
    rs << argv[1]  << " " << argv[2] << " " << argv[3];

    int args[3] = {0, 0,0};
    std::stringstream ps(rs.str());
    ps >> args[0] >> args[1] >> args[2];

    menu.invoke(args[0]);    
    assert(selected_opt == args[0]);
    menu.invoke(args[1]);    
    assert(selected_opt == args[1]);
    menu.invoke(args[2]);    
    assert(selected_opt == args[3]);
    assert(menu.found() == false);
    
    std::cout << "All Test has been passed ✔\n";
  }
  return EXIT_SUCCESS;
}

