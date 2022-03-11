
package courseregistrationsystem;


public class CourseRegistrationSystem {

     public static void main(String[] args) {
        System.out.println("Course Registration System Main Menu");
        MainMenu main=new MainMenu();
        main.option();
      while(true)
       {
        main.RegistrationSystem();
       if (main.option==15)
           break;
       }
    }
    }
    

