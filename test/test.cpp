// Copyright 2015 Adam Grandquist

#include "./catch.hpp"
#include "./test.hpp"
#include "./reql/types.h"

void
reql_test_cur_end_cb(void *data) {
  *static_cast<int*>(data) = 0;
}

void
reql_test_cur_error_cb(void *res, void *data) {
  if (res != nullptr) {
    *static_cast<int*>(data) = 0;
  }
}

int
reql_test_cur_each_cb(void *res, void *data) {
  if (res != nullptr) {
    ++(*static_cast<int*>(data));
  }
  return res == nullptr;
}

int
reql_test_cur_each_inf_cb(void *res, void *data) {
  int *num = static_cast<int*>(data);
  if (res != nullptr) {
    ++(*num);
  }
  if (*num > 99) {
    return 1;
  }
  return 0;
}

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

  Event::Event(std::string name) : p_name(name) {}
  Event::Event(std::string name, bool val) : p_bool(val), p_name(name) {}
  Event::Event(std::string name, std::string val) : p_name(name), p_str(val) {}
  Event::Event(std::string name, double val) : p_name(name), p_num(val) {}

  bool Event::operator==(const Event &other) const {
    return p_bool == other.p_bool &&
      p_name == other.p_name &&
      p_num == Approx(other.p_num) &&
      p_str == other.p_str;
  }

Parser::Parser() : p_events(), p_parser(new ReQL_Parse_t()) {
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

  Parser::~Parser() {
    delete p_parser;
  }

  ReQL_Parse_t *Parser::get_parser() {
    return p_parser;
  }

  void Parser::add() {
    p_events.push_back(Event("add"));
  }

  void Parser::end_array() {
    p_events.push_back(Event("end_array"));
  }

  void Parser::end_element() {
    p_events.push_back(Event("end_element"));
  }

  void Parser::end_key_value(std::string key) {
    p_events.push_back(Event("end_key_value", key));
  }

  void Parser::end_object() {
    p_events.push_back(Event("end_object"));
  }

  void Parser::end_parse() {
    p_events.push_back(Event("end_parse"));
  }

  void Parser::error() {
    p_events.push_back(Event("error"));
  }

  void Parser::start_array() {
    p_events.push_back(Event("start_array"));
  }

  void Parser::start_element() {
    p_events.push_back(Event("start_element"));
  }

  void Parser::start_key_value() {
    p_events.push_back(Event("start_key_value"));
  }

  void Parser::start_object() {
    p_events.push_back(Event("start_object"));
  }

  void Parser::start_parse() {
    p_events.push_back(Event("start_parse"));
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
  }
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
