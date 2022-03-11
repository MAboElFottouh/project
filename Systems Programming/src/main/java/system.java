
import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

/**
 *
 * @author Mahmoud
 */
public class system {

    public static String[] format = new String[59];
    public static String[] Modify = new String[59];

    private static final String[][] OPTAB = new String[59][3];

    public static boolean isNumeric(String strNum) {
        try {
            double d = Double.parseDouble(strNum);
        } catch (NumberFormatException | NullPointerException nfe) {
            return false;
        }
        return true;
    }

    public static void initialize() {
        OPTAB[0] = new String[]{"FIX", "1", "C4"};
        OPTAB[1] = new String[]{"FLOAT", "1", "C0"};
        OPTAB[2] = new String[]{"HIO", "1", "F4"};
        OPTAB[3] = new String[]{"NORM", "1", "C8"};
        OPTAB[4] = new String[]{"SIO", "1", "F0"};
        OPTAB[5] = new String[]{"TIO", "1", "F8"};
        OPTAB[6] = new String[]{"ADDR", "2", "90"};
        OPTAB[7] = new String[]{"CLEAR", "2", "B4"};
        OPTAB[8] = new String[]{"COMPR", "2", "A0"};
        OPTAB[9] = new String[]{"DIVR", "2", "9C"};
        OPTAB[10] = new String[]{"MULR", "2", "98"};
        OPTAB[11] = new String[]{"RMO", "2", "AC"};
        OPTAB[12] = new String[]{"SHIFTL", "2", "A4"};
        OPTAB[13] = new String[]{"SHIFTR", "2", "A8"};
        OPTAB[14] = new String[]{"SUBR", "2", "94"};
        OPTAB[15] = new String[]{"SVC", "2", "B0"};
        OPTAB[16] = new String[]{"TIXR", "2", "B8"};
        OPTAB[17] = new String[]{"ADD", "3", "18"};
        OPTAB[18] = new String[]{"ADDF", "3", "58"};
        OPTAB[19] = new String[]{"AND", "3", "40"};
        OPTAB[20] = new String[]{"COMP", "3", "28"};
        OPTAB[21] = new String[]{"COMPF", "3", "88"};
        OPTAB[22] = new String[]{"DIV", "3", "24"};
        OPTAB[23] = new String[]{"DIVF", "3", "64"};
        OPTAB[24] = new String[]{"J", "3", "3C"};
        OPTAB[25] = new String[]{"JEQ", "3", "30"};
        OPTAB[26] = new String[]{"JGT", "3", "34"};
        OPTAB[27] = new String[]{"JLT", "3", "38"};
        OPTAB[28] = new String[]{"JSUB", "3", "48"};
        OPTAB[29] = new String[]{"LDA", "3", "00"};
        OPTAB[30] = new String[]{"LDB", "3", "68"};
        OPTAB[31] = new String[]{"LDCH", "3", "50"};
        OPTAB[32] = new String[]{"LDF", "3", "70"};
        OPTAB[33] = new String[]{"LDL", "3", "08"};
        OPTAB[34] = new String[]{"LDS", "3", "6C"};
        OPTAB[35] = new String[]{"LDT", "3", "74"};
        OPTAB[36] = new String[]{"LDX", "3", "04"};
        OPTAB[37] = new String[]{"LPS", "3", "D0"};
        OPTAB[38] = new String[]{"MUL", "3", "20"};
        OPTAB[39] = new String[]{"MULF", "3", "60"};
        OPTAB[40] = new String[]{"OR", "3", "44"};
        OPTAB[41] = new String[]{"RD", "3", "D8"};
        OPTAB[42] = new String[]{"RSUB", "3", "4C"};
        OPTAB[43] = new String[]{"SSK", "3", "EC"};
        OPTAB[44] = new String[]{"STA", "3", "0C"};
        OPTAB[45] = new String[]{"STB", "3", "78"};
        OPTAB[46] = new String[]{"STCH", "3", "54"};
        OPTAB[47] = new String[]{"STF", "3", "80"};
        OPTAB[48] = new String[]{"STI", "3", "D4"};
        OPTAB[49] = new String[]{"STL", "3", "14"};
        OPTAB[50] = new String[]{"STS", "3", "7C"};
        OPTAB[51] = new String[]{"STSW", "3", "E8"};
        OPTAB[52] = new String[]{"STT", "3", "84"};
        OPTAB[53] = new String[]{"STX", "3", "10"};
        OPTAB[54] = new String[]{"SUB", "3", "1C"};
        OPTAB[55] = new String[]{"SUBF", "3", "5C"};
        OPTAB[56] = new String[]{"TD", "3", "E0"};
        OPTAB[57] = new String[]{"TIX", "3", "2C"};
        OPTAB[58] = new String[]{"WD", "3", "DC"};
    }

    public static int getDecimal(String hex) {
        String digits = "0123456789ABCDEF";
        hex = hex.toUpperCase();
        int val = 0;
        for (int i = 0; i < hex.length(); i++) {
            char c = hex.charAt(i);
            int d = digits.indexOf(c);
            val = 16 * val + d;
        }
        return val;
    }

    public static String hexToBin(String hex) {
        String bin = "";
        String binFragment = "";
        int iHex;
        hex = hex.trim();
        hex = hex.replaceFirst("0x", "");

        for (int i = 0; i < hex.length(); i++) {
            iHex = Integer.parseInt("" + hex.charAt(i), 16);
            binFragment = Integer.toBinaryString(iHex);

            while (binFragment.length() < 4) {
                binFragment = "0" + binFragment;
            }
            bin += binFragment;
        }
        return bin;
    }

    public static String binaryToHex(String binary) {
        int decimalValue = 0;
        int length = binary.length() - 1;
        for (int i = 0; i < binary.length(); i++) {
            decimalValue += Integer.parseInt(binary.charAt(i) + "") * Math.pow(2, length);
            length--;
        }
        return decimalToHex(decimalValue);
    }

    public static String binaryToHex1(String bin) {
        String hex = Long.toHexString(Long.parseLong(bin, 2));
        return String.format("%" + (int) (Math.ceil(bin.length() / 4.0)) + "s", hex).replace(' ', '0');
    }

    private static String decimalToHex(int decimal) {
        String hex = "";
        while (decimal != 0) {
            int hexValue = decimal % 16;
            hex = toHexChar(hexValue) + hex;
            decimal = decimal / 16;
        }
        return hex;
    }

    private static char toHexChar(int hexValue) {
        if (hexValue <= 9 && hexValue >= 0) {
            return (char) (hexValue + '0');
        } else {
            return (char) (hexValue - 10 + 'A');
        }
    }

    public static String decToHex(int dec) {
        return Integer.toHexString(dec);
    }

    public static int hexToDec(String hex) {
        return Integer.parseInt(hex, 16);
    }

    private static String dectoBin(int dec) {
        return Integer.toBinaryString(dec);
    }

    public static void main(String[] args) throws FileNotFoundException {

        String BASE = "null";
        String DispBASE = "null";
        HashMap<String, String> map = new HashMap<>();
        initialize();

        File file = new File("inSICXE (1).txt");
        if (file.exists()) {
            System.out.println("found " + file.getName());
        } else {
            System.out.println("Could not find the project file");
        }
        Scanner Proj = new Scanner(file);

        String[] references = new String[100];
        String[] address = new String[100];
        String[] instruction = new String[100];
        String[] Labels = new String[100];
        String[] OPCode = new String[100];
        String[][] SymbolTable = new String[100][100];
        format[0] = "0"; //value of starting format, "Start"
        String nixbpe[] = new String[6];
        String register1register2[] = new String[2];
        register1register2[0] = ";;";

        String line1 = Proj.nextLine();
        String[] Text0 = line1.split(" ");
        String programName = Text0[0]; //Program Name
        String startAdd = Text0[2]; //starting address
        if (startAdd.length() != 4) { //Checking length of the starting address
            int tempStrt = Integer.parseInt(startAdd);
            startAdd = String.format("%04d", tempStrt);
        }

        address[0] = startAdd;
        address[1] = startAdd;//First and second line has the same address value

        //resetting scanner
        Proj.close();
        Proj = null;
        Proj = new Scanner(file);

        int f = 0;
        int i = 0; //nixbpe counter
        int AddrTempCounter = 0;

        System.out.print("\n");
        System.out.print("\n");

        /////pass 1////
        while (Proj.hasNext()) {

            String line2 = Proj.nextLine();

            AddrTempCounter++;
            String[] Text1 = line2.split(" ");

            for (int y = 0; y < OPTAB.length; y++) {

                if (Text1.length == 3 && Text1[1].equals(OPTAB[y][0])) {

                    format[f] = OPTAB[y][1];

                } else if (Text1.length < 3 && Text1[0].equals(OPTAB[y][0])) {

                    format[f] = OPTAB[y][1];

                } else if (line2.contains("+")) {
                    format[f] = "4";
                } else if (Text1[0].contains("BASE")) {
                    format[f] = "0";
                } else if (Text1[0].equalsIgnoreCase("END")) {
                    format[f] = "0";
                }

            }

            //SymbolTable
            if (Text1.length == 3) {

                Labels[f] = Text1[0];
                SymbolTable[f][1] = Labels[f];
            } else if (Text1.length != 3) {
                Labels[f] = ";";
                SymbolTable[f][1] = Labels[f];

            }
            if (Text1.length == 3) {
                instruction[f] = Text1[1];
            } else if (Text1.length == 1) {
                instruction[f] = Text1[0];
            } else {
                instruction[f] = Text1[0];
            }

            if (Text1.length == 3) {
                references[f] = Text1[2];
            } else if (Text1.length == 1) {
                references[f] = ";";
            } else {
                references[f] = Text1[1];
            }
/////////////////////////SymbolTable address
            if (Labels[f] != ";") {
                SymbolTable[f][0] = address[f];
            } else if (Labels[f] == ";") {
                SymbolTable[f][0] = ";";
            }

            if (AddrTempCounter > 1) { //Start calculating address
                if (Text1[0].contains("BASE")) {
                    address[f+1 ] = address[f - 1];

                }

                if ("RSUB".equals(Text1[0])) {

                    address[f + 1] = decToHex(hexToDec(address[f]) + Integer.parseInt(format[f]));
                    if (address[f].length() == 1) {
                        address[f] = "000" + address[f];
                    } else if (address[f].length() == 2) {
                        address[f] = "00" + address[f];
                    } else if (address[f].length() == 3) {
                        address[f] = "0" + address[f];
                    }

                } else if ("RESW".equals(instruction[f])) {

                    int reserve = Integer.parseInt(Text1[2]) * 3;
                    address[f + 1] = decToHex(hexToDec(address[f]) + reserve);
                    if (address[f].length() == 1) {
                        address[f] = "000" + address[f];
                    } else if (address[f].length() == 2) {
                        address[f] = "00" + address[f];
                    } else if (address[f].length() == 3) {
                        address[f] = "0" + address[f];
                    }

                } else if ("RESB".equals(instruction[f])) {
                    int reserve2 = Integer.parseInt(Text1[2]) * 1;
                    address[f + 1] = decToHex(hexToDec(address[f]) + reserve2);
                    if (address[f].length() == 1) {
                        address[f] = "000" + address[f];
                    } else if (address[f].length() == 2) {
                        address[f] = "00" + address[f];
                    } else if (address[f].length() == 3) {
                        address[f] = "0" + address[f];
                    }

                } else if ("BYTE".equals(instruction[f])) {
                    if (Text1[2].contains("X")) {
                        int temp = Text1[2].length() - 3;
                        temp = temp / 2;
                        address[f + 1] = decToHex(hexToDec(address[f]) + temp);
                        if (address[f].length() == 1) {
                            address[f] = "000" + address[f];
                        } else if (address[f].length() == 2) {
                            address[f] = "00" + address[f];
                        } else if (address[f].length() == 3) {
                            address[f] = "0" + address[f];
                        }
                    } else if (Text1[2].contains("C")) {
                        int temp2 = Text1[2].length() - 3;
                        address[f + 1] = decToHex(hexToDec(address[f]) + temp2);
                        if (address[f].length() == 1) {
                            address[f] = "000" + address[f];
                        } else if (address[f].length() == 2) {
                            address[f] = "00" + address[f];
                        } else if (address[f].length() == 3) {
                            address[f] = "0" + address[f];
                        }
                    }

                } else {

                    address[f + 1] = decToHex(hexToDec(address[f]) + Integer.parseInt(format[f]));
                    if (address[f].length() == 1) {
                        address[f] = "000" + address[f];
                    } else if (address[f].length() == 2) {
                        address[f] = "00" + address[f];
                    } else if (address[f].length() == 3) {
                        address[f] = "0" + address[f];
                    }

                }

            }
//End of address

            if ("BASE".equals(instruction[f])) {
                BASE = references[f];
                address[f] = address[f - 1];
            }

            map.put(Labels[f], address[f]);

            System.out.println(address[f] + "\t" + Labels[f] + "\t" + instruction[f] + "\t" + references[f]);

            f++;

        }
        System.out.println("\n\n");

        f = 0;

        //resetting scanner
        Proj.close();
        Proj = null;
        Proj = new Scanner(file);

        while (Proj.hasNext()) {
            nixbpe[0] = "0"; //n
            nixbpe[1] = "0"; //i
            nixbpe[2] = "0"; //x
            nixbpe[3] = "0"; //b
            nixbpe[4] = "0"; //p
            nixbpe[5] = "0"; //e
            String line3 = Proj.nextLine();

            String[] Text2 = line3.split(" ");
            //Detecting the OPCode
            for (int k = 0; k < OPTAB.length; k++) {
                if (Text2.length > 1) {
                    if (instruction[f].contains("+")) {
                        if (instruction[f].substring(1).equals(OPTAB[k][0])) {
                            OPCode[f] = OPTAB[k][2];
                        }

                    } // dool kda malhomsh object code 
                    else if ("COPY".equalsIgnoreCase(Text2[0]) || "END".equalsIgnoreCase(Text2[0]) || "BASE".equalsIgnoreCase(Text2[0])) {

                        OPCode[f] = ";";

                    } else if (Text2[0].equalsIgnoreCase(OPTAB[k][0]) || Text2[1].equalsIgnoreCase(OPTAB[k][0])) {

                        OPCode[f] = OPTAB[k][2];

                    } else if ("RESW".equals(Text2[1]) || "RESB".equals(Text2[1]) || "BYTE".equals(Text2[1])) {
                        OPCode[f] = ";";

                    } else if ("WORD".equals(Text2[1]) && Text2.length == 3) {
                        int decInt = Integer.parseInt(Text2[2]);

                        OPCode[f] = String.format("%06X", decInt);

                    }

                } else if (Text2[0].equalsIgnoreCase(OPTAB[k][0]) && Text2.length == 1) {
                    //RSUB condition
                    OPCode[f] = OPTAB[k][2];
                }

            }

            //nixbpe
            if (references[f].contains("#")) {
                nixbpe[0] = "0"; //n
                nixbpe[1] = "1"; //i
                nixbpe[2] = "0"; //x
                nixbpe[3] = "0"; //b
                nixbpe[4] = "0"; //p
                if (instruction[f].contains("+")) {
                    nixbpe[5] = "1"; //e
                }
            } else if (instruction[f].contains("+")) {

                nixbpe[0] = "1"; //n
                nixbpe[1] = "1"; //i    
                nixbpe[2] = "0"; //x
                nixbpe[3] = "0"; //b
                nixbpe[4] = "0"; //p
                nixbpe[5] = "1"; //e

            } else if ("START".equalsIgnoreCase(instruction[f]) || "END".equalsIgnoreCase(instruction[f]) || "BASE".equalsIgnoreCase(instruction[f]) || "RESW".equalsIgnoreCase(instruction[f]) || "RESB".equalsIgnoreCase(instruction[f]) || "WORD".equalsIgnoreCase(instruction[f]) || "RESW".equalsIgnoreCase(instruction[f])) {

                nixbpe[0] = "0"; //n
                nixbpe[1] = "0"; //i 
                nixbpe[2] = "0"; //x
                nixbpe[3] = "0"; //b
                nixbpe[4] = "0"; //p
                nixbpe[5] = "0"; //e
            } else if (references[f].contains("@")) {
                nixbpe[0] = "1"; //n
                nixbpe[1] = "0"; //i 
                nixbpe[2] = "0"; //x
                nixbpe[3] = "0"; //b
                nixbpe[4] = "1"; //p
                nixbpe[5] = "0"; //e
            } else if (format[f] == "2") {
                if (line3.contains(",")) {
                    String registersTemp[] = line3.split(" ");
                    String tempReg = registersTemp[1];
                    String registers[] = tempReg.split(",");
                    String newReg = registers[0].replaceFirst("A", "0");
                    String newReg1 = registers[1].replaceFirst("S", "4");
                    String value = newReg + newReg1;
                    register1register2[0] = value;

                } else {
                    if (Text2.length == 3) {
                        String registersTemp[] = line3.split(" ");
                        String tempReg = registersTemp[2];
                        tempReg = tempReg.replace("X", "1");
                        register1register2[0] = tempReg + "0";

                    } else {

                        String registersTemp[] = line3.split(" ");
                        String tempReg = registersTemp[1];
                        tempReg = tempReg.replace("A", "0");
                        tempReg = tempReg.replace("S", "4");
                        tempReg = tempReg.replace("T", "5");
                        register1register2[0] = tempReg + "0";

                    }
                }

            } else if ("RSUB".equalsIgnoreCase(instruction[f])) {
                nixbpe[0] = "1"; //n
                nixbpe[1] = "1"; //i 
                nixbpe[2] = "0"; //x
                nixbpe[3] = "0"; //b
                nixbpe[4] = "0"; //p
                nixbpe[5] = "0"; //e
            } else {

                nixbpe[0] = "1"; //n
                nixbpe[1] = "1"; //i 
                nixbpe[2] = "0"; //x
                nixbpe[3] = "0"; //b
                nixbpe[4] = "1"; //p
                nixbpe[5] = "0"; //e
                if (line3.contains(",X")) {
                    nixbpe[2] = "1"; //x
                }

            }

            String x = nixbpe[0] + nixbpe[1] + nixbpe[2] + nixbpe[3] + nixbpe[4] + nixbpe[5];

            if ("110010".equals(x)) {
                String DispPCTemp = "";
                if (OPCode[f] != ";") {

                    String temp = hexToBin(OPCode[f]);
                    temp = temp.substring(0, 6); //method to seperate
                    String tempLabel = references[f];
                    String TA = (map.get(tempLabel));
                    String PC = address[f + 1];
                    String DispPC = "0" + Integer.toHexString(getDecimal(TA) - getDecimal(PC));
                    if (DispPC.length() == 9) {
                        DispPCTemp = DispPC;
                        DispPC = DispPC.substring(6, 9);

                    }
                    if (DispPC.length() == 2) {
                        DispPC = "0" + DispPC;
                    }

                    int flagCheck = getDecimal(DispPCTemp);
                    if (flagCheck < -2048) {
                        nixbpe[3] = "1"; //b
                        nixbpe[4] = "0"; //p
                        String BaseAddr = (map.get(BASE));
                        DispBASE = "0" + Integer.toHexString(getDecimal(TA) - getDecimal(BaseAddr));
                    }
                    String part1 = temp.substring(0, 4);
                    String part2 = temp.substring(4, 6) + "11";
                    String part3 = "";
                    if (nixbpe[4] == "1") { //p
                        part3 = "0010";
                    } else if (nixbpe[3] == "1") { //b

                        part3 = "0100";
                    }

                    if ("1".equals(nixbpe[4])) {
                        OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + binaryToHex(part3) + DispPC;
                    } else if ("1".equals(nixbpe[3])) {
                        if (DispBASE.length() == 2) {
                            DispBASE = "0" + DispBASE;
                        }
                        OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + binaryToHex(part3) + DispBASE;
                    }

                    if (OPCode[f].length() != 6 && "1".equals(nixbpe[4])) {
                        OPCode[f] = "0" + OPCode[f];
                    }
                }
            } else if (("110001".equals(x))) { //Case format 4

                String temp = hexToBin(OPCode[f]);
                temp = temp.substring(0, 6); //method to seperate
                String tempLabel = references[f];
                String TA = "0" + (map.get(tempLabel));
                String part1 = temp.substring(0, 4);

                String part2 = temp.substring(4, 6) + "11";
                String part3 = "0001";
                OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + binaryToHex(part3) + TA;

            } else if (("010001".equals(x))) { //Case format4 with a #
                String temp = hexToBin(OPCode[f]);
                temp = temp.substring(0, 6); //method to seperate
                String tempAddress = references[f].substring(1, 5);
                int prevAddress = Integer.parseInt(tempAddress);
                String currAddress = "0" + Integer.toHexString(prevAddress);
                String part1 = temp.substring(0, 4);

                String part2 = temp.substring(4, 6) + "01";
                String part3 = "0001";
                OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + binaryToHex(part3) + currAddress;

            } else if ("010000".equals(x)) { //Case Immediate, either numeric or non-numeric

                String checkFlag = references[f].substring(1);

                if (isNumeric(checkFlag) == true) {
                    String temp = hexToBin(OPCode[f]);
                    temp = temp.substring(0, 6); //method to seperate 
                    String currAddress = "00" + checkFlag;
                    //System.out.println(temp);
                    String part1 = temp.substring(0, 4);
                    String part2 = temp.substring(4, 6) + "01";

                    OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + "0" + currAddress;

                    if ("LDA".equals(instruction[f])) {
                        OPCode[f] = "0" + OPCode[f];
                    } //LDA is the only instruction which has 00, so the 0's might be ignored during conversion

                } else {
                    String temp = hexToBin(OPCode[f]);
                    temp = temp.substring(0, 6); //method to seperate 
                    nixbpe[4] = "1";
                    String tempLabel = references[f].substring(1);
                    String TA = (map.get(tempLabel));
                    String PC = address[f + 2]; //Instead of being o+1, the base has the address of ";"
                    String DispPC = "0" + Integer.toHexString(getDecimal(TA) - getDecimal(PC));
                    String part1 = temp.substring(0, 4);

                    String part2 = temp.substring(4, 6) + "01";
                    String part3 = "0010";
                    OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + binaryToHex(part3) + DispPC;

                }

            } else if ("000000".equals(x) && format[f] != "2") {
                //Case , Start , End or BASE.
                OPCode[f] = ";";
            } else if ("110000".equals(x)) {
                //Case RSUB
                String temp = hexToBin(OPCode[f]);
                temp = temp.substring(0, 6); //method to seperate 
                String part1 = temp.substring(0, 4);
                String part2 = temp.substring(4, 6) + "11";
                String part3 = "0000";
                OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + "0000"; //Once again, the zeros were ignored during the conversion

            } else if ("100010".equals(x)) {
                String temp = hexToBin(OPCode[f]);
                temp = temp.substring(0, 6); //method to seperate 
                String tempLabel = references[f].substring(1);
                String TA = (map.get(tempLabel));
                String PC = address[f + 1];
                String DispPC = "0" + Integer.toHexString(getDecimal(TA) - getDecimal(PC));
                String part1 = temp.substring(0, 4);

                String part2 = temp.substring(4, 6) + "10";
                String part3 = "0010";
                OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + binaryToHex(part3) + "0" + DispPC;
                // System.out.println(OPCode[o]);

            } else if ("111010".equals(x)) {
                String temp = hexToBin(OPCode[f]);
                temp = temp.substring(0, 6); //method to seperate 
                String[] tempSplit = references[f].split(",");
                String tempLabel = tempSplit[0];
                String TA = (map.get(tempLabel));
                String BaseAddr = (map.get(BASE));
                // System.out.println(BaseAddr);
                DispBASE = "0" + Integer.toHexString(getDecimal(TA) - getDecimal(BaseAddr)); //The two addresses which have the index "x" were base,, "waste of time"
                String part1 = temp.substring(0, 4);
                String part2 = temp.substring(4, 6) + "11";
                String part3 = "1100";
                OPCode[f] = binaryToHex(part1) + binaryToHex(part2) + binaryToHex(part3) + "0" + DispBASE.trim();
                //  System.out.println(OPCode[o]);

            } else if (format[f] == "2") {
                String part2 = register1register2[0];

                OPCode[f] = OPCode[f] + part2;

            }

            if (instruction[f].contains("+") && references[f].contains("#") == false) {

                String tempAdd = decToHex(hexToDec(address[f]) + Integer.parseInt("1"));
                Modify[i] = tempAdd;
                if (Modify[i].length() == 1) {
                    Modify[i] = "000" + Modify[i];
                } else if (Modify[i].length() == 2) {
                    Modify[i] = "00" + Modify[i];
                } else if (Modify[i].length() == 3) {
                    Modify[i] = "0" + Modify[i];
                }

                i++;

            }

            if (references[f].length() > 7) {
                System.out.println(address[f] + "\t" + Labels[f] + "\t" + instruction[f] + "\t" + references[f] + "\t" + OPCode[f]);
            } else {

                System.out.println(address[f] + "\t" + Labels[f] + "\t" + instruction[f] + "\t" + references[f] + "\t" + OPCode[f]);
            }
            f++;
        }

        System.out.printf("%n");
        System.out.printf("%n");
        System.out.println("");
        String lastAddress = address[f];
        //System.out.println(o);
        int tempLength = getDecimal((lastAddress)) - getDecimal((startAdd));
        String Length = Integer.toHexString(tempLength);
        System.out.println("length " + Length);

        System.out.println("");
        System.out.println("SYMBOL TABLE ");
        System.out.printf("%n");

        for (i = 0; i < Labels.length; i++) {
            if (Labels[i] != ";" && Labels[i] != null) {
                System.out.print(Labels[i] + "\t" + address[i]);
                System.out.printf("%n");
            }
        }
        
        
        
        
        
        
        
        System.out.println("\n");
        System.out.println("HTE RECORD");

        Proj.close();
        Proj = null;
        Proj = new Scanner(file);

        if (programName.length() == 4) { 
            programName = programName;
        }
        int tempStrt = getDecimal(startAdd);

        int tempEnd = getDecimal(address[f]); 
        int tempLengthProg = tempEnd - tempStrt;
        String LengthOfProg = Integer.toHexString(tempLengthProg);
        //System.out.println(LengthOfProg);
        //Head
        System.out.println("H^" + programName + "^" + "00" + startAdd + "^" + "00" + LengthOfProg);
        String T = "";
        f = 0;

        while (Proj.hasNext()) {

            String line3 = Proj.nextLine();
            if (!instruction[f].equalsIgnoreCase("RESW") && !instruction[f].equalsIgnoreCase("BYTE") && !instruction[f].equalsIgnoreCase("RESB")) {

                if (!";".equals(OPCode[f])) {
                    T = T + " " + OPCode[f];
                }

            } else {

            }
            i++;
            f++;
        }

        String TRecord[] = T.split(" ");
        System.out.print("T^" + "1D^");
        for (int y = 1; y < 7; y++) {
            System.out.print(TRecord[y] + "^");
        }
        System.out.println("");
        System.out.print("T^" + "13^");
        for (int y = 7; y < 13; y++) {
            System.out.print(TRecord[y] + "^");
        }
        System.out.println("");
        System.out.print("T^" + "1D^");
        for (int y = 13; y < 19; y++) {
            System.out.print(TRecord[y] + "^");
        }
        System.out.println("");
        System.out.print("T^" + "1D^");
        for (int y = 19; y < 25; y++) {
            System.out.print(TRecord[y] + "^");
        }
        System.out.println("");
        System.out.print("T^" + "1D^");
        for (int y = 25; y < 31; y++) {
            System.out.print(TRecord[y] + "^");
        }
        System.out.println("");
        System.out.print("T^" + "07^");
        for (int y = 31; y < 38; y++) {
            System.out.print(TRecord[y] + "^");
        }

        System.out.println("");
        for (int y = 0; y < Modify.length; y++) {
            if (Modify[y] != null) {
                System.out.println("M^" + Modify[y] + "^" + "05");
            }
        }
        System.out.println("E^" + address[0]);

    }
}
