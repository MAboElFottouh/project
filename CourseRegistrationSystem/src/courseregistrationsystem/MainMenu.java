
package courseregistrationsystem;

import java.util.Scanner;


public class MainMenu {
     int option;
       int id;
       String name;
       Scanner input = new Scanner (System.in);
       CollageClass collage=new CollageClass(1,"CCIT"); 
        public  void option(){
            System.out.println(
           "1. Add a course\n" +
           "2. Add a student.\n" +
           "3. Add a lecturer.\n" +
           "4. Register a course for a student.\n" +
           "5. Register a course for a lecturer.\n" +
           "6. Display collage information.\n" +
           "7. Display the complete list of courses.\n" +
           "8. Display the complete list of students.\n" +
           "9. Display the complete list of lecturers.\n" +
           "10. Display a list of courses currently taken by a particular student.\n" +
           "11. Display a list of courses currently taught by a particular lecturer.\n" +
           "12.Delete course.\n"+
           "13.Delete student.\n"+
           "14.Delete lecturer.\n"+  
           "15.Quit.");
            
        }
       
    public  void RegistrationSystem() {
        
         System.out.println("Enter operation number");
        
         option=input.nextInt();
         switch(option){
            case 1:
                 System.out.println("Enter courseID ");
                 id=input.nextInt();
                 System.out.println("Enter courseName ");
                 name=input.next();
                 collage.addcourse(id, name);
                 break;
            case 2:
                 System.out.println("Enter studentID ");
                  id=input.nextInt();
                 System.out.println("Enter studentName ");
                  name=input.next();
                 collage.addstudent(id, name);
                 break;
            case 3:
                 System.out.println("Enter lecturerID ");
                  id=input.nextInt();
                 System.out.println("Enter lecturerName ");
                 name=input.next();
                 collage.addlecturer(id, name);
                 break;
            case 4:
                System.out.println("Enter studentID ");
                id=input.nextInt();
                System.out.println("Enter courseName ");
                name=input.next();
                collage.regstudent(id, name);
                break;
            case 5:
                System.out.println("Enter lecturerID ");
                id=input.nextInt();
                System.out.println("Enter courseName ");
                name=input.next();
               collage.reglecturer(id, name);
                break;
            case 6:
                System.out.println("Enter collageID ");
                id=input.nextInt();
                collage.displaycollage(id);
                break;
            case 7:
                System.out.println("Enter courseID ");
                id=input.nextInt();
                collage.displaycourse(id);
                break; 
            case 8:
                System.out.println("Enter studentID ");
                id=input.nextInt();
                collage.displaystudent(id);
                break;
            case 9:
                System.out.println("Enter lecturerID ");
                id=input.nextInt();
                collage.displaylecturer(id);
                
                break;
            case 10:
                System.out.println("Enter studentID ");
                id=input.nextInt();
                collage.searchstudent(id);
                break;
                
            case 11:
                System.out.println("Enter lecturerID ");
                id=input.nextInt();
                collage.searchlecturer(id);
                break;
            case 12:
                System.out.println("Enter courseID ");
                id=input.nextInt();
                collage.removecourse(id);
                break; 
            case 13:
                System.out.println("Enter studentID ");
                id=input.nextInt();
                collage.removestudent(id);
                break; 
            case 14:
                System.out.println("Enter lecturerID ");
                id=input.nextInt();
                collage.removelecturer(id);
                break;
            case 15:
                break;
                
                
         }
        
    }
}
