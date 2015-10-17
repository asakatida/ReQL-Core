// Copyright 2015 Adam Grandquist

#ifndef TEST_HPP_
#define TEST_HPP_

#include "./reql/types.h"

#include <string>
#include <vector>

void
reql_test_cur_end_cb(void *data);

void
reql_test_cur_error_cb(void *res, void *data);

int
reql_test_cur_each_cb(void *res, void *data);

int
reql_test_cur_each_inf_cb(void *res, void *data);

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
  Event(std::string name);
  Event(std::string name, bool val);
  Event(std::string name, std::string val);
  Event(std::string name, double val);

  bool operator==(const Event &other) const;

  bool p_bool;
  std::string p_name;
  double p_num;
  std::string p_str;
};

class Parser {
public:
  Parser();
  ~Parser();

  ReQL_Parse_t *get_parser();

  void add();

  template<typename type>
  void add(type val) {
    p_events.push_back(Event("add", val));
  }

  void end_array();
  void end_element();
  void end_key_value(std::string key);
  void end_object();
  void end_parse();
  void error();
  void start_array();
  void start_element();
  void start_key_value();
  void start_object();
  void start_parse();

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
_add(ReQL_Parse_t *p);

int
_end_array(ReQL_Parse_t *p);

int
_end_element(ReQL_Parse_t *p);

int
_end_key_value(ReQL_Parse_t *p, const char *key, size_t length);

int
_end_object(ReQL_Parse_t *p);

int
_end_parse(ReQL_Parse_t *p);

void
_error(ReQL_Parse_t *p);

int
_start_array(ReQL_Parse_t *p);

int
_start_element(ReQL_Parse_t *p);

int
_start_key_value(ReQL_Parse_t *p);

int
_start_object(ReQL_Parse_t *p);

int
_start_parse(ReQL_Parse_t *p);

#endif  // TEST_HPP_
