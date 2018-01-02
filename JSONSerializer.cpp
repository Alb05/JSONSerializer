/*
  JSONSerializer.cpp - Library for Serialize data in JSON format.
  Created by Alberto Cozzi, January 2018.
  Released into the public domain.
*/

#include "JSONSerializer.h"
#include "Arduino.h"

/* ObjectSerializer implementation */
ObjectSerializer::ObjectSerializer()
{
  this->Clear();
}

void ObjectSerializer::AddElement(const char* _key, const boolean _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  if (_value)
  {
    this->_serialized += "\"" + String(_key) + "\":true}";
  }
  else
  {
    this->_serialized += "\"" + String(_key) + "\":false}";
  }
}

void ObjectSerializer::AddElement(const char* _key, const char _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const short _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const int _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const long _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const byte _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const unsigned int _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const unsigned long _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const float _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const double _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + String(_value) + "}";
}

void ObjectSerializer::AddElement(const char* _key, const char* _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":\"" + _value + "\"}";
}

void ObjectSerializer::AddElement(const char* _key, ArraySerializer _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + _value.GetSerialized() + "}";
}

void ObjectSerializer::AddElement(const char* _key, ObjectSerializer _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":" + _value.GetSerialized() + "}";
}

void ObjectSerializer::AddElement(const char* _key, String _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":\"" + _value + "\"}";
}

void ObjectSerializer::AddNullElement(const char* _key)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "{")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_key) + "\":null}";
}

String ObjectSerializer::GetSerialized()
{
  return this->_serialized;
}

void ObjectSerializer::Clear()
{
  this->_serialized  = "{}";
}

/* ArraySerializer implementation */
ArraySerializer::ArraySerializer()
{
  this->Clear();
}

void ArraySerializer::AddElement(const boolean _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  if (_value)
  {
    this->_serialized += "true]";
  }
  else
  {
    this->_serialized += "false]";
  }
}

void ArraySerializer::AddElement(const char _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const short _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const int _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const long _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const byte _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const unsigned int _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const unsigned long _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const float _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const double _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += String(_value) + "]";
}

void ArraySerializer::AddElement(const char* _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + String(_value) + "\"]";
}

void ArraySerializer::AddElement(ArraySerializer _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += _value.GetSerialized() + "]";
}

void ArraySerializer::AddElement(ObjectSerializer _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += _value.GetSerialized() + "]";
}

void ArraySerializer::AddElement(String _value)
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += "\"" + _value + "\"]";
}

void ArraySerializer::AddNullElement()
{
  this->_serialized.remove(this->_serialized.length()-1);
  if (this->_serialized != "[")
  {
    this->_serialized += ",";
  }
  this->_serialized += "null]";
}

String ArraySerializer::GetSerialized()
{
  return this->_serialized;
}

void ArraySerializer::Clear()
{
  this->_serialized  = "[]";
}
