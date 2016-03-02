#include <iostream>
#include <fstream>

#include <silicon/api.hh>
#include <silicon/backends/mhd.hh>

#include "symbols.hh"

int main()
{

  using namespace sl;
  using namespace s;

  // Create an api
  auto api = http_api(

    _hello * get_parameters(_name) = [] (auto p) { return D(_message = "hello " + p.name); }

    );

  // Serve it using cppnetlib and the json protocol.
  mhd_json_serve(api, 9999);
}
