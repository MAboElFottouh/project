
package courseregistrationsystem;


public class StudentClass {
     private int studentID;
   private String studentName; 
   private  String course[]={"\\","\\","\\","\\","\\","\\"};
   
   int i=0;
   int n=0;
   
   private CollageClass cl=new CollageClass(); 
    public StudentClass(int sid, String sname) {
        this.studentID = sid;
        this.studentName = sname;
      //  initialcourse();
        
    }

    public String getCourse() {
       
         i++;          
       return  course[i-1]; 
    }
    

    public int getSid() {
        return studentID;
    }

    public String getSname() {
        return studentName;
    }

    public void setSid(int sid) {
        this.studentID = sid;
    }

    public void setSname(String sname) {
        this.studentName = sname;
    }

    public void setCourse(String course) {
      this.course[n]=course;
      n++;
    }

    @Override
    public String toString() {
        return "studentID="+studentID+"\n"+"studentName="+studentName+"\n"+
                "numberOfTakenCourses="+countcourse();
    }
    
    public int countcourse(){
        //initialcourse();
        int count=0;
        for(int x=0;x<6;x++){
            if(course[x]!="\\")
              count++;  
        }
       return count;
    }
  
   public void search(){
         for(int i=0;i<6;i++){
             if(course[i]!="\\")
           System.out.println(course[i]);
         }
     }         
            
            
            
    
}
