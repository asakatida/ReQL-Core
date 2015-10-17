// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./reql/decode.hpp"

#include <string>

class Parser;

template <typename type>
int
_add(ReQL_Parse_t *, type, size_t);

template <typename type>
int
_add(ReQL_Parse_t *, type);

int
_add(ReQL_Parse_t *);

int
_end_array(ReQL_Parse_t *);

int
_end_element(ReQL_Parse_t *);

int
_end_key_value(ReQL_Parse_t *, const char *, size_t);

int
_end_object(ReQL_Parse_t *);

int
_end_parse(ReQL_Parse_t *);

void
_error(ReQL_Parse_t *);

int
_start_array(ReQL_Parse_t *);

int
_start_element(ReQL_Parse_t *);

int
_start_key_value(ReQL_Parse_t *);

int
_start_object(ReQL_Parse_t *);

int
_start_parse(ReQL_Parse_t *);

class Event {
public:
  Event(std::string name) : p_name(name) {}
  Event(std::string name, bool val) : p_bool(val), p_name(name) {}
  Event(std::string name, std::string val) : p_name(name), p_str(val) {}
  Event(std::string name, double val) : p_name(name), p_num(val) {}

  bool operator==(const Event &other) const {
    return p_bool == other.p_bool &&
      p_name == other.p_name &&
      p_num == Approx(other.p_num) &&
      p_str == other.p_str;
  }

  bool p_bool;
  std::string p_name;
  double p_num;
  std::string p_str;
};

class Parser {
public:
  Parser() : p_events(), p_parser(new ReQL_Parse_t()) {
    p_parser->add_bool = _add;
    p_parser->add_null = _add;
    p_parser->add_number = _add;
    p_parser->add_string = _add;
    p_parser->data = this;
    p_parser->end_array = _end_array;
    p_parser->end_element = _end_element;
    p_parser->end_key_value = _end_key_value;
    p_parser->end_object = _end_object;
    p_parser->end_parse = _end_parse;
    p_parser->error = _error;
    p_parser->start_array = _start_array;
    p_parser->start_element = _start_element;
    p_parser->start_key_value = _start_key_value;
    p_parser->start_object = _start_object;
    p_parser->start_parse = _start_parse;
  }

  ~Parser() {
    delete p_parser;
  }

  ReQL_Parse_t *get_parser() {
    return p_parser;
  }

  void add() {
    p_events.push_back(Event("add"));
  }

  template<typename type>
  void add(type val) {
    p_events.push_back(Event("add", val));
  }

  void end_array() {
    p_events.push_back(Event("end_array"));
  }

  void end_element() {
    p_events.push_back(Event("end_element"));
  }

  void end_key_value(std::string key) {
    p_events.push_back(Event("end_key_value", key));
  }

  void end_object() {
    p_events.push_back(Event("end_object"));
  }

  void end_parse() {
    p_events.push_back(Event("end_parse"));
  }

  void error() {
    p_events.push_back(Event("error"));
  }

  void start_array() {
    p_events.push_back(Event("start_array"));
  }

  void start_element() {
    p_events.push_back(Event("start_element"));
  }
  
  void start_key_value() {
    p_events.push_back(Event("start_key_value"));
  }
  
  void start_object() {
    p_events.push_back(Event("start_object"));
  }
  
  void start_parse() {
    p_events.push_back(Event("start_parse"));
  }
  
  std::vector<Event> p_events;

private:
  ReQL_Parse_t *p_parser;
};

template <typename type>
int _add(ReQL_Parse_t *p, type val, size_t length) {
  try {
    reinterpret_cast<Parser *>(p->data)->add(std::string(val, length));
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

template <typename type>
int _add(ReQL_Parse_t *p, type val) {
  try {
    reinterpret_cast<Parser *>(p->data)->add(static_cast<bool>(val));
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_add(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->add();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_end_array(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->end_array();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_end_element(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->end_element();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_end_key_value(ReQL_Parse_t *p, const char *key, size_t length) {
  try {
    reinterpret_cast<Parser *>(p->data)->end_key_value(std::string(key, length));
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_end_object(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->end_object();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_end_parse(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->end_parse();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

void
_error(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->error();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_start_array(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->start_array();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_start_element(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->start_element();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_start_key_value(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->start_key_value();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_start_object(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->start_object();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

int
_start_parse(ReQL_Parse_t *p) {
  try {
    reinterpret_cast<Parser *>(p->data)->start_parse();
  } catch (std::exception) {
    return -1;
  }
  return 0;
}

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
