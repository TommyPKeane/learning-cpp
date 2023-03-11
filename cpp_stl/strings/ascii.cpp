#include <iostream>
#include <string>


int main()
{
   // Creating a string using string literal
   std::string first_name = "First";
   std::string last_name = "Last";

   // Combine Strings to a new String
   std::string full_name = first_name + " M. " + last_name;

   // Send the full String to the stdout Buffer (print on the commandline)
   std::cout
      << "\""
      << "👋 Hello, "
      << full_name
      << "! Welcome to C++ and the world of Strings!"
      << "\""
      << std::endl;
}
