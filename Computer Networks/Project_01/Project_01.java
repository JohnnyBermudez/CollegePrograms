/*
 Juan Bermudez
CMPE 4345
10/01/2018
Project 1
 */
package project_01;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;
import java.util.Arrays;

/**
 *
 * @author jaber
 */
public class Project_01 {

    /**
     * @param args the command line arguments
     */
 
    public static void main(String[] args) throws IOException {
      
        // test the first encapsulation, create an object
Encapsulate encapsulationObject = new Encapsulate(); 
        
        // create a new reference and refer to the input stream.
        Scanner input = new Scanner(System.in); 
        
        // tell the user enter their message
        System.out.println("Please enter a message: ");
      
       
         
// read the next line from the stream (entered from the keyboard) and store it in a String variable named Message         
        String Message = input.nextLine(); 
          System.out.println(); 
        // convert the string into a byte array the String class getBytes(); 
        //method to encode the string into a sequence of bytes using the platform’s default charset.
        byte[] Load1 = Message.getBytes(); 

        // prepare the header, Load1 consists of the message, and 1024 is the size of the byte message padded
        byte[] Load1Padded = encapsulationObject.prepareHeader(Load1, 1024);
      
     // tell the user to enter the name of the person for whom the message is intended for
     
       System.out.println("Please enter the full name of the person receiving this message: ");

       // store the line from the string in PersonName
     String PersonName = input.nextLine(); 
          System.out.println(); 
     // convert the string PersonName into a byte array
     
     byte[] PersonHeader = PersonName.getBytes();

     // padd the PersonHeader into 1024 bytes
     byte[] PersonHeaderPadded = encapsulationObject.prepareHeader(PersonHeader, 1024);
     
// encapsulate method appends Load1Padded byte array in the back of the PersonHeader byte array
byte[] Payload1 = encapsulationObject.encapsulate(PersonHeaderPadded, Load1Padded);


  
     
        
     // Tell the user to enter the address
 System.out.println("Please enter the address where we should send your message: ");
         

    // store the line from the string entered in AdressName
         String AddressName = input.nextLine(); 
        System.out.println(); 
     // convert the string AddressName into a byte array
     byte[] AddressHeader = AddressName.getBytes();

     // padd the AddressHeader into 1024 bytes
     byte[] AddressHeaderPadded = encapsulationObject.prepareHeader(AddressHeader, 1024);

     // encapsulate the PersonHeader byte array in the back of the  AddressHeaderPadded  byte array
byte[] Payload2 = encapsulationObject.encapsulate(AddressHeaderPadded, Payload1);


        //     Part D
        
     // Tell the user to enter the State
 System.out.println("Please enter the State where you live: ");

    // store the line from the string entered in StateName
         String StateName = input.nextLine(); 
                 System.out.println(); 

     // convert the string StateName into a byte array
     byte[] StateHeader = StateName.getBytes();

     // padd the StateNameHeader into 1024 bytes
     byte[] StateHeaderPadded = encapsulationObject.prepareHeader(StateHeader, 1024);

     // encapsulate,append the StateHeaderPadded byte array in the back of the  AddressHeaderPadded  byte array
byte[] Payload3 = encapsulationObject.encapsulate(StateHeaderPadded, Payload2);

try (FileOutputStream fos = new FileOutputStream("finalPacket.raw")) {
   fos.write(Payload3);
   
}

        
      // byte[] Payload3\4 /// ra
       //finalPacket.raw
      /*
       FileOutputStream finalPack = new FileOutputStream("finalPacket.raw");
       finalPack.write(DecapState);
       finalPack.close();
       Decapsulation.decapsulate(Payload3);
       */
    // test the first encapsulation, create an object
Decapsulation DecapObject = new Decapsulation(); 
DecapObject.decapsulate();
    
    }
    
   
}
