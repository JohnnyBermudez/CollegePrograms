/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JavaCrip;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
/**
 *
 * @author xwc981
 */


public class IOUtilities {
    public static void printHexDump(byte[] aData) throws Exception {
        int i = 0;
// takes a byte of data, of a key or digest, prints data in hexa format,
// then goes to nxt row
        for (byte t : aData) {
            i++;
            System.out.format("%02x ", t);
            if (i % 32 == 0) {
                System.out.println("");
            }
        }
        System.out.println("");
    }
// seeing the array to txt format,
    public static String byteArray2String(byte[] aBytes) throws Exception {
        return (new String(aBytes));
    }
// encryption of image, get name of file
    public static byte[] getImageRawBytes(String fname) throws Exception {
        //return  "I love UTRGV".getBytes("UTF-8"); 

        byte[] imageRawaData = null;
// low level byte stream
        FileInputStream in = null;
        File img = new File(fname);
        int length = (int) img.length();
        imageRawaData = new byte[length];
        try {
            in = new FileInputStream(fname);
            in.read(imageRawaData);
        } finally {
            if (in != null) {
                in.close();
            }
        }
        return imageRawaData;

    }

    // same as top just in chunks of buffer
    public static byte[] getImageRawBytes(String fname, int bufferSize) throws IOException {
        ByteArrayOutputStream ous = null;
        InputStream ios = null;
        try {
            byte[] buffer = new byte[bufferSize];
            ous = new ByteArrayOutputStream();
            ios = new FileInputStream(fname);
            int read = 0;
            while ((read = ios.read(buffer)) != -1) {
                ous.write(buffer, 0, read);
            }
        } finally {
            try {
                if (ous != null) {
                    ous.close();
                }
            } catch (IOException e) {
            }

            try {
                if (ios != null) {
                    ios.close();
                }
            } catch (IOException e) {
            }
        }
        return ous.toByteArray();

    }

   
    public static void writeImageRawBytes(byte[] plaintext, String fname) throws Exception {
        FileOutputStream out = null;
        try {
            out = new FileOutputStream(fname);
            out.write(plaintext);
        } finally {
            if (out != null) {
                out.close();
            }
        }
    }
}
