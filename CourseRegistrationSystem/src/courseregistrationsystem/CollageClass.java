
package courseregistrationsystem;


public class CollageClass {
    
    private int collageID;
    private String collageName;
    private CourseClass[] co=new CourseClass[50];
    private StudentClass[] st=new StudentClass[1000];
    private LecturerClass[] le=new LecturerClass[50];
    int count=0;
    int c=0,s=0,l=0;

    CollageClass() {
        
    }
    
    

    public void setCo(CourseClass[] co) {
        this.co = co;
    }

    public CourseClass getCo() {
        return co[0];
    }

    

    public CollageClass(int cid, String cname) {
        this.collageID = cid;
        this.collageName= cname;
    }

  

    public void setCid(int cid) {
        this.collageID = cid;
    }

    public void setCname(String cname) {
        this.collageName = cname;
    }
    
    

    public int getCid() {
        return collageID;
    }

    public String getCname() {
        return collageName;
    }
     
  /*   public void reg(String course) {
         
        st[0].setCourse(course);
        st[0].getCourse();
    }*/

    @Override
    public String toString() {
        return "collageID = "+ collageID+"\n"+"collageName = "+collageName
                +"\n"+"numberOfCourses = "+c+"\n"+"numberOfStudents = "+s+"\n"+
                "numberOfLecturers = "+l; //To change body of generated methods, choose Tools | Templates.
    }
    public void displaycollage(int collagetid ){
         
         if(collageID==collagetid)
                System.out.println( toString());
                
             }
         
     
    //student 
     public void addstudent(int id,String name) {
         
       st[s]=new StudentClass(id,name);
       s++;
    }
     public void regstudent(int studentid ,String coursename) {
         for(int i=0;i<s;i++){
             if(st[i].getSid()==studentid){
                 st[i].setCourse(coursename);
             }
         }
        
        
    }
     public void displaystudent(int studentid ){
         
         for(int i=0;i<s;i++){
             if(st[i].getSid()==studentid){
                System.out.println( st[i].toString());
                
             }
         }
     }
     public void removestudent(int studentid ){
         int count=0;
         for(int i=0;i<s;i++)
         {
           if(st[i].getSid()==studentid)  
               for(int j=i; j<(s-1); j++)
               {
                   st[j] = st[j+1];
               }
               count++;
               break;
           }
         if(count==0)
       {
           System.out.print("Element Not Found..!!\n");
       }
       else
       {
           System.out.print("Element Deleted Successfully..!!\n");
         }     
     }
     public void searchstudent(int studentid ){
         for(int i=0;i<s;i++)
         {
             if(st[i].getSid()==studentid){
                 st[i].search();
                 }
                 
             }
         }
         
     
     //course
     public void addcourse(int id,String name) {
       
      co[c]=new CourseClass(id,name);
      c++;
       
       
    }
     public void displaycourse(int courseid ){
         
         for(int i=0;i<c;i++){
             if(co[i].getId()==courseid){
                System.out.println( co[i].toString());
                
             }
         }
     }
      public void removecourse(int courseid ){
         int count=0;
         for(int i=0;i<c;i++)
         {
           if(co[i].getId()==courseid)  
               for(int j=i; j<(c-1); j++)
               {
                   co[j] = co[j+1];
               }
               count++;
               break;
           }
         if(count==0)
       {
           System.out.print("Element Not Found..!!\n");
       }
       else
       {
           System.out.print("Element Deleted Successfully..!!\n");
         }     
     }
     //lecturer
      public void addlecturer(int id,String name) {
         
       le[l]=new LecturerClass(id,name);
       l++;
    }
      public void reglecturer(int lecturerid ,String coursename) {
         for(int i=0;i<l;i++){
             if(le[i].getLecturerID()==lecturerid){
                 le[i].setCourse(coursename);
             }
         }
        
        
    }
      public String lecCourse(String courseName){
        for(int i=0;i<l;i++){
            if(le[i].getCourse()==courseName)
            return le[i].getLecturerName();
        
    }
        return null;
        
}
     public int countCourse(String courseName){
        for(int i=0;i<l;i++){
            if(st[i].getCourse()==courseName){
            count++;
            }
    }
        return count;
        
}
     public void removelecturer(int lecturerid ){
         int count=0;
         for(int i=0;i<l;i++)
         {
           if(le[i].getLecturerID()==lecturerid)  
               for(int j=i; j<(l-1); j++)
               {
                   le[j] = le[j+1];
               }
               count++;
               break;
           }
         if(count==0)
       {
           System.out.print("Element Not Found..!!\n");
       }
       else
       {
           System.out.print("Element Deleted Successfully..!!\n");
         }     
     }
     public void searchlecturer(int lecturerid ){
         for(int i=0;i<l;i++)
         {
             if(le[i].getLecturerID()==lecturerid){
                 le[i].search();
                 }
                 
             }
         }
         
     
     public void displaylecturer(int lecturerid ){
         
         for(int i=0;i<l;i++){
             if(le[i].getLecturerID()==lecturerid){
                System.out.println( le[i].toString());
                
             }
         }
}
}


    

