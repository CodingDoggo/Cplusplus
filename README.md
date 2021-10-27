# Split function
-Improved split function
-Added features:

1)Recognizes set of delimeters
  Example:
  
  
  delimeters = ";, -"



2)Recognizes more than one delimeter in a row
  Example:
  
  string = "   The ....,,, string,,,, "
  
  Output: 
  
  The
  
  string



3)Takes only two arguments and returns an array of strings


  Example:
  
  
  delimeters = ";, -"
  
  
  stringToCut = "   The ....,,, string,,,, "

  string* wordArray = split(delimeters,stringToCut)

