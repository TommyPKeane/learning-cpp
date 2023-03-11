#include <iostream>
#include <string>


int main()
{
   // Get access to the `""s` operator for String Literal Creation
   using namespace std::literals;

   // Creating a string using string literal
   std::string first_name = "First"s;
   auto last_name = "Last"s;

   // Combine Strings to a new String
   auto full_name = first_name + " M. " + last_name;

   // Send the full String to the stdout Buffer (print on the commandline)
   std::cout
      << "\"👋 Hello, "
      << full_name
      << "! Welcome to C++ and the world of Strings!\""
      << std::endl;
}
