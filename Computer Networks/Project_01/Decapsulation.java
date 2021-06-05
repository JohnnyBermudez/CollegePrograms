/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package project_01;
import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
/**
 *
 * @author jaber
 */
public class Decapsulation {
    
  

     public void decapsulate() throws IOException
    {

    
    byte[] FileArray = Files.readAllBytes(new File("finalPacket.raw").toPath());
        System.out.println();
        System.out.println();
        
        System.out.println("State: ");
        for (int i = 0; i < 1023; i++) {
            System.out.print((char)FileArray[i]);
            
        }
       
         System.out.println();
          System.out.println("Address: ");
        for (int i = 1024; i <2047; i++) {
            System.out.print((char)FileArray[i]);
            
        }
        
      System.out.println();
          System.out.println("Name: ");
        for (int i = 2048; i <3071; i++) {
            System.out.print((char)FileArray[i]);
            
        }
        
        System.out.println();
          System.out.println("Message: ");
        for (int i = 3072; i <4095; i++) {
            System.out.print((char)FileArray[i]);
            
        }
       
    }

    
}
