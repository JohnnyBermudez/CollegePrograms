/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaCrip;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.MessageDigest;
import java.security.PublicKey;
import java.security.SecureRandom;
import java.security.Signature;
import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.util.Scanner;  

/**
 *
 * @author jaber
 */
public class JavaEncryption {
    
    
     public static void main(String[] args) throws Exception{
       Scanner in = new Scanner(System.in);
   
    
    // Enter pwd and get password
    System.out.println("Enter your password"); 
        String pwd = in.nextLine();
    
    // Enter file name and get file name
        System.out.println("Enter your file name"); 
        String fname = in.nextLine();
        
        
       // Enc/Dec Ciphers:
       Cipher cipherNY     = Cipher.getInstance("AES/CBC/PKCS5Padding");
       
       // create 32 byte hash
          byte[] pwdBytes =pwd.getBytes("UTF-8");
         MessageDigest md = MessageDigest.getInstance("MD5");  // hash function ( add hash to msg)
       
        
        // updates chunks of digest
        md.update(pwdBytes); // updates every piece of the code read then does digest on the bottom
       byte[] hash = md.digest();
         
       // Initialization Vector for the CBC part       
       byte [] iv = new byte [16];  
       for ( int i = 0; i < 16; i++){
           iv[i] = hash[i]; 
       }
           
       IvParameterSpec ivspec = new IvParameterSpec(iv);
       
    
       byte[] keyBytes    = new byte[16];  
        for ( int i = 0; i < 16; i++){
           keyBytes[i] = hash[i]; 
       }
        
       String algorithm   = "AES"; 
       SecretKeySpec key  = new SecretKeySpec(keyBytes, algorithm); 
          
      
       //Set up Enc or Dec Operations
       cipherNY.init    (Cipher.ENCRYPT_MODE, key,ivspec); 
 
      
       byte[] rawBytes =  IOUtilities.getImageRawBytes(fname);
        byte[] cipherText = cipherNY.doFinal(rawBytes); 

// create file name        
        String outFname = ("encryp_" + fname);
        
     
        // save cipherData to a file
        IOUtilities.writeImageRawBytes(cipherText,outFname);
        
        // Decode the ciphered image
       Cipher cipher2Calif = Cipher.getInstance("AES/CBC/PKCS5Padding");
     
       
       
       cipher2Calif.init(Cipher.DECRYPT_MODE, key,ivspec);        
        
             outFname = ("decryp_" + fname);
       
       
       byte[] plaintext  = cipher2Calif.doFinal(cipherText); 
       IOUtilities.writeImageRawBytes(plaintext,outFname);
    
    }  
    
    
}
