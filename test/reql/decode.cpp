// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./reql/decode.hpp"

#include <string>

TEST_CASE("decode errors", "[reql][decode]") {
  SECTION("empty string") {
    const uint32_t size = 1;
    uint8_t src[size] = "";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("unterminated null") {
    const uint32_t size = 4;
    uint8_t src[size] = "nul";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("unterminated object") {
    const uint32_t size = 2;
    uint8_t src[size] = "{";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("unterminated array") {
    const uint32_t size = 12;
    uint8_t src[size] = "[{}, [], 10";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }
}

TEST_CASE("decode values", "[c][decode]") {
  SECTION("null") {
    const uint32_t size = 6;
    uint8_t src[size] = " null";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("true") {
    const uint32_t size = 6;
    uint8_t src[size] = "true ";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("false") {
    const uint32_t size = 6;
    uint8_t src[size] = "false";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("number") {
    const uint32_t size = 6;
    uint8_t src[size] = "12345";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("string") {
    const uint32_t size = 6;
    uint8_t src[size] = "\"hi!\"";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("array") {
    SECTION("one") {
      const uint32_t size = 7;
      uint8_t src[size] = "[true]";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }

    SECTION("two") {
      const uint32_t size = 7;
      uint8_t src[size] = "[[[]]]";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }

    SECTION("three") {
      const uint32_t size = 7;
      uint8_t src[size] = "[[{}]]";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }
  }

  SECTION("object") {
    SECTION("one") {
      const uint32_t size = 10;
      uint8_t src[size] = "{\"key\":0}";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }

    SECTION("two") {
      const uint32_t size = 10;
      uint8_t src[size] = "{\"\":[{}]}";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }

    SECTION("three") {
      const uint32_t size = 10;
      uint8_t src[size] = "{\"\":\"\"}";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }

    SECTION("four") {
      const uint32_t size = 13;
      uint8_t src[size] = "{\"\":{\"\":\"\"}}";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }

    SECTION("five") {
      const uint32_t size = 20;
      uint8_t src[size] = "{\"\":[{\"\":{\"\":\"\"}}]}";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }

    SECTION("six") {
      const uint32_t size = 27;
      uint8_t src[size] = "{\"\":[{\"\":[{\"\":{\"\":\"\"}}]}]}";

      Parser parser;
      reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

      std::vector<Event> expected({Event("start_parse"), Event("error")});

      REQUIRE(expected == parser.p_events);
    }
  }
}

TEST_CASE("decode term", "[c][decode]") {
  SECTION("term fake") {
    const uint32_t size = 95;
    uint8_t src[size] = "[1, [[15, [[30], [17], [12, [13.7, 15.4, 16.8], {}]], {\"key\": \"value\", \"other\":  false}]], {}]";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }

  SECTION("term one") {
    const uint32_t size = 148;
    uint8_t src[size] = "{\"t\":1,\"r\":[{\"config_changes\":[{\"new_val\":{\"id\":\"32f1b212-1a27-4c62-97e3-5ac85a4786d0\",\"name\":\"libReQL\"},\"old_val\":null}],\"dbs_created\":1}],\"n\":[]}";

    Parser parser;
    reql_decode(std::basic_string<ReQL_Byte>(src, size), parser.get_parser());

    std::vector<Event> expected({Event("start_parse"), Event("error")});

    REQUIRE(expected == parser.p_events);
  }
}
