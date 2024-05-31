#include <iostream>
#include <vector>
#include <functional>
#include <string>

template <class... T>
class OutputAdapter
{
public:
  virtual void out(std::ostream &out, T... args) = 0;
};

class Menu
{

protected:
  typedef std::function<void()> action_type;
  typedef std::pair<std::string, std::function<void()>> option_type;

public:
  /**
   * @brief Default Construct
   */
  Menu() : output_adapter(nullptr){};

  /**
   * @brief Construct a new Menu object
   * @param map
   */
  Menu(std::vector<std::pair<std::string, action_type>> list) : list(std::move(list))
  {
    Menu();
  }

  /**
   * @brief attaches new option to the menu
   * @param option
   */
  Menu &attach(option_type option)
  {
    list.push_back(option);
    return *this;
  }

  /**
   * @brief attach default call back if no option match
   * @param action
   * @return Menu&
   */
  Menu &attach_default(action_type action)
  {
    has_default = true;
    default_action = action;
    return *this;
  }

  /**
   * @brief invokes option action
   * @param idx (index+1) of the option
   */
  Menu &invoke(int idx)
  {
    is_found = true;
    int itr = 1;
    for (int i = 0; i < list.size(); i += 1)
    {
      if (idx == (i + 1))
      {
        list[i].second();
        return *this;
      }
    }
    is_found = false;
    if (has_default)
      default_action();
    return *this;
  }

  /**
   * @brief returns true if last invoke call triggered some action
   * @return true
   * @return false
   */
  bool found()
  {
    return is_found;
  }

  /**
   * @brief attaches custom adapter to customize console output
   * @param adapter
   */
  Menu &attach_adapter(OutputAdapter<const int&, const std::string&> *adapter)
  {
    output_adapter = adapter;
    return *this;
  }

  /**
   * @brief renders menu to the console
   * @param out std::ofstream&
   * @param self Menu&
   * @return std::ofstream&
   */
  friend std::ostream &operator<<(std::ostream &out, Menu &self)
  {
    for (int i = 0; i < self.list.size(); i += 1)
      self.handle_console_output(i, self.list[i], out);
    return out;
  }

  /**
   * @brief gets input from user
   * @param in
   * @param self
   * @return std::istream&
   */
  friend std::istream &operator>>(std::istream &in, Menu &self)
  {
    self.handle_console_input(in);
    return in;
  }

protected:
  std::vector<std::pair<std::string, action_type>> list;
  bool is_found, has_default;
  action_type default_action;
  OutputAdapter<const int&, const std::string&> *output_adapter;

  /**
   * @brief handles console output
   * @param idx
   * @param option
   * @param out
   */
  void handle_console_output(int idx, const option_type &option, std::ostream &out)
  {
    if (output_adapter != nullptr)
      return output_adapter->out(out, idx, option.first);
    out << (idx + 1) << " - " << option.first << "\n";
  }

  /**
   * @brief handles console input
   * @param in
   */
  void handle_console_input(std::istream &in)
  {
    int selectedIdx = -1;
    do
    {
      in.clear(); // clear previous buffer
      in.sync();  // reset flags
      in >> selectedIdx;
    } while (in.fail());
    invoke(selectedIdx);
  }
};
