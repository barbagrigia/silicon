#include <iostream>
#include <iod/symbol.hh>
#include <silicon/microhttpd_serve.hh>
#include <silicon/api.hh>

auto api = sl::make_api(

  @test = [] () { return D(@message = "hello world."); },
  @test2(@name) = [] (const auto& p) { return iod::D(@message = std::string("hello " + p.name)); },
  @test3 = [] (sl::microhttpd_response* r) {
    r->body = "{\"message\":\"hello world.\"}";
  }

);

int main(int argc, char* argv[])
{
  sl::microhttpd_json_serve(api, atoi(argv[1]));
}
