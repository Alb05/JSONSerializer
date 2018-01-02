/*
 * This example shows how to create an array of objects  
 */

#include <JSONSerializer.h>

// ObjectSerializer is used to create objects
ObjectSerializer os;

// ArraySerializer is used to create arrays
ArraySerializer as;

void setup() {
  // begin serial connection
  Serial.begin(115200);

  // reset both serializers
  os.Clear();
  as.Clear();
}

void loop() {
  
  // this loop creates an object and appends it to the array
  for (int i = 1; i <= 3; i++) {
    // for each object (3 in this case)

    // add temperature to the object (integer)
    os.AddElement("temperature", (i*20)-30);

    // add humidity to the object (float)
    os.AddElement("humidity", i*20.4);

    // add city to the object (String)
    os.AddElement("city", "San Francisco, CA");
    
    // add a flag to the object (boolean)
    os.AddElement("online", false);

    // add the object to the array
    as.AddElement(os);

    // reset the object to be used in the next iteration
    os.Clear();
  }

  /*
   * print the array to the serial monitor once serialized with the GetSerialized method
   * es. [{"temperature":-10,"humidity":20.40,"city":"San Francisco, CA","online":false},{"temperature":10,"humidity":40.80,"city":"San Francisco, CA","online":false},{"temperature":30,"humidity":61.20,"city":"San Francisco, CA","online":false}]
   * GetSerialized can also be used to serialize an object
   */
  Serial.println(as.GetSerialized());
  delay(2);

  // reset the array to be used in the next iteration
  as.Clear();
  delay(1998);
}
