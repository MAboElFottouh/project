
package courseregistrationsystem;


public class CourseClass {
     private int courseID;
    private String courseName;
    private LecturerClass lecturer=new LecturerClass();
    private CollageClass cl=new CollageClass(); 

    public CourseClass(int id, String name) {
        this.courseID = id;
        this.courseName = name;
    }

    public int getId() {
        return courseID;
    }

    public String getName() {
        return courseName;
    }

    public void setId(int id) {
        this.courseID = id;
    }

    public void setName(String name) {
        this.courseName = name;
    }

   
    public  String lecname (String couseName)
    {
        
            
        return null;
        
    }
        
    
    @Override
    public String toString() {
        return  "courseID="+courseID+"\n"+"courseName="+courseName+"\n"+
                "lecturerName="+lecturer.Leccourse(courseName)+"\n"
                +"numberOfRegisteredStudents"+cl.countCourse(courseName);
    }
    

    
    
}
