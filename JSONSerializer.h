/*
  JSONSerializer.h - Library for Serialize data in JSON format.
  Created by Alberto Cozzi, January 2018.
  Released into the public domain.
*/

#ifndef JSONSerializer_h
#define JSONSerializer_h

#include "Arduino.h"

class ArraySerializer;
class ObjectSerializer;

class ObjectSerializer
{
public:
  ObjectSerializer();
  void AddElement(const char* _key, const boolean _value);
  void AddElement(const char* _key, const char _value);
  void AddElement(const char* _key, const short _value);
  void AddElement(const char* _key, const int _value);
  void AddElement(const char* _key, const long _value);
  void AddElement(const char* _key, const byte _value);
  void AddElement(const char* _key, const unsigned int _value);
  void AddElement(const char* _key, const unsigned long _value);
  void AddElement(const char* _key, const float _value);
  void AddElement(const char* _key, const double _value);
  void AddElement(const char* _key, const char* _value);
  void AddElement(const char* _key, ArraySerializer _value);
  void AddElement(const char* _key, ObjectSerializer _value);
  void AddElement(const char* _key, String _value);
  void AddNullElement(const char* _key);
  String GetSerialized();
  void Clear();

private:
  String _serialized;
};

class ArraySerializer
{
public:
  ArraySerializer();
  void AddElement(const boolean _value);
  void AddElement(const char _value);
  void AddElement(const short _value);
  void AddElement(const int _value);
  void AddElement(const long _value);
  void AddElement(const byte _value);
  void AddElement(const unsigned int _value);
  void AddElement(const unsigned long _value);
  void AddElement(const float _value);
  void AddElement(const double _value);
  void AddElement(const char* _value);
  void AddElement(ObjectSerializer _value);
  void AddElement(ArraySerializer _value);
  void AddElement(String _value);
  void AddNullElement();
  String GetSerialized();
  void Clear();

private:
  String _serialized;
};

#endif
