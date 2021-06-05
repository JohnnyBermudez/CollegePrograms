/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project_01;
    import java.io.File;
import java.nio.file.Files;

public class Encapsulate
{
   File file; 

    //encapsulation function that returns combined array of header and payload on the notes
//the array takes in the header and the payload byte arrays
    
    public byte[] encapsulate(byte[] header, byte[] payload)
    {
    
        /*have the header at the beggining. The header is the beginning of each layer
         The layers are the message, person, address, and state
   The Next Payload consist of a header appended to a payload
   Ex: The next payload for the first encapsulation is payload(person + message) */
       
        byte[] NextPayload = new byte[header.length + payload.length];
   
   //do a for loop to store the words of the message in the header array
   for (int i = 0; i < header.length; i++) {

//the beginning bytes of the header array are stored in nextPayload  

NextPayload[i] = header[i];
}

//this for loop will store the rest of the empty space that was not used
for (int i = 0; i < payload.length; i++)
{
//payload comes at the end

//start storing at the end of the header, stores the payload
    
    NextPayload[header.length+ i] = payload[i];

}

      return NextPayload;   
    
    }
    
/*
    This method adds padding
    Ex: A message may be 900 bytes long, and the max amount of bytes alloted was 1024
    Then the remaining bytes will be filled with blanks
    */
    
 public byte[] prepareHeader(byte[] payload, int paddedLength)
 {
 
 //LengtToPad is the left over space after the header is filled
 // this will determine how many bytes left will be padded
     
     byte[] paddedLoaded = new byte[paddedLength];

  
     int lengthToPad = paddedLength - payload.length;
     
//this is the original data
// Copy the 900 bytes first in new array of 1024 bytes, Suppose here that 1024 bytes is the total length

for (int i = 0; i < payload.length; i++) {

//the beginning bytes of the header array are stored in NextPayload  

paddedLoaded[i] = payload[i];

}
/*this is the rest of the data, the remaining bytes are filled with spaces(blanks, value is 32)
that is the padding
Ex: The 1024 - 900 byte is the remaining padding, this returns the full message with padding
*/

for (int i = 0; i < lengthToPad; i++)
{

paddedLoaded[payload.length+i] = (byte)' ';

}

return paddedLoaded; 

 }
    
    
}