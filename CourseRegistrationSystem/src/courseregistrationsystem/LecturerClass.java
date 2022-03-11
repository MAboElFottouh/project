
package courseregistrationsystem;


public class LecturerClass {
     private  int lecturerID;
    private String lecturerName;
    private String Course[]={"\\","\\","\\","\\","\\","\\","\\","\\","\\","\\"};
    int i=0;
    int n=0;
    int count=0;
    private CollageClass cl=new CollageClass(); 
    public LecturerClass(int lecturerID, String lecturerName) {
        this.lecturerID = lecturerID;
        this.lecturerName = lecturerName;
    }

    LecturerClass() {
        
    }
    

    public int getLecturerID() {
        return lecturerID;
    }

    public String getLecturerName() {
        return lecturerName;
    }

    public String getCourse() {
        
         i++;
        return Course[i-1];
    }

    public void setLecturerID(int lecturerID) {
        this.lecturerID = lecturerID;
    }

    public void setLecturerName(String lecturerName) {
        this.lecturerName = lecturerName;
    }

    public void setCourse(String Course) {
        this.Course[n]=Course;
         n++;
    }

    public String Leccourse(String courseName) {
       String lecname= cl.lecCourse(courseName);
        return lecname;
    }

    @Override
    public String toString() {
        
        return "lecturerID"+lecturerID+"\n"+
                "lecturerName"+lecturerName+"\n"
                        +"numberOfTaughtCourses" +countcourse();
    }
    
     public int countcourse(){
        int count=0;
        for(int x=0;x<10;x++){
         
            if(Course[x]!="\\")
              count++;  
        }
       return count;
    }
     public void search(){
         for(int i=0;i<10;i++){
             if(Course[i]!="\\")
           System.out.println(Course[i]);
         }
     }
    
}
