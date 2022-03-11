import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
import java.util.Arrays;

public class ReadFile{

     public static void main(String[] arg) throws FileNotFoundException, IOException{
        
      

         File file = new File("F:\\trem 5\\Systems Programming (CS321)\\inSIC.txt");
                // create three arraysq
                String [] label=new String[25];
                String [] instruction=new String[25];
                String [] reference=new String[25];
                int i=0;// i for index of label , instruction, reference arrays
                int [] addresses = new int [25];
               
                BufferedReader reader = new BufferedReader (new FileReader(file));
                String st;
                while((st = reader.readLine()) !=null){
                    String[] newString = st.split("\\s+");
                    //you should use the split function inorder to fill in the
                    // three arrays depending on the lengh
                    if(newString.length==3) {
                        label[i]=newString[0];
                        instruction[i]=newString[1];
                        reference[i]=newString[2];
                    }
                    else if(newString.length==2) {
                        label[i]=";";
                       instruction[i]=newString[0];
                        reference[i]=newString[1];
                    }
                    i++;
     }
     for (int j = 0; j < i; j++) {
        System.out.println(label[j]+"   "+instruction[j]+"  "+reference[j] );
}
      
          System.out.println("____________________________________");
 
        //Location Counter

           int x = Integer.parseInt(reference[0],16);
           addresses[0] = x;
           addresses[1] = addresses[0];
           System.out.println(Integer.toHexString(addresses[0])+"  "+label[0]+"   "+instruction[0]+"  "+reference[0]);
           System.out.println( Integer.toHexString(addresses[1])+"   "+label[1]+"   "+instruction[1]+"  "+reference[1]);
         
               
     for (int j = 2; j < 19; j++) {

          if (instruction[j-1].equals("RESW")) {
           String value = reference[j-1];
           int   y = Integer.parseInt(value) * 3;
             addresses[j] = addresses[j-1] + y ;     
         }   
         else if(instruction[j-1].equals("WORD")){
               addresses[j] = addresses[j-1] + 3;
         }  
         
          else if (instruction[j-1].equals("RESB")){
             String value =  reference[j-1];
            int    y = Integer.parseInt(value) ;
               addresses[j] = addresses[j-1] + y;
            }
          else if(instruction[j-1].equals("BYTE")){
                String temp = reference[j-1];
                double byt1;
                int byt;
                if(temp.charAt(0)=='C'){
                    byt = temp.length()-3;  
                }
                    else {
                    byt1= (temp.length() -3)/2.0;
                    byt = (int) Math.ceil(byt1);
                }
                    addresses[j] = addresses[j-1] + byt;
                }
        else{
                addresses[j] = addresses[j-1] + 3;            
                }
                 System.out.println(Integer.toHexString(addresses[j])+"   "+label[j] + "    " + instruction[j] );
       
  }      
            System.out.println("________________________________");
            int [] symAddress= new int[25];
            String [] symLabel= new String[25];

           for(int j= 0; j <19 ;j++){
              if(!label[j].equals(";") )
           {
               symLabel[j]=label[j];
               symAddress[j] = addresses[j];
            System.out.println(symLabel[j] + "\t" +Integer.toHexString(symAddress[j]) );
           }
 }

       System.out.println("__________________________________");
        // objectcode
      
    
        String[] ObjectCode = new String [25];
        String[][] OPTAB = new String[59][3];
        OPTAB[0] = new String[] {"FIX", "1", "C4"};
        OPTAB[1] = new String[] {"FLOAT", "1", "C0"};
        OPTAB[2] = new String[] {"HIO", "1", "F4"};
        OPTAB[3] = new String[] {"NORM", "1", "C8"};
        OPTAB[4] = new String[] {"SIO", "1", "F0"};
        OPTAB[5] = new String[] {"TIO", "1", "F8"};
        OPTAB[6] = new String[] {"ADDR", "2", "90"};
        OPTAB[7] = new String[] {"CLEAR", "2", "B4"};
        OPTAB[8] = new String[] {"COMPR", "2", "A0"};
        OPTAB[9] = new String[] {"DIVR", "2", "9C"};
        OPTAB[10] = new String[] {"MULR", "2", "98"};
        OPTAB[11] = new String[] {"RMO", "2", "AC"};
        OPTAB[12] = new String[] {"SHIFTL", "2", "A4"};
        OPTAB[13] = new String[] {"SHIFTR", "2", "A8"};
        OPTAB[14] = new String[] {"SUBR", "2", "94"};
        OPTAB[15] = new String[] {"SVC", "2", "B0"};
        OPTAB[16] = new String[] {"TIXR", "2", "B8"};
        OPTAB[17] = new String[] {"ADD", "3", "18"};
        OPTAB[18] = new String[] {"ADDF", "3", "58"};
        OPTAB[19] = new String[] {"AND", "3", "40"};
        OPTAB[20] = new String[] {"COMP", "3", "28"};
        OPTAB[21] = new String[] {"COMPF", "3", "88"};
        OPTAB[22] = new String[] {"DIV", "3", "24"};
        OPTAB[23] = new String[] {"DIVF", "3", "64"};
        OPTAB[24] = new String[] {"J", "3", "3C"};
        OPTAB[25] = new String[] {"JEQ", "3", "30"};
        OPTAB[26] = new String[] {"JGT", "3", "34"};
        OPTAB[27] = new String[] {"JLT", "3", "38"};
        OPTAB[28] = new String[] {"JSUB", "3", "48"};
        OPTAB[29] = new String[] {"LDA", "3", "00"};
        OPTAB[30] = new String[] {"LDB", "3", "68"};
        OPTAB[31] = new String[] {"LDCH", "3", "50"};
        OPTAB[32] = new String[] {"LDF", "3", "70"};
        OPTAB[33] = new String[] {"LDL", "3", "08"};
        OPTAB[34] = new String[] {"LDS", "3", "6C"};
        OPTAB[35] = new String[] {"LDT", "3", "74"};
        OPTAB[36] = new String[] {"LDX", "3", "04"};
        OPTAB[37] = new String[] {"LPS", "3", "D0"};
        OPTAB[38] = new String[] {"MUL", "3", "20"};
        OPTAB[39] = new String[] {"MULF", "3", "60"};
        OPTAB[40] = new String[] {"OR", "3", "44"};
        OPTAB[41] = new String[] {"RD", "3", "D8"};
        OPTAB[42] = new String[] {"RSUB", "3", "4C"};
        OPTAB[43] = new String[] {"SSK", "3", "EC"};
        OPTAB[44] = new String[] {"STA", "3", "0C"};
        OPTAB[45] = new String[] {"STB", "3", "78"};
        OPTAB[46] = new String[] {"STCH", "3", "54"};
        OPTAB[47] = new String[] {"STF", "3", "80"};
        OPTAB[48] = new String[] {"STI", "3", "D4"};
        OPTAB[49] = new String[] {"STL", "3", "14"};
        OPTAB[50] = new String[] {"STS", "3", "7C"};
        OPTAB[51] = new String[] {"STSW", "3", "E8"};
        OPTAB[52] = new String[] {"STT", "3", "84"};
        OPTAB[53] = new String[] {"STX", "3", "10"};
        OPTAB[54] = new String[] {"SUB", "3", "1C"};
        OPTAB[55] = new String[] {"SUBF", "3", "5C"};
        OPTAB[56] = new String[] {"TD", "3", "E0"};
        OPTAB[57] = new String[] {"TIX", "3", "2C"};
        OPTAB[58] = new String[] {"WD", "3", "DC"};
            
            for(int j=0;j<19;j++){
                for(int y = 0;  y <OPTAB.length;y++){
                    if(instruction[j].equals(OPTAB[y][0])) {
                 
                      
                    for(int k = 0 ; k<19; k++){
                       if(reference[j].equals(label[k])){
                            int Opcode = addresses[k];
                    ObjectCode[j]=OPTAB[y][2]+""+Integer.toHexString(Opcode);
                    } continue;
                    }        
                }
                
               if(instruction[j].equals("RESW")){ 
                  ObjectCode[j]= "no objectCode";
                    continue;  
                 }
                else if(instruction[j].equals("RESB")){     
                   ObjectCode[j]= "no objectCode";
                    continue;   
              }
                else if(instruction[j].equals("WORD")){///
                 //  int value  = Integer.parseInt(reference[j],16);
                   String A = reference [j];
                       for(int h=0; h<6 ; h++){
                            A= '0'+A;
                      
                       }
                      
                     ObjectCode[j] = A  ;
                      
                        }

            else if(instruction[j].equals("BYTE")){ //////////////
                    if(reference[j].startsWith("'X'")){
                     String b = reference[j].substring(2,reference[j].length()-1);
                       ObjectCode[j]= b;
                    } 
                    else{ 
                    int b = Integer.parseInt(reference[j],16);  /// convert to ASCIICode
                   
             }        continue;  
                   }
               else if(instruction.equals("RSUB")){
			ObjectCode[j] =  instruction[j] + "0000";
                        continue;
               }
               
                     if(instruction[j].equals(OPTAB[y][0])){
                     if(reference[j].contains(",X")){
                     String z = reference[j].substring(0,reference[j].length()-2);
                     for(int k = 0 ; k<19; k++){
                       if(z.equals(label[k])){
                            int Opcode = (int) (addresses[k]+ 32768); ///8000 to dec 32768
                         
                            ObjectCode[j]=OPTAB[y][2]+""+Integer.toHexString(Opcode);
                  
                    }
                         }
                
                }
                     }
            
                
                }
                
    System.out.println(Integer.toHexString(addresses[j])+"   "+label[j] + "    " + instruction[j] +"     "+reference[j]+"   "+ObjectCode[j]);
           
            }
              int length = addresses[18]-addresses[0];
            System.out.println( " H ^ "+label[0]+" ^ "+reference[0]+" ^ " + Integer.toHexString(length));
           int  z = 1, j = 0;
                  for( z=1;z<11;z++){
                        if (ObjectCode[z] != " no objectCode" && ObjectCode[z] != null && z < j+10) {
                             
                          int  diff = addresses[11] - addresses[0];
                            System.out.println(" ");
                            System.out.print("T ^ " +Integer.toHexString(addresses[z]) + " ^ " + Integer.toHexString(diff)+ " ^"+ObjectCode[z] + " ^");
                        }
                  
                        for( j=1;j<11;j++){
                            if (ObjectCode[z] != "no objectCode" && ObjectCode[z] != null) {
                                System.out.print(ObjectCode[z] + " ");
                                z++;
                            } else {
                                z++;
                             break;
                            }
                            
                        }
                  }
                    
                    
                    System.out.println(" ");
                    System.out.println("E ^ " + reference[0]);
                    
                    

     }
  
     }



       
    
   



     

            
  
      
     
          
         
     

